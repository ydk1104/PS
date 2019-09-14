#include<cstdio>
#include<algorithm>

using namespace std;

int N, M, a[9], ans[9];

void BT(int now, int cnt){
	if(cnt==M){
		for(int i=0; i<M; i++) printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for(int i=now+1; i<N; i++) ans[cnt++]=a[i], BT(i, cnt), ans[--cnt]=0;
	return;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	sort(a, a+N);
	BT(-1, 0);
}
