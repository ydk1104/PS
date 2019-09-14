#include<stdio.h>
#include<vector>

std::vector<std::pair<int, int> > v[500001];
char s[500001], P[500001];
int fail[500001];
int dp[500001][26];
int ans;

void __init__(){
	dp[0][P[0]-'a'] = 1;
	for(int i=1, j=0; P[i]; i++){
		while(j && P[i] != P[j]) j = fail[j-1];
		if(P[i] == P[j]) fail[i] = ++j;
		for(int k=0; k<26; k++){
			if(k==P[i]-'a') dp[i][k] = i+1;
			else dp[i][k] = dp[fail[i-1]][k];
		}
	}
}

void dfs(int now, int cnt, int cmp, char *S){
	for(auto i:v[now]){
		int temp = cmp;
		int tcnt = cnt;
		char *ctemp = S;
		S[cnt++] = i.second;
		if(~dp[cmp][S[cmp]-'a']){
			int temp = dp[cmp][S[cmp]-'a'];
			if(temp<0){
				S += cmp - temp;
				cnt -= cmp - temp;
			}
			cmp = temp;
		}
		else{
			int* temp = &dp[cmp][S[cmp]-'a'];
			while(cmp && S[cmp] != P[cmp]){
			S += cmp-fail[cmp-1];
			cnt -= cmp-fail[cmp-1];
			cmp = fail[cmp-1];
			}
			*temp = cmp;
		}
//		if(S[cmp] == P[cmp]) cmp++;
//		else{S += cnt, cnt=0;}
		if(!P[cmp]){
			ans++;
			dfs(i.first, cnt-cmp+fail[cmp-1], fail[cmp-1], S+cmp-fail[cmp-1]);
		}
		else dfs(i.first, cnt, cmp, S);
		S[--cnt] = 0;
		cnt = tcnt;
		cmp = temp;
		S = ctemp;
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<N; i++){
		int x, y;
		char z;
		scanf("%d %d %c\n", &x, &y, &z);
		v[x].push_back({y, z});
	}
	scanf("%s", &P);
	__init__();
	dfs(1, 0, 0, s);
	printf("%d", ans);
}
