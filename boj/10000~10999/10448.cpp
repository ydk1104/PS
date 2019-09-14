#include<stdio.h>

int main(void){
	int tri[100] = {0, };
	for(int i=1; tri[i-1]<=1000; i++){
		tri[i] = tri[i-1] + i;
	}
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int K;
		scanf("%d", &K);
		int i = 1;
		for(; tri[i]!=0 && tri[i]<K; i++){
			for(int j=1; tri[j]!=0 && tri[i]+tri[j]<K; j++){
				for(int k=1; tri[k]!=0; k++){
					if(tri[i] + tri[j] + tri[k] == K){
						printf("1\n");
						i = j = k = -1;
					}
					else if(tri[i] + tri[j] + tri[k] > K){
						break;
					}
				}
			}
		}
		if(i!=0){
			printf("0\n");
		}
	}
}
