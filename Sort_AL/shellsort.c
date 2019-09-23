#include "stdio.h"

int main(){
		int a[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
		for (int d = 5; d >= 1; d /= 2){
				for (int i = d; i < 10; i++){
						for (int j = i -d; j >= 0; j -= d){
								if (a[j] > a[j+d]){
										int t = a[j];
										a[j] = a[d + j];
										a[d + j] = t;
								}
						}
				}
		}
		for (int i = 0; i < 10; i++){
				printf("%d ", a[i]);
		}
}
