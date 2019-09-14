#include<stdio.h>

int A, B, N, ans;

int main(void){
	scanf("%d %d %d", &A, &B, &N);
	B = A+B;
	A--;
	for(int i=2; i<B; i++){
		if(A<i) A=i;
		ans += B/i - A/i;
		long long now=1;
		for(int cnt=0; cnt<N && now<=B; cnt++) now*=i;
		ans -= B/now - A/now;
//		printf("%d %d\n", i, ans);
	}
	printf("%d", ans);
}
