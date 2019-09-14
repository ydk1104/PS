#include<stdio.h>
#define check(a) (a=='Y') ? 1 : 0
#define max(a,b) a>b ? a : b

int fr[51][51];
int N;

int find(int x){
	for(int i=1; i<=N; i++){
		if(fr[x][i] == 1){
			fr[x][0]++;
			fr[x][i] = 2;
		}
		else if(fr[x][i] == 0 && x != i){
			for(int j=1; j<=N; j++){
				if(fr[x][j] > 0 && fr[i][j] > 0){
					fr[x][i] = -1;
					fr[i][x] = -1;
					break;
				}
			}
		}
		if(fr[x][i] == -1){
			fr[x][0] ++;
			fr[x][i] = -2;
		}
	}
	return fr[x][0];
}

int main(void){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		getchar();
		for(int j=1; j<=N; j++){
			char temp;
			scanf("%c", &temp);
			fr[i][j] = check(temp);
			fr[j][i] = check(temp);
		}
	}
	int ans = find(1);
	for(int i=2; i<=N; i++){
		ans = max(ans, find(i));
	}
	printf("%d", ans);
}
