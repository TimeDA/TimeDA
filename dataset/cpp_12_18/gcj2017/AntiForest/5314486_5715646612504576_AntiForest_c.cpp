#include <bits/stdc++.h>
 
 #define INF 1000000010
 #define INFLL ((1LL<<62)-5)
 #define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
 #define rep(i,a,b) for (int i = (a); i < (b); ++(i))
 #define OF(i,a,b) for (int (i) = (a)-1; (i) >= (b); --(i))
 #define SZ(v) int(v.size())
 #define pb push_back
 
 using namespace std;
 //PAIRS:
 #define mp make_pair
 #define fi first
 #define se second
 typedef pair<int,int> pii;
 typedef long long ll;
 
 /*~~~~TEMPLATE END~~~~*/
 // 2SAT:
 // 2SAT
 const int maxn = 5110; // 2-sat: maxn = 2*maxvars
 vector<int> adj[maxn], radj[maxn];
 bool vis[maxn];
 int col, color[maxn];
 vector<int> bycol[maxn];
 vector<int> st;
 
 void init() { rep(i,0,maxn) adj[i].clear(), radj[i].clear(); }
 void dfs(int u, vector<int> adj[]) {
     if (vis[u]) return;
     vis[u] = 1;
     for (int it : adj[u]) {
         dfs(it, adj);
     }
     if (col) {
         color[u] = col;
         bycol[col].pb(u);
     } else st.pb(u);
 }
 // this computes SCCs, outputs them in bycol, in topological order
 void kosaraju(int n) { // n = number of nodes
     st.clear();
     FO (i,0,maxn) vis[i] = false;
     col=0;
     rep(i,0,n) dfs(i,adj);
     FO (i,0,maxn) vis[i] = false;
     FO (i,0,maxn) color[i] = 0;
     while(!st.empty()) {
         bycol[++col].clear();
         int x = st.back(); st.pop_back();
         if(color[x]) continue;
         dfs(x, radj);
     }
 }
 // 2-SAT
 int assign[maxn]; // for 2-sat only
 int var(int x) { return x<<1; }
 bool solvable(int vars) {
     /*
     FO (i,0,10) {
         for (int c : adj[i]) {
             printf ("%d->%d\n", i, c);
         }
         for (int c : radj[i]) {
             printf ("%d<-%d\n", i, c);
         }
     }
     */
     kosaraju(2*vars);
     rep(i,0,vars) if (color[var(i)] == color[1^var(i)]) return 0;
     return 1;
 }
 void assign_vars() {
     FO (i,0,maxn) assign[i] = 0;
     rep(c,1,col+1) {
         for (int it : bycol[c]) {
             int v = it >> 1;
             bool neg = it&1;
             if (assign[v]) continue;
             assign[v] = neg?1:-1;
         }
     }
 }
 void add_impl(int v1, int v2) { adj[v1].push_back(v2); radj[v2].push_back(v1); }
 void add_equiv(int v1, int v2) { add_impl(v1, v2); add_impl(v2, v1); }
 void add_or(int v1, int v2) { add_impl(1^v1, v2); add_impl(1^v2, v1); }
 void add_xor(int v1, int v2) { add_or(v1, v2); add_or(1^v1, 1^v2); }
 void add_true(int v1) { add_impl(1^v1, v1); }
 void add_false(int v1) { add_impl(v1, 1^v1); }
 void add_and(int v1, int v2) { add_true(v1); add_true(v2); }
 
 int parse(int i) {
     if (i>0) return var(i-1);
     else return 1^var(-i-1);
 }
 
 // END 2SAT
 
 #define MAX_R 52
 int _T;
 
 int R, C;
 char gr[MAX_R][MAX_R];
 
 int lId[MAX_R][MAX_R];
 int cLID;
 int lasCover[2][MAX_R][MAX_R];
 bool canDo[2][MAX_R][MAX_R];
 
 void reset() {
     FO (i,0,MAX_R) {
         FO (p,0,MAX_R) {
             lId[i][p] = 0;
             FO (t,0,2) {
                 lasCover[t][i][p] = -1;
                 canDo[t][i][p] = true;
             }
         }
     }
     cLID = 0;
 }
 
 bool seen[MAX_R][MAX_R];
 // 0 for hori, 1 for vert.
 #define HORI 0
 #define VERT 1
 int cDR, cDC, cDD, cID;
 int dy[4] = {-1,0,1,0};
 int dx[4] = {0,1,0,-1};
 
 int fSD[4] = {1,0,3,2};
 int bSD[4] = {3,2,1,0};
 
 
 bool dfs(int r, int c, int d) {
     // not really necessary but eh:
     if (seen[r][c]) {
         return false;
     }
     seen[r][c] = true;
     if (gr[r][c] == '-' || gr[r][c] == '|') {
         if (r != cDR || c != cDC) {
             return false;
         }
     }
     if (gr[r][c] == '/') {
         d = fSD[d];
     }
     if (gr[r][c] == '\\') {
         d = bSD[d];
     }
     lasCover[cDD][r][c] = cID;
     if (gr[r][c] == '#') {
         return true;
     }
     return dfs(r+dy[d], c+dx[d], d);
 }
 
 void tryVert(int r, int c) {
     cDR = r;
     cDC = c;
     cDD = VERT;
     cID = lId[r][c];
     FO (i,0,MAX_R) FO(p,0,MAX_R) seen[i][p] = false;
     if (!dfs(r,c,0)) {
         canDo[VERT][r][c] = false;
     }
     FO (i,0,MAX_R) FO(p,0,MAX_R) seen[i][p] = false;
     if (!dfs(r,c,2)) {
         canDo[VERT][r][c] = false;
     }
 }
 
 
 void tryHori(int r, int c) {
     cDR = r;
     cDC = c;
     cDD = HORI;
     cID = lId[r][c];
     FO (i,0,MAX_R) FO(p,0,MAX_R) seen[i][p] = false;
     if (!dfs(r,c,1)) {
         canDo[HORI][r][c] = false;
     }
     FO (i,0,MAX_R) FO(p,0,MAX_R) seen[i][p] = false;
     if (!dfs(r,c,3)) {
         canDo[HORI][r][c] = false;
     }
 }
 
 int main() {
     scanf ("%d", &_T);
     FO (_z,0,_T) {
         printf ("Case #%d: ", _z+1);
         scanf ("%d %d", &R, &C);
         reset();
         FO (i,1,R+1) {
             FO (p,1,C+1) {
                 scanf (" %c", &gr[i][p]);
                 // standardize lasers:
                 if (gr[i][p] == '|') gr[i][p] = '-';
             }
         }
         FO (i,1,R+1) {
             gr[i][0] = gr[i][C+1] = '#';
         }
         FO (i,1,C+1) {
             gr[0][i] = gr[R+1][i] = '#';
         }
         FO (i,1,R+1) {
             FO (p,1,C+1) {
                 if (gr[i][p] == '-') {
                     lId[i][p] = ++cLID;
                     tryVert(i,p);
                     tryHori(i,p);
                 }
             }
         }
         /*
         FO (i,1,R+1) {
             FO (p,1,C+1) {
                 printf ("(%d/%d) ", lasCover[0][i][p], lasCover[1][i][p]);
             }
             printf ("\n");
         }
         printf ("~~Can do:~~\n");
         FO (i,1,R+1) {
             FO (p,1,C+1) {
                 printf ("(%d/%d) ", canDo[0][i][p], canDo[1][i][p]);
             }
             printf ("\n");
         }
         */
         // 2sat:
         init();
         // false is hori, true is vert 
         bool imp = false;
         FO (i,1,R+1) {
             FO (p,1,C+1) {
                 if (gr[i][p] == '-') {
                     if (!canDo[HORI][i][p]) {
                         add_true(var(lId[i][p]));
                     }
                     if (!canDo[VERT][i][p]) {
                         add_false(var(lId[i][p]));
                     }
                 }
                 if (gr[i][p] == '.') {
                     if (lasCover[0][i][p] == -1) {
                         if (lasCover[1][i][p] == -1) {
                             imp = true;
                         } else {
                             add_true(var(lasCover[1][i][p]));
                         }
                     } else {
                         if (lasCover[1][i][p] == -1) {
                             add_false(var(lasCover[0][i][p]));
                         } else {
                             //printf ("adding impl: %d %d\n", lasCover[0][i][p], lasCover[1][i][p]);
                             add_or(1^var(lasCover[0][i][p]), var(lasCover[1][i][p]));
                         }
                     }
                 }
             }
         }
         if (imp) {
             printf ("IMPOSSIBLE\n");
             continue;
         }
         if (!solvable(2505)) {
             printf ("IMPOSSIBLE\n");
             continue;
         }
         assign_vars();
         printf ("POSSIBLE\n");
         FO (i,1,R+1) {
             FO (p,1,C+1) {
                 if (gr[i][p] == '-') {
                     if (assign[lId[i][p]] == 1) {
                         printf ("|");
                     } else {
                         printf ("-");
                     }
                 } else {
                     printf ("%c", gr[i][p]);
                 }
             }
             printf ("\n");
         }
 
     }
     return 0;
 }
