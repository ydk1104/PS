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
	ll row=0;
	ll aba=a+b+a;
	for(int i=0; i<=aba; i++){
		printf("%d ", ans[i]);
		check[ans[i]]++;
		while(check[row]) row++;
		A[i]=row;
		sum+=A[i];
		if(i==N){
			printf("%lld", sum);
			return 0;
		}
//		if(i>0 && row==i+1){
//			sum+=(N-i)*(N+i+3)/2;
//			break;
//		}
	}
	ll cha = A[aba]-A[0];
	sum -= A[aba];
//	printf("%lld\n", sum);
	sum = sum *(N/(aba)) + ((N/aba)-1)*(N/(aba)) * aba*cha/2; //(N/(a+b+a) + (N/a+b+a) + 1)/2;
//	printf("%lld\n", sum);
	sum += cha*((N/aba))*(N%aba+1);
//	printf("%lld\n", sum);
	N%=aba;
	for(int i=0; i<=N; i++) sum+=A[i];
//	printf("\n");
//	for(int i=0; i<=N; i++){printf("%d ", A[i]);}
	printf("%lld", sum);
}
