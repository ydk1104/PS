#include<stdio.h>

long long int card[1001];
long long int sum;
int cnt;

void swap(int a, int b){
	long long int temp = card[a];
	card[a] = card[b];
	card[b] = temp;
}

int com(int a, int b){
	if(card[a]>card[b]) return 1;
	return 0;
}

void push(long long int x){
	cnt++;
	card[cnt] = x;
	int i = cnt;
	while(i>1 && com(i/2, i)){
		swap(i/2, i);
		i = i/2;
	}
}

long long int pop(){
	long long int temp = card[1];
	card[1] = card[cnt--];
	int i = 1;
	while((i*2<=cnt && com(i, i*2)) || (i*2+1<=cnt && com(i, i*2+1))){
		if(i*2+1<=cnt && com(i*2, i*2+1)){
			swap(i, i*2+1);
			i = i*2+1;
		}
		else{
			swap(i, i*2);
			i = i*2;
		}
	}
	return temp;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		long long int x;
		scanf("%lld", &x);
		sum += x;
		push(x);
	}
	for(int i=1; i<=M; i++){
		long long int a = pop();
		long long int b = pop();
		sum += a+b;
		push(a+b);
		push(a+b);
	}
	printf("%lld", sum);
}
