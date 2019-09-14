#include<stdio.h>
#include<vector>

using namespace std;

const int p=100000007;

class node{
	public:
	int num;
	vector<int> E;
	void push(int x){
		E.push_back(x);
	}
};

int N, M;
node V[101];

int main(void){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		V[x].push(y);
		V[y].push(x);
	}
	if(N%2) printf("0");
	else{
		
	}
}
