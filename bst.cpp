#include <stdio.h>
#include <stdlib.h>
struct tree {
	int data;
	struct tree *left;
	struct tree *right;
	// struct tree *parent;
};
typedef struct tree Tree;
void add (Tree **r, int data) {
	Tree *node = (Tree*)malloc(sizeof(Tree));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	if ((*r) == NULL) {
		*r = node;
	} else {
		Tree *parent = *r;
		Tree *child = *r;
		while (child != NULL) {
			parent = child;
			if (data < parent->data) child = parent->left;
			else child = parent->right;
 		}
 		if (data < parent->data) parent->left = node;
 		else parent->right = node;
	}
}
int search (Tree *root, int data) {
	while (root != NULL) {
		if (data == root->data) return data;
		if (data < root->data) root = root->left;
		else root = root->right;
	}
	printf("%d : not found \n", data);
	return -1;
}
void remove (Tree **root, int data) {
	Tree *parent = *root;
	Tree *child = *root;
	bool found = false;
	while (child != NULL) {
		if (data == child->data) {
			found = true;
			break;
		} else if (data < child->data) {
			parent = child;
			child = child->left;
		} else {
			parent = child;
			child = child->right;
		}
	}
	if (!found) {
		printf("%d not found to remove\n",data);
		return;
	}
	if (child->left != NULL && child->right != NULL) {
		Tree *succ = child->right;
		Tree *succ_p = child;
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		// set l and r of successors parent
		if (succ == succ_p->left) {
			succ_p->left = succ->right;
		} else {
			succ_p->right = succ->right;
		}
		// set l and r of successor
		succ->left = child->left;
		succ->right = child->right;
		//set l and r of parent of child (the one being deleted)
		if (child == parent->left) parent->left = succ;
		else parent->right = succ;

	} else if (child->left == NULL && child->right == NULL) {
		if (child == parent->right) parent->right = NULL;
		else parent->left = NULL;
	} else {
		if (child == parent->left) {
			if (child->left != NULL) parent->left = child->left;
			else parent->left = child->right;
		} else {
			if (child->left != NULL) parent->right = child->left;
			else parent->right  = child->right;
		}
	}
	
}
void traverse (Tree *root) {
	if (root != NULL) {
		traverse(root->left);
		printf("%d\n", root->data);
		traverse(root->right);
	}
}
int main() {
	Tree *root = NULL;

	add(&root, 1);
	add(&root, 4);
	add(&root, 2);
	add(&root, 8);
	add(&root, 6);
	add(&root, 7);

	// add(&root, 5);
	// add(&root, 6);
	// add(&root, 15);
	traverse(root);
	search(root, 15);
	remove(&root, 4);
	traverse(root);
	add(&root, 4);
	printf("*****\n");
	traverse(root);
	remove(&root, 2);
	printf("*****\n");
	traverse(root);
	return 0;
}
