

#define MAX_FUNC 12

#define STACK_LIMIT 100
#define MAX_FLAGS 100

typedef void (*opcode)(char, int);
int isCorrect(char *);
char isOperand1Correct(char *);
int constructVal(char *);

int A=0, B=0, C=0, D=0;
struct flags_t {
  unsigned int ZF:1;
  unsigned int OV:1;
  unsigned int reserved:6;
} flags_reg;
int stack[STACK_LIMIT] = {0};
int stack_pointer = 0;

void _mov (char c, int val);
void _add (char c, int val);
void _sub (char c, int val);
void _mul (char c, int val);
void _divi(char c, int val);
void _xor (char c, int val);
void _and (char c, int val);
void  _or (char c, int val);
void _shl (char c, int val);
void _shr (char c, int val);
void _push(int val);
void _pop (char c);

opcode o[] = {_mov, _add, _sub, _mul, _divi, _xor, _and, _or, _shl, _shr};
