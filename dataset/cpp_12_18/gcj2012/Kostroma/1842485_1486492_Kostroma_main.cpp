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
 
 int n;
 int x[10500];
 
 pair <int, int> ans[10500];
 int anss[10500];
 
 double eps=1e-9;
 
 int gcd (int q, int w)
 {
     if (q<w)
         swap(q, w);
     while (w)
     {
         q%=w;
         swap(q, w);
     }
     return q;
 }
 
 void rec (int l, int r)
 {
     //cout<<l<<' '<<r<<endl;
     if (l>=r)
         return;
     int cur=x[l];
     int now=(r-cur)*ans[l].first*ans[r].second+(cur-l)*ans[r].first*ans[l].second;
     int zn=ans[r].second*ans[l].second*(r-l);
     int g=gcd(now, zn);
     now/=g; zn/=g;
     ans[cur]=mp(now, zn);
     //cout<<now<<' '<<zn<<endl;
     
     rec(l+1, cur);
     rec(cur, r);
 }
 
 void solve()
 {  
     cin>>n;
     for (int i=0; i<n; i++)
         ans[i]=mp(0, 1);
     for (int i=0; i<n-1; i++)
     {
         cin>>x[i];
         x[i]--;
     }
     for (int i=0; i<n-1; i++)
         if (x[i]<=i)
         {
             cout<<"Case #"<<timer<<": Impossible\n";
             cout<<i<<' '<<x[i]<<endl;
             return;
         }
     for (int i=0; i<n-1; i++)
         for (int j=0; j<n-1; j++)
             if (i!=j)
             {
                 if (i>j && x[j]>i && x[i]>x[j])
                 {
                     cout<<"Case #"<<timer<<": Impossible\n";
                     //cout<<cur1<<' '<<cur2<<endl;
                     return;
                 }
             }
     int cur=0;
     while (cur<n-1)
     {
         ans[x[cur]]=mp(1, 1);
         rec(cur, x[cur]);
         cur=x[cur];
     }
        
 
     cout<<"Case #"<<timer<<": ";
     
     int pr=1;
     for (int i=0; i<n; i++)
     {
         int cur=ans[i].second;
         int g=gcd(cur, pr);
         cur/=g; pr*=cur;
     }
     
     for (int i=0; i<n; i++)
     {
         anss[i]=pr*ans[i].first/ans[i].second;
         cout<<anss[i]<<' ';
     }
     
     
     
     for (int i=0; i<n-1; i++)
     {
         bool f=true;
         int cur=x[i];
         for (int j=i+1; j<cur; j++)
         {
             
             int now=(cur-j)*anss[i]+(j-i)*anss[cur];
             if ( now <= (cur-i)*anss[j] )
             {
                 f=false;
                 cout<<"BAD: "<<i<<' '<<j<<endl;
                 break;
             }
         }
         for (int j=cur+1; j<n; j++)
         {
             
             int now=(cur-j)*anss[i]+(j-i)*anss[cur];
             if ( now < (cur-i)*anss[j] )
             {
                 f=false;
                 cout<<"BAD: "<<i<<' '<<j<<endl;
                 break;
             }
         }
     }
     
     cout<<endl;
 }
