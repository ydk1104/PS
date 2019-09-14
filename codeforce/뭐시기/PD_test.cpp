#include<stdio.h>
#define ll long long
#define max 500000

ll ans[max+1];
ll check[max+1];
ll A[max+1];
ll stack[max+1];
ll cnt, count, sum;

void push(ll x){stack[cnt++] = x;}
ll pop(void){return stack[--cnt];}

int main(void){
	ll N, a, b;
	scanf("%lld %lld %lld", &N, &a, &b);
	push(0);
	while(cnt){
		ll temp = pop();
		while(cnt&&ans[temp]) temp=pop();
		if(temp>b && !ans[temp-b]) push(temp-b), ans[temp-b]=ans[temp]+1;
		if(temp+a<max && !ans[temp+a]) push(temp+a), ans[temp+a]=ans[temp]+1;
	}
	int row=0;
	for(int i=0; i<=N; i++){
//		printf("%d ", ans[i]);
		check[ans[i]]++;
		while(check[row]) row++;
		A[i]=row;
		sum+=A[i];
//		if(i>0 && row==i+1){
//			sum+=(N-i)*(N+i+3)/2;
//			break;
//		}
	}
	ll cha = A[a+b+a]-A[0];
//	printf("\n");
//	for(int i=0; i<=N; i++){printf("%d ", A[i]);}
	printf("%lld", sum);
}
