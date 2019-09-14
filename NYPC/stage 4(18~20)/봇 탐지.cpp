#include<stdio.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

int n, a, b;
char s[3001];
int check[3001][3001];

// 소스 참고 : http://kks227.blog.me/220917078260 
 
int count(int compare_start, int compare_end){
	char compare[3001];
	for(int i=compare_start; i<=compare_end; i++){
		compare[i-compare_start] = s[i];
	}
	int compare_length = compare_end - compare_start+1;
	compare[compare_length] = 0;
	int cnt = 0;
	int fail[3001] = {0, };
	for(int i=1, j=0; i<compare_length; i++){
		while(j>0 && compare[i] != compare[j]) j = fail[j-1];
		if(compare[i] == compare[j]) fail[i] = ++j;
	}
	for(int i=compare_end+1, j=0; i<n; i++){
		while(j>0 && s[i] != compare[j]) j = fail[j-1];
		if(s[i] == compare[j]){
			if(j==compare_length-1){
				cnt++;
				j = 0;
				check[i][compare_length] = 1;
			}
			else j++;
		}
	}
//	printf("%s %d\n", compare, cnt);
//	printf("%d %d %d\n", compare_start, compare_end, compare_length);
	return cnt;
}

int main(void){
	scanf("%d %d %d", &n, &a, &b);
	scanf("%s", &s);
	int ans = 0; 
	int need = a;
	for(int i=0; need<n-i; i++){
		for(int j=0; i+j<n; j++){
			if(!check[i][j]){
				int temp = (count(i, i+j)+1);
				if(temp>1) ans = max(ans, (j+1)*temp);
//				printf("%d\n", ans);
			}	
		}
		if(ans>=a) need=b;
		if(ans>b) need=n;
	}
	int answer = 3;
	if(ans>=a) answer--;
	if(ans>b) answer--;
	printf("%d", answer);
}
