#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*opcode)(char, int);

int isCorrect(char *);
char isOperand1Correct(char *);

int A=0, B=0, C=0, D=0;


void add(char c, int val);
void sub(char c, int val);
void mul(char c, int val);
void divi(char c, int val);

opcode o[] = {add, sub, mul, divi};

int main() {
  FILE *code  = fopen("code.asm", "r");
  char opc[10], op1[10], op2[10], c;
  int lit;
  char op1l;
  while(!feof(code)) {
    c = fscanf(code, "%s%s%s\n", opc, op1, op2);
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
      lit = atoi(op2);
      o[funcName](op1l, lit);
    }
  }
  printf(" A = %d\n B = %d\n C = %d\n D = %d\n", A, B, C, D);
}

int isCorrect(char * opc) {
  char legal[10][10] =
  {"mov", "add", "sub", "mul", "div",
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
    j = strcmp(op1, legal[i++]);
    if(j == 0) return legal[i][0];
  }
 return 0;
}


void mov(char c, int val) {
  switch (c) {
    case 'a': A=val; return;
    case 'b': B=val; return;
    case 'c': C=val; return;
    case 'd': D=val; return;
  }
}

void add(char c, int val) {
  switch (c) {
    case 'a': A+=val; return;
    case 'b': B+=val; return;
    case 'c': C+=val; return;
    case 'd': D+=val; return;
  }
}
void sub(char c, int val) {
  switch (c) {
    case 'a': A-=val; return;
    case 'b': B-=val; return;
    case 'c': C-=val; return;
    case 'd': D-=val; return;
  }
}
void mul(char c, int val) {
  switch (c) {
    case 'a': A*=val; return;
    case 'b': B*=val; return;
    case 'c': C*=val; return;
    case 'd': D*=val; return;
  }
}
void divi(char c, int val) {
  switch (c) {
    case 'a': A/=val; return;
    case 'b': B/=val; return;
    case 'c': C/=val; return;
    case 'd': D/=val; return;
  }
}
