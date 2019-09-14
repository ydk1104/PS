#include<stdio.h>
#include<stdlib.h>
#define abs(x) ((x)>0 ? (x) : -(x))
#define INF 100000

typedef struct node{
	int num;
	node* next;
}node;

node* fr;
node* vs;

int compare(const void *a, const void *b){
	int* pa = (int*) a;
	int* pb = (int*) b;
	if(*pa<*pb) return 1;
	return -1;
}

void push(node *x, int num){
	node* temp = (node*)calloc(1, sizeof(node));
	node* i = x;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = temp;
	temp->num = num;
}

int place(int com[], int now, int nowp){
	if(com[now] && com[now]!=nowp) return INF;
	if(com[now]) return 0;
	com[now] = nowp;
	int sum = nowp;
	node* i = fr+now;
	while(i->next != NULL){
		i = i->next;
		int x = place(com, i->num, nowp);
		if(x==INF) return INF;
		sum += x;
	}
	i = vs+now;
	while(i->next != NULL){
		i = i->next;
		int x = place(com, i->num, -nowp);
		if(x==INF) return INF;
		sum += x;
	}
	return sum;
}

int main(void){
	for(int t=1; t<=5; t++){
		int N, M;
		scanf("%d %d", &N, &M);
		fr = (node*)calloc(N+1, sizeof(node));
		vs = (node*)calloc(N+1, sizeof(node));
		for(int i=1; i<=M; i++){
			int x, a, b;
			scanf("%d %d %d", &x, &a, &b);
			if(x==1){
				push(fr+a, b);
				push(fr+b, a);
			}
			else{
				push(vs+a, b);
				push(vs+b, a);
			}
		}
		int check[10001] = {0, };
		int ans[10001] = {0, };
		int cnt = 0;
		int flag = 0;
		for(int i=1; i<=N; i++){
			if(check[i]) continue;
			int x = place(check, i, 1);
			if(x==INF){
				i=N+1;
				flag = 1;
			}
			else ans[cnt++] = x;
		}
		if(flag) printf("-1\n");
		else if(cnt==1) printf("%d\n", abs(ans[0]));
		else{
			qsort(ans, cnt, sizeof(int), compare);
			int sum = 0;
			for(int i=0; i<cnt; i++){
				ans[i]+=10000;
				sum+=ans[i];
//				printf("ans = %d ", ans[i]);
			}
			int nowsum = 0;
			for(int i=0; i<cnt; i++){
				if(nowsum+ans[i]<=sum/2) nowsum+=ans[i];
			}
			printf("%d\n", (sum-nowsum*2)%10000);
		}
		for(int i=1; i<=N; i++){
//			printf("%d ", check[i]);
		}
//		printf("\n");
		free(fr);
		free(vs);
	}
}
