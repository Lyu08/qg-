#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

void menu() {
	printf("———————————————---单链表---——————————————--—\n");
	printf("               1.初始化空链表                \n");
	printf("               2.销毁链表                   \n");
	printf("               3.创建结点                   \n");
	printf("               4.插入数据                   \n");
	printf("               5.删除结点                   \n");
	printf("               6.显示链表                   \n");
	printf("               7.按值查找                   \n");
	printf("               8.按位查找                   \n");
	printf("               9.倒转链表                   \n");
	printf("               10.取中间结点                 \n");
	printf("               11.判断成环                 \n");
	printf("               0.退出系统                   \n");
}

//初始化空链表
Status InitList(LinkedList* L) {
	LinkedList List;
	List = (LinkedList)malloc(sizeof(LNode));
	if (List == NULL) {
		printf("内存分配失败\n");
		return OVERFLOW; 
	}
	else {
		List ->next = NULL;
		*L = List;
		printf("已初始化空链表！");
		return SUCCESS;
	}
}

//销毁链表
void DestroyList(LinkedList* L) {
	LinkedList p;
	while (*L) {
		p = *L;
		(*L) = (*L)->next;
		free(p);
	}
	printf("成功销毁链表！");
}


//插入结点，在p结点后面插入q结点
Status InsertList(LNode* p, LNode* q) {
	if (!p || !q) {
		printf("请先初始化链表！！");
		return ERROR;
	}
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

//删除结点
Status DeleteList(LNode* p, ElemType* e) {
	if (!p->next||!p) {
		printf("请先初始化链表！！");
		return ERROR;
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return SUCCESS;
}

//遍历链表
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LinkedList p;
	p = L->next;
	if (!p) {
		printf("无法输出空链表");
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



//根据e找到链表中的第一个节点
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

//按值查找
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

//按位查找
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

//反转链表
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
		printf("链表不存在或为空。");
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


//清屏，回到菜单
void Back() {
	printf("\n");
	getchar();
	system("pause");
	system("cls");
	menu();
}