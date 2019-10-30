#include<iostream>

int main(void){
	std::string s;
	std::cin >> s;
	int N;
	std::cin >> N;
	int ans=0;
	while(N--){
		std::string x;
		std::cin >> x;
		x += x;
		for(int i=0; x[i]; i++){
			for(int j=0; s[j]; j++){
				if(x[i+j] != s[j]) goto v;
			}
			ans++;
			goto w;
			v:;
		}
		w:;
	}
	std::cout << ans;
}
