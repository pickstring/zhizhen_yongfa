#include<iostream>
#include<cstdlib>
using namespace std;

void swap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap2(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

//2、指针与函数
void swap3(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3、指针、数组、函数
void bubbleSort(int* arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//4、上述代码改版
void bubbleSort1(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	//1、指针与数组
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* p = arr;
	
	cout << arr[0] << endl;
	cout << *p << endl;
	
	for (int i = 0; i < 9; i++) {
		cout << *p << endl;
		//指针++是移动一个指针单元（32位下的4个字节）
		p++;
	}

	//值传递
	int a = 10, b = 20;
	swap1(a, b);
	cout << a << b << endl;
	//地址传递
	int c = 30, d = 40;
	swap2(c, d);
	cout << c << d << endl;
	//地址传递
	int e = 50, f = 60;
	swap3(&e, &f);
	cout << e << f << endl;
	//值传递与地址传递
	int arr1[] = { 1, 4, 5, 2, 7, 9, 3 };
	int length = sizeof(arr1) / sizeof(arr1[0]);
	bubbleSort(arr1, length);
	for (int i = 0; i < length; i++) {
		cout << arr1[i] << " ";
	}
	cout << "_______________________________________________";
	//上述代码改版
	int arr2[] = { 1, 4, 5, 2, 7, 9, 3 };
	int length1 = sizeof(arr2) / sizeof(arr2[0]);
	bubbleSort(arr2, length1);
	for (int i = 0; i < length1; i++) {
		cout << arr2[i] << " ";
	}
	return 0;
}