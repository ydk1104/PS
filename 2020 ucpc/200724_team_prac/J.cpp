#include<stdio.h>

int x[2010];
int y[2010];
int xj, yj;

bool go(long long now){
	double a = ((double)yj - (double)now) / (double)xj;
//	printf("%lld %lf\n", now, a);
	for(int i=0; x[i]<xj; i++){
//		printf("%f %lld %d %d %lf\n", a, now, x[i], y[i], a*x[i]+now);
		if((long long)(a*x[i] + now) < y[i]) return false;
	}
	return true;
}

int main(void){
	int N;
	scanf("%d", &N);
	int type = 1;
	for(int i=0; i<N*2; i++){
		scanf("%d", &x[i]);
		if(i){
			y[i] = y[i-1] + (x[i] - x[i-1]) * type;
			type *= -1;
		}
	}
	x[2*N] = 1e9;
	scanf("%d", &xj);
	for(int i=0; i<N*2; i++){
		if(x[i] < xj && xj <= x[i+1]){
			yj =  y[i] + (y[i+1] - y[i]) / (x[i+1] - x[i]) * (xj - x[i]);
			break;
		}
	}
	long long l=0, r=1e15, mid=(l+r)/2;
	while(l<r-2){
		if(go(mid)){
			r = mid;
		}
		else{
			l = mid+1;
		}
		mid = (l+r)/2;		
	}
	for(long long i=mid-2; i<=mid+2; i++){
		if(i < 0) continue;
		if(go(i)){
			printf("%lld", i);
			break;
		}
	}
	return 0;
}
