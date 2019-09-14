#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>

using namespace std;

class node{
	public:
		int num;
		node* next;
};

int N, M, x, y;
node* head;
int ans[100001];
int check[100001];
priority_queue <int, vector<int>, greater<int> > pq;

void push(int num, int next){
	node* temp = (node*)calloc(1, sizeof(node));
	node* i = head + num;
	temp->next = i->next;
	i->next = temp;
	temp->num =next;
}

int main(void){
	scanf("%d %d", &N, &M);
	head = (node*)calloc(N+1, sizeof(node));
	for(int i=0; i<M; i++){
		scanf("%d %d", &x, &y);
		if(x==y) continue;
		push(x, y);
		push(y, x);
	}
	pq.push(1);
	check[1] = 1;
	for(int now=1; now<=N; now++){
	int num = pq.top(); pq.pop();
	ans[now] = num;
	node* temp = head + num;
		while(temp->next != NULL){
			if(check[temp->next->num] == 0){
				check[temp->next->num] = 1;
				pq.push(temp->next->num);
			}
			temp = temp->next;
		}
	}
	for(int i=1; i<=N; i++) printf("%d ", ans[i]);
}
