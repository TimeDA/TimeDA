#include <cstdio>
 #include <vector>
 #include <cmath>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <memory.h>
 using namespace std;
 
 #define forn(i, n) for (int i = 0; i < (int)(n); i++)
 #define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 #define pb push_back
 typedef long long ll;
 typedef pair<int, int> pii;
 typedef long double ld;
 
 int n, L[1010], p[1010], id[1010];
 
 bool cmp(int i, int j) {
     int v1 = 100*L[i] + L[j]*p[i];
     int v2 = 100*L[j] + L[i]*p[j];
     if (v1 != v2) return v1 < v2;
     else return i < j;
 }
 
 void solve() {
     scanf("%d", &n);
     forn(i, n) scanf("%d", &L[i]);
     forn(i, n) scanf("%d", &p[i]), p[i] = 100 - p[i];
 
     forn(i, n) id[i] = i;
     sort(id, id+n, cmp);
 
     forn(i, n) printf(" %d", id[i]);
     printf("\n");
 }
 
 int main() {
     int tc;
     scanf("%d", &tc);
     for (int q = 1; q <= tc; q++) {
         printf("Case #%d:", q);
         solve();
     }
 }
