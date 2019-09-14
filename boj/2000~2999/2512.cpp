#include<stdio.h>
#include<algorithm>

int main(void){
	int N, M, a[10001], sum=0; scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]), sum+=a[i];
	a[N]=0; N++;
	std::sort(a, a+N);
	scanf("%d", &M);
	int r=N-1;
	if(M>=sum){
		printf("%d", a[r]);
		return 0;
	}
	while(M<sum && r>0){
		sum-=a[r]*(N-r);
		sum+=a[r-1]*(N-r);
		r--;
	}
	printf("%d\n", a[r]+(M-sum)/(N-r-1));
}
