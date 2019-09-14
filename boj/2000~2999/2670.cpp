#include<stdio.h>

int main(void){
	int N;
	double a[10000];
	double ans = 1, max=0;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%lf", &a[i]);
	int left=0;
	for(int i=0; i<N; i++){
//		while(ans<1 && left<i-1) ans /= a[left++];
		if(ans<1) ans=1;
		ans *= a[i];
		if(max<ans) max=ans;
	}
	printf("%.3f", max);
}
