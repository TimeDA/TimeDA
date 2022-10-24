#include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <algorithm>
 #include <queue>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 
 char buf[50][50];
 
 struct K {
   int len;
   int di, dj;
   int i, j;
   char ch;
 };
 bool operator<(const K& a, const K& b) {
   return a.len < b.len;
 }
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     int nRow, nCol;
     scanf("%d%d", &nRow, &nCol);
     REP(i, nRow) {
       scanf("%s", buf[i]);
     }
 
     priority_queue<K> q;
     for(char ch = 'A'; ch <= 'Z'; ++ch) {
       int iMin = 100;
       int iMax = -1;
       int jMin = 100;
       int jMax = -1;
       REP(i, nRow) REP(j, nCol) {
         if(buf[i][j] == ch) {
           iMin = min(iMin, i);
           iMax = max(iMax, i);
           jMin = min(jMin, j);
           jMax = max(jMax, j);
         }
       }
       if(iMax >= 0) {
         REP(i, iMax-iMin+1) REP(j, jMax-jMin+1) {
           buf[iMin+i][jMin+j] = ch;
         }
         q.push((K){iMax-iMin+1, 0, 1, iMin, jMax+1, ch});
         q.push((K){iMax-iMin+1, 0, -1, iMin, jMin-1, ch});
         q.push((K){jMax-jMin+1, 1, 0, iMax+1, jMin, ch});
         q.push((K){jMax-jMin+1, -1, 0, iMin-1, jMin, ch});
       }
     }
 
     while(!q.empty()) {
       K cur = q.top(); q.pop();
       if(cur.i < 0 || cur.j < 0 || cur.i >= nRow || cur.j >= nCol) {
         continue;
       }
       int ci = cur.i;
       int cj = cur.j;
       bool updated = false;
       for(;; ci += cur.di, cj += cur.dj) {
         if(cur.di != 0) {
           bool ok = true;
           REP(j, cur.len) {
             ok = ok && buf[ci][cj+j] == '?';
           }
           if(ok) {
             REP(j, cur.len) {
               buf[ci][cj+j] = cur.ch;
             }
             updated = true;
           } else {
             break;
           }
         } else {
           bool ok = true;
           REP(i, cur.len) {
             ok = ok && buf[ci+i][cj] == '?';
           }
           if(ok) {
             REP(i, cur.len) {
               buf[ci+i][cj] = cur.ch;
             }
             updated = true;
           } else {
             break;
           }
         }
       }
       if(updated) {
         q = priority_queue<K>();
         for(char ch = 'A'; ch <= 'Z'; ++ch) {
           int iMin = 100;
           int iMax = -1;
           int jMin = 100;
           int jMax = -1;
           REP(i, nRow) REP(j, nCol) {
             if(buf[i][j] == ch) {
               iMin = min(iMin, i);
               iMax = max(iMax, i);
               jMin = min(jMin, j);
               jMax = max(jMax, j);
             }
           }
           if(iMax >= 0) {
             q.push((K){iMax-iMin+1, 0, 1, iMin, jMax+1, ch});
             q.push((K){iMax-iMin+1, 0, -1, iMin, jMin-1, ch});
             q.push((K){jMax-jMin+1, 1, 0, iMax+1, jMin, ch});
             q.push((K){jMax-jMin+1, -1, 0, iMin-1, jMin, ch});
           }
         }
       }
     }
 
     REP(i, nRow) REP(j, nCol) {
       assert(buf[i][j] != '?');
     }
 
     printf("Case #%d:\n", iCase+1);
     REP(i, nRow) {
       printf("%s\n", buf[i]);
     }
   }
   return 0;
 }
