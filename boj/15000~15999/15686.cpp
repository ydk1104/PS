#include<stdio.h>
#include<stdlib.h>
#define INF 1000000000
#define abs(x) ((x)>0) ? (x) : 0-(x)
#define min(a,b) (a>b) ? b : a

typedef struct point{
	int x[200];
	int y[200];
	int max;
	int d[200][50];
}point;

point house;
point chicken;
int map[101][101];

int compare(const void *a, const void *b){
	int *p1 = (int*) a;
	int *p2 = (int*) b;
	int n1 = *p1 / 100;
	int n2 = *p2 / 100;
	if(n1>n2) return 1;
	if(n1==n2) return 0;
	return -1;
}

int DFS(int cnt, int M, int check[], int now){
	if(cnt == M){
		int ans = 0;
		for(int i=0; i<house.max; i++){
			for(int j=0; j<chicken.max; j++){
				if(check[house.d[i][j]%100] == 1){
					ans += house.d[i][j]/100;
					break;
				}
			}
		}
		return ans;
	}
	if(now>=chicken.max) return INF; 
	int temp1 = DFS(cnt, M, check, now+1);
	check[now] = 1;
	int temp2 = DFS(cnt+1, M, check, now+1);
	check[now] = 0;
	return min(temp1, temp2);
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1){
				house.x[house.max] = i;
				house.y[house.max] = j;
				house.max++;
			}
			else if(map[i][j] == 2){
				chicken.x[chicken.max] = i;
				chicken.y[chicken.max] = j;
				chicken.max++;
			}
		}
	}
	for(int i=0; i<chicken.max; i++){
		for(int j=0; j<house.max; j++){
			house.d[j][i] = abs(chicken.x[i] - house.x[j]);
			house.d[j][i] += abs(chicken.y[i] - house.y[j]);
			house.d[j][i] *= 100;
			house.d[j][i] += i;
		}
	}
	for(int i=0; i<house.max; i++){
		qsort(house.d[i], chicken.max, sizeof(int), compare);
	}
	int check[15] = {0, };
	int ans = DFS(0, M, check, 0);
	printf("%d", ans);
}
