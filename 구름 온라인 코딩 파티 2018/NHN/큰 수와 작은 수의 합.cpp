#include<stdio.h>
#include<stdlib.h>
#define con(a,b) (b>9) ? a*100 : a*10 
#define front(x) (x>9) ? x/10 : x%10

int compare(const void *a, const void *b){
	int* pr1 = (int*) a;
	int* pr2 = (int*) b;
	int n1 = *pr1;
	int n2 = *pr2;
	int fr1 = front(n1);
	int fr2 = front(n2);
	if(fr1>fr2) return 1;
	if(fr1<fr2) return -1;
	if(n1<10){
		n1 *= 10;
		n1 += fr1;
	}
	if(n2<10){
		n2 *= 10;
		n2 += fr2;
	}
	if(n1>n2) return 1;
	if(n1<n2) return -1;
	return 0;
}

int main(void){
	int N;
	int num[10];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &num[i]);
	}
	qsort(num, N, sizeof(int), compare);
	long long int sum1 = 0;
	long long int sum2 = 0;
	for(int i=0; i<N; i++){
		sum1 = con(sum1, num[i]);
		sum2 = con(sum2, num[N-1-i]);
		sum1 += num[i];
		sum2 += num[N-1-i];
	}
	printf("%lld", sum1 + sum2);
}
