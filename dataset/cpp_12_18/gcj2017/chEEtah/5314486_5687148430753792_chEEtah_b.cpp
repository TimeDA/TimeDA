#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <cmath>
 #include <cassert>
 #include <sstream>
 #include <functional>
 #include <algorithm>
 #include <map>
 #include <string>
 #include <vector>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 int nt;
 int N, C, M;
 
 vector< pair<int, int> > a;
 
 // Used seat i in round j by customer used[i][j]
 int used[1001][1001];
 
 // Customer i done ride in round j in position done[i][j]
 int done[1001][1001];
 
 // Seat i used cnt[i] times
 int cnt[1001];
 
 int push_c, push_r;
 int was[1001];
 
 bool push(int p)
 {
     if (was[p]) return false;
     was[p] = true;
 
     for(int i = 1; i <= push_r; i++)
     if (!used[p][i])
     {
         if (!done[push_c][i])
         {
             used[p][i] = push_c;
             done[push_c][i] = p;
             cnt[p]++;
             return true;
         }
 
         int p2 = done[push_c][i];
 
         if (push(p2))
         {
             used[p2][i] = 0;
             used[p][i] = push_c;
             done[push_c][i] = p;
             cnt[p2]--;
             cnt[p]++;
             return true;
         }
     }
     return false;
 }
 
 
 int ok(int r)
 {
     memset(used, 0, sizeof used);
     memset(done, 0, sizeof done);
     memset(cnt,  0, sizeof cnt );
     int res = 0;
     for(int i = 0; i < M; i++)
     {
         int p = a[i].first;
         int c = a[i].second;
 
         bool found = false;
         for(int j = 1; j <= r; j++)
             if (!used[p][j] && !done[c][j])
             {
                 used[p][j] = c;
                 done[c][j] = p;
                 cnt[p]++;
                 found = true;
                 break;
             }
         if (found) continue;
 
         // push
         memset(was, 0, sizeof was);
         push_c = c;
         push_r = r;
         if (push(p)) continue;
 
         // give up
         for(int np = 1; np < p; np++)
             if (cnt[np] < r && !found)
             for(int j = 1; j <= r; j++)
                 if (!used[np][j] && !done[c][j])
                 {
                     used[np][j] = c;
                     done[c ][j] = np;
                     cnt[np]++;
                     found = true;
                     res++;
                     break;
                 }
         if (!found) return -1;
     }
     return res;
 }
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
         scanf("%d %d %d", &N, &C, &M);
 
         a.clear();
         for(int i = 0; i < M; i++)
         {
             int p, c;
             scanf("%d %d", &p, &c);
             a.push_back(make_pair(p, c));
         }
 
         sort(a.begin(), a.end());
 
         int L = 0, R = M;
         while(L != R - 1)
         {
             int rounds = (L + R) / 2;
 
             if (ok(rounds) != -1) R = rounds; else L = rounds;
         }
 
         printf("%d %d\n", R, ok(R));
 	}
 	return 0;
 }
