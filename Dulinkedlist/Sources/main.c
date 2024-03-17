#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "duLinkedList.h"

int main() {
	DuLinkedList first = NULL;
	ElemType data,e;
	int num;
	menu();
	int input ;
	do{
		printf("\n请输入序号 >>>");
		scanf_s("%d", &input);
		switch (input)
		{
		case(1): {
			if (InitList_DuL(&first)) {
				printf("\n成功初始化一个双向链表！\n");
			}
			else {
				printf("创建链表失败");
			}
			Back();
			break;
		}
		case(2): {
			DestroyList_DuL(&first);
			break;
		}
		case(3): {
			DuLNode* r;
			r = first;
			if (!r)
			{
				printf("请先初始化链表\n");
				break;
			}
			printf("\n请输入要创建的结点数据(键入'-1'结束创建链表)：");
			scanf_s("%d", &data);
			if (data == -1)break;
			while (data != -1) {
				while (r->next != NULL)
				{
					r = r->next;
				}
					DuLNode* newnode = (DuLNode*)malloc(sizeof(DuLNode));
					newnode->data = data;
					if (InsertAfterList_DuL(r, newnode)) {
						printf("OK!\n");
						//TraverseList_DuL(first, visit);
					}
					else {
						printf("出现错误，未插入数据\n");
					}
					scanf_s("%d",&data);
				}
			Back();
			break;
		}
		case(4): {
				DuLNode* r;
				r = first;
				if (!r)
				{
					printf("请先初始化链表\n");
					Back();
					break;
				}
				printf("要在第几个数据后插入数据：");
				scanf_s("%d", &num);
				if (num == 1) {

				}
				else {
					for (int i = 0; i < num; i++) {
						r = r->next;
					}
				}
				
				printf("要插入的数据为：");
				scanf_s("%d", &data);
				DuLNode* ins = (DuLNode*)malloc(sizeof(DuLNode));
				ins->data = data;
				ins->next = r->next;
				r->next = ins;
				Back();
				break;
			
		}
		case(5): {
			printf("请输入要删除的数据：");
			scanf_s("%d", &data);
			if(Locate(first, data) == 1) {
				DeleteList_DuL(first, data);
				printf("已删除第一个数据！\n");
				printf("目前链表：");
				TraverseList_DuL(first, visit);
			}
			else{
				DuLNode* del, * pre;
				pre = first->next;
				del = pre->next;
				while (del != NULL && del->data != data) {
					pre = pre->next;
					del = del->next;
				}
				DeleteList_DuL(pre, del);
				printf("数据删除成功！\n");
				printf("目前链表：");
				TraverseList_DuL(first, visit);
			}
			Back();
			break;
		}
		case(6): {
			if (!first || first->next == NULL ) {
				printf("链表不存在或为空，无法输出！\n");
			}
			else {
				printf("链表："); 
				TraverseList_DuL(first, visit);
			}
			Back();
			break;
		}
		case(7): {
			printf("请输入要查询的结点元素：");
			scanf_s("%d", &e);
			if (Locate(first, e)==0) {
				printf("没有这个元素哦！~");
			}
			else {
				printf("这个元素在第%d个结点。", Locate(first, data)+1);
			}
			Back();
			break;
		}
		case(8): {
			printf("请输入你要查询第几个元素：");
				scanf_s("%d", &num);
			printf("此元素为：%d\n", get(first, num-1));
			Back();
			break;
			
		}
		default: {
			printf("请重新输入。\n");
			Back();
			break;
			}
		}
	} while (input != 0);
	return 0;
}