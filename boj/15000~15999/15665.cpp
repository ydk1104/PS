#include<stdio.h>
#include<algorithm>

int N, M, a[9], cnt, ans[9];

void BT(int now){
	if(cnt==M){
		for(int i=0; i<M; i++) printf("%d ",ans[i]);
		printf("\n");
		return;
	}
	for(int i=now; i<N; i++){
		while(i>now && a[i]==a[i-1]) i++;
		if(!a[i]) return;
		ans[cnt++] = a[i];
		BT(i);
		ans[--cnt] = 0;
	}
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	std::sort(a, a+N);
	BT(0);
}
