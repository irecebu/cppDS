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
    if (data < parent) child = parent->left;
    else child = parent->right;
  }
}
int main() {
  Tree *root = NULL;
  insert(&root, 10);
  return 0;
}
