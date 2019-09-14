/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);
    const long long int MAX = 4.5e5;
    vector<pair<long long int, int> > v;
    for(long long int i=1, now=0; i<=MAX; i++){
        now += i;
        v.push_back({now, i});
    }
    int dp[MAX+1] = {0,};
    for(int i=1; i<=MAX; i++) dp[i] = i;
    int cnt=0;
    for(int i=0; v[i].first<=MAX; i++){
    	dp[v[i].first] = v[i].second;
    	for(int j=0; j<=i+1; j++){
    		if(v[i].first+j<=MAX) dp[v[i].first+j] = dp[v[i].first] + dp[j];
//    		printf("%d:%d ", v[i].first+j, dp[v[i].first+j]);
		}
//		printf("\n");
	}
 	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		long long int a, b;
		cin >> a >> b;
		int now = 0;
		while(v[now].first <= b) now++;
		now--;
		for(long long int i=b, cnt=0; i-cnt>=a && cnt<=MAX; cnt++ ){
			if(i-cnt<v[now].first){
				now--;
			}
			Answer = max(Answer, v[now].second + dp[b-v[now].first-cnt]);
		}
		cout << "Case #" << test_case+1 << '\n';
		cout << Answer << '\n';
	}

	return 0;//Your program should return 0 on normal termination.
}
