# Desafio Detective Quest – Tema 4
Trabalho de Estrutura de Dados — Estácio

Este projeto implementa um sistema de detetive usando **Árvore Binária de Decisão**, que aprende novas perguntas e novos suspeitos conforme você joga.

## Funcionalidades
- Percurso de perguntas "Sim/Não"
- Cada suspeito é um nó folha
- Permite aprender novos suspeitos
- Gera novas perguntas automaticamente
- Salva e carrega a árvore (`arvore.txt`)
- Versão em C (com Makefile) e versão em Python

## Como compilar (C)
```bash
cd src
make
./detective
