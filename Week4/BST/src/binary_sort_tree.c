#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "binary_sort_tree.h"

Status BST_init(BinarySortTreePtr* T){
	BinarySortTreePtr tree = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	if (!tree) {
		printf("内存分配失败\n");
		return -1;
	}
	tree->root = NULL;
	*T = tree;
	return succeed;
}


Status BST_insert(BinarySortTreePtr T, ElemType value) {
	NodePtr new = (NodePtr)malloc(sizeof(Node));
	NodePtr cur = T->root;
	if (!new) {
		printf("开辟结点失败!\n");
		return failed;
	}
	else {
		new->value = value;
		new->right = new->left = NULL;
	}
	if (cur == NULL) {
		T->root = new;
		return succeed;
	}
	else {
		ElemType data = cur->value;
		while (1) {
			
			if (value < data) {
				if (!cur->left) {
					cur->left = new;
					break;
				}
				else {
					cur = cur->left;
					continue;
				}
			}
			else if (value  > data) {
				if (!cur->right) {
					cur->right = new;
					break;
				}
				else {
					cur = cur->right;
					continue;
				}
			}
			else {
				free(new);
				return succeed;
			}
		}
	}
}


Status BST_search(BinarySortTreePtr T, ElemType value) {
	Node* p =T->root;
	while (p) {
		if (p->value == value) {
			break;
		}
		else if (p->value > value) {
			p = p->left;
		}
		else if (p->value < value) {
			p = p->right;
		}
	}
	if (p == NULL) {
		return false;
	}
	return true;
}

Status BST_delete(BinarySortTreePtr T, ElemType value) {
	NodePtr p = T->root, par = NULL;
	while (p) {
		if (p->value == value)break;
		par = p;
		if (value > p->value) {
			p = p->right;
		}
		else p = p->left;
	}

	if (!p)return failed;
	if (p->left && p->right) {
		NodePtr lchild = p->left;
		while (lchild->right) {
			lchild = lchild->right;
		}
		if (p->value > par->value) {
			par->right = lchild;
		}
		else {
			par->left = lchild;
		}
	}
	else if (!p->left && p->right) {
		if (p->value > par->value) {
			par->right = p->right;
		}
		else {
			par->left = p->right;
		}
	}
	else if (p->left && !p->right) {
		if (p->value > par->value) {
			par->right = p->left;
		}
		else {
			par->left = p->left;
		}
	}
	else if (!p->left && !p->right) {
		if (p->value > par->value) {
			par->right = NULL;
		}
		else {
			par->left = NULL;
		}
	}
	free(p);
	p = NULL;
}

Status BST_preorderR(BinarySortTreePtr T, void (*visit)(NodePtr e)) {
	if (!T)return succeed;
	visit(T->root->value);
	BST_preorderR(T->root->left, visit);
	BST_preorderR(T->root->right, visit);
}

Status BST_inorderR(BinarySortTreePtr T, void (*visit)(NodePtr e)) {
	if (!T)return succeed;
	BST_inorderR(T->root->left, visit);
	visit(T->root->value);
	BST_inorderR(T->root->right, visit);
}

Status BST_postorderR(BinarySortTreePtr T, void (*visit)(NodePtr e)){
	if (!T)return succeed;
	BST_postorderR(T->root->left, visit);
	BST_postorderR(T->root->right, visit);
	visit(T->root->value);
}

void Printdata(Node* node) {
	printf("%d ",node->value);
}