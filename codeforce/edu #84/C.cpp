#include<stdio.h>
#include<vector>
#include<tuple>

int board[202][202];

//L : 0,-1
//R : 0,1
//D : 1,0
//U : -1,0

int dx[4] = {0,0,1,-1,}, dy[4] = {-1,1,0,0};
char arrow[5] = "LRDU";

int main(void){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	std::vector<std::pair<int, int> > st, ed;
	for(int i=0; i<K; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		st.emplace_back(x,y);
	}
	for(int i=0; i<K; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		ed.emplace_back(x,y);		
	}
	
	std::vector<char> ans;
	for(int i=1; i<N; i++) ans.push_back('U');
	for(int i=1; i<M; i++) ans.push_back('L');
	bool flag = true;
	for(int i=1; i<=N; i++){
		for(int j=1; j<M; j++){
			ans.push_back(flag ? 'R' : 'L');
		}
		flag = !flag;
		ans.push_back('D');
	}
	printf("%d\n", ans.size());
	for(auto ch : ans) printf("%c",ch);
}
