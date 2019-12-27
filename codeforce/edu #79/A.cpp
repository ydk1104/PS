#include<stdio.h>
#include<algorithm>

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		int a[3];
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		std::sort(a, a+3);
		printf("%s\n", a[2] > a[0] + a[1] + 1 ? "No" : "Yes");
	}
}
