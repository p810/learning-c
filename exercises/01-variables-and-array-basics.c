#include <stdio.h>

/* main() will be the entry point of a C program.
 *
 * It will return an int, 0 for success or >= 1 for failure. This is used as the
 * program's exit code. By default if nothing is returned it will be 0.
 */
int main() {
  /* Variables are declared with the type preceding the name, like so,
   * and can optionally omit the value to be assigned later:
   */
  int factorial = 1;

  /* Arrays are declared by appending square brackets to the variable name.
   * In the case below we have an array of ints that can have up to 10 items.
   * If the length is omitted from the brackets, the array will be dynamically sized.
   * As for the declaration itself (the value), curly braces are used.
   */
  int numbers[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  for (int i = 0; i < 10; i++) {
    factorial *= numbers[i];
  }

  printf("The factorial of ten is %d", factorial);

  return 0;
}