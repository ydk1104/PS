#include<stdio.h>
#define min(a,b) (r[a]<r[b]) ? a : b

int main(void){
	int x[6];
	int y[6];
	int r[6];
	int ans = 1;
	for(int i=0; i<6; i++){
		scanf("%d %d", &x[i], &y[i]);
		if(i==0){
			scanf("%d", &r[0]);
			r[0] *= r[0];
		}
		else{
			r[i] = (x[i] - x[0]) * (x[i] - x[0]);
			r[i] += (y[i] - y[0]) * (y[i] - y[0]);
			ans = min(ans, i);
		}
	}
	if(min(0, ans)){
		printf("%d", ans);
	}
	else{
		printf("-1");
	}
	return 0;
} 
