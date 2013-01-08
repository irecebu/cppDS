#include <stdio.h>
#include <stdlib.h>

struct tree {
  int data;
  struct tree *left;
  struct tree *right;
  struct tree *parent;
};
typedef struct tree Tree;

void insert(Tree **root, int data) {
  Tree *node = (Tree*)malloc(sizeof(Tree));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  if ((*root) == NULL) {
    *root = node;
    return;
  }
  Tree *parent = *root;
  Tree *child = *root;
  while(child != NULL) {
    parent = child;
    if (data < parent->data) child = parent->left;
    else child = parent->right;
  }
  if (data < parent->data) parent->left = node;
  else parent->right = node;
}

void traversal(Tree *n) {
  if (n != NULL) {
    traversal(n->left);
    printf("%d\n",n->data);
    traversal(n->right);
  }
}
int main() {
  Tree *root = NULL;
  insert(&root, 10);
  insert(&root, 20);
  insert(&root, 5);
  insert(&root, 7);
  traversal(root);
  return 0;
}
