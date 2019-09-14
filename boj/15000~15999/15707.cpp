#include<iostream>
#include<string>

using namespace std;

void test_print(string s){
	cout << "Test";
	for(string::iterator i=s.end(); i!=s.begin(); i--) cout << *(i-1);
	cout << endl;
}

string product(string a, string b){
	string s;
	int size = 600010;
	s.resize(size);
	for(int i=0; i<size; i++) s[i] = 0;
	int alen = a.length();
	int blen = b.length();
	for(int i=alen-1; i>=0; i--){
		for(int j=blen-1; j>=0; j--){
			int now = alen-1-i + blen-1-j;
			if(s[now] == 0) s[now] += '0';
			int plus = (a[i]-'0') * (b[j]-'0');
			if(plus>19){
				if(s[now+1] == 0) s[now+1] = '0';
				s[now+1] += (plus/10)-1;
				plus -= ((plus/10)-1)*10;
			}
			s[now] += plus;
			while(s[now]>'9'){
//				cout << "test_start" << endl;
//				test_print(s);
				int temp = (s[now]-'0')/10;
//				cout << (s[now]-'0') << " "<< temp << endl;
				s[now] = (s[now]-'0')%10+'0';
				now++;
				if(s[now] == 0) s[now] = '0';
				s[now] += temp;
//				test_print(s);
			}
//			test_print(s);
		}
	}
	string s2;
	string::iterator i=s.end();
	while(i!=s.begin() && (*(i-1)==0 || *(i-1) == '0')) i--;
	if(i==s.begin()) s2.push_back('0');
	for(; i!=s.begin(); i--) s2.push_back(*(i-1));
//	test_print(s);
//	test_print(s2);
	return s2;
}

string cmp(string a, string b){
	if(a.length() < b.length()) return "overflow";
	if(a.length() > b.length()) return b;
	for(int i=0; a[i]; i++){
		if(a[i] < b[i]) return "overflow";
		if(a[i] > b[i]) return b;
	}
	return b;
}

int main(void){
	string a, b, c;
	cin >> a >> b >> c;
	string d = product(a, b);
	cout << cmp(c, d);
//	cout << d;
}
