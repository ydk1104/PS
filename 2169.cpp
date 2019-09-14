#include<stdio.h>
#include<algorithm>
#define INF -1000000000

int save[1002][1002][3];
int a[1002][1002];

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i <=N; i++) {
		for (int j = 0; j <=M; j++) {
			for (int k = 0; k <= 2; k++) {
				save[i][j][k] = INF;
			}
		}
	}
	save[1][1][0] = save[1][1][1] = a[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			save[i][j][0] = std::max({save[i-1][j][0], save[i-1][j][1], save[i-1][j][2]}) + a[i][j];
		}
		for (int j = 1; j <= M; j++) {
			save[i][j + 1][1] = std::max(std::max(save[i][j][0], save[i][j][1]) + a[i][j + 1], save[i][j + 1][0]);
		}
		for (int j = M; j ; j--) {
			save[i][j - 1][2] = std::max(std::max(save[i][j][0], save[i][j][2]) + a[i][j - 1], save[i][j - 1][0]);
		}
	}
	printf("%d\n", std::max(save[N][M][0], save[N][M][1]));
}
