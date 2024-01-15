#include <stdio.h>
#include <stdlib.h>

/* Unions are basically structures that use shared memory space for their members,
 * limiting it to where only one distinct value may be stored at a time. This can
 * be useful if/when:
 * 
 *  - You have some data that you want to interpret in multiple ways. This is
 *    sometimes known as **type punning**: reading the data of type `T` at a
 *    memory address `x` as if it were of type `J`. For example, if you have
 *    a union that contains members `int someNumber` and `char asBytes[4]`, it
 *    would be possible to read each byte of that integer via `asBytes`.
 *  - You have some data that you want to interpret with multiple names. For
 *    example, the `Coins` union below.
 *  - You're working in an environment where memory is limited (like embedded
 *    systems) and have multiple values that you know you'll only need to use
 *    one of at a time.
 * 
 * The example below is a union that represents some USD change with an array of
 * four integers.
 * 
 * The names of the members of the anonymous struct will point to each item in the
 * array. This works that way because of how structs and unions are each allocated:
 * 
 *  - Structures are given contiguous memory space for their members. In the case
 *    below, 4 bytes are needed for each member of the struct, so the space that's
 *    allocated would look something like `0x0000, 0x0004, 0x0008, 0x0012`
 *  - The `coins` array also allocates four memory addresses for its elements, and
 *    since they're also integers, the size of these addresses will be the same as
 *    the struct's items
 *  - Because the members of a union all share the same memory address (in this case,
 *    the same starting address), both the structure and the array are laid out in the
 *    same block of memory
 */
union Coins {
  int coins[4];
  /* An anonymous structure within a union will have its members "lifted"
   * up into the union as if each of these members were declared at the
   * top level alongside `coins`:
   */
  struct {
    int quarter;
    int dime;
    int nickel;
    int penny;
  };
};

int main() {
  union Coins x;

  x.coins[0] =  3;
  x.coins[1] =  1;
  x.coins[2] =  0;
  x.coins[3] = 15;

  printf("The members of x start at %p\n\n", x.coins);
  printf("┌─────────────────────────────────────┐\n");
  printf("|          | Amount | Address         |\n");
  printf("|----------|--------|-----------------|\n");
  printf("| Quarters |    %i   | %p  |\n", x.quarter, &x.quarter);
  printf("| Dimes    |    %i   | %p  |\n", x.dime, &x.dime);
  printf("| Nickels  |    %i   | %p  |\n", x.nickel, &x.nickel);
  printf("| Pennies  |   %i   | %p  |\n", x.penny, &x.penny);
  printf("└─────────────────────────────────────┘\n");
}