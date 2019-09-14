#include<stdio.h>
#define max(a,b) ((a)>(b) ? (a) : (b))

int a[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	int MAX = 0;
	for(int i=0; i<N; i++) MAX = max(MAX, a[i]);
	int ans = 0;
	int row = 0;
	for(int i=0; i<N; i++){
		if(a[i] == MAX){
			int row = 0;
			for(int j=i; a[j]==MAX && j<N; j++) row++;
			ans = max(ans, row);
			i += row-1;
		}
	}
	printf("%d\n", ans);
}
