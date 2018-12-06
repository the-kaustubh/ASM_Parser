parse:
	gcc parse.c -o parse.o

debug:
	gcc parse.c -DDEBUGH -o parse.o

debug-all:
		gcc parse.c -g -o parse.o

debug_op2:
		gcc parse.c -DDEBUGOP2 -o parse.o

clean:
	rm *.o
