#include<stdio.h>
main(void){int H,M,S,T;scanf("%d%d%d%d", &H,&M,&S,&T);S+=T;M+=S/60;S%=60;H+=M/60;M%=60;H%=24;printf("%d %d %d",H,M,S);}
