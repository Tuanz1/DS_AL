#include "stdio.h"
#include "assist.h"
void printIntArray(int p[], int length);

void printIntArray(int p[], int length){
		for (int i = 0; i < length; i++){
				printf("%d   ", p[i]);
		}
		printf("\n");
}
