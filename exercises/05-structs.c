#include <stdio.h>

/* Structures are analogous to objects in JavaScript:
 */
struct point {
  int x;
  int y;
};

void draw(struct point p) {
  printf("x = %d\ny = %d", p.x, p.y);
}

int main() {
  struct point example;

  example.x = 1;
  example.y = 2;

  draw(example);

  return 0;
}
