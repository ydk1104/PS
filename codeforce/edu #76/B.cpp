#include<stdio.h>

char print_ans[2][5] = {"YES", "NO"};

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		long long a,b;
		scanf("%lld %lld", &a, &b);
		int ans=0;
		if(a<=3){
			if(a==1 && b>=2) ans = 1;
			if(a>=2 && b>=4) ans = 1;
		}
		printf("%s\n", print_ans[ans]);
	}
}
