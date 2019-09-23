#include "stdio.h"

int main(){
		int a[10] = {1,3,5,7,8, 2, 4, 6, 8, 10};

		for (int i = 1; i < 10; i++){
				for (int j = i; j > 0; j--){
						if (a[j-1] > a[j]){
								int t = a[j];
								a[j] = a[j - 1];
								a[j - 1] = t;
						}
				}
		}
		for (int i =0; i < 10; i++){
				printf("%d ", a[i]);
		}
}
