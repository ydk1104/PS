#include<stdio.h>

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int N;
		scanf("%d", &N);
		int ans = 0;
		for(int i=1; i<=N; i++){
			int c1, c2, r;
			scanf("%d %d %d", &c1, &c2, &r);
			int d1 = (c1-x1) * (c1-x1) + (c2-y1) * (c2-y1);
			int d2 = (c1-x2) * (c1-x2) + (c2-y2) * (c2-y2);
			r = r * r;
			if((d1>r) ^ (d2>r)){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
}
