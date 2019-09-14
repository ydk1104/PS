#include<iostream>
#include<vector>
#include<tuple>
#include<queue>

const int vertex_MAX = 100000;
const int edge_MAX = 200000;
const long long int MAX = 1LL << 50;

class dijkstra{
public:
    std::vector<std::pair<int,int> > edge[edge_MAX+1];
    long long int visited[vertex_MAX+1];
    int N,M,K;
    int start,end;
    void input(){
        std::cin >> N >> M >> K;
        for(int i=0; i<N; i++) visited[i] = MAX;
        for(int i=0; i<M; i++){
            int x,y,cost;
            std::cin >> x >> y >> cost;
            edge[x].push_back({cost, y});
            edge[y].push_back({cost, x});
        }
        std::cin >> start >> end;
    }
    long long process(){
        std::priority_queue<std::pair<long long int,int> > pq;
        pq.push({-0, start});
        while(!pq.empty()){
            std::pair<long long int,int> now;
            do{
                now = pq.top(); pq.pop();
            } while(!pq.empty() && visited[now.second] != MAX);
            if(now.second == end) return -now.first;
            visited[now.second] = -now.first;
            for(auto &i : edge[now.second]){
                if(visited[i.second] == MAX)pq.push({-(i.first + visited[now.second]),i.second});
            }
        }
        return -1;
    }
};

int main(void){
    int testCase;
    std::cin >> testCase;
    for(int t=1; t<=testCase; t++){
        dijkstra A;
        A.input();
        std::cout << '#' << t << ' ' << A.process() << '\n';
    }
}
