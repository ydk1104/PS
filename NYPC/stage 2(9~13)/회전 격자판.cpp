#include<stdio.h>

int board[301][301][301];
int temp[301][301];
int N, T;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void turn90(int t){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			temp[-j+N+1][i] = board[t][i][j];
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			board[t][i][j] = temp[i][j];
		}
	}
}

int check(int a, int b){
	if(b<0) return 0;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(board[a][i][j] != board[b][i][j]) return 0;
		}
	}
	return 1;
}

int main(void){
	scanf("%d %d", &N, &T);
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			scanf("%d", &board[0][i][j]);
		}
	}
	for(int t=1; t<=T; t++){
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				board[t][i][j] = board[t-1][i][j];
				if(board[t][i][j-1]>board[t][i][j]){
					swap(&board[t][i][j-1], &board[t][i][j]);
				}
			}
		}
		turn90(t);
		if(check(t, t-4)){
			T = (T-t)%4+t-4;
			break;
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			printf("%d ", board[T][i][j]);
		}
		printf("\n");
	}
}
