#include<stdio.h>
#include<math.h>

int main(void){
	int N, ans=0;
	double prev=0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		double x;
		scanf("%lf", &x);
		if(prev) ans += floor(x);
		else ans += floor(x+0.5);
		prev += x;
	}
	printf("%d",ans);
}
