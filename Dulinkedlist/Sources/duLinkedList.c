#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include "duLinkedList.h"


void menu() {
	printf("����������������������������---˫������---����������������������������-��\n");
	printf("               1.��ʼ��������                \n");
	printf("               2.��������                   \n");
	printf("               3.�������                   \n");
	printf("               4.������                   \n");
	printf("               5.ɾ�����                   \n");
	printf("               6.��ʾ����                   \n");
	printf("               7.��ֵ����                   \n");
	printf("               8.��λ����                   \n");
	printf("                ����0�˳�                   \n");
}

Status InitList_DuL(DuLinkedList* L) {
	DuLinkedList list = (DuLinkedList )malloc(sizeof(DuLNode));
	if (!list) {
		printf("�ڴ����ʧ��\n");
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
		printf("�ɹ���������\n");
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
		printf("����ʧ��");
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

//��ֵ����
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

//��λ����
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
		printf("�����λ�ò�������ȷ��û�������㡣");
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