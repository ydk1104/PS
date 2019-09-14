#include<stdio.h>

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	if(N%2==0 && M%2==0) printf("NO");
	else{
		printf("YES\n");
		int now=2, go=-1;
		if(M%2==0) go=1;
		int ans = (N-2)*(M-1)/2;
		if(M%2==0) ans = (N-2)*(1+N-M)/2;
		printf("%d\n", ans);
		for(int i=1; i!=M; i=(i-go*2-1+N)%N+1){
			for(int j=1; j<=N-2; j++){
				printf("%d ", now);
				now += go;
				if(now>N) now-=N;
				if(now<=0) now+=N;
			}
		}
	}
}
