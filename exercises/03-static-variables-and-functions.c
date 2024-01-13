#include <stdio.h>

/* When the static keyword is applied to a function, it will _reduce_ its scope
 * to the file it's defined in. Otherwise, a function that is declared without
 * using the static keyword will be global.
 */
static int addToCount(int num) {
  /* When the static keyword is applied to a variable, it will _expand_ its scope
   * and make it so it outlives the lifetime of the function call, and subsequent
   * calls to the function it's defined in will have the same value.
   */
  static int count = 0;

  count += num;

  return count;
}

int main() {
  printf("count = %d\n", addToCount(5)); // count = 5
  printf("count = %d\n", addToCount(4)); // count = 9
}
