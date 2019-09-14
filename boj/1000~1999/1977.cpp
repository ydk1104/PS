#include<stdio.h>
#include<math.h>

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	int ans = -1;
	int sum = 0;
	for(int i=1; i*i<=M; i++){
		if(i*i>=N){
			sum += i*i;
			if(ans==-1){
				ans = i*i;
			}
		}
	}
	if(ans==-1){
		printf("-1");
	}
	else{
		printf("%d\n%d", sum, ans);
	}
}
