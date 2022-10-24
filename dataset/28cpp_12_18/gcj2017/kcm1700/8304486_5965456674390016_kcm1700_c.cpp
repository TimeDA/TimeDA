#include <cstdio>
 #include <climits>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 struct edge_t {
   int dest;
   int at;
   int duration;
 };
 
 int main() {
   int T;
   scanf("%d", &T);
   for (int testcase = 1; testcase <= T; testcase++) {
     int n;
     scanf("%d", &n);
     vector<edge_t> info;
     for (int i = 0; i < n * 2; i++) {
       int e, l, d;
       scanf("%d%d%d", &e, &l, &d);
       e--;
       edge_t edge;
       edge.dest = e;
       edge.at = l;
       edge.duration = d;
       info.emplace_back(edge);
     }
 
     int ans = INT_MAX;
     for (int st = 0; st < (1 << n); st++) {
       // determines order
       vector<int> vcnt(n);
       int startP = 0;
       int len = 0;
 
       int curTime = 0;
       for (int i = 0; i < 2 * n; i++) {
         int edgeIndex = startP*2;
         int firstTour = 0;
         if (st & (1 << startP)) firstTour = 1;
         if (vcnt[startP] == 0) edgeIndex += firstTour;
         else edgeIndex += 1 - firstTour;
         if (++vcnt[startP] > 2) {
           len = -1;
           break;
         }
 
         if (curTime > info[edgeIndex].at) {
           len += 24 - curTime;
           curTime = 0;
         }
         len += info[edgeIndex].at - curTime;
         len += info[edgeIndex].duration;
         curTime = (info[edgeIndex].at + info[edgeIndex].duration) % 24;
         startP = info[edgeIndex].dest;
       }
 
       if (len >= 0) {
         ans = min(ans, len);
       }
     }
     printf("Case #%d: %d\n", testcase, ans);
   }
   return 0;
 }