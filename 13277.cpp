#include<stdio.h>
#define ll long long
#define MAX 1000000000
#define len 30000

char a_char[300001];
char b_char[300001];
ll a[len+1];
ll b[len+1];
ll c[2*len+1];

int length(char s[]){
	int i=0;
	while(s[i]) i++;
	return i-1;
}

int main(void){
	scanf("%s %s", &a_char, &b_char);
	for(int i=0; i<=len; i++) a[i]=-1;
	for(int i=0; i<=len; i++) b[i]=-1;
	for(int i=0; i<=2*len; i++) c[i]=-1;
	int alen = length(a_char);
	int blen = length(b_char);
	for(int i=0; a_char[i]; i++){
		if(a[len-i/10]==-1) a[len-i/10]=0;
		a[len-i/10] *= 10;
		a[len-i/10] += a_char[alen-i]-'0';
	}
	for(int i=0; b_char[i]; i++){
		if(b[len-i/10]==-1) b[len-i/10]=0;
		b[len-i/10] *= 10;
		b[len-i/10] += b_char[blen-i]-'0';
	}
	for(int i=0; i<=len; i++){
		if(a[i]==-1) continue;
		printf("%lld ", a[i]);
	}
	for(int i=0; i<=len; i++){
		if(b[i]==-1) continue;
		printf("%lld ", b[i]);
	}
	for(int i=0; a[i]!=-1; i++){
		for(int j=0; b[j]!=-1; j++){
			int now=len-(i+j);
			if(c[now] == -1) c[now]=0;
			c[now] += a[i]*b[j];
			while(c[now]>=MAX){
				if(c[now+1] == -1) c[now+1]=0;
				c[now+1] += c[now]/MAX;
				c[now]%=MAX;
				now++;
			}
		}
	}
}
