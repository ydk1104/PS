#include<stdio.h>
#include<vector>

int main(void){
	int N;
	do{
		scanf("%d", &N);
		if(!~N) break;
		std::vector<int> v;
		int sum=0;
		for(int i=1; i<=N/2; i++){
			if(N%i==0) sum+=i, v.push_back(i);
		}
		if(sum==N){
			char oper[] = {'=', '+'};
			printf("%d ", N);
			for(auto &i : v) printf("%c %d ", oper[!!(i-1)], i);
			printf("\n");
		}
		else printf("%d is NOT perfect.\n", N);
	}while(1);
}
