#include<stdio.h>
 
int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		if(N==1) printf("-1\n");
		else{
			int last = 5;
			if(N%3==1) last = 6;
			for(int i=0; i<N-2; i++) printf("5");
			printf("%d3\n", last);
		}
	}
}
