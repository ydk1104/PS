#include<stdio.h>
#include<algorithm>

using namespace std;

class Conference{
	public:
	int start;
	int end;
	void scan(void){
		scanf("%d %d", &start, &end);
	}
	bool operator <(Conference &x){
		if(this->end == x.end) return this->start<x.start;
		return this->end < x.end;
	}
};

Conference C[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) C[i].scan();
	sort(C, C+N);
	int now=0, ans=0;
	for(int i=0; i<N; i++){
		if(now<=C[i].start){
			now = C[i].end;
			ans++;
		}
	}
	printf("%d", ans);
}
