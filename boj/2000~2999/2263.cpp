#include<stdio.h>

int in[100001];
int post[100001];
int pre[100001][3];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%d", &in[i]);
	}
	for(int i=1; i<=N; i++){
		scanf("%d", &post[i]);
	}
	int left, right;
	left = right = 1;
	while(left<=N){
		if(in[left] == post[right]){
			pre[0][0]++;
			pre[pre[0][0]][0] = in[left];
			left++;
			right++;
		}
		else{
			pre[0][1]++;
			pre[pre[0][1]][1] = in[left];
			left++;
		}
	}
	for(int i=1; i<=pre[0][0]; i++){
		printf("%d", pre[i][0]);
		if(i!=pre[0][0]) printf(" ");
	}
	for(int i=1; i<=pre[0][1]; i++){
		printf("%d", pre[i][1]);
		if(i!=pre[0][1]) printf(" ");
	}
	
}
