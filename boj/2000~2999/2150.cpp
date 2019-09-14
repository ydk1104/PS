#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
	int num;
	int visited;
	int check;
};

struct stack{
	int stack[10001];
	int cnt;
	void push(int x){
		stack[cnt++] = x;
	}
	void pop(){
		cnt--;
	}
	int top(){
		return stack[cnt-1];
	}
	int empty(){
		return !cnt;
	}
};

struct answer{
	vector<int> ans;
	void print(){
		for(vector<int>::iterator p=ans.begin(); p!=ans.end(); p++) printf("%d ", *p);
		printf("-1\n");
	}
	void qsort(){
		sort(ans.begin(), ans.end());
	}
	bool operator <(answer &x){
		return this->ans[0] < x.ans[0];
	}
};

vector<int>v[10001];
int cnt;
node V[10001];
stack s;
answer a[10001];
int ans;

int dfs(int now){
	if(V[now].check) return 0;
	if(V[now].visited) return 1;
	printf("%d\n", now);
	V[now].visited = 1;
	V[now].num = ++cnt;
	s.push(now);
	int temp=0;
	for(vector<int>::iterator p=v[now].begin(); p!=v[now].end(); p++){
		temp += dfs(*p);
	}
	if(!temp){
		ans++;
		while(s.top() != now){
			a[ans].ans.push_back(s.top());
			V[s.top()].check=1;
			s.pop();
		}
		a[ans].qsort();
	}
	return temp;
}

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
	}
	dfs(1);
	if(!s.empty()) ans++;
	while(!s.empty()){
		a[ans].ans.push_back(s.top()); s.pop();
	}
	a[ans].qsort();
	printf("%d\n", ans);
	sort(a+1, a+ans+1);
	for(int i=0; i<ans; i++) a[i].print();
}
