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
 #define EPS 1E-10
 #define x1 x111
 #define y1 y111
 typedef long long ll;
 typedef unsigned long long ull;
 typedef long double ld;
 typedef pair<int,int> pii;
 // real solution
 int n , vals[210] , sum;
 bool can(int w , double per){
    double least=0;
    double T=vals[w] + per*sum;
    for(int i=0;i<n;++i){
     if(w==i)continue;
     least += max(0.0 , (T-vals[i]+0.0) / sum);
                        }
    if(least < 1-per-EPS)return false;
    return true;
 }
 double ans(int w){
   double lo=0.0 , hi=1.0;
   for(int i=0;i<100;++i)
    if(can(w , (lo+hi)/2))hi=(lo+hi)/2;
    else lo=(lo+hi)/2;
   return hi;
 }
 void doit(int CASE){
   scanf("%d",&n);
   sum=0;
   for(int i=0;i<n;++i)scanf("%d",&vals[i]) , sum+=vals[i];
   printf("Case #%d: " , CASE);
   for(int i=0;i<n;++i)
    printf("%.9lf%c" , ans(i)*100 , (i+1==n)?'\n':' ');
 }
 int main(){
   int Q; scanf("%d",&Q);
   for(int i=1;i<=Q;++i)doit(i);
   //system("pause");
   return 0;
 }
