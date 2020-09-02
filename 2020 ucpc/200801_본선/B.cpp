#include<stdio.h>
#include<vector>
#include<algorithm>

char map[26][200010];
std::vector<int> v[200010];
int l[200010];
int r[200010];

int main(void){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<K; i++){
		scanf("%s", map+i);
		for(int j=0; map[i][j]; j++){
			if(map[i][j] == 'U') v[i].push_back(j);
		}
		l[i] = r[i] = v[i].size()-1;
	}
	char s[200010];
	scanf("%s", s);
	int left = M-2, right = M-1;
	long long ans = 0;
	for(int len=N; len--;){
		int now = s[len] - 'A';
//		char* p = map+now;
		
		if(len != N-1){
			while(~r[now] && v[now][r[now]] > right){
				r[now]--;
			}			
			if(r[now] == -1){
				break;
			}
			right = v[now][r[now]];
			if(right <= left){
				break;
			}
		}
		
		while(~l[now] && v[now][l[now]] > left){
			l[now]--;
		}
		
		
		if(l[now] == -1){
			left = -1;
		}
		else{
			left = v[now][l[now]];
		}
		ans += right - left;
	}
	
	printf("%lld", ans);
}
