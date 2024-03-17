#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

void menu() {
	printf("������������������������������---������---����������������������������--��\n");
	printf("               1.��ʼ��������                \n");
	printf("               2.��������                   \n");
	printf("               3.�������                   \n");
	printf("               4.��������                   \n");
	printf("               5.ɾ�����                   \n");
	printf("               6.��ʾ����                   \n");
	printf("               7.��ֵ����                   \n");
	printf("               8.��λ����                   \n");
	printf("               9.��ת����                   \n");
	printf("               10.ȡ�м���                 \n");
	printf("               11.�жϳɻ�                 \n");
	printf("               0.�˳�ϵͳ                   \n");
}

//��ʼ��������
Status InitList(LinkedList* L) {
	LinkedList List;
	List = (LinkedList)malloc(sizeof(LNode));
	if (List == NULL) {
		printf("�ڴ����ʧ��\n");
		return OVERFLOW; 
	}
	else {
		List ->next = NULL;
		*L = List;
		printf("�ѳ�ʼ��������");
		return SUCCESS;
	}
}

//��������
void DestroyList(LinkedList* L) {
	LinkedList p;
	while (*L) {
		p = *L;
		(*L) = (*L)->next;
		free(p);
	}
	printf("�ɹ���������");
}


//�����㣬��p���������q���
Status InsertList(LNode* p, LNode* q) {
	if (!p || !q) {
		printf("���ȳ�ʼ��������");
		return ERROR;
	}
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

//ɾ�����
Status DeleteList(LNode* p, ElemType* e) {
	if (!p->next||!p) {
		printf("���ȳ�ʼ��������");
		return ERROR;
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return SUCCESS;
}

//��������
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LinkedList p;
	p = L->next;
	if (!p) {
		printf("�޷����������");
	}
	while (p!=NULL) {
		visit(p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void visit(ElemType e){
	printf("%d->", e);
}



//����e�ҵ������еĵ�һ���ڵ�
Status SearchList(LinkedList L, ElemType e) {
	LNode* q = L->next;
	while (q->data!=e) {
		q = q->next;
	}
	if (!L) {
		return ERROR;
	}
	return SUCCESS;
}

//��ֵ����
int Locate(LNode* L, ElemType e) {
	int i = 0;
	LNode* q = L->next;
	while (q && q->data != e) {
		q = q->next;
		i++;
	}
	if (q==NULL){
		return ERROR;
		printf("error");
	}
	else {
		return (i+1);
	}
}

//��λ����
LNode* get(LNode* p, int i) {
	int j = 0;
	LNode* q = p->next;
	while (j < i && q) {
		q = q->next;
		j++;
	}if (q) {
		return(q->data);
	}
	else {
		return ERROR;
	}
}

//��ת����
Status ReverseList(LinkedList* L) {
	if (!L || !(*L)->next) {
		return ERROR;
	}
	LNode* head = (*L)->next;
	LNode* rear = (*L)->next->next;

	while (rear) {
		head->next = rear->next;
		rear->next = (*L)->next;
		(*L)->next = rear;
		rear = head->next;
	}
}

LNode* FindMidNode(LinkedList* L) {
	LinkedList slow = *L, fast = *L;
	if (!L || (*L)->next == NULL) {
		return L;
	}
	while (fast && fast->next && slow) {
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

Status IsLoopList(LinkedList L) {
	if (!L|| !L->next) {
		printf("�������ڻ�Ϊ�ա�");
		return ERROR;
	}
	LinkedList fast = L, slow = L;
	while (fast->next != NULL && slow->next != NULL)
	{
		slow = slow->next;
		if ((fast = fast->next->next) == NULL)
			return ERROR;
		if (fast == slow)
			return SUCCESS;
	}
	return ERROR;
}


//�������ص��˵�
void Back() {
	printf("\n");
	getchar();
	system("pause");
	system("cls");
	menu();
}