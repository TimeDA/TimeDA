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
 
 const int MAXN = 1010;
 int go[MAXN];
 vi rev[MAXN];
 int n;
 
 bool used[MAXN];
 
 int Cycle(int vr){
   int len = 1;
   int start = vr;
 
   fill(used, used + n, false);
   used[vr] = true;
 
   for(;;){
     vr = go[vr];
     if(used[vr]) break;
     used[vr] = true;
     ++len;
   }
 
   if(vr == start) return len;
   return 0;
 }
 
 int PATH = 0;
 
 int Dfs(int vr, int PL){
   relaxMax(PATH, PL);
   used[vr] = true;
   for(int i = 0;i < sz(rev[vr]);++i){
     int to = rev[vr][i];
     if(used[to] == false)
       Dfs(to, PL + 1);
   }
 }
 
 int CASE = 0;
 void Solve(){
   CASE++;
   cerr << "Case: " << CASE << "\n";
 
   int ans = 0;
   scanf("%d", &n);
   for(int i = 0;i < n;++i){
     scanf("%d", &go[i]);
     --go[i];
   }
 
   for(int i = 0;i < n;++i) rev[i].clear();
   for(int i = 0;i < n;++i)
     rev[go[i]].pb(i);
 
   for(int i = 0;i < n;++i)
     ans = max(ans, Cycle(i));
 
   int pr = 0;
   for(int i = 0;i < n;++i)
     for(int j = i + 1;j < n;++j)
       if(go[i] == j && go[j] == i){
         int add = 0;
         int l = 0;
         PATH = 0;
         fill(used, used + n, false);
         used[i] = used[j] = true;
         Dfs(i, 1);
         l = PATH;
         add += l;
 
         PATH = 0;
         fill(used, used + n, false);
         used[i] = used[j] = true;
         Dfs(j, 1);
         l = PATH;
         add += l;
 
         pr += add;
       }
 
   relaxMax(ans, pr);
 
   printf("Case #%d: %d\n", CASE, ans);
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Solve();
   return 0;
 }
 
