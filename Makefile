CC = gcc
CFLAGS = -g
CFILESINDEX = algo.c

all: goldbach

goldbach : $(CFILESINDEX)
	$(CC) $(CFLAGS) -o goldbach $(CFILESINDEX) -lm


clean:
	rm -rf *.o goldbach.txt goldbach
