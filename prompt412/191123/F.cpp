#include<stdio.h>

int a[1001], b[1001], check[1001];

int main(void){
	int N, K;
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		scanf("%d", &a[i]);
	}
	int left = 0;
	int sys_test = 0;
	int ans=0;
	while(left < N){
		int temp=0;
		for(int i=left; i<left+K; i++){
			b[i]++;
			if(b[i]==a[i]) temp++;
			if(!check[i] && b[i]==sys_test) ans += check[i]=1;
		}
		left += temp;
		sys_test = (int)((double)N/left);
	}
	printf("%d", ans);
}

//3 2 1 100 40
// maybe 2
