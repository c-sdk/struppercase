#include <assert.h>
#include <ctype.h>

#include "struppercase.h"

void struppercase(char* str) {
  assert(str);
  while(*str != 0) {
    *(str) = toupper(*str);
    ++str;
  }
}

void strnuppercase(char* str, size_t length) {
  assert(str);
  assert(length >= 0);
  while(*str != 0 && length-- > 0) {
    *(str) = toupper(*str);
    ++str;
  }
}
