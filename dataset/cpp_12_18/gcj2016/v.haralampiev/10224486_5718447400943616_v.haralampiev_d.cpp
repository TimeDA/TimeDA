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
 
 bool FINE = true;
 int tbl[10][10];
 void OK(vi wrk, vi mch){
   if(!FINE) return;
   if(count(all(wrk), 0) == 0) return;
 
   for(int i = 0;i < sz(wrk);++i){
     if(wrk[i] == 1) continue;
     int tmp = 0;
     for(int m = 0;m < sz(mch);++m){
       if(mch[m] == 1) continue;
       if(!tbl[i][m]) continue;
       ++tmp;
       wrk[i] = 1, mch[m] = 1;
       OK(wrk, mch);
       if(!FINE) return;
       wrk[i] = 0, mch[m] = 0;
     }
     if(tmp == 0){
       FINE = false;
       return;
     }
   }
 }
 
 
 int CASE = 0;
 
 int n;
 char in[10][10];
 
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
   scanf("%d", &n);
   for(int i = 0;i < n;++i)
     scanf("%s", &in[i]);
 
   int cost = 1E9;
   vector<pii> pos;
 
   for(int i = 0;i < n;++i)
     for(int j = 0;j < n;++j)
       if(in[i][j] == '0') pos.pb(mp(i, j));
 
   for(int msk = 0;msk < (1 << sz(pos));++msk){
     int cur = __builtin_popcount(msk);
     for(int i = 0;i < n;++i)
       for(int j = 0;j < n;++j)
         tbl[i][j] = in[i][j] - '0';
     for(int i = 0;i < sz(pos);++i)
       if(msk & (1 << i))
         tbl[pos[i].fi][pos[i].se] = 1;
     FINE = true;
     OK(vi(n, 0), vi(n, 0));
     if(FINE){
       relaxMin(cost, cur);
     }
   }
 
   printf("Case #%d: %d\n", CASE, cost);
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
   return 0;
 }
