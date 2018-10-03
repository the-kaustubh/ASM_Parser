#include "../include/preprocess.h"

// union register_immediate {
//   GPR reg;
//   int immediate;
// };
// struct registerImmediate {
//   int status; // 0 means union has immediate
//               // 1 means union has GPR
//   union register_immediate RI;
// }
//
// struct instruction {
//   int instruction_id;
//   registerImmediate op1, op2;
// }
// typedef struct instruction * Instruction;

// Instruction * getInstrutions (const char file[]) {
//   LOC lines = getLines(file);
//   char * currentMnemonic = lines->lines;
//   for(int i = 0;i < lines->lineCount; i++) {
//
//   }
// }

void getOperands(const char * mnemonic, char * op0, char * op1, char * op2) {
  // int op1Start, op2Start, op1End, op2End;
  // int i=0;
  // for(i = 0; mnemonic[i] != ' '; i++);
  // for (; mnemonic[i] != 0; i++) {
  //   if(mnemonic[i] == ' ') {
  //     op1Start = i+1;
  //   }
  //   if(mnemonic[i] == ',') {
  //     op2Start = i+1;
  //     op1End  = i;
  //   }
  //   if(mnemonic[i+1] == '\0') {
  //     op2End  = i+1;
  //   }
  // }
  // strncpy(op1, mnemonic+op1Start, op1End - op1Start - 1);
  // strncpy(op2, mnemonic+op2Start, op2End - op2Start - 1);
  // printf("op1s: %d\nop1e: %d\nop2s: %d\nop2e: %d\n", op1Start, op1End, op2Start, op2End);
  sscanf(mnemonic, "%4[^ ] %4[^, ]%*[,] %4s", op0, op1, op2);
}
