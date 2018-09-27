#include "../include/fileRead.h"
#include "../include/opcodes.h"
#include "../include/preprocess.h"
#include "../include/LinkedList.h"

union register_immediate {
  GPR reg;
  int immediate;
};
struct registerImmediate {
  int status; // 0 means union has immediate
              // 1 means union has GPR
  union register_immediate RI;
}

struct instruction {
  int instruction_id;
  registerImmediate op1, op2;
}
typedef struct instruction Instruction;

Instruction * getInstrutions (const char file[]) {
  LOC lines = getLines(file);

}
