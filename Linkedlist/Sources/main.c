#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main() {
	LinkedList first = NULL;
	ElemType data;
	int input,num = 0;
	menu();

	do {
		printf("请输入序号 >>>  \n");
		scanf_s("%d", &input);
		switch (input) {
		case(1): 
		{
			InitList(&first);
			Back();
			break;
		}    //建立空链表
		case(2): {
			DestroyList(&first); 
			Back();
			break;
		}
		case(3): {
			LNode* r;
			r = first;
			if (!r)
			{
				printf("请先初始化链表\n");
				break;
			}
			printf("\n请输入链表数据\n(请输入整型数字；键入'-1'结束创建链表)：\n");

			scanf_s("%d",&data);
			while (data != -1 ) {
				while (r->next != NULL)
				{
					r = r->next;
				}
				LNode* newnode = (LNode*)malloc(sizeof(LNode));
				newnode->data = data;
				if (InsertList(r, newnode)) {
					printf("OK!\n");
					/*TraverseList(first, visit);*/
				}
				else {
					printf("出现错误，未插入数据\n");
				}
				scanf_s("%d", &data);
			}
			printf("成功创建链表！\n");
			Back();
			break;
		}
		case(4): {
			LNode* r;
			r = first;
			if (!r)
			{
				printf("请先初始化链表\n");
				break;
			}
			printf("要在第几个数据后插入数据：");
			scanf_s("%d", &num); if (num == 1) {

			}
			else {
				for (int i = 0; i < num; i++) {
					r = r->next;
				}
			}
			printf("要插入的数据为：");
			scanf_s("%d", &data);
			LNode* ins = (LNode*)malloc(sizeof(LNode));
			ins->data = data;
			ins->next = r->next;
			r->next = ins;
			Back();
			break;
		}
		case(5): {
			printf("输入要删除的数据：");
			scanf_s("%d", &data);
			if (Locate(first, data) == 1) {
				DeleteList(first, data);
				printf("已删除第一个数据！\n");
				printf("链表：");
				TraverseList(first, visit);
			}
			else if(!Locate(first, data)) {
				printf("没有这个数据，请重新操作。");
			}
			else {
				LNode* del, * pre;
				pre = first->next;
				del = pre->next;
					while (del!=NULL && del->data != data) {
						pre = pre->next;
						del = del->next;
						/*printf("%d", pre->data);
						printf("%d", del->data);*/
					}	
					DeleteList(pre, data);
					printf("数据删除成功！\n");
					printf("链表：");
					TraverseList(first, visit);
			}
			Back();
			break;
		}
		case(6): {
			if (!first || first->next == NULL) {
				printf("链表不存在或为空，无法输出！\n");
			}
			else {
				printf("链表：");
				TraverseList(first,visit);
			}
			Back();
			break;
		}
		case(7): {
			printf("请问要查询的结点：");
			scanf_s("%d",&data);
			if(Locate(first, data)==0) printf("未查询到该数据\n");
			printf("数据存在，位于第%d个结点。", Locate(first, data));
			Back();
			break;
		}
		case(8): {
			printf("请问要查询第几个结点？");
			scanf_s("%d", &data);
			if (data==0||get(first, data - 1) == 0) {
				printf("没有这个结点哦\n");
			}
			else {
				printf("结点的数据为%d\n", get(first, data - 1));
			}
			Back();
			break;
		}
		case(9): {
			ReverseList(&first);
			printf("链表已反转！！");
			Back();
			break;
		}
		case(10): {
			printf("%d", FindMidNode(&first)->data);
			Back();
			break;
		}
		case(11): {
			if (IsLoopList(first) ){
				printf("链表成环\n");
			}
			else {
				printf("链表不成环\n");
			}
			
		}
		default:
			printf("请重新输入。\n");
			Back();
			break;
		}
	} while (input!=0);
}
