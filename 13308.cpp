#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int end;
	long long int cost;
	int min;
	node* next;
}node;

int N, M;
int city[2501];
long long int dp[2501][2501];
node heap[10000001];
int cnt;
node* edge;

int com(int a, int b){
	if(heap[a].cost > heap[b].cost) return 0;
	return 1;
}

void swap(int a, int b){
	node temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void PQ_push(int num, long long int cost, int min){
	cnt++;
	heap[cnt].end = num;
	heap[cnt].cost = cost;
	heap[cnt].min = min;
	int i = cnt;
	while(i>1){
		if(com(i/2, i)) return;
		swap(i/2, i);
		i/=2;
	}
}

node pop(){
	node temp = heap[1];
	heap[1] = heap[cnt];
	heap[cnt--] = heap[0];
	int i = 1;
	while(i*2<=cnt){
		if(i*2==cnt){
			if(com(i, i*2)) return temp;
			swap(i, i*2);
			i = i*2;
		}
		else{
			if(com(i, i*2) && com(i, i*2+1)) return temp;
			if(!com(i*2, i*2+1)){
				swap(i, i*2+1);
				i  = i*2+1;
			}
			else{
				swap(i, i*2);
				i *= 2;
			}
		}
	}
	return temp;
}

void push(int start, int end, long long int cost){
	node* temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	node* i = edge + start;
	while(i->next != NULL){
		i = i -> next;
	}
	i -> next = temp;
	temp->end = end;
	temp->cost = cost;
}

long long int dijk(){
	node i = pop();
//	printf("nownum = %d\nnowcost = %d\n", i.end, i.cost);
	if(dp[i.end][i.min]) return dijk();
	if(i.end == N) return i.cost;
	dp[i.end][i.min] = i.cost;
	if(city[i.min] > city[i.end]) i.min = i.end;
	node* temp = edge+i.end;
	while(temp->next != NULL){
		temp = temp->next;
		if(!dp[temp->end][i.min]){
			PQ_push(temp->end, i.cost+(temp->cost)*city[i.min], i.min);	
		}
	}
	return dijk();
}

int main(void){
	scanf("%d %d", &N, &M);
	edge = (node*)calloc(N+1, sizeof(node));
	for(int i=1; i<=N; i++){
		scanf("%d", &city[i]);
	}
	for(int i=1; i<=M; i++){
		int a, b;
		long long int c;
		scanf("%d %d %lld", &a, &b, &c);
		push(a, b, c);
		push(b, a, c);
	}
	PQ_push(1, 0, 1);
	long long int ans = dijk();
	printf("%lld", ans);
}
