#include<stdio.h>

char map[110][110];
char s[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567899";
int arr[63];

int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		int r,c,k;
		scanf("%d %d %d", &r, &c, &k);
//		for(int i=0; i<=r+1; i++)
//			for(int j=0; j<=c+1; j++)
//				map[i][j] = 0;
		for(int i=1; i<=r; i++)
			scanf("%s", &map[i][1]);
		int cnt=0;
		for(int i=1; i<=r; i++)
			for(int j=1; j<=c; j++)
				cnt += map[i][j]=='R';
		for(int i=0; i<k; i++) arr[i] = cnt/k+(cnt%k>i);
		arr[k-1]++;
		int x=1, y=1, now=0, go=1;
		while(x<=r){
			while(map[x][y]){
//				printf("%c",s[now]);
				arr[now]-=map[x][y]=='R';
				map[x][y] = s[now];
				if(!arr[now]) now++;
				//
				y += go;
			}
			y -= go;
			go *= -1;
			x++;
		}
		for(int i=1; i<=r; i++){
			printf("%s\n", &map[i][1]);
		}
	}
}
