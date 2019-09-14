#include<stdio.h>
#include<string>

using namespace std;

string operator +(string a, string b){
	string c;
	for(int i=0; i<=1000; i++) c.push_back(0);
	int len = a.length() > b.length() ? a.length() : b.length();
	for(int i=0; i<len; i++){
		int plus = a[i] + b[i];
		if((!a[i]) && (!b[i])) break;
		if(a[i]) plus -= '0';
		if(b[i]) plus -= '0';
//		printf("plus : %d \n", plus);
		if(!c[i]) plus += '0';
		c[i] += plus;
		int now = i;
		while(c[now]>'9'){
			int temp = (c[now]-'0')/10;
			c[now] -= temp*10;
			now++;
			if(!c[now]) c[now]+='0';
			c[now] += temp;
		}
	}
//	printf("%s %s %s\n", a.c_str(), b.c_str(), c.c_str());
	return c;
}

void print(string s){
	for(string::iterator i = s.end(); i > s.begin(); i--){
		if(*(i-1) == 0) continue;
		printf("%c", *(i-1));
	}
	printf("\n");
}

int main(void){
	int N;
	string dp[251] = {"1", "1", };
	for(int i=2; i<=250; i++){
		dp[i] = dp[i-1] + dp[i-2] + dp[i-2];
	}
	while(scanf("%d", &N) != -1){
		print(dp[N]);
	}
}
