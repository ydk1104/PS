#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main(){
    int N, M;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;
    std::vector<int> v(N);
    for(int i=0; i<N; i++) std::cin >> v[i];
    std::sort(v.begin(), v.end());
    M = N-M-1;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
    for(int i=0; i<M-1; i++) pq.push({v[i+1]-v[i], i});
    int ans = 1e9;
    for(int i=M; i<N; i++){
    	pq.push({v[i]-v[i-1], i});
    	while(pq.top().second < i-M) pq.pop();
    	ans = std::min(ans, pq.top().first+v[i]-v[i-M]);
	}
	std::cout << ans;
}
