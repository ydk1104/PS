#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> v[1001];
vector<int> Next[1001];
int start[1001];
int cnt[1001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		start[y]++;
		v[y].push_back(x);
	}
	for(int i=N; i>0; i--){
		for(auto j:v[i]){
			cnt[j] = cnt[i]+1;
			if(start[j]==0) Next[j].push_back(i);
		}
	}
	int ans = N+M+1;
	for(int i=1; i<=N; i++){
		int temp=0, flag=0;
		if(start[i]==0){
//			printf("%d\n",i);
			
			for(auto j:Next[i]){
				temp += cnt[j]%2==0;
				flag += cnt[j]%2==1;
			}
			if(flag) ans = min(temp,ans);
		}
	}
	printf("%d\n",ans==N+M+1 ? -1 : ans);
//	for(int i=1; i<=N; i++) printf("%d ", cnt[i]);
}
