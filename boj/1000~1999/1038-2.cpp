#include<stdio.h>

int nCr[13][13];

int com(int n, int r){
	if(nCr[n][r] != 0) return nCr[n][r];
	if(n<=r) return nCr[n][r] = 1;
	if(r==0) return nCr[n][r] = 1;
	return nCr[n][r] = com(n-1, r-1) + com(n-1, r);
} 

void find(int d, int N, int a[10], int max){
	int i = 0;
	if(N==0) return;
	while(d>=com(max, N-1)){
		d -= com(max, N-1);
		max--;
		if(max==0) break;
	}
	a[max] = 1;
	return find(d, N-1, a, max-1);
}

int main(void){
	int N;
	scanf("%d", &N);
	N+=2;
	int i = 0;
	int cnt = 0;
	while((cnt<N) && (i<11)){
		cnt += com(10, i);
		i++;
	}
	if(cnt<N){
		printf("-1");
	}
	else{
		i--;
		int a[10] = {0, };
		find(cnt-N, i, a, 9);
		for(int i=9; i>=0; i--){
			if(a[i] == 1) printf("%d", i);
		}
	}
	return 0;
}
