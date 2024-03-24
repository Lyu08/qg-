#define _CRT_SECURE_NO_WARNINGS
#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void InitLQueue(LQueue* Q) {
	Node *p = (Node*)malloc(sizeof(Node));
	if (!p) {
		printf("��ʼ��ʧ�ܣ�\n");
		return;
	}
	p->next = NULL;
	Q->rear = p;
	Q->front = Q->rear;
	Q->length = 0;
}

void DestoryLQueue(LQueue* Q) {
	ClearLQueue(Q);
	free(Q->front);
}

Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == Q->rear) return TRUE;
	else return FALSE;
}

//ȡ��ͷԪ�� 
Status GetHeadLQueue(LQueue* Q, void* e,int size) {
	if (Q->front->next == NULL) {
		printf("��ǰ����Ϊ�ա�\n");
		return FALSE;
	}
	else {
		(Node*)e = Q->front->next->data ;
		LPrint(e, size);
		return TRUE;
	
	}
}

int LengthLQueue(LQueue* Q) {
	return (int)Q->length;
}

//��Ӳ���
Status EnLQueue(LQueue* Q, void* data) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (!p)return FALSE;
	else {
		p->data = data;
		p->next = NULL;
		if (Q->front->next != NULL) {
			Q->rear->next = p;
		}
		/*Q->rear->next = p;*/

		if (Q->front->next == NULL) {
			Q->front->next = p;
		}
		Q->rear = p;
		Q->length++;
		//printf("%d", Q->length);
		return TRUE;
	}
	
}

//���Ӳ���
Status DeLQueue(LQueue* Q) {
	if (IsEmptyLQueue(&Q)) {
		printf("����Ϊ�ա�\n");
		return FALSE;
	}
	else {
		Node* p;
		p = Q->front->next;
		if (p!=NULL) Q->front->next = p->next;
		else {
			printf("�����Ѿ�Ϊ�գ�����ʧ�ܡ�\n");
			return FALSE;
		}
		/*if (Q->rear == p) Q->rear = Q->front;*/
		free(p);
		Q->length--;
		return TRUE;
	}
}

void ClearLQueue(LQueue* Q) {
	while (Q->length != 0) {
		Node* p=NULL,*q;
		p = Q->front->next;
		Q->rear = Q->front;
		while (p->next != NULL) {
			q = p;
			p = p->next;
			free(q);
		}
		free(p);
		Q->length = 0;
	}
	printf("��������ա�\n");
}

Status TraverseLQueue(const LQueue* Q, int size) {
	if (IsEmptyLQueue(Q))return 0;
	else {
		Node* p;
		p = Q->front->next;
		while (p->next != NULL) {
			LPrint(p, size);
			p = p->next;
		}
		return TRUE;
	}
}

void LPrint(void* q,int size) {
	//�����������ͽ�void*ת������Ӧ���͵�ָ��
	//printf("%d\n", size);
	if (q) {
		if (size == sizeof(int)) printf("%d\n", *(int*)q);
		else if (size == sizeof(char))  printf("%c\n", *(char*)q);
		else if (size == sizeof(double)) printf("%lf\n", *(double*)q);
	}
}
