#include<stdio.h>

int N, M, a[21], ans;
void BT(int num, int sum){
	if(num==N){
		if(sum == M) ans++;
		return;
	}
	BT(num+1, sum);
	BT(num+1, sum+a[num]);
	return;
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	BT(0, 0);
	if(M==0) ans--;
	printf("%d", ans);
}
