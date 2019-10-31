#include<stdio.h>
#include<set>
#include<algorithm>
 
struct node{
		int value = 0;
		node* prev = NULL;
		node* next = NULL;
}arr[300001];
 
std::set<node*> set[300001];
int cnt[300001];
int check[300001];
 
int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &arr[i].value);
		set[arr[i].value].insert(&arr[i]);
		arr[i].next = &arr[i+1];
		cnt[arr[i].value]=1;
	}
	arr[N-1].next = NULL;
	int M;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		int x;
		scanf("%d", &x);
		if(check[x]) continue;
		if(set[x].size()>=2){
				node* ptr = *set[x].begin();
				node* end = *set[x].rbegin();
				while(ptr->next != end){
					set[ptr->next->value].erase(set[ptr->next->value].find(ptr->next));
					ptr->next = ptr->next->next;
				}
				set[ptr->next->value].erase(set[ptr->next->value].find(ptr->next));
				ptr->next = ptr->next->next;
//				set[ptr->value].clear();
				cnt[ptr->value] = end-ptr+1;
//				set[ptr->value].clear();
//				set[ptr->value].insert(NULL);
				check[x] = 1;
		}
//		else if(set[x].size() && *set[x].begin() == NULL) continue;
		else cnt[x] = set[x].size();
	}
	node*ptr = arr;
	for(int i=0; i<=300000; i++) check[i] = 0;
	while(ptr != NULL){
//		if(check[ptr->value]) goto v;
		for(int i=0; i<cnt[ptr->value]; i++) printf("%d ", ptr->value);
		check[ptr->value] = 1;
v:;
		ptr = ptr->next;
	}
}
