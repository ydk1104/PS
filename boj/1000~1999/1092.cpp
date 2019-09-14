#include<stdio.h>
#include<algorithm>

int a[51], b[10001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	int M;
	scanf("%d", &M);
	for(int i=0; i<M; i++) scanf("%d", &b[i]);
	std::sort(a, a+N);
	std::sort(b, b+M);
	if(a[N-1] < b[M-1]){
		printf("-1");
		return 0;
	}
	int ans=0;
	while(M){
		int right = M-1;
		for(int i=N; i>0; i--){
			while(right>=0 && ((a[i-1] < b[right]) || !b[right])) right--;
			if(right>=0 && (a[i-1]>=b[right]))b[right--] = 0;
		}
		while(M && !b[M-1]) M--;
		ans++;
	}
	printf("%d",ans);
}
