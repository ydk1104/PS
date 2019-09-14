#include<stdio.h>

int cnt(int N, int a){
	int ans = 0;
	while(N>0){
		ans += N%a;
		N /= a;
	}
	return ans;
}

int main(void){
	for(int i=1000; i<10000; i++){
		if((cnt(i,10) == cnt(i,12))&&(cnt(i,10) == cnt(i,16))){
			printf("%d\n", i);
		}
	}
}
