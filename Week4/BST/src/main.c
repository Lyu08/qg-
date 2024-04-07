#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "binary_sort_tree.h"

int main() {
	BinarySortTreePtr  T = NULL;
	ElemType data, e;
	int num;
	menu();
	char input[100];
	do {
		printf("\n��������� >>>");
		gets_s(input, 100);
		if (strcmp(input, "1") == 0) {
			if (BST_init(&T)) {
				printf("��ʼ���ɹ���\n");
			}else
				printf("��ʼ��ʧ�ܡ�\n");
			Back();
		}

		else if (strcmp(input, "2") == 0)
		{
			BinarySortTree* r = T;
			if (!r)printf("��δ��ʼ������\n");
			else {
				printf("������Ҫ���������>>>");
				if (scanf_s("%d", &num)) {
					if (BST_insert(r, num)) printf("����ɹ���\n");
					else printf("����ʧ�ܣ������ԡ�\n");
				}
				else printf("�Ƿ����룡\n");
			}
			Back();
		}
		else if (strcmp(input, "3") == 0)
		{
			BinarySortTree* r = T;
			if (!r)printf("��δ��ʼ������\n");
			else {
				printf("������Ҫ����������>>>");
				if (scanf_s("%d", &num)) {
					if (BST_search(r, num)) printf("�������ڣ�\n");
					else printf("���������ڡ�\n");
				}
				else printf("�Ƿ����룡\n");
			}
			Back();
		}
		else if (strcmp(input, "4") == 0)
		{
			BinarySortTree* r = T;
			if (!r)printf("��δ��ʼ������\n");
			else {
				printf("������Ҫɾ��������>>>");
				if (scanf_s("%d", &num)) {
					if (BST_search(r, num)) {
						if (BST_delete(r, num))printf("��ɾ����\n");
						else printf("����ʧ�ܣ������ԡ�\n");
					}
					else printf("�������������С�\n");
				}
				else printf("�Ƿ����룡\n");
			}
			Back();
		}
		else if (strcmp(input, "5") == 0) {
			BST_preorderR(T->root, Printdata);
		}
		else if (strcmp(input, "6") == 0) {
			BST_inorderR(T->root,Printdata);
		}
		else if (strcmp(input, "7") == 0) {
			BST_postorderR(T->root, Printdata);
		}
		else if (strcmp(input, "0") == 0)
		{
			exit(0);
		}
		else {
			printf("���������롣\n");
			Back();
		}
	} while (input != 0);
	return 0;
}


void menu() {
	printf("\t\tBinarySortTree\n");
	printf("\t\t1.��ʼ��\n");
	printf("\t\t2.��������\n");
	printf("\t\t3.��������\n");
	printf("\t\t4.ɾ������\n"); 
	printf("\t\t5.ǰ�����\n");
	printf("\t\t6.�������\n");
	printf("\t\t7.�������\n");
	printf("\t\t0.�˳�ϵͳ\n");

}

void Back() {
	printf("\n");
	//getchar();
	system("pause");
	system("cls");
	menu();

}