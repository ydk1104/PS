#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

class students{
	public:
	char name[15];
	int score[3]; // korean, english, math
	void scan(){
		scanf("%s", &name);
		for(int i=0; i<3; i++)scanf("%d", &score[i]);
	}
	bool operator <(students &x){
		for(int i=0; i<3; i++){
			if(this->score[i] != x.score[i]){
				if(i%2) return this->score[i] < x.score[i];
				return this->score[i] > x.score[i];
			}
		}
		int temp = strcmp(x.name, this->name);
		if(temp<0) temp=0;
		return temp;
	}
};

students S[100001];

int main(void){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++) S[i].scan();
	sort(S, S+N);
	for(int i=0; i<N; i++) printf("%s\n", &S[i].name);
}
