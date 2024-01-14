#include <stdlib.h>
#include <stdio.h>

/* Binary trees are a type of data structure where a node may point to up to two
 * children. Left and right are the terms used to describe the child nodes because
 * of how that terminology reflects the visual representation of the structure.
 * 
 * Children are either considered to be **leaf** or **branch** nodes. Leaf nodes are
 * those that do not have any children, whereas branch nodes do. Branch nodes can be
 * referred to as **subtrees** also.
 * 
 * The **depth** or **height** of a tree is the measure of the longest distance (i.e.
 * length) between the root and a leaf node.
 * 
 * A tree is considered to be **balanced** if the depth of the left and right subtrees
 * of each node differs by one or less. The following is a balanced tree:
 * 
 *       1      <-- Level 0
 *      / \
 *     2   3    <-- Level 1
 *    / \
 *   4   5      <-- Level 2
 * 
 * For this tree:
 * 
 *  - Node 1 has a maximum depth of 2 going down the left path, and a depth of 1
 *    going down the right path. The difference between these two is 1, so it's
 *    balanced.
 *  - Node 2 has a depth of 1 going down its left and right paths. Since these are
 *    equivalent, it's balanced.
 *  - Nodes 3, 4, and 5 have no children and there's no depth to consider.
 * 
 * The following tree is unbalanced:
 * 
 *       1
 *      / \
 *     2   3
 *    / \
 *   4   5
 *        \
 *         6
 * 
 * For this one:
 * 
 *  - Node 1 has a maximum depth of 3 going down the left path to node 6, while
 *    it has a depth of 1 going down the right path. The difference between them
 *    is greater than 1, making it unbalanced.
 *  - Node 2 has a depth of 1 going down the left path, and a depth of 2 along the
 *    right path, making it a balanced _subtree_.
 *  - Nodes 3 and 4 are leaf nodes and have no depth to consider.
 *  - Node 5 has no left path (depth = 0) and a depth of 1 along the righthand path,
 *    meaning it is balanced.
 *  - Node 6 is also a leaf node and has no depth to consider.
 * 
 * There are two main ways of searching trees: **Depth-first** and **breadth-first
 * search**.
 * 
 * A depth first search (**DFS**) starts at the root node and goes all the way to 
 * the leaf node of a path, and then backtracks if necessary. There are three ways
 * that a DFS can be conducted:
 * 
 *  - **Pre-order**, which visits the root node, then traverses the left and then right subtrees
 *  - **In-order**, which traverses the left subtree, visits the root, and then the traverses the right
 *  - **Post-order**, which traverses left, then right, and then visits the root
 * 
 * Using the balanced tree above as an example, traversal for each of the respective
 * forms would be:
 * 
 *  - 1 >> 2 >> 4 >> 5 >> 3
 *  - 4 >> 2 >> 5 >> 1 >> 3
 *  - 4 >> 5 >> 2 >> 3 >> 1
 * 
 * Breadth-first search (**BFS**, a.k.a. **level-order traversal**) traverses each 
 * node of a level in a tree before continuing down the path. This is commonly done
 * with a queue, where the root node is pushed onto the queue, and at each iteration
 * a node is shifted off of it and the value is compared/operated on/etc. Then if
 * there are nodes on either side of the current node, they are pushed onto the queue
 * (first left, then right).
 * 
 * An example of this form of traversal would be:
 * 
 *  - 1 >> 2 >> 3 >> 4 >> 5 
 */

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
} node;

/* Borrowing this from `./10-linked-lists.c` to be able to implement breadth-first
 * search with a queue
 */
typedef struct ll_node {
  node *b_node;
  struct ll_node *next;
} ll_node;

void depthFirstPreOrder(node *x) {
  printf("%d", x->value);

  if (x->left != NULL) {
    depthFirstPreOrder(x->left);
  }

  if (x->right != NULL) {
    depthFirstPreOrder(x->right);
  }
}

void depthFirstInOrder(node *x) {
  if (x->left != NULL) {
    depthFirstInOrder(x->left);
  }

  printf("%d", x->value);

  if (x->right != NULL) {
    depthFirstInOrder(x->right);
  }
}

void depthFirstPostOrder(node *x) {
  if (x->left != NULL) {
    depthFirstPostOrder(x->left);
  }

  if (x->right != NULL) {
    depthFirstPostOrder(x->right);
  }

  printf("%d", x->value);
}

void append(node *value, ll_node *head) {
  ll_node *current = head;

  while (current->next != NULL) {
    current = current->next;
  }

  ll_node *n = malloc(sizeof(node));

  n->b_node = value;
  n->next = NULL;

  current->next = n;
}

void breadthFirst(node *x) {
  ll_node *queue = malloc(sizeof(ll_node));

  queue->b_node = x;

  ll_node *current = queue;

  while (current != NULL) {
    ll_node *previous = current;

    printf("%d", current->b_node->value);

    if (current->b_node->left != NULL) {
      append(current->b_node->left, current);
    }

    if (current->b_node->right != NULL) {
      append(current->b_node->right, current);
    }

    current = current->next;

    free(previous);
  }
}

// Another implementation of post-order DFS, since deleting trees is an area
// where that form shines
void freeTreeMemory(node *root) {
  if (root->left != NULL) {
    freeTreeMemory(root->left);
  }

  if (root->right != NULL) {
    freeTreeMemory(root->right);
  }

  free(root);
}

node* getNode(int value) {
  node *root = malloc(sizeof(node));

  root->left = NULL;
  root->right = NULL;
  root->value = value;

  return root;
}

int main() {
  node *root = getNode(1);

  root->left = getNode(2);
  root->right = getNode(3);

  root->left->left = getNode(4);
  root->left->right = getNode(5);

  printf("Depth-first pre-order traversal:\n");
  depthFirstPreOrder(root);
  printf("\n\n");

  printf("Depth-first in-order traversal:\n");
  depthFirstInOrder(root);
  printf("\n\n");

  printf("Depth-first post-order traversal:\n");
  depthFirstPostOrder(root);
  printf("\n\n");

  printf("Breadth-first traversal:\n");
  breadthFirst(root);
  printf("\n");

  freeTreeMemory(root);
}
