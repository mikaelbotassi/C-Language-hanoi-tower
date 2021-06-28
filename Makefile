CC = gcc
flags = -c -Wall
CFLAGS = -lm
ARQUIVOS = *.o
OBJS = fila.o pilha.o hanoi.o main.o
EXE = main
MAIN = main.c

all: fila.o pilha.o hanoi.o main.o
	$(CC) $(OBJS) -o $(EXE)

main.o: main.c
	$(CC) $(flags) $(MAIN) $(CLFLAGS)

pilha.o: pilha.c
	$(CC) $(flags) Pilha.c

fila.o: Fila.c
	$(CC) $(flags) Fila.c

hanoi.o: hanoi.c
	$(CC) $(flags) hanoi.c $(CLFLAGS)

passos: main.c
	gcc -E main.c -o main.i
	gcc -S main.i -o main.s
	gcc -c main.s -o main.o
	gcc main.o fila.o pilha.o hanoi.o -o main -lm


listar:
	ls $(ARQUIVOS)

clean:
	rm -f *.o *.i *.s
	rm -f $(EXE)

run:
	./main