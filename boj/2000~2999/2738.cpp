#include<stdio.h>

int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	int a[100][100], x;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d", &x), a[i][j]+=x;
	for(int i=0;i<n;i++,printf("\n")) for(int j=0;j<m;j++) printf("%d ",a[i][j]);
}
