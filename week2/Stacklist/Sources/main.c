#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h" 

void menu() {
	printf("------------------链栈------------------\n");
	printf("              1.初始化链栈\n");
	printf("              2.销毁链栈\n");
	printf("              3.清空链栈\n");
	printf("              4.元素入栈\n");
	printf("              5.元素出栈\n");
	printf("              6.检测长度\n");
	printf("              7.判断栈空\n");
	printf("              8.获得栈顶元素\n");
	printf("              0.退出系统\n");
}

int main() {
	menu();
	void Back();
	int num, length=0;
	ElemType data;
	LinkStack stack;
	initLStack(&stack);
	printf("已自动初始化一个空栈！\n");
	do {
		printf("请键入序号（0-8）>>> ");
		num = input();
		switch (num) {
			case(1): {
				if (initLStack(&stack)) {
					printf("已初始化空链栈。\n");
				}
				Back();
				break;
			}
			case(2): {
				destroyLStack(&stack);
				Back();
				break;
			}
			case(3): {
				clearLStack(&stack);
				Back();
				break;
			}
			case(4): {
				printf("请输入要压入栈的元素：\n");
				scanf_s("%d", &data);
				pushLStack(&stack, data);
				Back();
				break;
			}
			case(5): {
				popLStack(&stack, &data);
				Back();
				break;
			}
			case(6): {
				if (LStackLength(&stack, length));
				else {
					printf("当前没有栈或栈为空，栈长为0。\n");
				}
				Back();
				break;
			}
			case(7): {

				if (isEmptyLStack(&stack)) {
					printf("栈为空。\n");
				}
				else {
					printf("栈不为空。\n");
				}
				Back();
				break;
			}
			case(8): {
				getTopLStack(&stack, &data);
				Back();
				break;
			}
			case(0):break;
			default: {
				printf("输入有误,请输入0-8的整数。\n");
				Back();
				break;
			}

		}
		//char none = getchar();//吃掉输入的回车
	} while (num != 0);
	 
}

void Back() {
	printf("\n");
	//getchar();
	system("pause");
	system("cls");
	menu();
}

//防止乱输
int input() {
	int len, num = 0, arg = 1;
	char inp[100];
	int m, j = 1, k;
	while (j)
	{
		scanf("%s", inp);
		len = strlen(inp);
		for (m = 0; m < len; m++)
		{
			if (inp[m] < '0' || inp[m]>'9')  //检验是否有乱输入其他字符
			{
				printf("错误！请重新操作>>>");
				Back();
				break;
			}
			else
			{
				if (m == len - 1)
					j = 0;
			}
		}
	}
	j = len - 1;
	for (m = 0; m < len; m++)  // 将字符重新转换为数字
	{
		for (k = 0; k < j; k++)
			arg *= 10;
		num += (inp[m] - '0') * arg;
		arg = 1;
		j--;
	}
	return num;
}