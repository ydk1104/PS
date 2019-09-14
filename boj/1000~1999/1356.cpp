#include<stdio.h>

typedef long long int ll;

int product(ll x){
	int temp = 1;
	if(x==0) return 0;
	while(x>0){
		temp *= x%10;
		x /= 10;
	}
	return temp;
}

int main(void){
	char s[100];
	scanf("%s", &s);
	int flag = 0;
	for(int i=1; s[i]!=0; i++){
		int t1 = 1;
		for(int j=0; j<i; j++){
			t1 *= s[j]-'0';
		}
		int t2 = 1;
		for(int j=i; s[j]!=0; j++){
			t2 *= s[j]-'0';
		}
		if(t1 == t2) flag = 1;
	}
	if(flag) printf("YES");
	else printf("NO");
}
