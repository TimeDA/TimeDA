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
 int used[2000010] , ust;
 void doit(int CASE){
   int A,B,tmp;
   scanf("%d%d",&A,&B);
   int br=0,koef=1,ans=0;
   tmp=A;
   while(tmp)++br , koef*=10 , tmp/=10;
   --br; koef/=10;
   for(int n=A;n<=B;++n){
    int m=n; ++ust;
    for(int i=0;i<br;++i){
     m=koef*(m%10)+m/10;
     if(A<=n && n<m && m<=B && used[m]!=ust){used[m]=ust; ++ans;}
                         }
                        }
   printf("Case #%d: %d\n" , CASE , ans);
 }
 int main(){
   int Q; scanf("%d",&Q);
   for(int i=1;i<=Q;++i)doit(i);
   //system("pause");
   return 0;
 }
