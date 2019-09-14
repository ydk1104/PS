#include <stdio.h>

void convert(char* a){
   switch(*a){
   case '-':*a='|';break;
   case '|':*a='-';break;
   case '/':*a='\\';break;
   case '\\':*a='/';break;
   case '^':*a='<';break;
   case '<':*a='v';break;
   case 'v':*a='>';break;
   case '>':*a='^';break;
   }
}

int main(void){
   int n,m;
   char a[100][100],b[100][100]={0};
   scanf("%d %d",&n,&m);
   for(int i = 0;i < n;++i)scanf("%s",a[i]);
   for(int i = 0;i < n;++i)for(int j = 0;j < m;++j)b[m-j-1][i]=a[i][j];
   for(int i = 0;i < m;++i)for(int j = 0;j < n;++j)convert(&b[i][j]);
   for(int i=0;i<m;++i)printf("%s\n",b[i]);
   return 0;
}
