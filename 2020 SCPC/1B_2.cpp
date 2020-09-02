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
int dp[3001][3001];

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
		
		dp[0][0] = 1;
//		dp[1][0] = dp[0][1] = 0;

		for(int i=0; i<=N; i++){
			for(int j=0; j<=N; j++){
				dp[i][j] = !(i||j);
			    int check[3001] = {0, };
			    int sum = 0;
			    if(i) for(int k=1; k<=i; k++){
			        sum += A[i-k];
			        if(sum > K) break;
			        check[dp[i-k][j]]++;
			    }
			    sum = 0;
			    if(j) for(int k=1; k<=j; k++){
			        sum += B[j-k];
			        if(sum > K) break;
			        check[dp[i][j-k]]++;
			    }
			    while(check[dp[i][j]]) dp[i][j]++;
			    printf("dp : %d %d %d\n", i, j, dp[i][j]);
			    Answer += !!dp[i][j];
			}
		}

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << ' ' << StateCnt - Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
