#include<stdio.h>
#include<math.h>
#include<algorithm>

int a[500001], b[500011];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int x,y;
	scanf("%d %d", &x, &y);
	for(int i=0; i<N; i++) scanf("%d", a+i);
	for(int i=0; i<M; i++) scanf("%d", b+i+1);
	b[0] = -1e9; b[M+1] = 1e9;
	std::sort(a, a+N); std::sort(b+1,b+1+M);
	int left=0, right=0, ans=2e9, prev=0, cnt=0;
	while(left<N){
		while(a[left] > b[right]) right++;
		ans = std::min({ans, abs(a[left]-b[right-1]), abs(a[left]-b[right])});
		int temp = ((ans == abs(a[left]-b[right-1])) + (ans == abs(a[left]-b[right])));
		if(ans==prev) cnt+=temp;
		else prev=ans, cnt=temp;
		left++;
//		printf("%d %d %d %d %d\n", left, right, ans, cnt, temp);
	}
	printf("%d %d", ans+abs(y-x), cnt);
}
