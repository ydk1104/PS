#include<stdio.h>
#include<algorithm>
#include<tuple>
#include<vector>

struct point{
	int x,y,z;
};

std::vector<std::pair<int, point> > v;

int findyz(int left){
	int x = v[left+1].second.x;
	int y = v[left+1].second.y;
	int right = left+1;
	while(v[right+1].second.x == x && v[right+1].second.y == y && v[right+1].second.z<=v[left].second.z) right++;
	return right;
}

void findxy(int left){
	int x = v[left].second.x;
	int y = v[left].second.y;
	int right = left+1;
//	while(v[right+1].second.x == )
}

void func(int N){
	for(int i=0; i<N; ){
		if(v[i].second.x != v[i+1].second.x){
			if(v[i].second.y != v[i+1].second.y){
				// 2 2 2, 3 0 0, 3 0 3, 3 2 0, 3 2 3, 3 3 3
			}
			else{
			}
		}
		else{
			if(v[i].second.y != v[i+1].second.y){ // 0 1 2, 1 2 0, 1 2 1, 1 2 2
				int j = findyz(i);
				int temp = j;
				while(i<j){
					printf("%d %d\n", i, j);
					i++; j--;
				}
				if(i==j) printf("%d %d\n", i, temp++);
				i = temp+1;
			}
			else{ // 0 0 2, 0 0 3
				printf("%d %d\n", i, i+1);
				i+=2;
			}
		}
	}
}

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		point x;
		scanf("%d %d %d", &x.x, &x.y, &x.z);
		v.push_back({i+1, x});
	}
	std::sort(v.begin(), v.end(), [](std::pair<int, point> &a, std::pair<int, point> &b){
		point& x = a.second; point& y = b.second;
		if(x.x != y.x) return x.x<y.x;
		if(x.y != y.y) return x.y<y.y;
		if(x.z != y.z) return x.z<y.z;
		return true;
	});
	for(int i=0; i<N; i++){
		int max = i+1;
		if(v[i].first==-1) continue;
		for(int j=0; j<N; j++){
			if(i==j) continue;
			if(v[i].first==-1 || v[j].first==-1) continue;
			if(((v[i].second.x - v[j].second.x) * (v[j].second.x - v[max].second.x) <= 0) &&
			((v[i].second.y - v[j].second.y) * (v[j].second.y - v[max].second.y) <= 0) &&
			((v[i].second.z - v[j].second.z) * (v[j].second.z - v[max].second.z) <= 0)) max = j;
		}
		printf("%d %d\n", v[i].first, v[max].first);
		v[i].first = v[max].first = -1;
	}
//	v.push_back({-1, {-1,-1,-1}});
//	func(N);
/*	int left=0, right=1;
	while(left<N){
		while(v[right].first==-1) right++;
		while(v[left].first==-1) left++;
		if(left==right) right++;
/*		if(v[left].second.x != v[right].second.x){
			printf("%d %d\n", v[left].first, v[right].first);
			v[left].first = -1;
			v[right].first = -1;
		}
		else if{v[left].second.y != 
		}
		else if{
		} // // */ /*
		while(v[right].second.x > v[left].second.x && v[right].second.x == v[right+1].second.x
		&& v[right].second.y <= v[left].second.y && v[right+1].second.y <= v[left].second.y) right++;
		
		&& (v[right].second.y==v[left].second.y && v[right].second.y))
	} // */
}
