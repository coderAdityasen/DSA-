#include<stdio.h>

int main(){

	int a = 10;
	int *ptr = &a;
	int **pqtr = &ptr;
	printf("%d " , &pqtr);

	return 0;
}