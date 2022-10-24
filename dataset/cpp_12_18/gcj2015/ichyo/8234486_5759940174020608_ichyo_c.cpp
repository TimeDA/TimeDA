// Template {{{
 #include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 using namespace std;
 typedef long long LL;
 
 #ifdef LOCAL
 #include "contest.h"
 #else
 #define dump(x) 
 #endif
 
 class range {
     struct Iterator {
         int val, inc;
         int operator*() {return val;}
         bool operator!=(Iterator& rhs) {return val < rhs.val;}
         void operator++() {val += inc;}
     };
     Iterator i, n;
     public:
     range(int e) : i({0, 1}), n({e, 1}) {}
     range(int b, int e) : i({b, 1}), n({e, 1}) {}
     range(int b, int e, int inc) : i({b, inc}), n({e, inc}) {}
     Iterator& begin() {return i;}
     Iterator& end() {return n;}
 };
 
 const int dx[4] = {1, 0, -1, 0};
 const int dy[4] = {0, 1, 0, -1};
 inline bool valid(int x, int w) { return 0 <= x && x < w; }
 
 void iostream_init() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.setf(ios::fixed);
     cout.precision(12);
 }
 //}}}
 const int INF = 1e9;
 struct Edge{
     int dst, cap, rev;
 };
 typedef vector<Edge> Node;
 typedef vector<Node> Graph;
 struct Dinic{
     Graph G;
     vector<int> level;
     vector<int> iter;
     
     Dinic(int N) : G(N), level(N), iter(N) {}
 
     void bfs(int s){
         level.assign(G.size(), -1);
         queue<int> que;
         que.push(s);
         level[s] = 0;
         while(!que.empty()){
             int v = que.front(); que.pop();
             for(const auto& e : G[v]){
                 if(e.cap > 0 && level[e.dst] < 0){
                     level[e.dst] = level[v] + 1;
                     que.push(e.dst);
                 }
             }
         }
     }
 
     int dfs(int v, int t, int f){
         if(v == t) return f;
         for(int& i = iter[v]; i < G[v].size(); i++){
             Edge& e = G[v][i];
             if(e.cap > 0 && level[v] < level[e.dst]){
                 int d = dfs(e.dst, t, min(f, e.cap));
                 if(d > 0){
                     e.cap -= d;
                     G[e.dst][e.rev].cap += d;
                     return d;
                 }
             }
         }
         return 0;
     }
 
     void add_edge(int src, int dst, int cap){
         G[src].push_back({dst, cap, (int)G[dst].size()});
         G[dst].push_back({src, 0, (int)G[src].size() - 1});
     }
 
     int max_flow(int src, int dst){
         int flow = 0;
         while(true){
             bfs(src);
             if(level[dst] < 0) break;
             iter.assign(G.size(), 0);
             while(true){
                 int f = dfs(src, dst, INF);
                 if(f <= 0) break;
                 flow += f;
             }
         }
         return flow;
     }
 };
 
 vector<string> parse(string s){
     stringstream ss(s);
     vector<string> res;
     while(ss >> s) {
         res.push_back(s);
     }
     return res;
 }
 map<string, int> idm;
 int get_id(string s) {
     if(idm.count(s)) return idm[s];
     int t = idm.size();
     idm[s] = t;
     return t;
 }
 vector<int> get_list(vector<string> ps) {
     vector<int> res;
     REP(i, ps.size()) {
         res.push_back(get_id(ps[i]));
     }
     return res;
 }
 
 void solve() {
     idm.clear();
     int N;
     cin >> N;
     cin.ignore();
     string eng_s, fr_s;
     getline(cin, eng_s);
     getline(cin, fr_s);
     auto eng = parse(eng_s);
     auto fr = parse(fr_s);
     vector< vector<int> > rest;
     REP(i, N-2) {
         string str;
         getline(cin, str);
         auto pv = parse(str);
         rest.push_back(get_list(pv));
     }
     vector<int> ev = get_list(eng);
     vector<int> fv = get_list(fr);
     int ans = INT_MAX;
     REP(s, (1 << rest.size())) {
         const int L = idm.size();
         vector<bool> is_e(L, false);
         vector<bool> is_f(L, false);
         for(auto i : ev) is_e[i] = true;
         for(auto i : fv) is_f[i] = true;
         REP(j, rest.size()) {
             if(s >> j & 1) { 
                 for(auto i : rest[j]) is_e[i] = true;
             } else {
                 for(auto i : rest[j]) is_f[i] = true;
             }
         }
         int sum = 0;
         REP(i, L) if(is_e[i] && is_f[i]) sum ++;
         ans = min(ans, sum);
     }
     cout << ans << endl;
 }
 int main(){
     iostream_init();
     int TESTCASE;
     cin >> TESTCASE;
     for(int testcase = 1; testcase <= TESTCASE; testcase++) {
         cout << "Case #" << testcase << ": ";
         solve();
     }
     return 0;
 }
 
 /* vim:set foldmethod=marker: */
 
