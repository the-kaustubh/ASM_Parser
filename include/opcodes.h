#ifndef __STDLIB_H
#include <stdlib.h>
#endif
#ifndef __STDIO_H
#include <stdio.h>
#endif
#ifndef __STRING_H
#include <string.h>
#endif
#ifndef __CTYPE_H
#include <ctype.h>
#endif

 enum OPCODES { _ADD_=1, _SUB_, _MUL_, _DIV_,      // Arithmetic operations
                _MOV_ , _PUSH_, _POP,              // Data transfer operations
                _OR_, _AND_, _NOT_,                // Bitwise operations
                _JMP_, _JZ_, _JNZ_, _JC_, _JNC_,   // Branching
                _JG_, _JL_                         // operations
              };

typedef enum OPCODES Opcode;

Opcode getOpcode(const char opstring[]);

char * toLower(const char str[]);
