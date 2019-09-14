#include<stdio.h>
#include<vector>

std::vector<std::pair<int, int> >v;

int main(void){
	int a[10];
	for(int i=0; i<10; i++){
		scanf("%d", &a[i]);
		if(a[i]) v.push_back({a[i], i});
	}
	if((v[1].first - v[0].first) % (v[1].second - v[0].second)) printf("-1");
	else{
		int value = (v[1].first - v[0].first) / (v[1].second - v[0].second);
		for(int i=0; i<10; i++) printf("%d ", a[v[0].second] + value * (i - v[0].second));
	}
}
