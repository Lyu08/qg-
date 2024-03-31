#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertSort(int* a, int n) {

	for (int i = 1; i < n; i++) {
		int end = i;
		int temp = a[end];
		while (end > 0){
			if (a[end - 1] > temp){
				a[end] = a[end - 1];
				end--;
			}
			else break;
		}
		a[end] = temp;
	}

}

void MergeArray(int* a, int begin, int mid, int end, int* temp) {
	int left = mid - begin, right = end - mid;
	int l = 0, r = 0;
	if (begin - end == 1) {
		int temp = min(a[begin], a[end]);
		a[end] = max(a[begin], a[end]);
		a[begin] = temp;
		return;
	}
	for (int i = begin; i < mid; i++) {
		temp[i] = a[i];
	}
	for (int i = mid; i < end; i++) {
		temp[i] = a[i];
	}
	while (l + r < end - begin) {
		if (temp[l + begin] < temp[r + mid] && l < left || r >= right) {
			a[l + r + begin] = temp[l + begin];
			l++;
		}
		else if (r < right || l >= left) {
			a[l + r + begin] = temp[r + mid];
			r++;
		}
	}
}

void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin + 1 >= end) return;
	int mid = (begin + end) / 2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid, end, temp);
	MergeArray(a, begin, mid, end, temp);
}


void QuickSort_Recursion(int* a, int begin, int end) {
	int i, j, temp, pivot;
	if (begin >= end)return;
	pivot = a[begin];
	i = begin;
	j = end;
	while (i != j) {
		while (a[j] >= pivot && i < j) {
			j--;
		}
		while (a[i] <= pivot && i < j) {
			i++;
		}
		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}

	a[begin] = a[i];
	a[i] = pivot;
	QuickSort_Recursion(a, begin, i - 1);
	QuickSort_Recursion(a, i + 1, end);
}


void CountSort(int* a, int size, int max) {
	int ptr = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int range = max + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	memset(count, 0, sizeof(int) * range);

	for (int i = 0; i < size; i++) {
		count[a[i]] ++;
	}

	for (int j = 0; j < range; j++) {
		while (count[j]-- > 0) {
			a[ptr++] = j;
		}
	}
	free(count);
}

void RadixCountSort(int* a, int size) {
	int max = a[0];
	int exp =1 ;
	int* temp = (int*)malloc(sizeof(int) * size);
	
	for (int i = 0; i < size; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}

	while (max / exp > 0) {
		int i, buckets[10] = { 0 };

		for (i = 0; i < size; i++) {
			buckets[(a[i] / exp) % 10]++;
		}

		for (i = 1; i < 10; i++) {
			buckets[i] += buckets[i - 1];
		}

		for (i = size - 1; i >= 0; i--) {
			temp[buckets[(a[i] / exp) % 10] - 1] = a[i];
			buckets[(a[i] / exp) % 10]--;
		}

		for (i = 0; i < size; i++) {
			a[i] = temp[i];
		}
		exp *= 10;
	}

}

void ColorSort(int* a, int size) {
	int count[3] = { 0 };
	int index = 0;
	for (int i = 0; i < size; i++) {
		count[a[i]]++;
	}
	for (int i = 0; i < count[0]; i++) {
		a[index++] = 0;
	}
	for (int i = 0; i < count[1]; i++) {
		a[index++] = 1;
	}
	for (int i = 0; i < count[2]; i++) {
		a[index++] = 2;
	}
}