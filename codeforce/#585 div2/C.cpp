#include<stdio.h>
#include<vector>

std::vector<int> v[2];

int main(void){
	char s[2][200001];
	scanf("%*d");
	scanf("%s", &s[0]);
	scanf("%s", &s[1]);
	for(int i=0; s[0][i]; i++){
		if(s[0][i] != s[1][i]){
			v[s[0][i]-'a'].push_back(i+1);
		}
	}
	if(v[0].size()%2 != v[1].size()%2){
		printf("-1");
	}
	else{
		int ans=0;
		if(v[0].size()%2){
			ans++;
			v[0].push_back(v[1][0]);
			printf("%d\n", ans+v[0].size()/2+v[1].size()/2);
			printf("%d %d\n", v[1][0], v[1][0]);
			for(auto it=v[0].begin(); it<v[0].end(); it+=2){
				printf("%d %d\n", *it, *(it+1));
			}
			for(auto it=v[1].begin()+1; it<v[1].end(); it+=2){
				printf("%d %d\n", *it, *(it+1));
			}
		}
		else{
			printf("%d\n", ans+v[0].size()/2+v[1].size()/2);
			for(auto it=v[0].begin(); it<v[0].end(); it+=2){
				printf("%d %d\n", *it, *(it+1));
			}
			for(auto it=v[1].begin(); it<v[1].end(); it+=2){
				printf("%d %d\n", *it, *(it+1));
			}
		}
	}
}
