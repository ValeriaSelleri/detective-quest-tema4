CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = main.c tree.c
OBJ = $(SRC:.c=.o)
TARGET = detective

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
