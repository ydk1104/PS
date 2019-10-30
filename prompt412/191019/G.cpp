#include<stdio.h>

long long find_inverse(long long x, long long p){
	//find inverse x,p
	// Ix = 1(mod p)
	// Ix + py = 1(mod p)
	// so, I is answer of ax+py=1(mod p) 
	
	//naive(O(N))
	for(int i=1; i<=p; i++){
		if((x * i)%p==1) return i;
	}
}

int main(void){
	long long a,b,p,x,ans=0;
	scanf("%lld %lld %lld %lld", &a, &b, &p, &x);
	long long temp = 1;
	for(int i=1; i<p; i++){
		temp *= a;
		temp %= p;
		long long inverse = find_inverse(temp, p);
		ans += x/p + (x%p)>=inverse;
	}
//	if(b==0) ans += x/p;
	printf("%d", ans);
}
