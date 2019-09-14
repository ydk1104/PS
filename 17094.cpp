#include<stdio.h>
int a[2];char s[100001];main(int i){gets(s);gets(s);for(i=0;s[i];i++)a[s[i]>65]++;if(*a==a[1])puts("yee");else*a>a[1]?puts("2"):puts("e");}
