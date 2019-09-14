#include<iostream>
#include<map>

using namespace std;

map <string, int> M;
string dictionary[100001];

void print(string s){
	if(s[0] >= 'A'){
		cout << M[s] << "\n";
	}
	else{
		cout << dictionary[stoi(s)] << "\n";
		int temp = stoi(s);
		printf("%d\n", dictionary[temp]);
	}
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> dictionary[i];
		M[dictionary[i]] = i;
	}
	while(m--){
		string s;
		cin >> s;
		print(s);
	}
}
