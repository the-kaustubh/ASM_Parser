#ifndef __STDLIB_H
#include <stdlib.h>
#endif
#ifndef __STDIO_H
#include <stdio.h>
#endif
#ifndef __STRING_H
#include <string.h>
#endif

#ifndef __FILEREAD_H
#define __FILEREAD_H

typedef struct fileStats {
  unsigned bytes,lines, max_chars_per_line;
  char*data;
} *FileStats;

typedef struct lines {
  int lineCount;
  char ** lines;
} *LOC;

FileStats getFileStats(const char * fname);

LOC getLines(char const * fname);

#endif
