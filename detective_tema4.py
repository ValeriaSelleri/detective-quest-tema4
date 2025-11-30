class Node:
    def __init__(self, text):
        self.text = text
        self.yes = None
        self.no = None

def play(node):
    if not node.yes and not node.no:
        r = input(f"Você pensou em: {node.text}? (s/n): ").lower()
        if r == "s":
            print("Acertei!")
        else:
            novo = input("Quem era? ")
            pergunta = input(f"Uma pergunta que diferencia {novo} de {node.text}: ")
            r2 = input(f"Para {novo} a resposta é sim? (s/n): ").lower()

            old = Node(node.text)
            new = Node(novo)

            node.text = pergunta
            if r2 == "s":
                node.yes = new
                node.no = old
            else:
                node.yes = old
                node.no = new
        return

    r = input(node.text + " (s/n): ").lower()
    if r == "s":
        play(node.yes)
    else:
        play(node.no)

def print_tree(node, depth=0):
    if not node: return
    print("  "*depth + "- " + node.text)
    print_tree(node.yes, depth+1)
    print_tree(node.no, depth+1)

def main():
    root = Node("É humano?")
    root.yes = Node("Detetive Pikachu")
    root.no = Node("Batman")

    while True:
        print("\n1-Jogar  2-Mostrar  0-Sair")
        op = input("> ")
        if op == "1":
            play(root)
        elif op == "2":
            print_tree(root)
        else:
            break

if __name__ == "__main__":
    main()
