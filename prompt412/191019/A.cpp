#include<stdio.h>
 
char s1[20], s2[20];
 
int main(){
    scanf("%s %s", s1, s2);
    for(int i=1; s1[i]; i++){
        if(s1[i] >= s2[0]) s1[i]=0;
    }
    printf("%s%c",s1,*s2);
}
