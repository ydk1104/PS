#include<stdio.h>

int main(void){
    int N, ans=-1;
    scanf("%d", &N);
    if(N%2 && N%5){
        int temp = 1; ans = 1;
        while(temp%=N) temp = temp * 10 + 1, ans++;
    }
    printf("%d",ans);
}
