#include <bits/stdc++.h>
 using namespace std;
 #define null NULL
 #define mp make_pair
 #define pb(a) push_back(a)
 #define sz(a) ((int)(a).size())
 #define all(a) a.begin() , a.end()
 #define fi first
 #define se second
 #define relaxMin(a , b) (a) = min((a),(b))
 #define relaxMax(a , b) (a) = max((a),(b))
 #define SQR(a) ((a)*(a))
 #define PI 3.14159265358979323846
 typedef vector<int> vi;
 typedef pair<int,int> pii;
 typedef long long ll;
 
 typedef pair<ll, ll> pll;
 
 const int MAX = 100;
 int n, p;
 int need[MAX];
 vector<pll> ival[MAX];
 
 pll Have(ll ne, ll ha){
   ll lo = (10.0 * ha) / (11.0 * ne);
   ll hi = (10.0 * ha) / (9.0 * ne);
 
   while(10 * ha > 11 * lo * ne) ++lo;
   while(lo - 1 >= 0 && 10 * ha <= 11 * (lo - 1) * ne) --lo;
 
   while(10 * ha < 9 * hi * ne) --hi;
   while(10 * ha >= 9 * (hi + 1) * ne) ++hi;
 
   return mp(lo, hi);
 }
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   scanf("%d%d", &n, &p);
   for(int i = 0;i < n;++i) ival[i].clear();
   for(int i = 0;i < n;++i) scanf("%d", &need[i]);
 
   vi cand;
   for(int i = 0;i < n;++i){
     for(int j = 0;j < p;++j){
       int have;
       scanf("%d", &have);
       auto v = Have(need[i], have);
       relaxMax(v.fi, 1LL);
       if(v.fi <= v.se && v.se > 0){
         ival[i].pb(v);
         cand.pb(v.fi);
       }
     }
   }
 
   sort(all(cand));
   cand.erase(unique(all(cand)), cand.end());
 
   int ans = 0;
   for(int e : cand){
     while(true){
       vi pos(n, -1);
       for(int i = 0;i < n;++i){
         for(int j = 0;j < sz(ival[i]);++j){
           if(ival[i][j].fi <= e && e <= ival[i][j].se){
             if(pos[i] == -1 ||
                ival[i][j].se < ival[i][pos[i]].se)
               pos[i] = j;
           }
         }
       }
       if(count(all(pos), -1)) break;
       ++ans;
       for(int i = 0;i < n;++i)
         ival[i].erase(ival[i].begin() + pos[i]);
     }
   }
 
   printf("Case #%d: %d\n", CASE, ans);
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
   return 0;
 }
