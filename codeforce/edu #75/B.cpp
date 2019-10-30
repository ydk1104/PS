#include<stdio.h>

char s[60][60];

int main(void){
	int Q;
	scanf("%d", &Q);
	while(Q--){
		int N, cnt=0, check=0;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			scanf("%s", &s[i]);
			int j;
			for(j=0; s[i][j]; j++){
				if(s[i][j]=='1') cnt++;
			}
//			printf("%d\n", j);
			if(j%2) check=1;
		}
		if(!check) check = !(cnt%2);
		printf("%d\n", N-(1-check));
	}
}
