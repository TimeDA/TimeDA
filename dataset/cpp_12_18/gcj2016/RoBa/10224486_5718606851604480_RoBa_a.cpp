#include <cstdio>
 #include <string>
 #include <vector>
 using namespace std;
 
 const int MAXK = 13;
 string v[MAXK][3];
 
 void init() {
     v[0][0] = "R";
     v[0][1] = "S";
     v[0][2] = "P";
     for (int i = 1 ; i < MAXK ; ++i) {
         for (int j = 0 ; j < 3 ; ++j) {
             vector<int> t;
             for (int k = 0 ; k < 3 ; ++k) {
                 if (k == j) continue;
                 t.push_back(k);
             }
             if (v[i-1][t[0]] < v[i-1][t[1]])
                 v[i][j] = v[i-1][t[0]] + v[i-1][t[1]];
             else
                 v[i][j] = v[i-1][t[1]] + v[i-1][t[0]];
             // if (i <= 2) printf("v[%d][%d]:%s\n", i,j,v[i][j].c_str());
         }
     }
 }
 
 int main() {
     int T, ca, N, a[3];
     init();
     scanf("%d",&T);
     for (int ca = 1 ; ca <= T ; ++ca) {
         scanf("%d%d%d%d",&N,&a[0],&a[1],&a[2]);
         printf("Case #%d: ", ca);
         int flg = 0;
         for (int k = 0 ; k < 3 ; ++k) {
             int t[3] = {0};
             for (int i = 0 ; i < v[N][k].size() ; ++i) {
                 if (v[N][k][i] == 'R') ++t[0];
                 else if (v[N][k][i] == 'P') ++t[1];
                 else ++t[2];
             }
             if (t[0] == a[0] && t[1] == a[1] && t[2] == a[2]) {
                 printf("%s\n", v[N][k].c_str());
                 flg = 1;
                 break;
             }
         }
         if (!flg) printf("IMPOSSIBLE\n");
     }
     return 0;
 }