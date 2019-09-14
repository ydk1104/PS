#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		std::string x, y;
		std::cin >> x;
		y = x;
		if(std::next_permutation(x.begin(), x.end())) std::cout << x;
		else std::cout << y;
		std::cout << '\n';
	}
}
