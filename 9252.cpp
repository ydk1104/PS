#include<stdio.h>
#include<stdlib.h>

typedef struct ans{
	int cnt;
	char a[1001];
}ans;

char a[1001];
char b[1001];
ans dp[2][1001];

ans max(ans a, ans b){
	if(a.cnt > b.cnt){
		return a;
	}
	return b;
}

int main(void){
	scanf("%s %s", &a, &b);
	int i, j;
	for(i=0; a[i]!='\0'; i++){
		for(j=0; b[j]!='\0'; j++){
			if(a[i] == b[j]){
				dp[(i+1)%2][j+1] = dp[i%2][j];
				dp[(i+1)%2][j+1].a[dp[(i+1)%2][j+1].cnt] = a[i];
				dp[(i+1)%2][j+1].cnt++;
			}
			else{
				dp[(i+1)%2][j+1] = max(dp[(i+1)%2][j], dp[i%2][j+1]);
			}
		}
	}
	printf("%d\n", dp[i%2][j].cnt);
	printf("%s", dp[i%2][j].a);
}
