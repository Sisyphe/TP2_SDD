#Makefile pour les programmes

# Commandes
CC = cc
GCC = gcc
CFLAGS = -g -Wall -ansi -pedantic -Wextra
LFLAGS =

EXE = tp2

all: $(EXE)

# Liste des programmes
tp2: main.o stack.o queue.o tree.o dictionnary.o
stack.o: stack.c stack.h tools.h
queue.o: queue.c queue.h tools.h
tree.o: tree.c tree.h tools.h
dictionnary.o: dictionnary.c dictionnary.h

#Compilation Exe
$(EXE) :
	$(GCC) $^ -o $@ $(LFLAGS)

#Compilation Modules
.o : .c
	$(GCC) -o $@ -c $< $(CFLAGS)

#Pour faire le menage
clean:
	rm -f *.o *~ $(EXE)

