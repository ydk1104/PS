#include<stdio.h>
#include<stack>

char s[200011];

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		std::stack<int> stk[2];
		int N;
		scanf("%d",&N);
		scanf("%s", s+1);
		stk[0].push(0);
		for(int i=1; s[i]; i++){
			while(!stk[0].empty() && s[stk[0].top()] > s[i]){
//				printf("%d\n", stk[0].top());
				stk[1].push(stk[0].top());
				stk[0].pop();
			}
			stk[0].push(i);
		}
		while(!stk[0].empty()){
			s[stk[0].top()] = '1'; stk[0].pop();
		}
		int prev = '9';
		while(!stk[1].empty()){
//			printf("%d\n", stk[1].top());
			int now = stk[1].top();
			if(prev < s[now]){
				printf("-");
				goto v;
			}
			prev = s[now];
			s[now] = '2';
			stk[1].pop();
		}
		printf("%s",s+1);
		v:
		printf("\n");
		s[0] = 0;
	}
}
