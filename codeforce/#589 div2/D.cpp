#include<stdio.h>
#include<vector>

std::vector<int> v[100001];
int ans[100001];

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int x,y;
		scanf("%d %d", &x, &y);
		x--; y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	int min = 0, cnt=0;
	for(int i=1; i<=3; i++){
		int check[100001] = {0, }, count=0;
		while(min<N && ans[min]) min++;
		if(min==N){
			printf("-1");
			return 0;
		}
		for(auto j:v[min]) check[j]++, count++;
		for(int j=0; j<N; j++){
			if(check[j]){
				if(ans[j] == i){
					printf("-1");
					return 0;
				}
				continue;
			}
			if(ans[j]){
				printf("-1");
				return 0;
			}
//			printf("t : %d %d\n", v[j].size(), count);
			if(v[j].size() != count){
				printf("-1");
				return 0;
			}
			ans[j] = i;
			cnt++;
		} 
	}
	for(int i=0; i<N; i++){
		for(auto j:v[i]){
			if(ans[i]==ans[j]){
				printf("-1");
				return 0;
			}
		}
	}
	if(cnt!=N){
		printf("-1");
		return 0;
	}
	for(int i=0; i<N; i++) printf("%d ",ans[i]);
}
