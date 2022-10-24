#include <cstdio>
 #include <set>
 #include <string>
 #include <cstring>
 #include <cstdlib>
 #include <iostream>
 #include <cmath>
 #include <vector>
 #include <queue>
 #include <algorithm>
 #include <map>
 #include <stack>
 
 using namespace std ;
 
 long long mod = 1000002013LL ;
 map<long long, long long>st, et ;
 long long n ;
 
 long long calc(long long stc)
 {
     return ((((((n*2)%mod)-stc+1)*stc)%mod)/2)%mod ;
 }
 
 int main(void)
 {
     long long t, tc ;
     long long m ;
     long long op ;
     
     cin >> t ;
     for(tc=1;tc<=t;tc++)
     {
         cin >> n >> m ;
         
         long long i ;
         
         op = 0 ;
         st.clear() ;
         et.clear() ;
         
         for(i=0;i<m;i++)
         {
             long long s, e, p ;
             cin >> s >> e >> p ;
 
             op = (op+((calc(e-s)%mod)*p)%mod)%mod ;
             st[s] += p ;
             et[e] += p ;
         }
         
         long long np = 0 ;
         stack< pair<long long ,long long> > sta ;
         for(i=1;i<=n;i++)
         {
             if(st[i]>0)
             {
                 sta.push(make_pair(i,st[i])) ;
             }
             while(et[i]>0)
             {
                 pair<long long, long long> pa = sta.top() ;
                 sta.pop() ;
                 
                 long long con = min(et[i],pa.second) ;
                 pa.second -= con ;
                 if(pa.second>0) sta.push(pa) ;
                 et[i]-=con ;
                 np = (np+(((calc(i-pa.first)%mod)*con)%mod))%mod ;
             }
         }
                 
         cout << "Case #" << tc << ": " << (op-np+mod)%mod << endl ;
     }
     
     return 0;
 }
