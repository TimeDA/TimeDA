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
 
 // Matching
 #define SZ 800
 int N , M;
 vi fo[SZ];
 bool lused[SZ]; int rmatch[SZ] , used[SZ] , ust;
 bool dfs(int vr){
   used[vr] = ust;
   for(int i=0;i<sz(fo[vr]);++i){
    int to = fo[vr][i];
    if(rmatch[to] == -1 || used[rmatch[to]]!=ust && dfs(rmatch[to])){
     rmatch[to] = vr;
     return true;
                                                                    }
                                }
   return false;
 }
 void max_matching(){
   memset(rmatch , -1 , M*sizeof(int));
   memset(lused , 0 , N*sizeof(int));
   for(int i=0;i<N;++i){
    int j;
    for(j=0;j<sz(fo[i]);++j)
     if(rmatch[fo[i][j]] == -1)break;
    if(j<sz(fo[i]))lused[i]=true , rmatch[fo[i][j]]=i;
                       }
   for(int i=0;i<N;++i)
    if(!lused[i]){
     ++ust;
     lused[i] = dfs(i);
                 }
 }
 // </end>
 
 const int PLUS = 1;
 const int CROSS = 2;
 
 char buf[20];
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   int n, m;
   scanf("%d%d", &n, &m);
 
   // Naming
   map<int, int> r, c, ld, rd;
   map<int, int> br, bc, bld, brd;
   set<int> dr, dc, dld, drd;
 
   for(int i = 0;i < n;++i)
     for(int j = 0;j < n;++j)
       r[i] = c[j] = 0,
       ld[i + j] = rd[i - j] = 0;
 
   int idx = 0;
   for(auto& e : r) e.se = idx, br[idx++] = e.fi;
   idx = 0;
   for(auto& e : c) e.se = idx, bc[idx++] = e.fi;
   idx = 0;
   for(auto& e : ld) e.se = idx, bld[idx++] = e.fi;
   idx = 0;
   for(auto& e : rd) e.se = idx, brd[idx++] = e.fi;
 
   // Existing edges + new edges
   map<pii, char> known;
   map<pii, int> put;
 
   for(int i = 0;i < m;++i){
     int x, y;
     scanf("%s%d%d", buf, &x, &y);
     --x, --y;
     known[mp(x, y)] = buf[0];
 
     int _r = r[x], _c = c[y],
         _ld = ld[x + y], _rd = rd[x - y];
 
     if(buf[0] == '+'){
       put[mp(x, y)] |= PLUS;
       dld.insert(_ld);
       drd.insert(_rd);
     }
     if(buf[0] == 'x'){
       put[mp(x, y)] |= CROSS;
       dr.insert(_r);
       dc.insert(_c);
     }
     if(buf[0] == 'o'){
       put[mp(x, y)] |= (PLUS | CROSS);
       dld.insert(_ld);
       drd.insert(_rd);
       dr.insert(_r);
       dc.insert(_c);
     }
   }
 
   // Row matching
   N = sz(r), M = sz(c);
   for(int i = 0;i < N;++i) fo[i].clear();
   for(int i = 0;i < n;++i){
     int _r = r[i];
     if(dr.count(_r)) continue;
     for(int j = 0;j < n;++j){
       int _c = c[j];
       if(dc.count(_c)) continue;
       fo[_r].pb(_c);
     }
   }
 
   max_matching();
   for(int i = 0;i < M;++i)
     if(rmatch[i] >= 0){
       int x = br[rmatch[i]];
       int y = bc[i];
       put[mp(x, y)] |= CROSS;
     }
 
   // Diag matching
   N = sz(ld), M = sz(rd);
   for(int i = 0;i < N;++i) fo[i].clear();
   for(int i = 0;i < n;++i){
     for(int j = 0;j < n;++j){
       int _ld = ld[i + j];
       int _rd = rd[i - j];
       if(dld.count(_ld) || drd.count(_rd))
         continue;
       fo[_ld].pb(_rd);
     }
   }
 
   max_matching();
   for(int i = 0;i < M;++i)
     if(rmatch[i] >= 0){
       int xpy = bld[rmatch[i]];
       int xmy = brd[i];
       int x = (xpy + xmy) >> 1;
       int y = xpy - x;
       put[mp(x, y)] |= PLUS;
     }
 
   // Answer
   printf("Case #%d: ", CASE);
 
   int scr = 0;
   for(const auto& e : put){
     if(e.se == 0) continue;
     if(e.se == 3) scr += 2;
     else scr += 1;
   }
   printf("%d ", scr);
 
   vector<char> ol;
   vi ox, oy;
   for(const auto& e : put){
     if(e.se == 0) continue;
     char u = 'o';
     if(e.se == PLUS) u = '+';
     if(e.se == CROSS) u = 'x';
 
     if(!known.count(e.fi) || known[e.fi] != u){
       ol.pb(u);
       ox.pb(e.fi.fi + 1);
       oy.pb(e.fi.se + 1);
     }
   }
 
   printf("%d\n", sz(ol));
   for(int i = 0;i < sz(ol);++i)
     printf("%c %d %d\n", ol[i], ox[i], oy[i]);
 }
 
 int main(){
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
 
   return 0;
 }
