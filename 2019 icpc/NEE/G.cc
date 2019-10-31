#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define pii pair<int,int>
 
vector<pii> ans;
vector<int> Trash;
int cnt[1005];
 
int main(void){
	int N;
	scanf("%d",&N);
	for(int i=1;i<N;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		cnt[a]++;
		cnt[b]++;
	}
	if(cnt[N]!=N-1){
		printf("NO"); return 0;
	}
 
	for(int i=1;i<=N;i++){
		if(cnt[i]==0)
			Trash.push_back(i);
	}
	sort(Trash.begin(),Trash.end());
	reverse(Trash.begin(),Trash.end());
	int Tsiz = Trash.size();
	int Tnum = 0;
 
	for(int i=N-1;i>=1;i--){
		if(cnt[i]==0)
			continue;
		int Now = i;
		while(cnt[i]>=1){
			cnt[i]--;
			if(cnt[i]==0) ans.push_back({Now,N});
			else{
				if(Tnum==Tsiz){
					printf("NO"); return 0;
				}
				int x = Trash[Tnum]; Tnum++;
				if(i<x){
					printf("NO");
					return 0;
				}
				ans.push_back({Now,x});
				Now = x;
			}
		}
	}
	int asiz = ans.size();
	printf("YES\n");
	for(int i=0;i<asiz;i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
 
}
