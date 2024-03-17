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
		printf("��������� >>>  \n");
		scanf_s("%d", &input);
		switch (input) {
		case(1): 
		{
			InitList(&first);
			Back();
			break;
		}    //����������
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
				printf("���ȳ�ʼ������\n");
				break;
			}
			printf("\n��������������\n(�������������֣�����'-1'������������)��\n");

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
					printf("���ִ���δ��������\n");
				}
				scanf_s("%d", &data);
			}
			printf("�ɹ���������\n");
			Back();
			break;
		}
		case(4): {
			LNode* r;
			r = first;
			if (!r)
			{
				printf("���ȳ�ʼ������\n");
				break;
			}
			printf("Ҫ�ڵڼ������ݺ�������ݣ�");
			scanf_s("%d", &num); if (num == 1) {

			}
			else {
				for (int i = 0; i < num; i++) {
					r = r->next;
				}
			}
			printf("Ҫ���������Ϊ��");
			scanf_s("%d", &data);
			LNode* ins = (LNode*)malloc(sizeof(LNode));
			ins->data = data;
			ins->next = r->next;
			r->next = ins;
			Back();
			break;
		}
		case(5): {
			printf("����Ҫɾ�������ݣ�");
			scanf_s("%d", &data);
			if (Locate(first, data) == 1) {
				DeleteList(first, data);
				printf("��ɾ����һ�����ݣ�\n");
				printf("����");
				TraverseList(first, visit);
			}
			else if(!Locate(first, data)) {
				printf("û��������ݣ������²�����");
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
					printf("����ɾ���ɹ���\n");
					printf("����");
					TraverseList(first, visit);
			}
			Back();
			break;
		}
		case(6): {
			if (!first || first->next == NULL) {
				printf("�������ڻ�Ϊ�գ��޷������\n");
			}
			else {
				printf("����");
				TraverseList(first,visit);
			}
			Back();
			break;
		}
		case(7): {
			printf("����Ҫ��ѯ�Ľ�㣺");
			scanf_s("%d",&data);
			if(Locate(first, data)==0) printf("δ��ѯ��������\n");
			printf("���ݴ��ڣ�λ�ڵ�%d����㡣", Locate(first, data));
			Back();
			break;
		}
		case(8): {
			printf("����Ҫ��ѯ�ڼ�����㣿");
			scanf_s("%d", &data);
			if (data==0||get(first, data - 1) == 0) {
				printf("û��������Ŷ\n");
			}
			else {
				printf("��������Ϊ%d\n", get(first, data - 1));
			}
			Back();
			break;
		}
		case(9): {
			ReverseList(&first);
			printf("�����ѷ�ת����");
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
				printf("����ɻ�\n");
			}
			else {
				printf("�����ɻ�\n");
			}
			
		}
		default:
			printf("���������롣\n");
			Back();
			break;
		}
	} while (input!=0);
}
