#include <stdio.h>

/* A pointer is an integer that represents a memory address for another value.
 * When you assign a pointer variable you're "referencing" that data.
 *
 * Declaring a pointer parameter like below essentially tells the compiler to
 * expect a memory address that points to a value of the hinted type.
 */
void doubleValue(int *z) {
  printf("z = %p\n", z); // Should print the memory address of the argument
  *z *= 2;
  printf("z = %d\n", *z);
}

int main() {
  int x = 5;
  /* If you have a value that you want to obtain a pointer / reference to, you
   * can use an ampersand to do so:
   */
  int *y = &x;
  
  printf("x = %d\n", x); // This will show the value of x
  printf("y = %p\n", y); // This will show the memory address of the value of x

  /* Dereferencing is the name for what we do when we have a pointer whose value
   * we want to fetch. For example we can increment `y` below by dereferencing it:
   */
  *y += 1;

  printf("y = %d\n", *y);
  printf("x = %d\n", x);

  doubleValue(y);

  printf("y = %d\n", *y);
}