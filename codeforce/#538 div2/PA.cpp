#include<stdio.h>

int main(void){
	int max = 0;
	int a[2][3];
	for(int i=0; i<2; i++){
		for(int j=0; j<3; j++) scanf("%d", &a[i][j]);
	}
	int flag = 1;
	for(int i=0; i<3; i++){
		max += a[1][i];
		max -= a[0][i];
		if(max<0) flag = 0;
	}
	if(flag) printf("YES");
	else printf("NO");
}
