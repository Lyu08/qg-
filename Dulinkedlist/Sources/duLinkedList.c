#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "duLinkedList.h"


void menu() {
	printf("——————————————---双向链表---——————————————-—\n");
	printf("               1.初始化空链表                \n");
	printf("               2.销毁链表                   \n");
	printf("               3.创建结点                   \n");
	printf("               4.插入结点                   \n");
	printf("               5.删除结点                   \n");
	printf("               6.显示链表                   \n");
	printf("               7.按值查找                   \n");
	printf("               8.按位查找                   \n");
	printf("                键入0退出                   \n");
}

Status InitList_DuL(DuLinkedList* L) {
	DuLinkedList list = (DuLinkedList )malloc(sizeof(DuLNode));
	if (!list) {
		printf("内存分配失败\n");
		return OVERFLOW;
	}
	list->prior = list->next = NULL;
	list->data = 0;
		*L = list;
		return SUCCESS;
}


void DestroyList_DuL(DuLinkedList* L) {
	DuLinkedList p;
	p = *L;
	while (*L) {
		(*L) = (*L)->next;
		p = NULL;
		printf("成功销毁链表！\n");
		free(p);
	}
}


Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	if (!p|| !q) {
		return ERROR;
	}
	q->next = p;
	q->prior = p->prior;
	p->prior->next = q;
	p->prior = q;
	return SUCCESS;
}

Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	if (!p||!q) {
		printf("插入失败");
		return ERROR;
	}
	else {
		q->next = p->next;
		q->prior = p;
		p->next = q;
		return SUCCESS;
	}
}


Status DeleteList_DuL(DuLNode* p, ElemType* e) {
	if (p == NULL || p->next == NULL) {
		return ERROR;
	}
	else {
		e = p->next->data;
		DuLNode* q = p->next;
		p->next = p->next->next; if (q->next){
			q->next->prior = p;
		}
		free(q);
		return SUCCESS;
	}
}

//按值查找
int Locate(DuLNode* L, ElemType e) {
	int i = 0;
	DuLNode* q = L->next;
	while (q && q->data != e) {
		q = q->next;
		i++;
	}
	if (!q) {
		return ERROR;
	}
	else {
		return i+1;
	}
}

//按位查找
ElemType get(DuLNode* L, int i) {
	int j = 0;
	DuLNode* q = L->next;
	while (j < i && q != NULL) {
		q = q->next;
		j++;
	}
	if (q) {
		return (q->data);
	}
	else {
		printf("输入的位置参数不正确，没有这个结点。");
		return NULL;
	}
}

void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode* p = L->next;
	while (p) {
		visit(p->data);
		p = p->next;
	}
	printf("NULL\n");
}
void visit(ElemType e) {
	printf("%d->", e);
}

void Back() {
		printf("\n");
		getchar();
		system("pause");
		system("cls");
		menu();
	
}