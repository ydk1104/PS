#include<stdio.h>
#include<stack>

char s[100001];

int main(void){
	int N;
	scanf("%d", &N);
	int cnt=0;
	while(N--){
		scanf("%s", s);
		std::stack<char> stk;
		for(int i=0; s[i]; i++){
			if(stk.empty()) stk.push(s[i]);
			else{
				if(stk.top() == s[i]) stk.pop();
				else stk.push(s[i]);
			}
		}
		while(!stk.empty()){
			char prev = stk.top(); stk.pop();
			if(stk.empty() || stk.top() != prev) goto v;
			stk.pop();
		}
		cnt++;
		v:;
	}
	printf("%d\n", cnt);
}
