#include<stdio.h>
#include<math.h>
#define ll long long int

using namespace std;

class point{
	public:
	ll x=0;
	ll y=0;
};

point operator +(point x, point y){
	point temp;
	temp.x = x.x + y.x;
	temp.y = x.y + y.y;
	return temp;
}

point operator -(point x){
	point temp;
	temp.x = -x.x;
	temp.y = -x.y;
	return temp;
}

point start;
point tar;
ll N;
char s[100001];

ll distant(point x, point y){
	return abs(x.x - y.x) + abs(x.y - y.y);
}

point wind(char x){
	point temp;
	if(x == 'U') temp.y = 1;
	if(x == 'D') temp.y = -1;
	if(x == 'L') temp.x = -1;
	if(x == 'R') temp.x = 1;
	return temp;
}

int main(void){
	scanf("%lld %lld\n%lld %lld", &start.x, &start.y, &tar.x, &tar.y);
	scanf("%lld", &N);
	scanf("%s", &s);
	point Wind;
	tar = tar + -start;
	ll dis = distant(Wind, tar);
	ll ans = 0;
	for(ll i=1; i<=N; i++){
		point now;
		now = wind(s[i-1]);
		Wind = Wind + now;
		if(distant(Wind, tar)<=ans+i){
			printf("%lld", ans+i);
			return 0;
		}
	}
	ll move = distant(Wind, tar) - dis - N; // move can one cycle
	if(move>=0){
		printf("-1");
		return 0;
	}
	move = -move;
	ll min = tar.x / Wind.x;
	ll min2 = tar.y / Wind.y;
	if(min > min2 && min2 >= 0) min = min2;
	ll count = min;
	ans = (N) * ( count);
	tar.x -= count * Wind.x;
	tar.y -= count * Wind.y;
	Wind = Wind + -Wind;
	dis = distant(Wind, tar);
	if(distant(Wind, tar) <= ans){
		printf("%lld", ans);
		return 0;
	}
	for(ll i=1; i<=N; i++){
		point now;
		now = wind(s[i-1]);
		Wind = Wind + now;
		if(distant(Wind, tar)<=ans + i){
			printf("%lld", ans + i);
			return 0;
		}
	}
	printf("-1");
//	while(1);
}
