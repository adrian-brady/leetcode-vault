#include "lc.h"
#include <stdio.h>

int main() {
  char *str = "abcabcbb";
  int length = lengthOfLongestSubstring(str);
  printf("%d\n", length);
  return 0;
}
