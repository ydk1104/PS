#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int value;
	node* next;
}node;

node st[1000001];
node* head;
int ans;
int ansnum;

void push(int num, int value){
	node* temp = (node*)calloc(1, sizeof(node));
	node* i = head+num;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = temp;
	temp->value = value;
}

void DFS(int prev, int now, int sum){
	int flag = 0;
	node* temp = head+now;
	while(temp->next != NULL){
		if(temp->next->value != prev){
			flag = 1;
			DFS(now, temp->next->value, sum + st[temp->next->value].value);
		}
		temp = temp->next;
	}
	if(flag==0){
		if(ans>sum) return;
		if(ans==sum && now>ansnum) ansnum = now;
		if(ans<sum){
			ans = sum;
			ansnum = now;
		}
	}
	return;
}

int main(void){
	int N;
	scanf("%d", &N);
	head = (node*)calloc(N+1, sizeof(node));
	for(int i=1; i<=N; i++){
		scanf("%d", &st[i].value);
	}
	for(int i=1; i<N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		push(a, b);
		push(b, a);
	}
	DFS(0, 1, st[1].value);
	printf("%d %d", ansnum, ans);
}
