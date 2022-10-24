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
 
 const int dx[4] = {1, 0, -1, 0};
 const int dy[4] = {0, 1, 0, -1};
 inline bool valid(int x, int w) { return 0 <= x && x < w; }
 
 void iostream_init() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.setf(ios::fixed);
     cout.precision(2);
 }
 //}}}
 
 struct Node{
     map<char, Node*> next;
     Node* fail;
     vector<int> match;
     Node() : fail(NULL) {}
     ~Node(){ for(auto p : next) if(p.second) delete p.second; }
 };
 
 Node *build(vector<string> pattens){
     // 1. trie木 をつくる
     Node* root = new Node();
     root->fail = root;
     for(int i = 0; i < pattens.size(); i++){
         Node* p = root;
         for(auto c : pattens[i]){
             if(p->next[c] == 0) p->next[c] = new Node();
             p = p->next[c];
         }
         p->match.push_back(i);
     }
 
     // 2. failure link を作る
     queue<Node*> que;
     for(int i = 0; i < 128; i++){
         if(!root->next[i]){
             root->next[i] = root;
         }else{
             root->next[i]->fail = root;
             que.push(root->next[i]);
         }
 
     }
     while(!que.empty()){
         Node* p = que.front(); que.pop();
         for(auto a : p->next) {
             int i = a.first;
             Node* np = a.second;
             if(!np) continue;
 
             // add que
             que.push(np);
 
             // search failure link
             Node* f = p->fail;
             while(!f->next[i]) f = f->fail;
             np->fail = f->next[i];
 
             // update matching list
             np->match.insert(np->match.end(), np->fail->match.begin(), np->fail->match.end());
         }
     }
     return root;
 }
 
 // Trie木のノード p からの 文字 c に対応する移動先
 Node* next_node(Node* p, char c) {
     while(!p->next[c]) p = p->fail;
     return p->next[c];
 }
 
 int N, M;
 vector<bool> match(Node* root, string query){
     vector<bool> res(M);
     int n = query.size();
 
     Node* p = root;
     REP(i, n) {
         int c = query[i];
         p = next_node(p, c);
         for(int k : p->match){
             res[k] = true;
         }
     }
 
     return res;
 }
 
 vector<int> nodes;
 vector<vector<int>> nexti;
 deque<int> generate(int idx) {
     int L = nexti[idx].size();
     vector<deque<int>> ps(L);
     REP(i, L) { ps[i] = generate(nexti[idx][i]); }
     deque<int> res;
     vector<int> cnt(L);
     REP(i, L) cnt[i] = ps[i].size();
     int sum = 0;
     REP(i, L) sum += cnt[i];
     REP(_, sum) {
         int r = rand() % (sum - _);
         int i;
         for(i = 0; i < L; i++) {
             if(0 <= r && r < cnt[i]) {
                 break;
             } else {
                 r -= cnt[i];
             }
         }
         res.push_back(ps[i][ps[i].size() - cnt[i]]);
         cnt[i]--;
     }
     if(idx != N) res.push_front(idx);
     return res;
 }
 
 void solve() {
     cin >> N;
     nodes.clear();
     nexti.assign(N+1, vector<int>());
     REP(i, N) {
         int x;
         cin >> x;
         if(x == 0) {
             nexti[N].push_back(i);
         } else {
             nexti[x-1].push_back(i);
         }
     }
     string name;
     cin >> name;
     cin >> M;
     vector<string> cool(M);
     REP(i, M) cin >> cool[i];
 
     clock_t start = clock();
     const double TIME = CLOCKS_PER_SEC * 2.2;
     long long total = 0;
     vector<long long> bucket(M);
     Node* root = build(cool);
     while(true) {
         clock_t end = clock();
         if(end - start >= TIME) break;
 
         total++;
         deque<int> vs = generate(N);
         string str;
         REP(i, vs.size()) str += name[ vs[i] ];
         vector<bool> res = match(root, str);
         for(int i = 0; i < M; i++) {
             if(res[i]) { bucket[i]++; }
         }
     }
     // cout << total << endl;
     REP(i, M) {
         double ans = 1.0 * bucket[i] / total;
         cout << ans;
         if(i == M-1) cout << endl;
         else cout << " ";
     }
 }
 
 int main(){
     iostream_init();
     int T;
     cin >> T;
     REP(casenum, T) {
         cout << "Case #" << casenum + 1 << ": ";
         solve();
     }
     return 0;
 }
 
