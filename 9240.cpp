#include<stdio.h>
#include<math.h>

double a[100001], b[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%lf %lf", &a[i], &b[i]);
	}
	double x=a[1], y=b[1], ans=0;
	for(int cnt=0; cnt<10; cnt++){
		double dis=0, nx=a[1], ny=b[1];
		for(int i=0; i<N; i++){
			if(dis < hypot(a[i]-x, b[i]-y)) dis = hypot(a[i]-x, b[i]-y), nx=a[i], ny=b[i];
		}
		x=nx, y=ny;
		if(ans<dis) ans=dis;
	}
	printf("%.10f", ans);
}
