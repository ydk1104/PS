#include<stdio.h>
#include<stdlib.h>

struct node{
	char ans;
	node* prev;
	node* next;
};

char s[1000001];

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", &s);
		node* ans = (node*)malloc(sizeof(node));
		ans->prev = NULL;
		ans->next = NULL;
		node* ptr = ans;
		for(int i=0; s[i]; i++){
			if(s[i] == '-'){
				if(ptr->prev==NULL) continue;
				node* temp = ptr;
				ptr = ptr->prev;
				ptr->next = temp->next;
				if(ptr->next != NULL) ptr->next->prev = ptr;
				free(temp);
			}
			else if(s[i] == '<'){
				if(ptr->prev != NULL) ptr = ptr->prev;
			}
			else if(s[i] == '>'){
				if(ptr->next != NULL) ptr = ptr->next;
			}
			else{
				node* temp = (node*)malloc(sizeof(node));
				temp->ans = s[i];
				temp->prev = ptr;
				temp->next = ptr->next;
				if(ptr->next != NULL) ptr->next->prev = temp;
				ptr->next = temp;
				ptr = ptr->next;
			}
		}
		for(node* temp = ans; temp->next != NULL; temp = temp->next){
			printf("%c", temp->next->ans);
			if(temp->prev!=NULL) free(temp->prev);
		}
		printf("\n");
	}
}
