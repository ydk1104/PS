/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <algorithm>
#include <iostream>
#include <vector>

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
		int N, K, M;
		cin >> N >> K >> M;
		string s;
		cin >> s;
		int K10 = 1;
		for(int i=0; i<K; i++) K10 *= 10;
		
		auto solve = [&](string& s){
		    long long num=0;
		    vector<long long> v;
		    for(int i=0; s[i]; i++){
		        num *= 10;
		        num += s[i] - '0';
		        if(i >= K-1) v.push_back(num %= K10);
		    }
		    sort(v.begin(), v.end());
		    int p=0, temp=0;
		    for(int i=0; i<v.size(); i++){
		        while(v[i] > v[p] + M) p++;
		        temp = max(temp, i-p+1);
		    }
		    return temp;
		};
		Answer = max(Answer, solve(s));
		for(int i=0; s[i]; i++){
		    char temp = s[i];
		    s[i] = '1';
		    if(temp != '1') Answer = max(Answer, solve(s));
		    s[i] = temp;
		}
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
