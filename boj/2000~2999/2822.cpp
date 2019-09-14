#include<stdio.h>
#include<stdlib.h>

typedef struct problem{
	int score;
	int num;
}pro;

int compare(const void *a, const void *b){
	pro* pa = (pro*) a;
	pro* pb = (pro*) b;
	if(pa->score<pb->score) return 1;
	if(pa->score==pb->score) return 0;
	return -1;
}

int main(void){
	pro p[8];
	for(int i=0; i<8; i++){
		scanf("%d", &p[i].score);
		p[i].num = i;
	}
	qsort(p, 8, sizeof(pro), compare);
	int ans = 0;
	int check[9] = {0, };
	for(int i=0; i<5; i++){
		ans += p[i].score;
		check[p[i].num+1] = 1;
	}
	printf("%d\n", ans);
	for(int i=1; i<=8; i++){
		if(check[i] == 1){
			printf("%d ", i);
		}
	}
}
