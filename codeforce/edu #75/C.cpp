#include<stdio.h>
#include<queue>
#include<algorithm>

char s[300001];

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		scanf("%s", &s);
		int min[10], check=-1;
		std::queue<std::pair<char, int> > q;
		for(int j=0; j<=9; j++) min[j] = 500000;
		for(int i=0; s[i]; i++){
			s[i] -= '0';
			if(check == s[i]%2){
				min[s[i]] = std::min(min[s[i]], i);
			}
			else{
				int temp = 500000;
				for(int j=s[i]+1; j<=9; j++){
					temp = std::min(temp, min[j]);
				}
				if(temp<=i){
					for(int j=s[i]; j>=0; j--) min[j] = 500000;
					q.push({s[i]+48, temp});
//					min[s[i]] = 500000;
//					min[s[i-1]-'0'] = i-1;
//					check = s[i-1]%2;
					s[i]=-1;
				}
				else{
					for(int j=0; j<=9; j++) min[j] = 500000;
					min[s[i]] = i;
					check = s[i]%2;
				}
			}
			s[i] += '0';
		}
		for(int i=0; s[i]; i++){
//			if(s[i]<'0') continue;
			while(!q.empty() && q.front().second == i){
				printf("%c", q.front().first);
				q.pop();
			}
			if(s[i]>='0') printf("%c", s[i]);
		}
		printf("\n");
	}
}
