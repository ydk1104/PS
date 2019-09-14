#include<stdio.h>

int gcd(int a, int b){
	return b?gcd(b,a%b):a;
}

int main(void){
	#define int long long
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if(b>c){
        b^=c;
        c^=b;
        b^=c;
    }
    if(b==1 || c==1) printf("%d", a);
    else if((b/gcd(b,c)-1) * (c/gcd(b,c)-1) * gcd(b,c) <= a) printf("%d", (a-1)/gcd(b,c)*gcd(b,c)+gcd(b,c));
    else{
        int ans = (a+b-1)/b*b;
        int i=0;
        for(; i<=a; i+=c){
            int temp = (a-i+b-1)/b*b+i;
            if(ans>temp) ans=temp;
        }
        if(ans>i) ans=i;
        printf("%d",ans);
    }
}
