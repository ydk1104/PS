/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>

using namespace std;

int Answer;
int dp[3001];

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
		
		int N, K;
		cin >> N >> K;
		int StateCnt = (N+1) * (N+1);
		
		vector<int> A(N),B(N);
		for(int i=0; i<N; i++){
		    cin >> A[i];
		}
		for(int i=0; i<N; i++){
		    cin >> B[i];
		}
		
		int dp[2][3001];
		auto func = [&](std::vector<int> v, int* dp){
		    int ret = 0;
		    dp[0] = 1;
		    dp[1] = 0;
		    for(int i=2; i<=N; i++){
		        dp[i] = 0;
		        int sum = 0;
		        int check[3001] = {0, };
		        for(int j=1; j<=i; j++){
		            sum += v[i-j];
		            if(sum > K) break;
					check[dp[i-j]]++;
		        }
		        while(check[dp[i]]) dp[i]++;
		        ret++;
		    }
		    return ret;
		};
		
		int x = func(A, dp[0]);
		int y = func(B, dp[1]);
		for(int i=0; i<=N; i++){
			for(int j=0; j<=N; j++){
				printf("%d %d %d %d %d\n", i, j, dp[0][i], dp[1][j], dp[0][i] ^ dp[1][j]);
				/*
				if(i==0 && j==0) Answer++;
				else if(i==0) Answer += !!dp[1][j];
				else if(j==0) Answer += !!dp[0][i];
				else // */
					Answer += !!((dp[0][i] ^ dp[1][j]) - 1);
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << ' ' << StateCnt - Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
