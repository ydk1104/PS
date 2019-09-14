#include<stdio.h>
#include<algorithm>

using namespace std;

int a[2], b[2];

int main(void){
	int N, M, x;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%d", &x), a[x%2]++;
	for(int j=1; j<=M; j++) scanf("%d", &x), b[x%2]++;
	printf("%d", min(a[0],b[1])+min(b[0],a[1]));
}
