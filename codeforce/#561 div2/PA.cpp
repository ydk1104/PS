#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string name[101];
int cnt[27];

int main(void){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> name[i];
		cnt[name[i][0]-'a']++;
	}
	int dp[101] = {0, };
	for(int i=2; i<=N; i++) dp[i] = dp[i-1]+i-1;
	int ans=0;
	for(int i=0; i<26; i++){
		int l=cnt[i]/2, r=cnt[i]-l;
		ans+=dp[l]+dp[r];
	}
	cout << ans;
}
