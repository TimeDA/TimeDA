
 
 
 /*
     Prob:   Google Code Jam Qualification Round 2014
     Author: peanut
     Time:   12/04/14 15:47
     Description:
 */
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <algorithm>
 using namespace std;
 
 const int MaxN = 10;
 
 int check[MaxN][MaxN], row[MaxN << 1], col[MaxN << 1];
 int T;
 
 int main(int argc, char* argv[]) {
     if (argc >= 2) {
         string input_file  = "A-" + string(argv[1]) + ".in",
                output_file = "A-" + string(argv[1]) + ".out";
         freopen(input_file.c_str(), "r", stdin);
         freopen(output_file.c_str(), "w", stdout);
     }
     
     scanf("%d", &T);
     for (int testcase = 1; testcase <= T; ++ testcase) {
         int x, y;
         scanf("%d", &x);
         for (int i = 1; i <= 4; ++ i)
             for (int j = 1; j <= 4; ++ j) {
                 int tmp; scanf("%d", &tmp);
                 row[tmp] = i;
             }
         scanf("%d", &y);
         for (int i = 1; i <= 4; ++ i)
             for (int j = 1; j <= 4; ++ j) {
                 int tmp; scanf("%d", &tmp);
                 col[tmp] = i;
             }
         
         printf("Case #%d: ", testcase);
         memset(check, -1, sizeof check);
         for (int k = 1; k <= 16; ++ k) {
             if (check[row[k]][col[k]] < 0) 
                 check[row[k]][col[k]] = k;
             else 
                 check[row[k]][col[k]] = 0;
         }
         
         if (check[x][y] < 0)
             puts("Volunteer cheated!");
         else if (check[x][y] == 0)
             puts("Bad magician!");
         else 
             printf("%d\n", check[x][y]);
     }
     
     return 0;
 }
