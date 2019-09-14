#include<stdio.h>
int dp[1001][1001];

int max(int a, int b){
	if(a>b) return a;
	return b;
}

int LCS(char a[], char b[], int left, int right, int num, int abc[][1001], int abc2[][1001]){
	if(dp[left][right] > num){
		return dp[left][right];
	}
	if(a[left] == '\0'){
		dp[left][right] = num;
		return num;
	}
/*	if(dp[left][right] == num){
		int c = a[left] - 65;
		abc[c][0]++;
		while(right>abc[c][abc[c][0]] && abc[c][abc[c][0]] != -1){
			abc[c][0]++;
		}
		right = abc[c][abc[c][0]];
		if(right == -1){
			return num;
		}
		dp[left][right] = num+1;
		return LCS(a, b, left+1, right+1, num+1, abc, abc);
	}
	*/
	int i = right;
	int c = a[left] - 65;
	abc[c][0]++;
	while(right>abc[c][abc[c][0]]&&abc[c][abc[c][0]] != -1){
		abc[c][0]++;
	}
	right = abc[c][abc[c][0]];
	if(right == -1){
		return LCS(a, b, left+1, i, num, abc2, abc2);
	}
	if(b[right] == a[left]){
		dp[left][right] = num+1;
		return max(LCS(a, b, left+1, i, num, abc2, abc2), LCS(a, b, left+1, right+1, num+1, abc, abc));
	}
	dp[left][right] = num;
	return LCS(a, b, left+1, i, num, abc2, abc2);
}

int main(void){
	char a[1001];
	char b[1001];
	int abc[62][1001] = {0, };
	scanf("%s %s", &a, &b);
	for (int i=0; i<=1000; i++){
		for(int j=0; j<=1000; j++){
			dp[i][j] = -1;
		}
	}
	for(int i=0; i<=61; i++){
		abc[i][0]++;
		for(int j=1; j<=1000; j++){
			abc[i][j] = -1;
		}
	}
	for(int i=0; b[i]!='\0'; i++){
		int c = b[i] - 65;
		abc[c][abc[c][0]] = i;
		abc[c][0]++;
	}
	for(int i=0; i<=61; i++){
		abc[i][0] = 0;
	}
	int ans = LCS(a, b, 0, 0, 0, abc, abc);
	printf("%d\n", ans);
	return 0;
}
