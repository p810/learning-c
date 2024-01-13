#include <stdlib.h>
#include <stdio.h>

typedef struct {
  char *name;
  int age;
} person;

person* getNewPerson() {
  /* In the following call we allocate enough memory to store a person object.
   * The size of a struct is the sum of its members, so on my machine this will
   * be 16 bytes: 4 bytes for an integer, 8 bytes for a pointer, & 4 bytes for
   * alignment padding (I think?)
   * 
   * (Side note: The tutorial I'm following did an explicit typecast by prefixing
   * the `malloc()` call with `(person *)`. This was done because apparently the
   * type returned by `malloc()` is `void *` by default. However I read elsewhere
   * that the explicit typecast is unnecessary, and that it can actually hide some
   * subtle errors that can be painful to debug. So I decided to omit it here and
   * allow the compiler to do that work for me.)
   */
  person *x = malloc(sizeof(person));

  return x;
}

int main() {
  person *y = getNewPerson();

  printf("sizeof(y) = %lu\n", sizeof(*y));

  y->name = "John Jacob Jingleheimer Schmidt";
  y->age = 28;

  printf("sizeof(y->age) = %lu\n", sizeof(y->age));
  /* This will still be 8 because sizeof() gives us the size of the type itself.
   * If we were to dereference the pointer with `sizeof(*p->name)` we would see
   * `1` because the pointer references a character, which is only 1 byte long
   * in ASCII. For the size of the value, we would use `strlen()`.
   */
  printf("sizeof(y->name) = %lu\n", sizeof(y->name));

  /* Whenever we dynamically allocate memory we must remember to free it after
   * we're done using it, otherwise we can run into memory leaks.
   */
  free(y);
}
