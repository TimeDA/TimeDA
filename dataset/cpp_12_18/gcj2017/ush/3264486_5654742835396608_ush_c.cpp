#include <cstdio>
 #include <cstring>
 #include <cassert>
 #include <iostream>
 #include <queue>
 using namespace std;
 #define REP(i, n) for(int i = 0; i < (int)(n); ++i)
 typedef long long ll;
 
 struct K {
   ll len, n;
 };
 bool operator<(const K& a, const K& b) {
   return a.len < b.len;
 }
 
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     ll n, k;
     scanf("%lld%lld", &n, &k);
     
     priority_queue<K> q;
     q.push((K){n, 1});
     ll res = -1;
     while(true) {
       K cur = q.top(); q.pop();
       while(!q.empty() && q.top().len == cur.len) {
         cur.n += q.top().n;
         q.pop();
       }
       if(k <= cur.n) {
         res = cur.len;
         break;
       } else {
         k -= cur.n;
         q.push((K){cur.len/2, cur.n});
         q.push((K){(cur.len-1)/2, cur.n});
       }
     }
     
     printf("Case #%d: %lld %lld\n", iCase+1, res/2, (res-1)/2);
   }
   return 0;
 }
