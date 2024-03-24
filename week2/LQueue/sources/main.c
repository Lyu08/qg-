#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "LQueue.h"
#include <stdlib.h>
#include <string.h>

LQueue Q;
void *data,*e=NULL,* q=NULL;
int datasize=0;


void menu() {
	printf("---------����----------\n");
	printf("        1.Ԫ������\n");
	printf("        2.Ԫ�س���\n");
	printf("        3.ȡ��ͷԪ��\n");
	printf("        4.��������\n");
	printf("        5.��ȡ���г���\n");
	printf("        6.�ж϶����Ƿ�Ϊ��\n");
	printf("        7.��ն���\n");
	printf("        0.���ٶ��в��˳�ϵͳ\n");
}

void typechoice() {
	char input[100]="\0";
	int len = 0;
	printf("i.���� f.������ c.�ַ���\n��ѡ�������������>>>");
	scanf("%s", input);//��ֹ����
	len = strlen(input);
	if (len != 1) {
		printf("��������ȷ��������ѡ�\n");
		typechoice();
	}
	else {
		type = input[0]  ;
		printf("%c\n",type);
		if (type == 'i') {
			data = (void*)malloc(sizeof(int));
			datasize = sizeof(int);
		}
		else if (type == 'f') {
			data = (void*)malloc(sizeof(float));
			datasize = sizeof(float);
		}
		else if (type == 'c') {
			data = (void*)malloc(sizeof(char));
			datasize = sizeof(char);
		}
		else {
			printf("��������ȷ��������ѡ�k\n");
			typechoice();
		}
	}
}

void functionchoice() {
	char input[100] = "\0";
	int len = 0;
	system("cls");
	menu();
	printf("���������>>>");
	scanf("%s", &input);
	len = strlen(input);
	if (len != 1) {
		printf("��������ȷѡ����š�\n");
		functionchoice();
	}
	else {
		char inp = input[0];
		switch (inp) {
		case'0':
			DestoryLQueue(&Q);
			exit(0);
		case'1':
			printf("����������>>>\n");
			if (type == 'i') {
				e = (int*)malloc(sizeof(int));
				while (!scanf("%d", (int*)e)) {
					printf("��������ȷ����\n");
					while (getchar() != '\n');
				}
				printf("%d", *(int*)e);
			}
			if (type == 'c') {
				e = (char*)malloc(sizeof(char));
				getchar();
				scanf("%c", &(char*)e);
				printf("%c", (char*)e);
			}
			if (type == 'f') {
				e = (float*)malloc(sizeof(float));
				while (!scanf("%f", (float*)e)) {
					printf("��������ȷ����\n");
					while (getchar() != '\n');
				}
				printf("%f", *(float*)e);
			}
			//memcpy(data, e, datasize);
			if (EnLQueue(&Q, data))printf("�ѽ������ݷ�����С�\n");
			else printf("����ʧ�ܡ�\n");
			system("pause");
			functionchoice();
			break;
		case'2': 
			if (DeLQueue(&Q)) printf("�ɹ����ӡ�\n");
		    else printf("����ʧ�ܡ�\n");
			system("pause");
			functionchoice();
			break;
		case'3':
			if (GetHeadLQueue(&Q,q,datasize));
			else printf("����ʧ�ܡ�\n");
			system("pause");
			functionchoice();
			break;
		case'4':
			TraverseLQueue(&Q,datasize);
			system("pause");
			functionchoice();
			break;
		case'5': 
			printf("���г���Ϊ%d��\n",LengthLQueue(&Q));
			system("pause");
			functionchoice();
			break;
		case'6':
			if (IsEmptyLQueue(&Q))printf("����Ϊ�ա�\n");
			else printf("���в�Ϊ�ա�\n");
			system("pause");
			functionchoice();
			break;
		case'7':
			ClearLQueue(&Q);
			system("pause");
			functionchoice();
			break;
		default:
			printf("��������ȷѡ����š�\n");
			system("pause");
			functionchoice();
			break;
		}
	}
}

int main() {
	typechoice();
	InitLQueue(&Q);
	printf("�ѳɹ���ʼ�����У�\n");
	functionchoice();
}