//https://github.com/Malatawy15/Algorithms-Library/blob/master/Data%20Structures/C%2B%2B/Monotone%20Queue.cpp

#include <stdio.h>
#include <queue>
#include <deque>

using namespace std;

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

int a[5000001];

int main(){
    monotone_queue mq;
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
    	scanf("%d", &a[i]);
    	mq.push(a[i]);
    	printf("%d ", mq.get_min());
    	if(i>=K-1) mq.pop();
	}
}
