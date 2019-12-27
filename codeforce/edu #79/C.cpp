#include<stdio.h>

int order[100001];
int send[100001];
int num_order[100001];
int num_send[100001];

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		int N, M;
		scanf("%d %d", &N, &M);
		long long ans = 0;
		for(int i=0; i<N; i++) scanf("%d", order+i), num_order[order[i]] = i+1;
		for(int i=0; i<M; i++) scanf("%d", send+i);
		int max = 0, sum = 0;
		for(int i=0; i<M; i++){
			if(num_order[send[i]] < max){
				ans++;
			}
			else{
				max = num_order[send[i]];
				ans += num_order[send[i]] * 2 - 1;
				ans -= i*2;
			}
		}
		
		printf("%lld\n", ans);
	}
}
