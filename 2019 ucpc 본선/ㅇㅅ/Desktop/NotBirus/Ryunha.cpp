#include<bits/stdc++.h>
#define lint long long
#define inf 100000000009
#define pii pair<int,int>
#define magic ios_base::sync_with_stdio(false);cin.tie(nullptr)
using namespace std;
#define forn(i,n) for(int i=1;i<=n;i++)
#define forRn(i,n) for(int i=n;i>=1;i--)
#define forz(i,n) for(int i=0;i<n;i++)
#define forRz(i,n) for(int i=n-1;i>=0;i--)
#define forab(i,a,b) for(int i=a;i<=b;i++)
#define forRab(i,a,b) for(int i=a;i>=b;i--)
#define mod 998244353
#define has 3

const int MAXN = 1000;
int arr[MAXN+5];
int main(void)
{
    magic;
    int D;
    cin>>D;
    forn(i,MAXN){
        int ii = i;
        int tren = 0;
        while(ii>0){
            tren = tren*10 + (ii%10);
            ii/=10;
         //   cout<<i<<' '<<ii<<'\n';
        }
        if(i-tren>0&&!arr[i-tren]) arr[i-tren] = i;
    }

    forn(i,MAXN){
        cout<<i<<" : "<<arr[i]<<'\n';
    }

    if(arr[D]) cout<<arr[D];
    else cout<<-1;

}
