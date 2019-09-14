#include<iostream>

int main(void){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int N;
	std::cin >> N;
	long long ans=0;
	int x;
	for(int i=0; i<N; i++) std::cin >> x, ans+=x;
	std::cout << ans;
}
