#include<stdio.h>

int main(void){
	int A, B, C, D, E, ans=0;
	scanf("%d\n%d\n%d\n%d\n%d", &A, &B, &C, &D, &E);
	if(A<0){
		ans = (-A)*C+D;
		A = 0;
	}
	ans += (B-A)*E;
	printf("%d",ans);
}
