#include "stdio.h"

// 快速排序
void QuickSort(int s[], int low, int high);

int main() {
  int t[12] = {1, 3, 7, 7, 9, 2, 4, 6, 8, 10, 0, 19};
  QuickSort(t, 0, 11);
  for (int i = 0; i < 12; i++) {
    printf("%d ", t[i]);
  }
  printf("\n");
}

void QuickSort(int s[], int low, int high) {
  printf("QuickSort: %d, %d\n", low, high);
  // 设置两个tmp的低位和高位变量
  int low_tmp = low, high_tmp = high;
  // 默认最低位为指标
  int temp = s[low];
  if (low_tmp < high_tmp) { // >= 时快排结束
    while (low_tmp < high_tmp) {
      // 高位与标志比较，较大则不变
      while (low_tmp < high_tmp && s[high_tmp] >= temp)
        --high_tmp;
      // 高位换到低位
      s[low_tmp] = s[high_tmp];
      while (low_tmp < high_tmp && s[low_tmp] <= temp)
        ++low_tmp;
      s[high_tmp] = s[low_tmp];
    }
    s[low_tmp] = temp; // 讲最后标志放在中间
    QuickSort(s, low, low_tmp - 1);
    QuickSort(s, low_tmp + 1, high);
  }
}
