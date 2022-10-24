#include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
 using namespace std;
 
 struct Node{
     int value;
     vector<Node*> next;
     Node() : value(0), next(256) {}
     ~Node(){ for(int i = 0; i < 256; i++) if(next[i]) delete next[i]; }
 };
 
 int my_size;
 Node* find(Node* root, string s){
     Node* p = root;
     for(int i = 0; i < s.size(); i++){
         char c = s[i];
         if(!p->next[c]){
             p->next[c] = new Node();
             my_size++;
         }
         p = p->next[c];
     }
     return p;
 }
 
 int main(){
     int T;
     cin >> T;
     for(int casenum = 1; casenum <= T; casenum++) {
         printf("Case #%d: ", casenum);
         int M, N;
         cin >> M >> N;
         vector<string> words(M);
         REP(i, M) {
             cin >> words[i];
         }
         assert(M <= 8);
         assert(N <= 4);
         int id[10] = {};
         map<int, int> ways;
         function<void(int)> dfs = [&](int k) {
             if(k == M) {
                 bool ok = true;
                 int sum = 0;
                 REP(i, N) {
                     bool exist = false;
                     my_size = 1;
                     Node* root = new Node();
                     REP(j, M) if(id[j] == i) {
                         exist = true;
                         find(root, words[j]);
                     }
                     if(!exist){
                         ok = false;
                         break;
                     }
                     sum += my_size;
                     delete root;
                 }
                 if(ok) ways[sum] += 1;
             } else {
                 for(int i = 0; i < N; i++) {
                     id[k] = i;
                     dfs(k + 1);
                 }
             }
         };
         dfs(0);
         auto it = ways.rbegin();
         cout << it->first << " " << it->second << endl;
     }
     return 0;
 }
 
