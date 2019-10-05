#include<stdio.h>

using ll = long long;
int a[20];
int ans;
int N, W;

/*void BT(int now, ll cnt, ll money){
	if(now == N){
		if(ans < money) ans = money;
		return;
	}
	BT(now+1, cnt, money);
	BT(now+1, cnt, )
} // */

int main(void){
	scanf("%d %d",&N, &W);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	int type = 0;
	a[N] = -1;
	long long money = W, cnt = 0;
	for(int i=0; i<N; i++){
//		printf("%d %d %d %d\n", type, money, cnt, a[i]);
		if(type){
			if(a[i] <= a[i+1]) continue;
			money += cnt * a[i];
			cnt = 0;
		}
		else{
			if(a[i] >= a[i+1]) continue;
			cnt += money/a[i];
			money -= money/a[i]*a[i];
		}
		type = 1-type;
	}
	printf("%lld\n", money);
}
