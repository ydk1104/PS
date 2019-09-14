#include<stdio.h>
#define ll long long int

ll N, M;
int BT(ll now){
	if(now>M) return 0;
	int cnt=0;
	if(now>=N && now<=M) cnt++;
	cnt += BT(now*10+4);
	cnt += BT(now*10+7);
	return cnt;
}

int main(void){
	scanf("%lld %lld", &N, &M);
	int sum = BT(0);
	printf("%d", sum);
}
