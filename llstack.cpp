#include <stdio.h>
#include <stdlib.h>
struct a {
  int data;
  struct a *link;
};
typedef struct a A;

void push(A **start, int data) {
  A *temp = (A*)malloc(sizeof(A));
  temp->data = data;
  temp->link = *start;
  *start = temp;  
}
int pop(A **start) {
  int res = -1;
  if ((*start) == NULL) {
    printf("cannot pop from empty stack\n");
  } else {
    res = (*start)->data;
    (*start) = (*start)->link;
  }
  return res;
}
void traverse(A *start) {
  printf("***************\n");
  while(start != NULL) {
    printf("%d\n",start->data);
    start = start->link;	
  }
  printf("***************\n");
}
int main() {
  A *start = NULL;
  push(&start, 100);
  push(&start, 200);
  push(&start, 300);
  traverse(start);
  pop(&start);
  traverse(start);
  pop(&start);
  traverse(start);
  pop(&start);
  traverse(start);
  pop(&start);
  //pop(&start, 200);
  

  return 0;
}
