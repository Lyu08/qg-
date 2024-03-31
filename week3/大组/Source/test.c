#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sort.h"
#include "randnum.h"
#include <time.h>


#define N 10000
#define MAX 50000
/*��д���Գ�����������������ڲ�ͬ�Ĵ�������
�µ���ʱ����������Σ�10000��50000��200000��*/

int arr[N], b[N], temp[N];

int main() {
	clock_t start, end;
	double runtime;
	void menu();
	void Back();
	int input();
	long long n;
	int num, max = 0;

	srand(1);

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % MAX;//��������������
		b[i] = arr[i];//������������֮ǰ������
		//printf("%d ",arr[i]);
		//printf("%d ", b[i]);
	}

	printf("������������ݣ�\n");

	menu();
	do {
		printf("�������ţ�0-5��>>> ");
		num = input();
		switch (num) {
		case 1:
			start = clock();
			insertSort(arr, N);
			end = clock();
			runtime = ((double)(end - start));
			printf("����(InsertSort)���� 10000 �����ݵ���ʱΪ: %f ms\n", runtime);
			for (int i = 0; i < N; i++)//�����������ָ�Ϊԭʼ˳�����¸����򷽷�����
			{
				arr[i] = b[i];
			}
			break;
		case 2:
			start = clock();
			MergeSort(arr, 0,N-1, temp);
			end = clock();
			runtime = ((double)(end - start));
			printf("�鲢(MergeSort)���� 10000 �����ݵ���ʱΪ: %f ms\n", runtime);
			for (int i = 0; i < N; i++)//�����������ָ�Ϊԭʼ˳�����¸����򷽷�����
			{
				arr[i] = b[i];
			}
			break;
		case 3:
			start = clock();
			QuickSort_Recursion(arr, 0, N - 1);
			end = clock();
			runtime = ((double)(end - start));
			printf("����(QuickSort)���� 10000 �����ݵ���ʱΪ: %f ms\n" ,runtime);
			for (int i = 0; i < N; i++)
			{
				arr[i] = b[i];
			}
			break;
		case 4:
			start = clock();
			CountSort(arr, N, max);
			end = clock();
			runtime = ((double)(end - start));
			printf("����(CountSort)���� 10000 �����ݵ���ʱΪ: %f ms\n", runtime);
			for (int i = 0; i < N; i++)
			{
				arr[i] = b[i];
			}
			break;
		case 5:
			start = clock();
			RadixCountSort(arr, N);
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
	printf("\t\t--------�������-------\n");
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

