#include <cstdio>
 #include <cstdlib>
 #include <iostream>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <math.h>
 #include <queue>
 #include <memory.h>
 
 using namespace std;
 
 /*
 CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
 REAL SOLTION AFTER MAIN FUNCTION
 */
 
 #define mp make_pair
 #define pb push_back
 #define all(a) a.begin(), a.end()
 
 typedef long long li;
 typedef double ld;
 typedef vector <int> vi;
 typedef pair <int, int> pi;
 typedef vector <li> vli;
 typedef pair <li, li> pli;
 
 void solve();
 int timer=1;
 int main() 
 {
 #ifdef DEBUG
     freopen ("in.txt", "r", stdin);
     freopen ("out.txt", "w", stdout);
 #endif
     //ios_base::sync_with_stdio(0);
     int t=1;
     cin>>t;
     while (t--)
         solve(), ++timer;
     return 0;
 }
 
 #define int li
 
 int w, l;
 int n;
 pair <int, int> r[100500];
 
 pair <int, int> ans[100500];
 
 void solve()
 {  
     cin>>n>>w>>l;
     for (int i=0; i<n; i++)
         cin>>r[i].first, r[i].second=i;
     sort (r, r+n);
     reverse (r, r+n);
     bool f=true;
     if (w>l)
     {
         swap(w, l);
         f=false;
     }
     int border1=0, border2=2*r[0].second;
     for (int i=0; i<n; i++)
     {
         if (border1+r[i].first<=l)
             ans[r[i].second]=mp(border1+r[i].first, border2-r[i].first), border1+=2*r[i].first;
         else
         {
             border2+=2*r[i].first;
             border1=0;
             i--;
         }
     }
        
 
     cout<<"Case #"<<timer<<": ";
     
     for (int i=0; i<n; i++)
         if (f)
             cout<<ans[i].first<<".0 "<<ans[i].second<<".0 ";
         else
             cout<<ans[i].second<<".0 "<<ans[i].first<<".0 ";
     
     cout<<endl;
 }
