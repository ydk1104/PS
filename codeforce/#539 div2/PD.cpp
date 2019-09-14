#include<iostream>
#include<string>

using namespace std;

int check(string s){
	int len = s.length();
	for(int i=0; i<len; i++){
		for(int j=0; j<len; j++){
			if(s[(i+j)%len] != s[(i-1-j+len)%len]) goto v;
		}
		for(int j=0; j<len; j++){
			if(s[(i+j)%len] != s[j]) return 0;
		}
		v:;
	}
	return 1;
}

int main(void){
	string s;
	cin >> s;
	bool flag = false;
	int len = s.length();
	for(int i=0; i<len/2; i++){
		if(s[i] != s[0]) flag=true;
	}
	if(len<=3) flag = false;
	if(flag){
		if(len%2 || check(s)) cout << "2";
		else cout << "1";
	}
	else{
		cout << "Impossible";
	}
}
