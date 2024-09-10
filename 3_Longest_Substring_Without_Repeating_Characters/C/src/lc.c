#include <stdbool.h>
#include <stdio.h>

int lengthOfLongestSubstring(char *s) {
  // Check for empty string
  int count[256] = {0};
  if (s[0] == '\0')
    return 0;
  int length = 0;
  char forward;
  int i = 0;
  int behind_idx = 0;
  char behind = s[behind_idx];
  bool condition = true;
  while (true) {
    // calculate length of substr

    // update position of forward pointer
    forward = s[i];
    if (length < i - behind_idx && forward != behind) {
      printf("behind: %c, forward: %c\n", behind, forward);
      length = i - behind_idx;
    }
    // printf("%c %c, %d\n", behind, forward, count[forward]);

    // check if end of string has been reached.
    if (forward == '\0')
      break;
    // increment count of character seen
    count[forward]++;

    // Check to see if character has been seen before
    if (count[forward] > 1) {
      printf("!!! - behind: %c, forward: %c, i: %d\n", behind, forward, i);
      condition = false;
    }

    // move behid pointer until condition is now met
    if (!condition) {
      printf("begin correction\n");
    }
    while (!condition) {
      printf("behind: %c, forward: %c, count[forward]: %d\n", behind, forward,
             count[forward]);
      // decrement count of character seen at behind pointer before moving it
      // forwards
      count[behind]--;

      // move behind pointer forward
      behind_idx++;
      behind = s[behind_idx];

      // break out of loop if indexes are the same, resets
      if (behind_idx == i) {
        condition = true;
      }

      if (count[forward] < 2) {
        condition = true;
      }
    }
    i++;
  }

  printf("\n");
  return length;
}
