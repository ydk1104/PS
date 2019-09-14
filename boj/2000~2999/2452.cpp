#include<stdio.h>
#define min(a,b) ((a)>(b) ? (b) : (a))

int map[101][101][2];
int stone[2];
int N, M;

int find(int a, int b){
	int temp = map[a][b][1];
	int pa = temp/1000;
	int pb = temp%1000;
	if((pa==a) && (pb==b)) return temp;
	return map[a][b][1] = find(pa, pb);
}

void merge(int x1, int y1, int x2, int y2){
	if(x2>N || y2>M) return;
	if(x2==0 || y2==0) return;
	if(map[x1][y1][0] != map[x2][y2][0]) return;
	int pa = find(x1, y1);
	int pb = find(x2, y2);
	if(pa == pb) return;
	map[pb/1000][pb%1000][1] = pa;
	stone[map[x1][y1][0]]--;
	merge(x2, y2, x2+1, y2);
	merge(x2, y2, x2-1, y2);
	merge(x2, y2, x2, y2+1);
	merge(x2, y2, x2, y2-1);
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			scanf("%d", &map[i][j][0]);
			stone[map[i][j][0]]++;
			map[i][j][1] = i*1000+j;
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			merge(i, j, i-1, j);
			merge(i, j, i+1, j);
			merge(i, j, i, j-1);
			merge(i, j, i, j+1);
		}
	}
	printf("%d", min(stone[0], stone[1]));
}
