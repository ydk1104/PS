#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		int a[1001];
		int cnt=0;
		for(int i=1; i<=N; i++) scanf("%d", &a[i]);
		for(int i=1; i<=N; i++){
			int temp = i;
			if(a[temp]) cnt++;
			while(a[temp] != 0){
				int t = temp;
				temp = a[temp];
				a[t] = 0;
			}
		}
		printf("%d\n", cnt);
	}
}
