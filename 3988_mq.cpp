#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

// https://github.com/Malatawy15/Algorithms-Library/blob/master/Data%20Structures/C%2B%2B/Monotone%20Queue.cpp

struct monotone_queue{
    queue<int> main_queue;
    deque<int> min_queue;

    void push(int x){
        main_queue.push(x);
        while(!min_queue.empty()&&x<min_queue.back()){
            min_queue.pop_back();
        }
        min_queue.push_back(x);
    }

    int pop(){
        int n = main_queue.front();
        if (n==min_queue.front()){
            min_queue.pop_front();
        }
        main_queue.pop();
        return n;
    }

    int get_min(){
        return min_queue.front();
    }

    int front(){
        return main_queue.front();
    }

    int size(){
        return main_queue.size();
    }
};

// https://github.com/Malatawy15/Algorithms-Library/blob/master/Data%20Structures/C%2B%2B/Monotone%20Queue.cpp 

int main(){
    monotone_queue mq;
    int N, M;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    std::vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];
    std::sort(v.begin(), v.end());
    M = N-M-1;
    for(int i=0; i<M-1; i++) mq.push(v[i+1]-v[i]);
    int ans = 1e9;
    for(int i=M; i<N; i++){
    	mq.push(v[i]-v[i-1]);
    	ans = std::min(ans, mq.get_min()+v[i]-v[i-M]);
    	mq.pop();
	}
	cout << ans;
}
