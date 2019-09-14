#include<stdio.h>
#include<algorithm>

using namespace std;

int a[2001];

int main(void){
	int N, M, now=1;
	scanf("%d %d", &N, &M);
	if(N%2==0 && M%2==0){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	if(M%2==0) M+=N;
	printf("%d\n", (N-2)*(M/2));
	for(int i=1; i<=N; i++) a[i-1] = i;
	for(int t=1; t<=(N-2)*(M/2); t++){
//		swap(a[(now-2+N)%N], a[(now-1+N)%N]);
//		swap(a[(now+2)%N], a[(now+1)%N]);
		printf("%d ",now+1);
		now = (now+N-1)%N;
	}
//	printf("\n");
//	for(int i=0; i<N; i++) printf("%d ",a[i]);
}
