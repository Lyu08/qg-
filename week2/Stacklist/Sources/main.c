#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h" 

void menu() {
	printf("------------------��ջ------------------\n");
	printf("              1.��ʼ����ջ\n");
	printf("              2.������ջ\n");
	printf("              3.�����ջ\n");
	printf("              4.Ԫ����ջ\n");
	printf("              5.Ԫ�س�ջ\n");
	printf("              6.��ⳤ��\n");
	printf("              7.�ж�ջ��\n");
	printf("              8.���ջ��Ԫ��\n");
	printf("              0.�˳�ϵͳ\n");
}

int main() {
	menu();
	void Back();
	int num, length=0;
	ElemType data;
	LinkStack stack;
	initLStack(&stack);
	printf("���Զ���ʼ��һ����ջ��\n");
	do {
		printf("�������ţ�0-8��>>> ");
		num = input();
		switch (num) {
			case(1): {
				if (initLStack(&stack)) {
					printf("�ѳ�ʼ������ջ��\n");
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
				printf("������Ҫѹ��ջ��Ԫ�أ�\n");
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
					printf("��ǰû��ջ��ջΪ�գ�ջ��Ϊ0��\n");
				}
				Back();
				break;
			}
			case(7): {

				if (isEmptyLStack(&stack)) {
					printf("ջΪ�ա�\n");
				}
				else {
					printf("ջ��Ϊ�ա�\n");
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
				printf("��������,������0-8��������\n");
				Back();
				break;
			}

		}
		//char none = getchar();//�Ե�����Ļس�
	} while (num != 0);
	 
}

void Back() {
	printf("\n");
	//getchar();
	system("pause");
	system("cls");
	menu();
}

//��ֹ����
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
			if (inp[m] < '0' || inp[m]>'9')  //�����Ƿ��������������ַ�
			{
				printf("���������²���>>>");
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
	for (m = 0; m < len; m++)  // ���ַ�����ת��Ϊ����
	{
		for (k = 0; k < j; k++)
			arg *= 10;
		num += (inp[m] - '0') * arg;
		arg = 1;
		j--;
	}
	return num;
}