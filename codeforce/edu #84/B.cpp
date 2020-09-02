#include<stdio.h>
#include<vector>

bool check[100001];

int main(void){
	int T;
	for(scanf("%d", &T); T--;)
	{
		int N;
		scanf("%d", &N);
		std::vector<std::vector<int>> v(N,std::vector<int>());
		for(int i=0; i<N; i++){
			int x;
			scanf("%d", &x);
			for(int j=0; j<x; j++){
				int temp;
				scanf("%d", &temp);
				v[i].push_back(temp-1);
			}
			
			check[i] = false;
		}
		int ans = -1;
		int now = 0;
		for(auto i:v){
			bool flag = false;
			for(auto j:i){
				if(!check[j]){
					check[j] = true;
					flag = true;
					break;
				}
			}
			now++;
			if(flag) continue;
			ans = now;
		}
		
		if(ans != -1){
			printf("IMPROVE\n");
			for(int i=0; i<N; i++){
				if(!check[i]){printf("%d %d\n", ans, i+1); break;}
			}
		}
		else{
			printf("OPTIMAL\n");
		}
	}
}
