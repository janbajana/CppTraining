// File name: ExtremeC_examples_chapter3_1_funcs.c
// Description: Contains two functions 'max' and 'max_3'

#include "examples_chapter3_2_funcs.h"

int max(int a, int b) {
  return a > b ? a : b;
}

int max_3(int a, int b, int c) {
  int temp = max(a, b);
  return c > temp ? c : temp;
}
