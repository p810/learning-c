#include <stdio.h>

typedef struct {
  int *x;
  int y;
} point;

void move(point *p) {
  /* The `->` operator is a shorthand for dereferencing a struct when accessing
   * one of its properties:
   */
  (*(p->x))++; // This one requires an additional dereference since the member is a pointer too
  p->y++;
}

int main() {
  point z;

  int x = 1;

  z.x = &x;
  z.y = 2;

  printf("z.x = %d\nz.y = %d\n", *(z.x), z.y);

  move(&z);

  printf("z.x = %d\nz.y = %d\n", *(z.x), z.y);

  return 0;
}
