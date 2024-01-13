#include <stdio.h>

/* The `typedef` keyword allows us to define an alias for a given type, which
 * can prove useful for structs by shortening the name you need to provide to
 * variable and parameter declarations.
 * 
 * It can also be used to alias existing types, built in or user defined 
 */
typedef int coordinate;

typedef struct {
  coordinate *x;
  coordinate y;
} point;

void draw(point p) {
  printf("x = %d\ny = %d", *p.x, p.y);
}

int main() {
  point example;

  int x = 1;

  example.x = &x;
  example.y = 2;

  draw(example);

  return 0;
}
