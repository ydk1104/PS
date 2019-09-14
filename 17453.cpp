#include<stdio.h>
#include<vector>

char map[101];
char s[21][101];
std::vector<int> v[201];
int N, M;

void BT(int now, int cnt, int ans[]){
	if(now==M){
		int temp=N;
		for(int i=0; i<N; i++){
			temp += map[i];
		}
		if(v[temp].size()==0){
			v[temp].push_back(cnt);
			for(int i=0; i<cnt; i++) v[temp].push_back(ans[i]);
		}
		return;
	}
	BT(now+1, cnt, ans);
	ans[cnt++] = now+1;
	for(int i=0; i<N; i++){
		map[i] *= s[now][i];
	}
	BT(now+1, cnt, ans);
	ans[--cnt] = 0;
	for(int i=0; i<N; i++){
		map[i] *= s[now][i];
	}
}

int main(void){
	scanf("%d %d", &N, &M);
	scanf("%s", map);
	for(int i=0; map[i]; i++){
		map[i] -= '0';
		if(map[i]) continue;
		map[i]--;
	}
	for(int i=0; i<M; i++){
		scanf("%s", &s[i]);
		for(int j=0; s[i][j]; j++){
			s[i][j] -= '0';
			if(s[i][j]) s[i][j]=-1;
			else s[i][j] = 1;
		}
	}
	int arr[21] = {0,};
	BT(0, 0, arr);
	for(int i=0; i<N*2+1; i++){
		if(v[i].size()==0){
			printf("-1");
		}
		else{
			for(auto j:v[i]) printf("%d ",j);
		}
		printf("\n");
	}
}
