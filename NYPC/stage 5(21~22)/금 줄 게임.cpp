#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

int edge[501][501];
int node[501];
int N, M;

int compare(const void *pa, const void *pb){
	int *a = (int*) pa;
	int *b = (int*) pb;
	return *a>*b;
}

int BT(int check[], int now, int cnt){
	if(now==N+1){
		if(cnt==0 || cnt==N) return 0;
		int ans = 0;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				if(check[i] == check[j]) ans+=edge[i][j];
			}
		}
		for(int i=1; i<=N; i++){
			if(node[i] == 0) ans++;
		}
		ans -= (N-3);
		return ans;	
	}
	int ans1 = BT(check, now+1, cnt);
	check[now]++;
	int ans2 = BT(check, now+1, cnt+1);
	check[now]--;
	return max(ans1, ans2);
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		edge[x][y]++;
		node[x]++;
		node[y]++;
	}
/*	qsort(edge, 501*501, sizeof(int), compare);
	int ans = 0; 
	for(int i=500; 500-i<N-2; i--){
		ans += edge[500][i];
		
	} */
/*	qsort(node+1, N, sizeof(int), compare);
	int ans = 0;
	for(int i=2; i<=N; i++){
		if(node[i]==0) ans++;
	}
	if(N==2) printf("0");
	else printf("%d", ans+M-node[1]-N+3); */
	int check[501] = {0, };
	int ans = 0;
	if(N<=10) ans = BT(check, 1, 0);
	qsort(node+1, N, sizeof(int), compare);
	if(N>10) ans = M-node[1]-N+3;
//	if(N==2) printf("0");
	else printf("%d", ans);
}
