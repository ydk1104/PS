#include<stdio.h>
#include<set>


int main(void){
	int T;
	for(scanf("%d", &T); T--;){
		std::multiset<int> s;
		int N;
		scanf("%d", &N);
		while(N--){
			getchar();
			char x;
			int y;
			scanf("%c %d", &x, &y);
			if(x=='I') s.insert(y);
			else if(s.empty()){}
			else if(y==-1) s.erase(s.begin());
			else s.erase(--s.end());
//			for(auto i : s) printf("%d ", i);
//			printf("\n");
		}
		if(s.empty()) printf("EMPTY\n");
		else printf("%d %d\n", *s.rbegin(), *s.begin());
	}
}
