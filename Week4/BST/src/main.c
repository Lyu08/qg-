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
		printf("\n请输入序号 >>>");
		gets_s(input, 100);
		if (strcmp(input, "1") == 0) {
			if (BST_init(&T)) {
				printf("初始化成功！\n");
			}else
				printf("初始化失败。\n");
			Back();
		}

		else if (strcmp(input, "2") == 0)
		{
			BinarySortTree* r = T;
			if (!r)printf("尚未初始化树！\n");
			else {
				printf("请输入要插入的数字>>>");
				if (scanf_s("%d", &num)) {
					if (BST_insert(r, num)) printf("插入成功！\n");
					else printf("操作失败，请重试。\n");
				}
				else printf("非法输入！\n");
			}
			Back();
		}
		else if (strcmp(input, "3") == 0)
		{
			BinarySortTree* r = T;
			if (!r)printf("尚未初始化树！\n");
			else {
				printf("请输入要搜索的数字>>>");
				if (scanf_s("%d", &num)) {
					if (BST_search(r, num)) printf("该数存在！\n");
					else printf("该数不存在。\n");
				}
				else printf("非法输入！\n");
			}
			Back();
		}
		else if (strcmp(input, "4") == 0)
		{
			BinarySortTree* r = T;
			if (!r)printf("尚未初始化树！\n");
			else {
				printf("请输入要删除的数字>>>");
				if (scanf_s("%d", &num)) {
					if (BST_search(r, num)) {
						if (BST_delete(r, num))printf("已删除！\n");
						else printf("操作失败，请重试。\n");
					}
					else printf("该数不存在树中。\n");
				}
				else printf("非法输入！\n");
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
			printf("请重新输入。\n");
			Back();
		}
	} while (input != 0);
	return 0;
}


void menu() {
	printf("\t\tBinarySortTree\n");
	printf("\t\t1.初始化\n");
	printf("\t\t2.插入数据\n");
	printf("\t\t3.搜索数据\n");
	printf("\t\t4.删除数据\n"); 
	printf("\t\t5.前序遍历\n");
	printf("\t\t6.中序遍历\n");
	printf("\t\t7.后序遍历\n");
	printf("\t\t0.退出系统\n");

}

void Back() {
	printf("\n");
	//getchar();
	system("pause");
	system("cls");
	menu();

}