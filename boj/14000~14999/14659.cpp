#include<stdio.h>

int main(void){
	int N;
	scanf("%d", &N);
	int prev = -1, row = 0, ans = 0;
	for(int i=0; i<N; i++){
		int x;
		scanf("%d", &x);
		if(x>prev){
			prev = x;
			row = 0;
		}
		else{
			row++;
			ans = ans>row?ans:row;
		}
	}
	printf("%d", ans);
}
