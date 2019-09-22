#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
vector<int> v[501];
int cost[501][501];
int visited[501][501];

const int MAXN = 2000;
struct MCMF{
    struct edg{ int pos, cap, rev, cost; };
    vector<edg> gph[MAXN];
    void clear(){
        for(int i=0; i<MAXN; i++) gph[i].clear();
    }
    void add_edge(int s, int e, int x, int c){
        gph[s].push_back({e, x, (int)gph[e].size(), c});
        gph[e].push_back({s, 0, (int)gph[s].size()-1, -c});
    }
    int dist[MAXN], pa[MAXN], pe[MAXN];
    bool inque[MAXN];
    bool spfa(int src, int sink){
        memset(dist, 0x3f, sizeof(dist));
        memset(inque, 0, sizeof(inque));
        queue<int> que;
        dist[src] = 0;
        inque[src] = 1;
        que.push(src);
        bool ok = 0;
        while(!que.empty()){
            int x = que.front();
            que.pop();
            if(x == sink) ok = 1;
            inque[x] = 0;
            for(int i=0; i<gph[x].size(); i++){
                edg e = gph[x][i];
                if(e.cap > 0 && dist[e.pos] > dist[x] + e.cost){
                    dist[e.pos] = dist[x] + e.cost;
                    pa[e.pos] = x;
                    pe[e.pos] = i;
                    if(!inque[e.pos]){
                        inque[e.pos] = 1;
                        que.push(e.pos);
                    }
                }
            }
        }
        return ok;
    }
    int match(int src, int sink){
        int ret = 0;
        while(spfa(src, sink)){
            int cap = 1e9;
            for(int pos = sink; pos != src; pos = pa[pos]){
                cap = min(cap, gph[pa[pos]][pe[pos]].cap);
            }
            ret += dist[sink] * cap;
            for(int pos = sink; pos != src; pos = pa[pos]){
                int rev = gph[pa[pos]][pe[pos]].rev;
                gph[pa[pos]][pe[pos]].cap -= cap;
                gph[pos][rev].cap += cap;
            }
        }
        return ret;
    }
}flow;




void bfs(int x){
   queue<pair<int, int>> q;
    visited[x][x] = 1;
   q.push({x, cost[x][x] = 0});
   while(!q.empty()){
      auto now = q.front(); q.pop();
      for(auto i:v[now.first]){
         if(visited[x][i]) continue;
         visited[x][i] = 1;
         q.push({i, cost[x][i] = now.second+1});
      }
   }
}

int main(void){
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int T;
   cin >> T;
   while(T--){
      int N, M;
      cin >> N >> M;
      for(int i=0; i<N; i++) v[i].clear(); flow.clear();
      int cv[505],cc[505];
      for(int i=0; i<M; i++){
         int x,y;
         cin >> x >> y;
         x--; y--;
         v[x].push_back(y);
         v[y].push_back(x);
      }
      for(int i=0; i<N; i++){
         for(int j=0; j<N; j++){
            visited[i][j] = 0;
         }
         cin >> cv[i];
      }
      int black = 0;
      for(int i=0; i<N; i++){
         cin >> cc[i];
         black += cc[i];
      }
      for(int i=0; i<N; i++){
          //  cout << i <<"\n" <<endl;
         bfs(i);
      }

     // cout<<"!";
      int start = 1010;
      int finish = 1011;
      for(int i=0;i<N;i++) if(cc[i]) flow.add_edge(start,i,1,0);
      for(int i=0;i<N;i++) if(cv[i]) flow.add_edge(i+503,finish,1,0);

      for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(cc[i] && cv[j]){

                //cout<<i<<' '<<(j)<<' '<<cost[i][j]<<'\n';
                flow.add_edge(i,j+503,1,cost[i][j]);
            }
        }
      }

      //cout<<"!";


      cout<<(flow.match(start,finish))<<'\n';


   }
}

