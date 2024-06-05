#pragma once
#include <mm_malloc.h>
#include <printf.h>

unsigned int Length(int array[]) {
   return sizeof(array) / sizeof(array[0]);
}

unsigned int Length(char array[]) {
   return sizeof(array) / sizeof(array[0]);
}


  /***************************************************************/
 //https://stackoverflow.com/users/2410359/chux-reinstate-monica//
/***************************************************************/
static char *itoa_simple_helper(char *dest, int i) {
  if (i <= -10) {
    dest = itoa_simple_helper(dest, i/10);
  }
  *dest++ = '0' - i%10;
  return dest;
}

char *toString(char *dest, int i) {
  char *s = dest;
  if (i < 0) {
    *s++ = '-';
  } else {
    i = -i;
  }
  *itoa_simple_helper(s, i) = '\0';
  return dest;
}

/**********************************************************/
