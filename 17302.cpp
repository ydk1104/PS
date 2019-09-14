#include<bits/stdc++.h>
#define ll long long
#define inf 1000001
#define pll pair<ll,ll>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define forn(i,n) for(ll i=1;i<=n;i++)
#define forRn(i,n) for(ll i=n;i>=1;i--)
#define forz(i,n) for(ll i=0;i<n;i++)
#define forRz(i,n) for(ll i=n-1;i>=0;i--)
#define forab(i,a,b) for(ll i=a;i<=b;i++)
#define mod 998244353
#define has 3
ll gcd(ll x,ll y){ return y==0?x:gcd(y,x%y); }
ll lcm(ll x,ll y){ return x/gcd(x,y)*y; }

ll N,M;
ll arr[2005][2005];
ll ans[2005][2005];
int main(void)
{
    magic;
    cin>>N>>M;
    forn(i,N){
        string str;
        cin>>str;
        ll ssiz = str.size();
        forz(j,ssiz){
            if(str[j]=='W') arr[i][j+1] = 1;
            else arr[i][j+1] = 0;
        }
    }

    forn(i,N) forn(j,M){
        forn(ii,3) forn(jj,3){
            arr[i-ii+2][j-jj+2]++;
            arr[i-ii+2][j-jj+2]%=2;
            ans[i][j] = 3;
        }
    }

    forn(i,N) forn(j,M){
        if(arr[i][j]%2==0){
            ans[i][j] = 2;
        }
    }

    cout<<"1"<<'\n';
    forn(i,N){
        forn(j,M) cout<<ans[i][j];
        cout<<'\n';
    }

}










