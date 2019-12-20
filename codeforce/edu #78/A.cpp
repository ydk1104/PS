#include<iostream>
#include<string>
#include<algorithm>
 
int main(void){
	int T;
	std::cin >> T;
	while(T--){
		std::string s,t;
		std::cin >> s >> t;
		std::sort(s.begin(), s.end());
		bool flag = false;
		for(int i=0; i<t.size(); i++){
			std::string temp = t.substr(i, s.size());
			std::sort(temp.begin(), temp.end());
			flag |= (s==temp);
		}
		std::cout << (flag?"YES\n":"NO\n");
	}
}
