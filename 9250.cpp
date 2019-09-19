#include<iostream>
#include<string>
#include<queue>

struct trie{
	trie *next[26] = {0, };
	trie *fail = 0;
	int cnt=0;
	trie(){for(int i=0; i<26; i++) next[i] = 0; fail=0; cnt=0;}
	~trie(){
		for(int i=0; i<26; i++) if(next[i]) delete next[i];
	}
};

struct ahocorasick{
	trie *root;
	void __init__(int N){ // input string, make fail func
		root = new trie;
		for(int i=0; i<N; i++){
			std::string s;
			std::cin >> s;
			trie *now = root;
			for(auto &c:s){
				c -= 'a';
				if(now->next[c]) now=now->next[c];
				else{
					now->next[c] = new trie;
					now=now->next[c];
				}
			}
			now->cnt++;
		}
		std::queue<trie*> q; // Reference : http://blog.naver.com/kks227/220992598966
		q.push(root);
		while(!q.empty()){
			trie *now = q.front(); q.pop();
			for(int i=0; i<26; i++){
				trie *next = now->next[i];
				if(!next) continue;
				q.push(next);
				if(now == root) next->fail = root;
				else{
					trie *temp = now->fail;
					while(temp!=root && temp->next[i]==NULL) temp=temp->fail;
					if(temp->next[i]) temp=temp->next[i];
					next->fail = temp;
				}
				next->cnt += next->fail->cnt;
			}
		}
	}
	void find(std::string &s){
		trie *now = root;
		for(auto &c : s){
			c-='a';
			while(now != root && now->next[c] == NULL) now = now->fail;
			if(now->next[c]) now=now->next[c];
			if(now->cnt){
				std::cout << "YES" << '\n';
				return;
			}
		}
		std::cout << "NO" << '\n';
	}
	void __del__(){
		delete root;
	}
}x;

int main(void){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int M;
	std::cin >> M;
	x.__init__(M);
	int N;
	std::cin >> N;
	while(N--){
		std::string s;
		std::cin >> s;
		x.find(s);
	}
	x.__del__();
}
