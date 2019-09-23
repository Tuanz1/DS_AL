//  冒泡法排序
//  flag 是针对外循环优化（如果没有交换则说明已经排序）
//  pos 是针对内循环优化（后面的没有交换就无需再比较）
#include "stdio.h"
#include "assist.h"
// 测试数据	
int data[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};

// 增序排列数组a
void bubbleSort(int a[]);

int main(){
	printIntArray(data, 10);
	bubbleSort(data);
	printIntArray(data, 10);
}

void bubbleSort(int a[]){
	int temp = 0;
	int flag = 0;
	int pos = 0;
	int i, j;
	int length = 10;
	for (i = 0; i < length; i++){
			flag = 0;
			for (j = 0; j < length - i - 1; j++){
					if (a[j] > a[j+1]){
							temp = a[j + 1];
							a[j + 1] = a[j];
							a[j] = temp;
							flag = 1;
							pos = j;
					}
			}
			if (flag == 0)
					break;
			i = pos;
	}
}


