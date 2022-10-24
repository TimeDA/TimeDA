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
     ios_base::sync_with_stdio(0);
     int t=1;
     cin>>t;
     while (t--)
         solve(), ++timer;
     return 0;
 }
 
 //#define int li
 
 int n;
 int d[100500], l[100500];
 int D;
 unsigned int dp[100500];
 
 void solve()
 {  
     
     cin>>n;
     for (int i=0; i<n; i++)
         cin>>d[i]>>l[i];
     cin>>D;
     d[n]=D;
     int cur=0;
     memset (dp, -1, sizeof dp);
     dp[0]=d[0];
     for (int i=0; i<n; i++)
         if (dp[i]!=-1)
         {
             while( cur<n && dp[i]+d[i]>=d[cur+1] )
                 dp[cur+1]=min(l[cur+1], d[cur+1]-d[i]), cur++;
         }
 
     cout<<"Case #"<<timer<<": ";
     
     if (dp[n]!=-1)
         cout<<"YES";
     else
         cout<<"NO";
     
     cout<<endl;
 }
