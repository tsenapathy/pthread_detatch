CC=gcc
CFLAGS=-I.

pthread: pthread.o 
	$(CC) -o pthread pthread.o -lpthread
