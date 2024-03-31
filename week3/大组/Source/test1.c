#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sort.h"
#include <time.h>

//编写一个按要求生成测试数据，并保存到文件的程序，和一个能按要求读取文件中的数据，并让上述排序函数进行排序的程序。

#define N 20
#define MAX 50


int arr[N], b[N], temp[N];

int main() {
	clock_t start, end;
	double runtime;
	void writerandnum(const char* fileURL, int* a, int* b);
	void menu();
	void Back();
	void getdata();
	int input();
	long long n;
	int num, max = 0;



	writerandnum("data.txt", arr,b);
	menu();
	do {
		printf("请键入序号（0-5）>>> ");
		num = input();
		switch (num) {
		case 1:

			insertSort(arr, N);
			for (int i = 0; i < N; i++)
			{
				printf("%d ", arr[i]);
			}
			for (int i = 0; i < N; i++)//操作后把数组恢复为原始顺序，让下个排序方法调用
			{
				arr[i] = b[i];
			}
			break;
		case 2:
			MergeSort(arr, 0, N - 1, temp);
			for (int i = 0; i < N; i++)
			{
				printf("%d ", arr[i]);
			}
			for (int i = 0; i < N; i++)
			{
				arr[i] = b[i];
			}
			break;
		case 3:
			QuickSort_Recursion(arr, 0, N-1);
			for (int i = 0; i < N; i++)
			{
				printf("%d ", arr[i]);
			}
			for (int i = 0; i < N; i++)
			{
				arr[i] = b[i];
			}
			break;
		case 4:
			CountSort(arr, N, max);
			for (int i = 0; i < N; i++)
			{
				printf("%d ", arr[i]);
			}
			for (int i = 0; i < N; i++)
			{
				arr[i] = b[i];
			}
			break;
		case 5:
			RadixCountSort(arr, N);
			for (int i = 0; i < N; i++)
			{
				printf("%d ", arr[i]);
			}
			for (int i = 0; i < N; i++)
			{
				arr[i] = b[i];
			}
			break;
		default:
			printf("请正确输入。\n");
			break;
		}

	} while (num != 0);
}

void menu() {
	printf("\t\t--------排序-------\n");
	printf("\t\t1.插入(InsertSort)\n");
	printf("\t\t2.归并(MergeSort) \n");
	printf("\t\t3.快排(QuickSort)(递归版)\n");
	printf("\t\t4.计数(CountSort)\n");
	printf("\t\t5.基数计数排序(RadixCountSort)\n");
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
			if (inp[m] < '0' || inp[m]>'9')  //检验是否有乱输入其他字符
			{
				printf("请正确输入。\n");
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

void getdata() {
	srand(time(0));

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % MAX;//用来操作的数组
		b[i] = arr[i];//用来保存排序之前的数组
		//printf("%d ", arr[i]);
		//printf("%d ", b[i]);
	}
}


void writerandnum(const char* fileURL, int* a, int* b) {
	srand(time(NULL));//随机数
	FILE* fp = fopen(fileURL, "w+");

	setvbuf(fp, NULL, _IONBF, 0);

	for (int i = 0; i < N; i++)
	{
		fprintf(fp, "%d \n", rand());
		a[i] = rand() % MAX;
		b[i] = a[i];
		printf("%d ", a[i]);
	}
	fclose(fp);
	printf("\n已生成随机数据并存入文件。\n");
	return;
}
