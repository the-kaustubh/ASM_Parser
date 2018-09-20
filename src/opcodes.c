#include "../include/opcodes.h"

Opcode getOpcode(const char opstring []) {
  char * opclist[] = {
    "add", "sub", "mul", "div",
    "mov", "push", "pop",
    "or", "and", "not",
    "jmp", "jz", "jnz", "jc", "jnc"
    "jg", "jl"
  };
  int code[20] = {0};
  for (int i = 0; i < 20; i++) code[i] = i+1;
  char * opStr = toLower(opstring);
  for(int i = 0; i < 17; i++) {
    if(!strcmp(opStr, opclist[i])) return code[i];
  }
  return 0;
}

char * toLower(const char str[]) {
  int len =  strlen(str);
  char * finalStr = malloc(len);
  for (int i = 0; i < len; i++) {
    finalStr[i] = tolower(str[i]);
  }
  return finalStr;
}
