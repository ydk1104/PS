#include <stdio.h>

int block[1000][1000];
int progress[1000][1000][11];
int list[11000500][3];
int count = 0; int now = 0;
int x, y, k;

void append(int curx, int cury, int curk, int curn) {
   if (block[curx][cury] == 1 && curk != k) {
      if (progress[curx][cury][curk + 1] == 0) {
         list[count][0] = curx;
         list[count][1] = cury;
         list[count++][2] = curk + 1;
         progress[curx][cury][curk + 1] = curn;
         // printf("%d %d %d %d appended\n", curx, cury, curk + 1, count);
      }
   }
   else if (block[curx][cury] == 0) {
      if (progress[curx][cury][curk] == 0) {
         list[count][0] = curx;
         list[count][1] = cury;
         list[count++][2] = curk;
         progress[curx][cury][curk] = curn;
         // printf("%d %d %d %d appended\n", curx, cury, curk, count);
      }
   }
}

void navigate(int curx, int cury, int curk) {
   now++;
   int curn = progress[curx][cury][curk];
   // printf("%d %d %d %d\n", curx, cury, curk, curn);
   if (curx != 0) {
      append(curx - 1, cury, curk, curn + 1);
   }
   if (cury != 0) {
      append(curx, cury - 1, curk, curn + 1);
   }
   if (curx + 1 != x) {
      append(curx + 1, cury, curk, curn + 1);
   }
   if (cury + 1 != y) {
      append(curx, cury + 1, curk, curn + 1);
   }
   if (now != count) navigate(list[now][0], list[now][1], list[now][2]);
}

int main() {
   int i, j, ans = -1; char temp;
   scanf("%d %d %d", &y, &x, &k);
   for (i = 0; i < y; i++) {
      scanf("%c", &temp);
      for (j = 0; j < x; j++) {
         scanf("%c", &temp);
         block[j][i] = temp - 48;
      }
   }

   count++; progress[0][0][0] = 1;
   navigate(list[now][0], list[now][1], list[now][2]);

   for (i = 0; i <= k; i++) {
      int newest = progress[x - 1][y - 1][i];
      if (newest == 0) continue;
      else if (newest < ans || ans == -1) ans = newest;
   }

   printf("%d", ans);

   return 0;
}
