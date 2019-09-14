#include<stdio.h>
#include<math.h>
#define min2(a,b) a<b ? a : b

int mak[10] = {64, };

int find(int N, int cnt){
	if(mak[0] == N){
		int sum = 0;
		for(int i=1; i<=7; i++){
			sum += mak[i];
		}
		return sum;
	}
	int min = 7;
	for(int i=7; i>0; i--){
		if(mak[i] != 0){
			min = min2(min, i);
		}
	}
	mak[min] --;
	mak[min-1] += 2;
	int t = pow(2, min-2);
	if(N <= mak[0] - t){
		mak[min-1] --;
		mak[0] -= t;
	}
	return find(N, cnt);
}

int main(void){
	int N;
	mak[7] = 1;
	scanf("%d", &N);
	printf("%d", find(N, 0));
}
