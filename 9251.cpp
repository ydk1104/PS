#include<stdio.h>

int dp[1001][1001];

int max(int a, int b){
  if(a>b) return a;
  return b;
}
int main(void){
  char a[1001];
  char b[1001];
  scanf("%s %s", &a, &b);
  int i, j;
  for(i=0; a[i]!='\0'; i++){
    for(j=0; b[j]!='\0'; j++){
      if(a[i] == b[j]){
        dp[i+1][j+1] = dp[i][j] + 1;
      }
      else{
        dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
      }
    }
  }
  printf("%d", dp[i][j]);
}
