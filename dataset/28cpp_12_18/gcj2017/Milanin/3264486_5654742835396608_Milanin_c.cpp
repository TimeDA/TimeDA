#pragma comment(linker, "/STACK:100000000")
 #include <cmath>
 #include <cstdio>
 #include <vector>
 #include <iostream>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <ctime>
 #include <queue>
 using namespace std;
 map <long long, long long> m;
 priority_queue <long long> q;
 int main()
 {
     int ts;
     scanf("%d", &ts);
     for(int t=1; t<=ts; t++)
     {
         printf("Case #%d: ", t);
         long long n, k;
         scanf("%lld%lld", &n, &k);
         m.clear();
         m[n]=1;
         q.push(n);
         for(; !q.empty(); )
         {
             long long x=q.top()-1;
             q.pop();
             if(x>0)
             {
                 if(!m.count(x/2)) q.push(x/2);
                 m[x/2]+=m[x+1];
                 if(!m.count(x-x/2)) q.push(x-x/2);
                 m[x-x/2]+=m[x+1];
             }
         }
         for(map <long long, long long>::reverse_iterator it=m.rbegin(); it!=m.rend(); it++)
         {
             if(k>it->second) k-=it->second;
             else { k=it->first; break; }
         }
         k--;
         printf("%lld %lld\n", k-k/2, k/2);
     }
 	return 0;
 }