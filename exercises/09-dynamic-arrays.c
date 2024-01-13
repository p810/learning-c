#include <stdlib.h>
#include <stdio.h>

/* The below example demonstrates the different ways to access a pointer to an
 * element of an array.
 *
 * For most cases, array *names* are implicitly typecast to a pointer of the data
 * type represented by the array. For example with an array of integers named `a`,
 * the variable `a` will often mean `a pointer to the first int in the array`.
 * This is why the first line that's printed, and the three lines that are printed
 * during the first iteration of the loop, all have the same address.
 */
void getPointerToArrayElementExample() {
  char vowels[] = {'A', 'E', 'I', 'O', 'U'};
  char *pointer_to_vowels = vowels;

  printf("vowels = %p\n\n", vowels);

  for (int i = 0; i < 5; i++) {
    /* These two forms are interesting because they demonstrate how we can use arithmetic
     * operators to move around the array. When used with a pointer, the expression will
     * take the size of the data type that pointer refers to into account, meaning it
     * really translates to `pointer + (size_of_type * i)`. Since characters are only 1
     * byte, `pointer_to_vowels + 1` adds only 1 byte, but if it were an array of ints
     * we were dealing with, it would be read as `pointer_to_ints + 4`, since the int type
     * is 4 bytes.
     */ 
    printf("pointer_to_vowels + %d = %p\n", i, pointer_to_vowels + i);
    printf("vowels + %d = %p\n", i, vowels + i);
    /* Below is one of the exceptions to the rule about implicit casting of array vars.
     * When used as the operand of either the `sizeof` or `&` operators, an array variable
     * will not be a pointer for the first element in the array, it will just be the array.
     * This is why `&vowels[i]` evaluates to be `a pointer for the i'th element in vowels`.
     * 
     * Square bracket access can also be thought of as "array dereferencing," so in the below
     * expression we first dereference `vowels` and access the member at index `i`, and then
     * acquire the memory address of that member. 
     */
    printf("&vowels[%d] = %p\n", i, &vowels[i]);

    if (i < 4) {
      printf("\n--------\n\n");
    }
  }
}

void dynamicArrayAllocationExample() {
  int *pointer_to_ints = malloc(5 * sizeof(int));

  // We can use the square bracket syntax to access a member...
  pointer_to_ints[0] = 1;
  pointer_to_ints[1] = 2;
  // ... or the dereferencing / arithmetic way:
  *(pointer_to_ints + 2) = 3;
  *(pointer_to_ints + 3) = 4;
  *(pointer_to_ints + 4) = 5;

  for (int i = 0; i < 5; i++) {
    printf("pointer_to_ints[%d] * %d = %d\n", i, i, pointer_to_ints[i] * i);
  }

  free(pointer_to_ints);
}

void dynamicAllocationOfMultidimensionalArrayExample() {
  int rows = 2;
  int columns = 5;

  /* We'll need to allocate enough memory for two rows of char arrays (strings),
   * which on my machine should be ~16 bytes.
   *
   * The double asterisk here allows us to point to a pointer:
   */
  char **vowels_table = malloc(rows * sizeof(char *));

  vowels_table[0] = malloc(columns * sizeof(char));
  vowels_table[1] = malloc(columns * sizeof(char));

  vowels_table[0][0] = 'A';
  vowels_table[0][1] = 'E';
  vowels_table[0][2] = 'I';
  vowels_table[0][3] = 'O';
  vowels_table[0][4] = 'U';

  vowels_table[1][0] = 'a';
  vowels_table[1][1] = 'e';
  vowels_table[1][2] = 'i';
  vowels_table[1][3] = 'o';
  vowels_table[1][4] = 'u';

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      printf("%c ", vowels_table[i][j]);
    }

    /* We need to free any memory we allocate, so freeing the vowels_table var
     * isn't enough
     */
    free(vowels_table[i]);

    printf("\n");
  }

  free(vowels_table);
}

int main() {
  getPointerToArrayElementExample();
  printf("\n----------------\n\n");
  dynamicArrayAllocationExample();
  printf("\n----------------\n\n");
  dynamicAllocationOfMultidimensionalArrayExample();

  return 0;
}
