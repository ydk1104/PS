#include<stdio.h>
#include<vector>

std::vector<int> prime;

// by https://casterian.net/archives/396
using ull = unsigned long long;
 
std::vector<ull> alist = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

// calculate (x + y) % m; overflow-safe
inline ull addmod(ull x, ull y, ull m) {
    x %= m;
    y %= m;
    return (x >= m - y? x - (m - y) : x + y);
}
 
// calculate (x * y) % m; overlow-safe
inline ull mulmod(ull x, ull y, ull m) {
    x %= m;
    y %= m;
    ull r = 0;
    while (y > 0) {
        if (y % 2 == 1)
            r = addmod(r, x, m);
        x = addmod(x, x, m);
        y /= 2;
    }
    return r;
}
 
// calculate x^y % m; overflow-safe
ull powmod(ull x, ull y, ull m) {
    x %= m;
    ull r = 1ULL;
    while (y > 0) {
        if (y % 2 == 1)
            r = mulmod(r, x, m);
        x = mulmod(x, x, m);
        y /= 2;
    }
    return r;
}
 
// true for probable prime, false for composite
inline bool miller_rabin(ull n, ull a) {
    ull d = n - 1;
    while (d % 2 == 0) {
        if (powmod(a, d, n) == n-1)
            return true;
        d /= 2;
    }
    ull tmp = powmod(a, d, n);
    return tmp == n-1 || tmp == 1;
}
 
bool is_prime(ull n) {
    if (n <= 1)
        return false;
    if (n <= 10000000000ULL) {
        for (ull i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }
    for (ull a : alist)
        if (!miller_rabin(n, a))
            return false;
    return true;
}

// by https://casterian.net/archives/396

void func(long long N, std::vector<long long>& v, long long prev){
	if(N==1) return;
	if(is_prime(N)){
		v.push_back(N);
		return;
	}
	else{
		long long i=prev;
		while(N%i) i+=2;
		while(!(N%i)) N/=i;
		v.push_back(i);
		func(N, v, i+2);
//		func(i, v);
	}
}

int main(void){
	long long N;
	scanf("%lld", &N);
	long long temp = N;
	std::vector<long long> v;
	if(!(temp&1)){
		v.push_back(2);
		while(!(temp&1)) temp/=2;
	}
	func(temp, v, 3);
	for(auto &i : v) N -= N/i;
	printf("%lld", N);
}
