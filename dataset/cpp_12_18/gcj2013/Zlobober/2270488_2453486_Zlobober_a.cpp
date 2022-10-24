#include <cstdio>
 #include <cassert>
 using namespace std;
 
 #define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
 const int N = 6;
 char buf[N][N];
 
 void solve(int tc)
 {
     for (int i = 0; i < 4; i++)
         scanf(" %s ", buf[i]);
     bool emp = true;
     int X = (1 << 10) - 1;
     int O = (1 << 10) - 1;
     for (int i = 0; i < 4; i++)
     {
         #define XX(c) ((c) == 'T' || (c) == 'X')
         #define OO(c) ((c) == 'T' || (c) == 'O')
         #define mark(i, j, l) X &= 1023 ^ (!XX(buf[i][j]) << l), O &= 1023 ^ (!OO(buf[i][j]) << l)
         mark(i, i, 0);
         mark(i, 3 - i, 1);
         for (int j = 0; j < 4; j++)
             emp &= buf[i][j] != '.', mark(i, j, 2 + i), mark(i, j, 6 + j);
     }
     printf("Case #%d: ", tc);
     if (X && !O)
         printf("X won\n");
     else if (!X && O)
         printf("O won\n");
     else if (X && O)
         assert(false);
     else if (emp)
         printf("Draw\n");
     else
         printf("Game has not completed\n");
 }
 
 int main()
 {
     int n;
     scanf("%d ", &n);
     for (int i = 0; i < n; i++)
         solve(i + 1);
 }
