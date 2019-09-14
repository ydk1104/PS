#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int gcd(int x, int y){
	return y ? gcd(y,x%y) : x;
}

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int N, L;
		scanf("%d %d", &N, &L);
		int a[101], check[10001]={0}, prime[10001]={0,}, ans[101], cnt=0;
		scanf("%d", &a[1]);
		for(int i=2; i<=L; i++){
			scanf("%d", &a[i]);
			int x = gcd(a[i], a[i-1]);
			if(x==a[i]) x = (int)sqrt(x);
			if(i==2) ans[i-2]=a[1]/x;
			ans[i-1] = x;
			if(i==L) ans[i] = a[i]/x;
		}
		for(int i=0; i<=L; i++){
			if(!check[ans[i]]) prime[cnt++] = ans[i], check[ans[i]] = 1;
		}
		sort(prime, prime+cnt);
		for(int i=0; i<cnt; i++){
			check[prime[i]] = 'A'+i;
		}
		printf("Case #%d: ", t);
		for(int i=0; i<=L; i++) printf("%c",check[ans[i]]);
		printf("\n");
	}
}
