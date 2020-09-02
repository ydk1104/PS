#include<iostream>
#include<string>

int main(void){
	std::string s;
	std::cin >> s;
	long long type;
	std::cin >> type;
	if(type%2){
		
	}
	else{
		s += s;
	}
	
	std::cout << ((s == std::string(s.rbegin(), s.rend())) ? "YES" : "NO");
}
