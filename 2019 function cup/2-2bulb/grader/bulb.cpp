#include "bulb.h"

int FindWinner(int T, std::vector<int> R, std::vector<int> L){
	int now = 0; 
	std::vector<int> v;
	while(now>=0){
		v.push_back(L[now]);
		now = R[now];
	}
	if(now == -2) return 0;
	int cnt = 0;
	for(auto &i : v){
		int check = 1;
		while(i>=0){
			int temp = L[i];
			while(temp>=0) temp = R[temp];
			if(temp == -1) check = 0;
			i = R[i];
		}
//		int temp = L[i];
//		while(temp >= 0) temp = R[temp];
//		if(temp == -1) check = 0;
		if(i == -1) continue;
		if(i == -2 && check == 1) return 0;
		if(i == -2) cnt++;
	}
	if(cnt > 1) return 0;
	return 1;
}
