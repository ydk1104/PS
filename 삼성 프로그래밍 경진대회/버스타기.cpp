#include<stdio.h>
#include<stdlib.h>

int N, K;
int player[200001];

int compare(const void *a, const void *b){
	int *p1 = (int*) a;
	int *p2 = (int*) b;
	if(*p1 > *p2) return 1;
	if(*p1 == *p2) return 0;
	return -1;
}

int search(int left, int right, int ta){
	int mid = left + right;
	mid /= 2;
	if(player[mid] > ta && player[mid-1] <= ta) return mid;
	if(player[mid] < ta) return search(mid+1, right, ta);
	return search(left, mid-1, ta);
}

void bus(int x){
	int cut = player[x] + K;
	player[x] = 0;
	if(player[N-1] <= cut) return;
	else{
		bus(search(x+1, N-1, cut));
	}
}

int main(void){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++){
			scanf("%d", &player[i]);
		}
		qsort(player, N, sizeof(int), compare);
		int ans = 0;
		for(int i=0; i<N; i++){
			if(player[i]!=0){
				ans++;
				bus(i);
			}
		}
		printf("Case #%d\n%d\n", t, ans);
	}
}
