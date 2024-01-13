#include <stdio.h>
#include <stdlib.h>

/* A linked list is a data structure similar to an array, in which each element
 * of the list points to the next until it reaches null, which signifies the end
 * of the list. An element in a linked list is known as a node, and the first in
 * the list is the head.
 *
 * 
 * Benefits of a linked list over an array:
 *  - **Dynamically sized:** Linked lists can grow and shrink as needed, whereas
 *    arrays are of a fixed size and the memory needs to be reallocated if you
 *    want to add more elements.
 *  - **Faster modifications:** Insertion and deletion is faster with a linked list
 *    because it doesn't require shifting the surrounding elements. For example: If
 *    you have an array `{ 1, 3, 4, 5 }` and want to insert `2` after `1`, the last
 *    three elements need to be shifted to the right by one somehow. On the other hand
 *    with a linked list, you do less work because you only need to update the first
 *    node to point to your newly created node (which points to `3` and so on).
 *  - **No memory is wasted:** When arrays are reallocated they may end up reserving
 *    more memory than is actually necessary. A linked list doesn't need to allocate
 *    any memory beyond the amount needed to store the node and its members, and so it
 *    isn't susceptible to this drawback.
 * 
 * Drawbacks of linked lists when compared to arrays:
 *  - **Slower reads:** Because arrays are contiguous, reads happen in constant time
 *    and require less work than with linked lists. With an array, accessing an index
 *    requires only one step: `i * n`, where `i` is the index being read, and `n` is
 *    the amount of space needed to store data of the type represented by that array;
 *    this value is added to the address of the first element in the array to get the
 *    address of the element at index `i`. For a linked list, you must traverse the
 *    entire sequence of nodes from the head to the requested index. 
 *  - **Larger memory footprint:** Nodes require more memory than array items because
 *    the value and a pointer need to be stored.
 *  - **Can only traverse from the beginning to end:** Arrays allow us to loop from the
 *    last element to the first, but this is impossible with linked lists since nodes
 *    only maintain a reference to the following node in the list. (However, there are
 *    variants of linked lists like doubly linked lists that allow this behavior.)
 * 
 * A temporary alias can be assigned to a typedef in order to give it the ability
 * to refer to itself:
 */
typedef struct node {
  int value;
  struct node *next;
} node;

/* Adds a node containing the given value to the end of the list
 */
void append(int value, node *head) {
  node *current = head;

  while (current->next != NULL) {
    current = current->next;
  }

  node *n = malloc(sizeof(node));

  n->value = value;
  n->next = NULL;

  current->next = n;
}

/* Adds a node containing the given value to the beginning of the list
 */
void prepend(int value, node **head) {
  node *n = malloc(sizeof(node));

  n->value = value;
  n->next = *head;

  *head = n;
}

/* Removes the node at the end of the list
 */
void remove_last(node *head) {
  node *current = head;
  node *previous = NULL;

  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }

  previous->next = NULL;

  free(current);
}

/* Removes the node at the beginning of the list
 */
void remove_first(node **head) {
  node *tmp_head = *head;
  *head = (*head)->next;
  free(tmp_head);
}

/* Removes the node at the given index
 */
void remove_at(int i, node *head) {
  if (i == 0) {
    return remove_first(&head);
  }

  node *current = head;

  for (int j = 0; j < i - 1; j++) {
    if (current->next == NULL) {
      return;
    }

    current = current->next;
  }

  node *subject = current->next;

  if (subject == NULL) {
    return;
  }

  current->next = subject->next;

  free(subject);
}

int main() {
  node *head = malloc(sizeof(node));

  head->value = 1;
  head->next = NULL;

  append(2, head);
  append(3, head);

  printf("%p = %d\n", head, head->value);
  printf("%p = %d\n", head->next, head->next->value);
  printf("%p = %d\n", head->next->next, head->next->next->value);

  prepend(0, &head);

  node *current = head;
  while (current != NULL) {
    printf("%p = %d\n", current, current->value);

    current = current->next;
  }

  remove_first(&head);

  remove_at(1, head);

  current = head;
  while (current != NULL) {
    printf("%p = %d\n", current, current->value);

    current = current->next;
  }

  remove_first(&head);
  remove_first(&head);

  printf("%p\n", head);
}
