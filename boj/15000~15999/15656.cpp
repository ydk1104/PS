#include<stdio.h>
#include<algorithm>

int a[9];
int N, M;
void BT(int now, int cnt, int ans[]){
	if(cnt == M){
		for(int i=0; i<M; i++) printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for(int i=0; i<N; i++){
		ans[cnt++] = a[i];
		BT(i, cnt, ans);
		ans[--cnt] = 0;
	}
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	std::sort(a, a+N);
	int ans[9] = {0, };
	BT(0, 0, ans);
}
