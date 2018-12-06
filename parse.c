#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*opcode)(char, int);

int isCorrect(char *);
char isOperand1Correct(char *);
int constructVal(char *);

int A=0, B=0, C=0, D=0;


void _mov(char c, int val);
void _add(char c, int val);
void _sub(char c, int val);
void _mul(char c, int val);
void _divi(char c, int val);
void _xor(char c, int val);
void _and(char c, int val);
void  _or(char c, int val);
void _shl(char c, int val);
void _shr(char c, int val);


opcode o[] = {_mov, _add, _sub, _mul, _divi, _xor, _and, _or, _shl, _shr};

int main(int argc, char const *argv[]) {
  if(argc != 2) {
    printf("\x1b[1mparse: \x1b[31mfatal error:\x1b[0m no input files\ncompilation terminated.\n" );
    return 0;
  }
  FILE *code  = fopen(argv[1], "r");
  char opc[10], op1[10], op2[10], c;
  int lit;
  char op1l;
  while(!feof(code)) {
    c = fscanf(code, "%s%s%s\n", opc, op1, op2);
    if (c == 3) {
      int funcName = isCorrect(opc);
      #ifdef DEBUG
      printf("funcName %d\n", funcName);
      #endif
      if(funcName < 0) {
        printf("Syntax Error: Aborting\n" );
        return 0;
      }
      sscanf(op1, "%[^,]s", op1);
      op1l = isOperand1Correct(op1);
      #ifdef DEBUGH
      printf("operand1 %d\n", op1l);
      #endif
      if(!op1l) {
        printf("%s\n", "Invalid Operand");
        return 0;
      }
      lit = constructVal(op2);
      #ifdef DEBUGOP2
      printf("lit %d\n", lit);
      #endif
      o[funcName](op1l, lit);
    }
  }
  printf(" A = %d\n B = %d\n C = %d\n D = %d\n", A, B, C, D);
}

int isCorrect(char * opc) {
  char legal[20][10] =
  {"mov", "add", "sub", "mul", "div",
   "xor", "and", "or", "shl", "shr"
  };
  int i = 0, r;
  while(i < 10) {
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
  int len  = strlen(operand);
  int flag = 0;  // Assume it is already int
  for(int i = 0; i < len; i++) {
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
