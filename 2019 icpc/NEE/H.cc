#include<stdio.h>
using namespace std;
 
int hamsu(int a1, int b1, int a2, int b2){
	int hei = a2-a1+1;
	int wid = b2-b1+1;
	int yy = 0;
	if(wid%2) yy = hei;
	return yy;
}
 
int main(void){
	int N,M;
	scanf("%d %d",&N,&M);
	int X1,X2,Y1,Y2;
	scanf("%d %d %d %d",&X1, &Y1, &X2, &Y2);
	
	int ans = 0;
	ans = ans + hamsu(1,1,X1-1,M);
	ans = ans + hamsu(X1,1,X2,Y1-1);
	ans = ans + hamsu(X1,Y2+1,X2,M);
	ans = ans + hamsu(X2+1,1,N,M);
 
	if(ans%2==1) ans = ans + 1;
 
	ans = ans / 2;
 
	printf("%d",ans);
 
}
 
