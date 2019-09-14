#include<stdio.h>
#include<math.h>

int main(void){
	int N;
	scanf("%d", &N);
	int a[300001];
	double ans=1;
	for(int i=N-1; i>=0; i--) scanf("%d", a+i);
	for(int i=0; i<N; i++){
		ans = ceil(ans/a[i])*a[i];
	}
	printf("%.0f", ans);
}
