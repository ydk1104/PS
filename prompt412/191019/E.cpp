#include<stdio.h>
#include<algorithm>

int main(void){
	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	int min = std::min({a[0],a[1],a[2]});
	for(auto& i:a) i-=min;
	std::sort(a, a+3);
//	printf("%d %d %d\n", a[0],a[1],a[2]);
	int match = std::min(a[2]/2, a[1]);
	a[2] -= match*2; a[1] -= match;
	int match2 = std::min(a[1]/2, a[2]);
	a[1] -= match2*2; a[1] -= match2;
	int match3 = std::min(a[1]/3, match);
	a[1] -= match3*3;
	printf("%d\n", min+match + std::min(a[2]/3,min) + std::min(a[1]/3, min));
//	printf("%d %d %d", a[0], a[1], a[2]);
}
