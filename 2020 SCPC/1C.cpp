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
int dp[1501][1501];

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

    const int MAX = 1e9;

    setbuf(stdout, NULL);
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
		int N, k, m;
		cin >> N >> k >> m;
		vector<pair<int, int> > v;
		int arr[1501] = {0, };
		for(int i=1; i<=N; i++) arr[i] = i;
		for(int i=1; i<=N; i++)
		    for(int j=1; j<=N; j++)
		        dp[i][j] = MAX;

		auto swap = [](int& x, int& y){
		    int temp = x;
		    x = y;
		    y = temp;
		};
		for(int i=0; i<k; i++){
		    int x,y;
		    cin >> x >> y;
		    v.push_back({arr[x],arr[y]});
		    swap(arr[x], arr[y]);
		}
		
		for(int i=1; i<=N; i++) dp[arr[i]][arr[i]] = dp[arr[i]][arr[i]] = 0;
		for(int i=0; i<k; i++){
			int x = v[i].first, y = v[i].second;
			dp[x][y] = dp[y][x] = 1;
			printf("v : %d %d\n", x,y);
		}
				for(int i=1; i<=N; i++){
		    for(int j=1; j<=N; j++){
		        for(int k=1; k<=N; k++){
		            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
		        }
		    }
		}


		for(int i=1; i<=N; i++)
			for(int j=1; j<=N; j++)
				printf("%d %d %d\n", i, j, dp[i][j]);
		for(int i=0; i<m; i++){
		    int x,y;
		    cin >> x >> y;
		    y = arr[y];
		    Answer += (dp[x][y] == MAX) ? -1 : dp[x][y];
		    printf("Answer : %d, rarr: %d\n", Answer, x);
		}
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
