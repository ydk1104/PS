#include<stdio.h>
#include<stdlib.h>
#define min(a,b) ((a)>(b) ? (b) : (a))
#define max(a,b) ((a)<(b) ? (b) : (a))

typedef struct node{
	int end;
	node* next;
}node;

typedef struct tree{
	int value;
	int pa;
}tree;

tree vil[10001];
node* edge;
node* Q;

void push(node* x, int a, int b){
	node* temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	temp->end = b;
	node* i = x+a-1;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = temp;
}

int pop(node* x){
	int temp = x->next->end;
	node* t = x->next;
	x->next = x->next->next;
	free(t);
	return temp;
}

void maketree(){
	int now = pop(Q);
	node* i = edge+now-1;
	while(i->next != NULL){
		if(!vil[i->next->end].pa){
		vil[i->next->end].pa = now;
		push(Q, 1, i->next->end);
		i = i->next;
		}
		else{
			pop(i);
		}
	}
	if(Q->next != NULL) return maketree();
	return;
}

int dp[10001][2];

int DP(int now, int check){
	node *i = edge+now-1;
//	printf("now = %d\n", now);
	if(dp[now][check]!=-1) return dp[now][check];
	int ans = vil[now].value * check;
	while(i->next != NULL){
		if(i->next->end != vil[now].pa){
			if(!check)	ans += max(DP(i->next->end, 1),DP(i->next->end,0));
			else ans += DP(i->next->end, 0);
		}
		i = i->next;
	}
	return dp[now][check] = ans;
}

int main(void){
	int N;
	scanf("%d", &N);
	edge = (node*)malloc(sizeof(node)*N);
	for(int i=0; i<N; i++){
		(edge+i)->next = NULL;
	}
	Q = (node*)malloc(sizeof(node));
	Q->next = NULL;
	for(int i=1; i<=N; i++){
		scanf("%d", &vil[i].value);
	}
	for(int i=1; i<N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		push(edge, a, b);
		push(edge, b, a);
	}
	vil[1].pa = -1;
	push(Q, 1, 1);
	maketree();
	for(int i=1; i<=N; i++){
		for(int j=0; j<=1; j++){
			dp[i][j] = -1;
		}
	}
	DP(1, 1);
	DP(1, 0);
	printf("%d", max(dp[1][0], dp[1][1]));
}
