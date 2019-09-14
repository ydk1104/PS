#include<stdio.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

int prime_f[1001][1001];
int era[1001];

void prime_factorization(int x){
	int temp = x;
	for(int i=2; i*i<=x; i++){
		if(era[i] == 0){
			while(x%i == 0){
				prime_f[temp][i]++;
				x/=i;
			}
		}
	}
	prime_f[temp][x]++;
	return;
}

void print(int ans[]){
	long long int temp = 1;
	for(int i=0; i<=1000; i++){
		while(ans[i]>0){
			ans[i]--;
			temp *= i;
			temp %= 1000000007;
		}
	}
	printf("%lld\n", temp);
}

int main(void){
	for(int i=2; i<=1000; i++){
		if(era[i] == 0){
			for(int j=i; i*j<=1000; j++) era[i*j]++;
		}
	}
	for(int i=2; i<=1000; i++){
		prime_factorization(i);
	}
	int T;
	scanf("%d", &T);
	for(; T>0; T--){
		int N;
		scanf("%d", &N);
		int a[1001] = {0, };
		int x;
		for(int i=0; i<N; i++){
			scanf("%d", &x);
			a[x] = 1;
		}
		int ans[1001] = {0, };
		for(int i=1; i<=1000; i++){
			if(a[i]){
				for(int j=2; j<=i; j++){
					ans[j] = max(ans[j], prime_f[i][j]);
				}
			}
		}
		print(ans);
	}
}
