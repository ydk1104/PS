#include<stdio.h>

int diff(int x){
	int cnt[10] = {0, };
	while(x){
		if(cnt[x%10]) return 0;
		cnt[x%10]++;
		x/=10;
	}
	return 1;
}

int main(void){
	int l,r;
	scanf("%d %d", &l, &r);
	for(int i=l; i<=r; i++){
		if(diff(i)){
			printf("%d", i);
			return 0;
		}
	}
	printf("-1");
	return 0;
}
