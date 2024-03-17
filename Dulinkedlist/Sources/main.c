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
		printf("\n��������� >>>");
		scanf_s("%d", &input);
		switch (input)
		{
		case(1): {
			if (InitList_DuL(&first)) {
				printf("\n�ɹ���ʼ��һ��˫������\n");
			}
			else {
				printf("��������ʧ��");
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
				printf("���ȳ�ʼ������\n");
				break;
			}
			printf("\n������Ҫ�����Ľ������(����'-1'������������)��");
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
						printf("���ִ���δ��������\n");
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
					printf("���ȳ�ʼ������\n");
					Back();
					break;
				}
				printf("Ҫ�ڵڼ������ݺ�������ݣ�");
				scanf_s("%d", &num);
				if (num == 1) {

				}
				else {
					for (int i = 0; i < num; i++) {
						r = r->next;
					}
				}
				
				printf("Ҫ���������Ϊ��");
				scanf_s("%d", &data);
				DuLNode* ins = (DuLNode*)malloc(sizeof(DuLNode));
				ins->data = data;
				ins->next = r->next;
				r->next = ins;
				Back();
				break;
			
		}
		case(5): {
			printf("������Ҫɾ�������ݣ�");
			scanf_s("%d", &data);
			if(Locate(first, data) == 1) {
				DeleteList_DuL(first, data);
				printf("��ɾ����һ�����ݣ�\n");
				printf("Ŀǰ����");
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
				printf("����ɾ���ɹ���\n");
				printf("Ŀǰ����");
				TraverseList_DuL(first, visit);
			}
			Back();
			break;
		}
		case(6): {
			if (!first || first->next == NULL ) {
				printf("�������ڻ�Ϊ�գ��޷������\n");
			}
			else {
				printf("����"); 
				TraverseList_DuL(first, visit);
			}
			Back();
			break;
		}
		case(7): {
			printf("������Ҫ��ѯ�Ľ��Ԫ�أ�");
			scanf_s("%d", &e);
			if (Locate(first, e)==0) {
				printf("û�����Ԫ��Ŷ��~");
			}
			else {
				printf("���Ԫ���ڵ�%d����㡣", Locate(first, data)+1);
			}
			Back();
			break;
		}
		case(8): {
			printf("��������Ҫ��ѯ�ڼ���Ԫ�أ�");
				scanf_s("%d", &num);
			printf("��Ԫ��Ϊ��%d\n", get(first, num-1));
			Back();
			break;
			
		}
		default: {
			printf("���������롣\n");
			Back();
			break;
			}
		}
	} while (input != 0);
	return 0;
}