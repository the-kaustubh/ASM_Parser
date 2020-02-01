#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

int main(int argc, char const *argv[]) {
	FILE *code  = fopen(argv[1], "r");
	char opc[10], op1[10], op2[10], line[50], c, op1l;
	long flags[MAX_FLAGS] = {0};
	int lit, counter=0;

	if(argc != 2) {
#ifdef WIN
		printf("parse: fatal error: no input files\ncompilation terminated.\n" );
#else
		printf("\x1b[1mparse: \x1b[31mfatal error:\x1b[m no input files\ncompilation terminated.\n" );
#endif
		return 0;
	}

	//    c = fscanf(code, "%s%s%s\n", opc, op1, op2);  // worked just fine
	while(fgets(line, 50, code))  {
		c = sscanf(line, "%s%s%s", opc, op1, op2);
		//    printf("%s %s %s\n", opc, op1, op2);
		if (c == 3) {
			int funcName = isCorrect(opc);

			if(funcName < 0) {
				printf("Syntax Error: Aborting\n" );
				return 0;
			}
			sscanf(op1, "%[^,]s", op1);
			op1l = isOperand1Correct(op1);

			if(!op1l) {
				printf("%s\n", "Invalid Operand");
				return 0;
			}
			lit = constructVal(op2);

			o[funcName](op1l, lit);
		}
		else if (c == 2) {
			int funcName = isCorrect(opc);
			//     printf("%d\n", funcName);
			//printf("%s %s\n", opc, op1);
			if(funcName < 0) {
				printf("Syntax Error: Aborting");
				return 0;
			}
			op1l = isOperand1Correct(op1);
			switch(funcName-10) {
				case 0:
					_push(constructVal(op1));
					break;
				case 1:
					if(!op1l) {
						printf("Syntax Error: Cannot pop into a literal\n");
						return 0;
					}
					_pop(op1[0]);
					break;
			}
		}
		else if(c == 1) {
		  printf("flag detected\n" );
		  flags[counter++] = ftell(code);
		  continue;
		}
	}
	for (size_t i = 0; i < counter; i++) {
	  printf("flag at %lu\n", flags[i]);
	}
	printf(" A = %d\n B = %d\n C = %d\n D = %d\n", A, B, C, D);
	fclose(fp);
}

int isCorrect(char * opc) {
	char legal[MAX_FUNC][5] =
	{"mov", "add", "sub", "mul", "div",
		"xor", "and", "or", "shl", "shr",
		"push", "pop"
	};
	int i = 0, r;
	while(i < MAX_FUNC) {
		r = strcmp(opc, legal[i]);
		if (r == 0) return i;
		i++;
	}
	return -1;
}

char isOperand1Correct(char * op1)  {
	char legal[4][2] = {"a", "b", "c", "d"};
	int i = 0, j;
	while (i < 4) {
		j = strcmp(op1, legal[i]);
		if(j == 0) return legal[i][0];
		i++;
	}
	return 0;
}

int constructVal(char * operand)  {
	int len  = strlen(operand), i = 0;
	int flag = 0;  // Assume it is already int
	for(i = 0; i < len; i++) {
		if(operand[i] > '9' || operand[i] < 0) {
			//  Simplified this -- !(operand[i] < '9' && operand[i] > 0)
			flag = 1;
		}
	}
	if(flag == 0) {
		return atoi(operand);
	}
	switch (operand[0]) {
		case 'A':
		case 'a':
			return A;
		case 'B':
		case 'b':
			return B;
		case 'C':
		case 'c':
			return C;
		case 'D':
		case 'd':
			return D;
	}
	return 0;
}

// -----------------------------------------------------------------------

void _mov(char c, int val) {
	switch (c) {
		case 'a': A=val; return;
		case 'b': B=val; return;
		case 'c': C=val; return;
		case 'd': D=val; return;
	}
}

void _add(char c, int val) {
	switch (c) {
		case 'a': A+=val; return;
		case 'b': B+=val; return;
		case 'c': C+=val; return;
		case 'd': D+=val; return;
	}
}
void _sub(char c, int val) {
	switch (c) {
		case 'a': A-=val; return;
		case 'b': B-=val; return;
		case 'c': C-=val; return;
		case 'd': D-=val; return;
	}
}
void _mul(char c, int val) {
	switch (c) {
		case 'a': A*=val; return;
		case 'b': B*=val; return;
		case 'c': C*=val; return;
		case 'd': D*=val; return;
	}
}
void _divi(char c, int val) {
	switch (c) {
		case 'a': A/=val; return;
		case 'b': B/=val; return;
		case 'c': C/=val; return;
		case 'd': D/=val; return;
	}
}


void _xor(char c, int val) {
	switch (c) {
		case 'a': A^=val; return;
		case 'b': B^=val; return;
		case 'c': C^=val; return;
		case 'd': D^=val; return;
	}
}

void _and(char c, int val) {
	switch (c) {
		case 'a': A&=val; return;
		case 'b': B&=val; return;
		case 'c': C&=val; return;
		case 'd': D&=val; return;
	}
}

void _or(char c, int val) {
	switch (c) {
		case 'a': A|=val; return;
		case 'b': B|=val; return;
		case 'c': C|=val; return;
		case 'd': D|=val; return;
	}
}

void _shl(char c, int val) {
	switch (c) {
		case 'a': A<<=val; return;
		case 'b': B<<=val; return;
		case 'c': C<<=val; return;
		case 'd': D<<=val; return;
	}
}

void _shr(char c, int val) {
	switch (c) {
		case 'a': A>>=val; return;
		case 'b': B>>=val; return;
		case 'c': C>>=val; return;
		case 'd': D>>=val; return;
	}
}
void _push( int val) {
	stack[stack_pointer] = val;
	stack_pointer++;
	if(stack_pointer == STACK_LIMIT) {
		printf("Stack Overflow\n");
	}
}

void _pop(char c) {
	// printf("%c = %d", c, stack[stack_pointer]);
	stack_pointer--;
	int val = stack[stack_pointer];
	_mov(c, val);
}
