#include<stdio.h>
#include<stdlib.h>

long long int a[101];
long long int PQ[10000001];
int cnt;
int count;
long long int max;
int K, N;

void swap(long long int *a, long long int *b){
	long long int temp = *a;
	*a = *b;
	*b = temp;
}

int compare(int a, int b){
	if(PQ[b] == 0){
		return 0;
	}
	if(PQ[a]>PQ[b]){
		return 1;
	}
	return 0;
}

void push(long long int x){
	cnt++;
	PQ[cnt] = x;
	int i = cnt;
	while(i>1 && (compare(i/2, i))){
		swap(&PQ[i], &PQ[i/2]);
		i = i/2;
	}
}

long long int pop(){
	long long int temp = PQ[1];
	PQ[1] = PQ[cnt];
	PQ[cnt] = 0;
	cnt--;
	int i = 1;
	while((i*2<=cnt) && (compare(i, i*2) || compare(i, i*2+1))){
		if(compare(i*2, i*2+1)){
			swap(&PQ[i], &PQ[i*2+1]);
			i = i*2+1;
		}
		else{
			swap(&PQ[i], &PQ[i*2]);
			i = i * 2;
		}
	}
	return temp;
}

long long int find(){
	long long int x = pop();
	if(x==max) return find();
	max = x;
	count++;
	if(count==N) return x;
	for(int i=0; i<K; i++){
		push(x*a[i]);
	}
	return find();
}

int main(void){
	scanf("%d %d", &K, &N);
	for(int i=0; i<K; i++){
		scanf("%d", &a[i]);
		push(a[i]);
	}
	long long int ans = find();
	printf("%lld", ans);
}
