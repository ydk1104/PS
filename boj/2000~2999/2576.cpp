#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

int main(void){
	for(int i=0; i<7; i++){
		int x;
		scanf("%d", &x);
		if(x%2) v.push_back(x);
	}
	sort(v.begin(), v.end());
	if(v.size()){
		int sum = 0;
		for(int i=0; i<v.size(); i++) sum+=v[i];
		printf("%d\n%d", sum, v[0]);
	}
	else{
		printf("-1");
	}
}
