#include<stdio.h>

int back(int x){
	int temp = 0;
	while(x){
		temp *= 10;
		temp += x%10;
		x /= 10;
	}
	return temp;
}

int main(void){
	int N;
	scanf("%d", &N);
	if(N%9){
		printf("-1");
		return 0;
	}
	int temp = N;
	while(temp>=0 && temp<=N*100){
		if(temp-back(temp) == N) break;
		temp++;
//		printf("%d %d\n", temp, temp-back(temp));
	}
	if(temp-back(temp)==N)printf("%d", temp);
	else printf("-1");
}
