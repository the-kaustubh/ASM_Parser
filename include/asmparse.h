#ifndef __KSTACK_H
#include <kstack.h>
#endif

#ifndef __ASMPARSE_H
#define __ASMPARSE_H

struct gpReg {
  char name;
  int value;
};
typedef struct gpReg *GPR;

static struct gpFlags {
  unsigned int Carry:1;
  unsigned int Zero:1;
  unsigned int err:6;
} FLAGS;

struct gpReg AccumulatorRegister, BaseRegister, CounterRegister, DataRegister;
GPR _AX = &AccumulatorRegister;
GPR _BX = &BaseRegister;
GPR _CX = &CounterRegister;
GPR _DX = &DataRegister;

GPR __register_array[] = {_AX, _BX, _CX, _DX};


/* TODO: Implement
  add, sub, mul, div,
  mov, push, pop,
  or, and, not.

  If time allows -
  jmp, jz, jnz, jc, jnc, jg, jl.

 */
void addImm(GPR R, int val);
void subImm(GPR R, int val);
void mulImm(GPR R, int val);
void divImm(GPR R, int val);

void addReg(GPR dst, GPR src);
void subReg(GPR dst, GPR src);
void mulReg(GPR dst, GPR src);
void divReg(GPR dst, GPR src);



#endif
