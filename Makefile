######	MAKEFILE	########

CC = gcc
flags = -c -Wall
CFLAGS = -lm
ARQUIVOS = *.o
OBJS = fila.o pilha.o hanoi.o main.o
EXE = main
MAIN = main.c

all: fila.o pilha.o hanoi.o main.o
	$(CC) $(OBJS) -o $(EXE)
	./main

main.o: main.c
	$(CC) $(flags) $(MAIN) $(CFLAGS)

pilha.o: pilha.c
	$(CC) $(flags) Pilha.c $(CFLAGS)

fila.o: Fila.c
	$(CC) $(flags) Fila.c $(CFLAGS)

hanoi.o: hanoi.c
	$(CC) $(flags) hanoi.c $(CFLAGS)


listar:
	ls $(ARQUIVOS)

clean:
	rm -f *.o *.i *.s
	rm -f $(EXE)