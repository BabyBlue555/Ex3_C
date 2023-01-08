CC=gcc
FLAGS= -Wall -g

all: isort txtfind

isort: main.o insertion_sort.o
	$(CC) $(FLAGS) -o isort main.o insertion_sort.o
	
txtfind: txt_find.o 
	$(CC) $(FLAGS) -o txtfind txt_find.o 
	
main.o: main.c insertion_sort.h 
	$(CC) $(FLAGS) -c main.c 
	
insertion_sort.o: insertion_sort.c insertion_sort.h
	$(CC) $(FLAGS) -c insertion_sort.c
	
txt_find.o: txt_find.c txt_find.h
	$(CC) $(FLAGS) -c txt_find.c
	
	
.PHONY: clean all 
 
clean:
	rm -f *.o *.so isort txtfind
	
	
	
