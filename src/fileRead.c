#include "../include/fileRead.h"
#include "../include/opcodes.h"
#include "../include/preprocess.h"

FileStats getFileStats(const char * fname) {
  FILE * fp = fopen(fname, "r");
  unsigned bytes = 0, row = 0, col = 0, max = 0, counter= 0;
  char curr;

  while(!feof(fp)) {
    curr = getc(fp);
    bytes++;
    curr = (curr != -1)? (curr) : (0);
    if (curr == 0xa) {
      row++;
      if(col > max) max = col;
      col = 0;

      continue;
    }
    else {
      col++;

    }
  }
  FileStats fs = malloc(sizeof(struct fileStats));
  fs->data = malloc(bytes+10);
  for(int i =0; i < bytes+10;i++) fs->data[i] =  0;
  rewind(fp);
  while(!feof(fp)) {
    curr = getc(fp);
    curr = (curr != -1) ? (curr) : (0);
    fs->data[counter] = curr;
    counter++;
  }
  fs->data[--counter] = 0;
  fclose(fp);
  fs->bytes = bytes;
  fs->lines = row;
  fs->max_chars_per_line = max;

  return fs;
}

LOC getLines(char const * fname) {
  char curr;
  int row, col, counter;
  row = col = counter = 0;
  int rows = 0, cols = 0;
  LOC loc1 = malloc(sizeof(struct lines));
  FileStats fs = getFileStats(fname);

  char **lines = malloc(fs->lines * fs->max_chars_per_line);
  for(int i = 0; i < fs->lines; i++) {
    *(lines+i) = calloc(1,fs->max_chars_per_line+10);
  }
  char *buffer = fs->data;
  for(counter = 0;buffer[counter]!=0; counter++) {
    if(buffer[counter] == 10) {
      row++;
      col=0;
      continue;
    }
    else {
      curr = buffer[counter];
      if(curr >= 'A' && curr <= 'Z')
        curr += 32;
      *(*(lines+row)+col) = curr;
      col++;
    }
  }
  loc1->lineCount = row;
  loc1->lines = lines;
  free(fs);
  return loc1;
}

void main() {
  LOC l1 = getLines("new.asm");
  for(int i =0; i < l1->lineCount; i++) {
    char c1[5], c2[5], c0[5];
    printf("%s\n", l1->lines[i]);
    getOperands(l1->lines[i], c0, c1, c2);
    printf("opc: `%s` & op1: `%s` & op2: `%s`\n", c0, c1, c2);
    printf("opcode: %d\n", getOpcode(c0));
    printf("---\n" );
  }
  printf("\n" );
}
