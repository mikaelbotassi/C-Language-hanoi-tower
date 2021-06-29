######	MAKEFILE	########

CC = gcc
flags = -c -Wall
CFLAGS = -lm
ARQUIVOS = *.o
OBJS = Fila.o Pilha.o hanoi.o main.o
EXE = main
MAIN = main.c

all: Fila.o Pilha.o hanoi.o main.o
	$(CC) $(OBJS) -o $(EXE)
	./main

main.o: main.c
	$(CC) $(flags) $(MAIN) $(CFLAGS)

Pilha.o: Pilha.c
	$(CC) $(flags) Pilha.c $(CFLAGS)

Fila.o: Fila.c
	$(CC) $(flags) Fila.c $(CFLAGS)

hanoi.o: hanoi.c
	$(CC) $(flags) hanoi.c $(CFLAGS)

run:
	./main

listar:
	ls $(ARQUIVOS)

clean:
	rm -f *.o
	rm -f $(EXE)