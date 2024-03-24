#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LQueue.h"
#include <stdlib.h>
#include <string.h>

LQueue Q;
void *data,*e=NULL,* q=NULL;
int datasize;


void menu() {
	printf("---------队列----------\n");
	printf("        1.元素入列\n");
	printf("        2.元素出列\n");
	printf("        3.取队头元素\n");
	printf("        4.遍历队列\n");
	printf("        5.获取队列长度\n");
	printf("        6.判断队列是否为空\n");
	printf("        7.清空队列\n");
	printf("        0.销毁队列并退出系统\n");
}

void typechoice() {
	char input[100]="\0";
	int len = 0;
	printf("i.整型 d.浮点型 c.字符型\n请选择存入数据类型>>>");
	scanf("%s", input);//防止乱输
	len = strlen(input);
	if (len != 1) {
		printf("请输入正确数据类型选项。\n");
		typechoice();
	}
	else {
		type = input[0];
		printf("%c\n",type);
		if (type == 'i') {
			data = (void*)malloc(sizeof(int));
			datasize = sizeof(int);
		}
		else if (type == 'd') {
			data = (void*)malloc(sizeof(double));
			datasize = sizeof(double);
		}
		else if (type == 'c') {
			data = (void*)malloc(sizeof(char));
			datasize = sizeof(char);
		}
		else {
			printf("请输入正确数据类型选项。\n");
			typechoice();
		}
	}
}

void functionchoice() {
	char input[100] = "\0";
	int len = 0;
	system("cls");
	menu();
	printf("请输入序号>>>");
	scanf("%s", &input);
	len = strlen(input);
	if (len != 1) {
		printf("请输入正确选项序号。\n");
		functionchoice();
	}
	else {
		char inp = input[0];
		switch (inp) {
		case'0':
			DestoryLQueue(&Q);
			exit(0);
		case'1':
			printf("请输入数据>>>\n");
			if (type == 'i') {
				e = (int*)malloc(sizeof(int));
				while (!scanf("%d", (int*)e)) {
					printf("请输入正确数据\n");
					while (getchar() != '\n');
				}
				//LPrint(e,datasize);
			}
			if (type == 'c') {
				e = (char*)malloc(sizeof(char));
				getchar();
				scanf("%c", &(char*)e);
			}
			if (type == 'd') {
				e = (double*)malloc(sizeof(double));
				while (!scanf("%lf", (double*)e)) {
					printf("请输入正确数据\n");
					while (getchar() != '\n');
				}
			}
			memcpy(data, e, datasize);
			if (EnLQueue(&Q, data))printf("已将该数据放入队列。\n");
			else printf("操作失败。\n");
			system("pause");
			functionchoice();
			break;
		case'2': 
			if (DeLQueue(&Q)) printf("成功出队。\n");
			system("pause");
			functionchoice();
			break;
		case'3':
			if (GetHeadLQueue(&Q,q,datasize));
			else printf("操作失败。\n");
			system("pause");
			functionchoice();
			break;
		case'4':
			TraverseLQueue(&Q,datasize);
			system("pause");
			functionchoice();
			break;
		case'5': 
			printf("队列长度为%d。\n",LengthLQueue(&Q));
			system("pause");
			functionchoice();
			break;
		case'6':
			if (IsEmptyLQueue(&Q))printf("队列为空。\n");
			else printf("队列不为空。\n");
			system("pause");
			functionchoice();
			break;
		case'7':
			ClearLQueue(&Q);
			system("pause");
			functionchoice();
			break;
		default:
			printf("请输入正确选项序号。\n");
			system("pause");
			functionchoice();
			break;
		}
	}
}

int main() {
	typechoice();
	InitLQueue(&Q);
	printf("已成功初始化队列！\n");
	system("cls");
	functionchoice();
}