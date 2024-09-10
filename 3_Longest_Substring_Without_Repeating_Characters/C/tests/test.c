#include "lc.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct test {
  char *name;
  char *str;
  int expected;
  int got;
} Test;

Test makeTest(char *name, char *str, int expected) {
  Test testVar;
  testVar.name = name;
  testVar.expected = expected;
  testVar.str = str;
  testVar.got = lengthOfLongestSubstring(testVar.str);

  return testVar;
}

int main() {
  Test tests[] = {
      makeTest("Test 1", "abcabcbb", 3),
      makeTest("Test 2", "abcdefgg", 7),
      makeTest("Test 3", "addy", 2),
      makeTest("Test 4", "AJ", 2),
      makeTest("Empty String Test", "", 0),
      makeTest("LC Test 102", "nfpdmpi", 5),
  };

  int size = sizeof(tests) / sizeof(Test);

  for (int i = 0; i < size; i++) {
    assert(tests[i].expected == tests[i].got);
    printf("Test '%s' passed.\n", tests[i].name);
  }

  printf("All tests passed.\n");

  return 0;
}
