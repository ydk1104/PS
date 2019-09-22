#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
struct TarjanScc{
	vector<int> graph[MAXN];
	int up[MAXN], visit[MAXN], vtime;
	vector<int> stk;
	int scc_idx[MAXN], scc_cnt;
	
	int CNT[MAXN];
	
	vector<int> dag[MAXN]; /// start where One Index
	
	void init(int n){
		for(int i=0;i<=n;i++){
			graph[i].clear();
			up[i] = 0;
			visit[i] = 0;
			scc_idx[i] = 0;
			CNT[i] = 0;
			dag[i].clear();
		}
		vtime = 0;
		stk.clear();
		scc_cnt = 0;
		
	}
	
	void dfs(int nod){
		up[nod] = visit[nod] = ++vtime;
		stk.push_back(nod);
		for(int next:graph[nod]){
			if(visit[next]==0){
				dfs(next);
				up[nod] = min(up[nod], up[next]);
			}
			else if(scc_idx[next]==0)
				up[nod] = min(up[nod],visit[next]);
		}
		if(up[nod]==visit[nod]){
			++scc_cnt;
			int t;
			int chk = 0;
	     	 int counting = 0; ////
			do{
				t = stk.back();
				CNT[t] = counting; counting++; ////
				dag[scc_cnt].push_back(t);
				stk.pop_back();
				scc_idx[t] = scc_cnt;
			} while( !stk.empty() && t != nod );
		}
	}
	
	void ReverseAndCounting(){
		int N = scc_cnt;
		for(int i=1;i<=scc_cnt;i++){
			reverse(dag[i].begin(),dag[i].end());
			int counting = 0;
			for(int j = 0; j<dag[i].size();j++){
				CNT[dag[i][j]] = counting; counting++;
			}
		}
	}
	
	void get_scc(int n){
		vtime = 0;
		memset(visit,0,sizeof(visit));
		scc_cnt = 0;
		memset(scc_idx,0,sizeof(scc_idx));
		for(int i=1;i<=n;i++)
			if(visit[i]==0) dfs(i);
	}
	
}scc;
int main(void){
	int T;
	scanf("%d",&T);
	for(int test=1;test<=T;test++){
	// printf("====================\n");
		
		int N,M;
		int found = 0;
		scanf("%d %d",&N,&M);
		scc.init(N);
		for(int i=1;i<=M;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			scc.graph[x].push_back(y);
		}
		scc.get_scc(N);//  scc.ReverseAndCounting();
	/*	 printf("Cycle %d\n",scc.scc_cnt);
		for(int Cycle=1;Cycle<=scc.scc_cnt;Cycle++){
			int dsiz = scc.dag[Cycle].size();
			for(int i = 0; i<dsiz;i++){
				printf("%d ",scc.dag[Cycle][i]);
			}
			printf("\n");
		} */
//	 printf("Cycle2 %d\n",scc.scc_cnt);
		for(int Cycle=1;Cycle<=scc.scc_cnt;Cycle++){
			if(found) break;
			int dsiz = scc.dag[Cycle].size();
			
			if(dsiz%2==1&&dsiz>=2){
				found = 1;
				printf("1\n");
				printf("%d\n",dsiz);
				vector<int> res;
				for(auto p:scc.dag[Cycle]){
					res.push_back(p);
				}
				reverse(res.begin(),res.end());
				for(auto p:res) printf("%d\n",p);
			}
			
			
			for(int i = 0; i<dsiz;i++){
				if(found) break;
				// printf("%d ",scc.CNT[scc.dag[Cycle][i]]);
				int u = scc.dag[Cycle][i];
				for(auto v:scc.graph[u]){
					if(found) break;
					if(scc.scc_idx[u]==scc.scc_idx[v]){
						int uwhere = scc.CNT[u];
						int vwhere = scc.CNT[v];
						if(uwhere>vwhere){
							vwhere = vwhere + dsiz;
						}
						int Size = vwhere-uwhere+1;
						if(Size%2==1&&Size>=2){
							found = 1;
							printf("1\n");
							printf("%d\n",Size);
							vector<int> res;
							for(int k = uwhere ; k <= vwhere; k++ ){
								res.push_back(scc.dag[Cycle][ k%dsiz ]);
								// printf("%d\n",scc.dag[Cycle][ k%dsiz ]);
							}
							reverse(res.begin(),res.end());
							 for(auto p:res) printf("%d\n",p);
						}
					}
				}
			}
			//printf("\n");
		}
		if(!found) printf("-1\n");
	}
}

/*
1
6 7
1 2
2 3
3 4
4 5
5 6
6 1
5 1
*/

