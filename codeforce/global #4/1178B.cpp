#include<stdio.h>
#include<vector>

int main(void){
	char s[1000001];
	scanf("%s", &s);
	long long check=0, cnt=0, ans=0;
	std::vector<int> v;
	for(int i=1; s[i]; i++){
		if(s[i]=='v' && s[i-1]=='v'){
			ans += check;
			cnt++;
		}
		if(s[i]=='o'){
			check += cnt;
		}
	}
	printf("%lld", ans);
}
/*
vvovooovovvovoovoovvvvovovvvov
1 (1 3 1)1 (1 2 2)3 (1 1)2
1*5*1 + 1*10*3 + 1*12*2 = 59 == 1*(5*(1+3+2)) + 1*(5*(3+2)) + 1*(2*2);
1*5*3 + 1*7*2 = 29 == (1*5*(3+2)) + 1*(2*2);
3*2*2 = 12

5*1+15*3+25*2 */
