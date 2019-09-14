#include<stdio.h>
#define INT 1000000007

long long int PQ[1000001], ans;
int cnt;

void swap(int a, int b){
	int temp = PQ[a];
	PQ[a] = PQ[b];
	PQ[b] = temp;
}

void push(long long int x){
	PQ[++cnt] = x;
	int i = cnt;
	while(i>1 && PQ[i]<PQ[i/2]){
		swap(i, i/2);
		i/=2;
	}
}

long long int pop(){
	long long int temp = PQ[1];
	PQ[1] = PQ[cnt];
	PQ[cnt--] = PQ[0];
	int i = 1;
	while(i*2<=cnt && (PQ[i]>PQ[i*2] || PQ[i]>PQ[i*2+1])){
		if(PQ[i*2] < PQ[i*2+1]){
			swap(i, i*2);
			i*=2;
		}
		else{
			swap(i, i*2+1);
			i = i*2+1;
		}
	}
	return temp;
}

int main(void){
	int T;
	PQ[0] = 1;
	PQ[0] = (PQ[0]<<62)-1;
	PQ[0] *=2;
	PQ[0]++;
	scanf("%d", &T);
	for(; T>0; T--){
		int N;
		scanf("%d", &N);
		for(int i=1; i<=N; i++){
			long long int x;
			scanf("%lld", &x);
			push(x);
		}
		ans = 1;
		while(N>1){
			long long int a = pop();
			long long int b = pop();
			long long int temp = a*b;
//			printf("%lld %lld %lld\n", a, b, temp);
			push(temp);
			temp %= INT;
			ans *= temp;
			ans %= INT;
			N--;
		}
		printf("%lld\n", ans);
		while(cnt) pop();
	}
}
