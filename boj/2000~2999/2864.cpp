#include<iostream>
#include<string>

using namespace std;

string change(string s, int from, int to){
	for(int i=0; s[i]!=0; i++){
		if(s[i]-'0' == from) s[i] = to + '0';
	}
	return s;
}

int main(void){
	string N, M;
	cin >> N >> M;
	N = change(N, 6, 5);
	M = change(M, 6, 5);
	cout << stoi(N)+stoi(M);
	N = change(N, 5, 6);
	M = change(M, 5, 6);
	cout << " " << stoi(N)+stoi(M);
}
