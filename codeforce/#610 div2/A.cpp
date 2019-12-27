#include<stdio.h>
#include<algorithm>

int main(void){
	int N;
	scanf("%d", &N);
	while(N--){
		int a,b,c,d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if(b<a){
			int temp = a; a = b; b = temp;
		}
		int ans = b-a;
		if(a <= c+d && c-d <= b){
			ans -= std::min(c-a, d);
			ans -= std::min(b-c, d);
		}
		printf("%d\n",ans);
	}
}
