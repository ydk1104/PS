#include<stdio.h>
#include<stdlib.h>

int a[500001];
int b[8001];
int sum = 0;

int compare(const void *a, const void *b){
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if(num1>num2){
		return 1;
	}
	else if(num1==num2){
		return 0;
	}
	else{
		return -1;
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
		b[a[i]+4000]++;
		sum += a[i];
	}
	qsort(a, N, sizeof(int), compare);
	printf("%.0f\n",float(sum) / N);
	printf("%d\n", a[N/2]);
	int cnt = 0;
	int cnt2 = 0;
	for(int i=0; i<=8000; i++){
		if(b[cnt] < b[i]){
			cnt = i;
			cnt2 = 0;
		}
		else if(b[cnt] == b[i] && cnt2 == 0){
			cnt = i;
			cnt2 = 1;
		}
	}
	cnt = cnt - 4000;
	printf("%d\n", cnt);
	printf("%d\n", a[N-1]-a[0]);
}
