#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#define min(a,b) ((a)>(b)?(b):(a))
#define MAX 100000000

using namespace std;
double dp[513][513];

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int N;
		scanf("%d", &N);
		vector<pair<double, double> > v;
		for(int i=0; i<N; i++){
			double x, y;
			scanf("%lf %lf", &x, &y);
			v.push_back(make_pair(x, y));
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				dp[i][j] = MAX;
			}
		}
		dp[0][0] = 0;
		for(int i=0; i<N-1; i++){
			for(int j=0; j<N-1; j++){
				int now = i>j ? i : j;
				now++;
				dp[now][j] = min(dp[now][j], dp[i][j]+hypot(v[i].first-v[now].first, v[i].second-v[now].second));
				dp[i][now] = min(dp[i][now], dp[i][j]+hypot(v[now].first-v[j].first, v[now].second-v[j].second));
			}
		}
		double ans = MAX;
		for(int i=0; i<N; i++){
			double plus = hypot(v[i].first - v[N-1].first, v[i].second - v[N-1].second);
			ans = min(ans, dp[N-1][i] + plus);
			ans = min(ans, dp[i][N-1] + plus);
		}
		printf("%lf\n", ans);
	}
}
