#include<stdio.h>
#include<string>

int main(void){
	long long N, K, cnt=0, match=0;
	std::string ans;
	scanf("%lld %lld", &N, &K);
	while(N){
		if(K>=N-1){
			cnt++;
			ans += '(';
			K-=N-1;
			N--;
		}
		else{
			ans += "()";
//			printf("()");
//			match++;
			N--;
		}
	}
	if(K){
		printf("Impossible");
		return 0;
	}
//	for(int i=0; i<cnt; i++) printf("(");
	printf("%s", ans.c_str());
	while(match--) printf("()");
	while(cnt--) printf(")");
}
