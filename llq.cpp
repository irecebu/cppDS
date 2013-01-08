#include <stdio.h>
#include <stdlib.h>
struct a {
  int data;
  struct a*link; 
};
typedef struct a A;
void enq(A **f, A **r, int data) {
  A *temp = (A*)malloc(sizeof(A));
  temp->data = data;
  temp->link = *f;
  if ((*f) == (*r) && (*f) == NULL ) {
    *f = temp;
    *r = temp;
  } else {
    *f = temp;
  }
}
int dq(A **f, A **r) {
  int res = -1;
  if ((*r) == NULL ) {
    printf("cannot dq from empty q\n");
    return -1;
  }
  res = (*r)->data; 
  if ((*f) == (*r)) {
    *f = NULL;
    *r = NULL;
  } else {
    A *temp = *f;
    while(temp->link != *r) {
      temp = temp->link;
    }
    temp->link = NULL;
    *r = temp;
    printf("%d\n", temp->data);
  }
  return res;
}
void traverse(A *f, A *r) {
  printf("************\n");
  while(f != NULL) {//only rear's link will contain NULL
    printf("%d\n",f->data);
    f = f->link;
  }
  printf("**************\n");
}
int main() {
  A *front = NULL, *rear = NULL;
  enq(&front, &rear, 100);
  enq(&front, &rear, 200);
  enq(&front, &rear, 300);
  enq(&front, &rear, 400);
  traverse(front, rear);
  dq(&front, &rear);
  traverse(front, rear);
  return 0;
}
