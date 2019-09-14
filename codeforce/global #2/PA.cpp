#include<stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))

int a[300001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &a[i]);
	}
	int left = 1, right=N;
	while(a[1] == a[left]) left++;
	while(a[N] == a[right]) right--;
	int ans=0;
	if(a[1] != a[N]) ans=N-1;
	else ans=max(N-left, right-1);
	printf("%d", ans);
}
