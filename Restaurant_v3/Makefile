all: restaurant

restaurant: main.o header.h
	gcc -o restaurant main.o init_table.o init_carte.o clean_buffer.o affiche_carte.o

main.o: main.c header.h init_table.o init_carte.o clean_buffer.o affiche_carte.o
	gcc -o main.o -c main.c

init_table.o: init_table.c header.h
	gcc -o init_table.o -c init_table.c

init_carte.o: init_carte.c header.h
	gcc -o init_carte.o -c init_carte.c

clean_buffer.o: clean_buffer.c	header.h
	gcc -o clean_buffer.o -c clean_buffer.c

affiche_carte.o: affiche_carte.c header.h
	gcc -o affiche_carte.o -c affiche_carte.c
