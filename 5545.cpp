#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
	int* p1 = (int*) a;
	int* p2 = (int*) b;
	if(*p1 < *p2) return 1;
	if(*p1 == *p2) return 0;
	return -1;
}

int main(void){
	int N;
	int pr1, pr2;
	int C;
	scanf("%d\n%d %d\n%d", &N, &pr1, &pr2, &C);
	int sum = C;
	int price = pr1;
	int kal[101];
	for(int i=0; i<N; i++){
		scanf("%d", &kal[i]);
	}
	qsort(kal, N, sizeof(int), compare);
	int ans[101] = {sum / price};
	int i = 0;
	do{
		sum += kal[i];
		price += pr2;
		ans[i+1] = sum / price;
		i++;
	}
	while(ans[i] >= ans[i-1] && i<N);
	printf("%d", ans[i-1]);
}
