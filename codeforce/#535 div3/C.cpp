#include<stdio.h>
#include<string.h>

int cnt[3][3];

int max(int a, int b, int c, int d, int e, int f){
	int x = a;
	if(x<b) x=b;
	if(x<c) x=c;
	if(x<d) x=d;
	if(x<e) x=e;
	if(x<f) x=f;
	return x;
}

int main(void){
	int N;
	char s[200005];
	scanf("%d\n%s", &N, &s);
	for(int i=0; i<N; i++){
		if(s[i] == 'R') cnt[0][i%3]++;
		else if(s[i] == 'G') cnt[1][i%3]++;
		else if(s[i] == 'B') cnt[2][i%3]++;
	}
	int num1 = cnt[0][0] + cnt[1][1] + cnt[2][2];
	int num2 = cnt[0][0] + cnt[1][2] + cnt[2][1];
	int num3 = cnt[0][1] + cnt[1][0] + cnt[2][2];
	int num4 = cnt[0][1] + cnt[1][2] + cnt[2][0];
	int num5 = cnt[0][2] + cnt[1][0] + cnt[2][1];
	int num6 = cnt[0][2] + cnt[1][1] + cnt[2][0];
	int big = max(num1, num2, num3, num4, num5, num6);
	char ans[3];
	if(big == num1){
		strcpy(ans, "RGB");
	}
	else if(big == num2){
		strcpy(ans, "RBG");
	}
	else if(big == num3){
		strcpy(ans, "GRB");
	}
	else if(big == num4){
		strcpy(ans, "BRG");
	}
	else if(big == num5){
		strcpy(ans, "GBR");
	}
	else if(big == num6){
		strcpy(ans, "BGR");
	}
	printf("%d\n", N-big);
	for(int i=0; i<N; i++) printf("%c", ans[i%3]);
}
