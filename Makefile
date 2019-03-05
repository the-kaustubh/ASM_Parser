parse:
	gcc parse.c -o parse.o

debug-all:
		gcc parse.c -g -o parse.d.o

clean:
	rm *.o
