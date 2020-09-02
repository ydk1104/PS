#include<stdio.h>
#include<algorithm>
#include<list>
#include<stack>

int arr[501];
std::list<std::pair<int, int>> a;

int dp[501][1501];

int check(std::list<std::pair<int, int> >::iterator it, int plus, int now, int cnt){
	if(it->first != now) return 0;
	int temp = 0;
	int pow = 1;
	int temp_cnt = 0;
	while(true){
		
		if(it->first == now) temp_cnt += it->second;
		
		if(temp_cnt % 2){
			if(temp + pow <= cnt) temp += pow, temp_cnt++;
			else break;
		}
		
		temp_cnt /= 2;
		
		if(it -> first == now){
			if(plus == 1) it++;
			else it--;
		}
		now++;
		pow *= 2;
	}
	return temp;
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", arr+i);
	int cnt = 0;
	for(int i=0; i<N; i++){
		if(a.back().first == arr[i]) a.back().second ++;
		else a.push_back({arr[i], 1});
	}
	for(int i=1; i<=1010; i++){
		std::stack<std::list<std::pair<int, int > >::iterator > stk;
		for(std::list<std::pair<int, int > > ::iterator j = a.begin(); j != a.end(); j++){
			if(j->first != i) continue;
			v:;
			auto temp = j;
			temp++;
			if(j->first == temp->first){
				temp->second += j->second;
				a.erase(j);
				j = temp;
				goto v;
			}
			if(j->second > 1){
				if(j->second % 2){
					auto prev = j, next = j;
					prev--; next++;
					if(prev->first != i+1) a.insert(next, {j->first+1, j->second/2});
					else if(next->first != i+1) a.insert(j, {j->first+1, j->second/2});
					else{
						int left = check(prev, -1, i+1, j->second/2);
						int right = check(next, +1, i+1, j->second/2);
						if(left > right) a.insert(next, {j->first+1, right}), a.insert(j, {j->first+1, j->second/2 - right});
						else a.insert(next, {j->first+1, j->second/2 - left}), a.insert(j, {j->first+1, left});
					}
					j->second = 1;
				}
				else{
					a.insert(j, {j->first+1, j->second/2});
					stk.push(j);
				}
			}
		}
		while(stk.size()){
			auto temp = stk.top(); stk.pop();
			a.erase(temp);
		}
	}
//	for(auto i : a) printf("%d %d\n", i.first, i.second);
//	printf("ans : ");
	printf("%d", a.size());
}
