#include<stdio.h>
#include<math.h>

int main(void){
	int N, arr[5] = {0, 1, 1, 2, 2};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int a,b;
		scanf("%d %d", &a, &b);
		int x = abs(a-b);
		int ans = x/5;
		x %= 5;
		printf("%d\n", ans+arr[x]);
	}
	return 0;
}
