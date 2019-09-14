#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_MAX_SIZE 1024
#define DELIM " \n"


typedef struct { 
    int stk[STACK_MAX_SIZE];
    int top;
} Stack;

void push(int v, Stack * stack) {
	  if (stack->top < 0 || stack->top >= STACK_MAX_SIZE) {
        return ;
    }
    stack->stk[stack->top++] = v;
}

int pop(Stack * stack) {
	  if (stack->top <= 0 || stack->top > STACK_MAX_SIZE) {
        return 0;
    }
    return stack->stk[--stack->top];
}


//Implement this structure
//Please use stack only
typedef struct {
	Stack front;
	Stack back;
} Queue;

//Implement this function
//Please use stack only
void enqueue(int v, Queue * q) {
	push(v, &q->front);
    /*
     * Description: insert value at front stack
     * Time complexity: O(1)
     * Space complexity: O(N)
     */    
}

//Implement this function
//Please use stack only
int dequeue(Queue * q) {
	if(q->back.top == 0){
		while(q->front.top>0){
			push(pop(&q->front), &q->back);
		}
	}
	return pop(&q->back);
    /*
     * Description: if back has no data, pop front
     it looks like reverse front
     so first data moves to top
     * Time complexity: O(N)
     * Space complexity: O(N)
     */    
}


int main(int argc, const char *argv[]) {

    Queue q;
    q.front.top = 0;
    q.back.top = 0;
    for(int i=0; i<STACK_MAX_SIZE; i++){
    	q.front.stk[i] = 0;
    	q.back.stk[i] = 0;
	}
    char buffer[BUFSIZ] = {'\0', };
    char *token = NULL, *brkt = NULL;
    int count = 0;

	  /* You might need codes here initializing stacks for Queue. */
	
    fgets(buffer, sizeof(buffer), stdin);
    count = atoi(buffer);

    for (int i = 0 ; i < count ; i++) {

        fgets(buffer, sizeof(buffer), stdin);
        token = strtok_r(buffer, DELIM, &brkt);

        if (strcmp(token, "ENQUEUE") == 0) {
            token = strtok_r(NULL, DELIM, &brkt);
            enqueue(atoi(token), &q);
        }
        else if (strncmp(token, "DEQUEUE", 7) == 0) {
            printf("%d\n", dequeue(&q));
        }
    }

    return 0;
}

