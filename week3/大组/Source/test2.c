#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sort.h"
#include "randnum.h"
#include <time.h>


#define N 100
#define MAX 50000


int arr[N], b[N], temp[N];

int main() {
	clock_t start, end;
	double runtime;
	void menu();
	void Back();
	void getdata();
	int input();
	long long n;
	int num, max = 0;



	
	menu();
	do {
		printf("�������ţ�0-5��>>> ");
		num = input();
		switch (num) {
		case 1:
			start = clock();
			for (int i = 0; i < 100000; i++) {

				getdata();
				insertSort(arr, N);
			}
			end = clock();
			runtime = ((double)(end - start));
			printf("����(InsertSort)���� 1000000 ������ 100 �����ݵ���ʱΪ: %f ms\n", runtime);
			for (int i = 0; i < N; i++)//�����������ָ�Ϊԭʼ˳�����¸����򷽷�����
			{
				arr[i] = b[i];
			}
			break;
		case 2:
			start = clock(); 
			for (int i = 0; i < 100000; i++) {

				getdata();
				MergeSort(arr, 0, N - 1, temp);
			}
			end = clock();
			runtime = ((double)(end - start));
			printf("�鲢(MergeSort)���� 1000000 ������ 100 �����ݵ���ʱΪ: %f ms\n", runtime);
			for (int i = 0; i < N; i++)//�����������ָ�Ϊԭʼ˳�����¸����򷽷�����
			{
				arr[i] = b[i];
			}
			break;
		case 3:
			start = clock();
			for (int i = 0; i < 100000; i++) {

				getdata();
				QuickSort_Recursion(arr, 0, N - 1);
			}
			end = clock();
			runtime = ((double)(end - start));
			printf("����(QuickSort)���� 1000000 ������ 100 �����ݵ���ʱΪ: %f ms\n" ,runtime);
			for (int i = 0; i < N; i++)
			{
				arr[i] = b[i];
			}
			break;
		case 4:
			start = clock(); 
			for (int i = 0; i < 100000; i++) {
				getdata();
				CountSort(arr, N, max);
			}
			end = clock();
			runtime = ((double)(end - start));
			printf("����(CountSort)���� 1000000 ������ 100 �����ݵ���ʱΪ: %f ms\n", runtime);
			for (int i = 0; i < N; i++)
			{
				arr[i] = b[i];
			}
			break;
		case 5:
			start = clock();
			for (int i = 0; i < 100000; i++) {
				getdata();
				RadixCountSort(arr, N);
			}
			end = clock();
			runtime = ((double)(end - start));
			printf("����(CountSort)���� 10000 �����ݵ���ʱΪ: %f ms\n", runtime);
			for (int i = 0; i < N; i++)
			{
				arr[i] = b[i];
			}
			break;
		default:
			printf("����ȷ���롣\n");
			break;
		}

	} while (num != 0);
}

void menu() {
	printf("\t\t--------�������(����С������)-------\n");
	printf("\t\t1.����(InsertSort)\n");
	printf("\t\t2.�鲢(MergeSort) \n");
	printf("\t\t3.����(QuickSort)(�ݹ��)\n");
	printf("\t\t4.����(CountSort)\n");
	printf("\t\t5.������������(RadixCountSort)\n");
}


void Back() {
	printf("\n");
	system("pause");
	system("cls");
	menu();
}


int input() {
	int len, num = 0, arg = 1;
	char inp[100];
	int m, j = 1, k;
	while (j)
	{
		scanf_s("%s", inp);
		len = strlen(inp);
		for (m = 0; m < len; m++)
		{
			if (inp[m] < '0' || inp[m]>'9')  //�����Ƿ��������������ַ�
			{
				printf("����ȷ���롣\n");
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

void getdata() {
	srand(time(0));

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % MAX;//��������������
		b[i] = arr[i];//������������֮ǰ������
		//printf("%d ", arr[i]);
		//printf("%d ", b[i]);
	}
}