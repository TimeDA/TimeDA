#include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <vector>
 #include <deque>
 #include <bitset>
 #include <set>
 #include <map>
 #include <utility>
 #include <string>
 #include <cstring>
 #include <queue>
 #include <algorithm>
 #include <cmath>
 using namespace std;
 #define fi first
 #define se second
 #define pb(a) push_back(a)
 #define sz(a) ((int)(a).size())
 #define all(a) a.begin() , a.end()
 #define EPS 1E-9
 #define x1 x111
 #define y1 y111
 typedef long long ll;
 typedef unsigned long long ull;
 typedef long double ld;
 typedef pair<int,int> pii;
 // real solution
 #define BITS(a) __built_popcount(a)
 map<int,int> avb;
 int vals[30] , n;
 void doit(int CASE){
   avb.clear();
   int ss1=-1,ss2=-1;
   scanf("%d",&n);
   for(int i=0;i<n;++i)
    scanf("%d",&vals[i]);
   for(int msk=1;msk<(1<<n);++msk){
    int sum=0;
    for(int i=0;i<n;++i)
     if(msk&(1<<i))sum+=vals[i];
    if(avb.count(sum)){
     ss1=msk;
     ss2=avb[sum];
     break;
                      }
    else avb[sum]=msk;
                                  }
   printf("Case #%d:\n" , CASE);
   if(ss1 == -1)printf("Impossible\n");
   else{
    vector<int> r1;
    for(int i=0;i<n;++i)if(ss1 & (1<<i))r1.pb(vals[i]);
    for(int i=0;i<sz(r1);++i)printf("%d%c" , r1[i] , (i+1==sz(r1))?'\n':' ');
    vector<int> r2;
    for(int i=0;i<n;++i)if(ss2 & (1<<i))r2.pb(vals[i]);
    for(int i=0;i<sz(r2);++i)printf("%d%c" , r2[i] , (i+1==sz(r2))?'\n':' ');
       }
 }
 int main(){
   int Q; scanf("%d",&Q);
   for(int i=1;i<=Q;++i)doit(i);
   //system("pause");
   return 0;
 }
