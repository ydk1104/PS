#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
	int *pa = (int*) a;
	int *pb = (int*) b;
	if(*pa > *pb) return 1;
	if(*pa == *pb) return 0;
	return -1;
}

int main(void){
	int a[4];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	qsort(a, 3, sizeof(int), compare);
	int minus[3];
	for(int i=0; i<2; i++){
		minus[i] = a[i+1] - a[i];
	}
	if(minus[0] == minus[1]) printf("%d", a[2]+minus[0]);
	else printf("%d", a[0]+minus[1]);
}
