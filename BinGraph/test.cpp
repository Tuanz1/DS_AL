int partition(innt a[], int low, int high); //与王道的基本一样的分块算法
void quicksort(iint a[], int low, int high); //与王道一样
// 改进版快排（随机一个当基准)
int randompartion(int a[], int low, int high) {
  int i = random(low, high); //中间随机一个数
  swap(a[i], a[low]);
  return partition(a, low, high);
}
//　是第一次用随机快排，还是所有都是随机快排