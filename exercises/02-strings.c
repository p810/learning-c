#include <stdio.h>

/* By default arguments will be passed by value rather than reference, so they
 * will be copied into the function's scope, and any changes to those variables
 * aren't reflected outside of it.
 * 
 * This behavior can be changed when using pointers, which is analogous to PHP's
 * references.
 */
int sayHelloTo(char* subject) {
  printf("Hello %s", subject);

  return 0;
}

int main() {
  /* Strings can be thought of as arrays of characters, and can be declared with
   * the `char` type.
   *
   * A `char` variable refers to a single character by default:
   * 
   * ```
   * // This is technically "w\0" (explained below)
   * char foo = "w";
   * 
   * // Whereas this is just "w" in its codepoint form (an integer),
   * // and something like printf("%c", bar) can be used to print it
   * char bar = 'w';
   * ```
   * 
   * Double quotes are used to define string literals, which are sequences of chars
   * followed by `\0` (the string terminator). Each character in the string is stored
   * sequentially in memory, and C reads each successive memory address starting from
   * the address that the first character was stored in, until it reaches `\0`.
   * 
   * Single quotes are used for individual characters.
   * 
   * Because strings contain multiple characters, we most often declare string vars
   * as pointers:
   * 
   * ```
   * char *foo = "world";
   * ```
   * 
   * However if we need a locally modifiable string we can declare it like an array:
   * 
   * ```
   * char foo[] = "world";
   * ```
   * 
   * This is a dynamically sized string, and if we want it to be statically sized,
   * we can specify the length of the string + 1 for the terminator:
   * 
   * ```
   * char foo[6] = "world";
   * ```
   */
  char *foo = "world";

  return sayHelloTo(foo);
}
