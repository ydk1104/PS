#include<stdio.h>
#include<vector>

int main(void){
	int N, M;
	std::vector<int> v;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++) v.push_back(i);
	int now = -1;
	printf("<");
	for(int i=0; i<N; i++){
		now = (now+M)%(v.size());
		printf("%d", v[now]);
		v.erase(v.begin()+now--);
		printf("%s", i==N-1 ? "" : ", ");
	}
	printf(">");
}
