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
 
 const int MAX = 110;
 
 vi Ival(int len){
   vi res(len);
   for(int i = 0;i < len;++i) res[i] = i;
   return res;
 }
 
 vector<vi> Subsets(vi tot, const vi& s){
   random_shuffle(all(tot));
   vector<vi> res;
   auto pos = tot.begin();
 
   for(int i = 0;i < sz(s);++i){
     res.pb(vi(pos, pos + s[i]));
     pos += s[i];
   }
 
   for(int i = 0;i < sz(res);++i)
     sort(all(res[i]));
 
   return res;
 }
 
 vi go[MAX];
 int n;
 char letter[MAX];
 char buf[MAX];
 int subtree[MAX];
 
 string current;
 
 int Dfs(int vr){
   int sub = 1;
 
   for(int nxt : go[vr])
     sub += Dfs(nxt);
 
   return (subtree[vr] = sub);
 }
 
 void Lay(int root, vi to){
   //cout << root << endl;
   //for(int i = 0;i < sz(to);++i)
   //  cout << to[i] << ' ';
   //cout << endl << endl;
 
   if(subtree[root] == 1){
     current[to[0]] = letter[root];
     return;
   }
 
   current[to[0]] = letter[root];
   to.erase(to.begin());
 
   vi put;
   for(int nxt : go[root])
     put.pb(subtree[nxt]);
   //put.pb(1);
 
   vector<vi> use = Subsets(to, put);
 
   //current[use.back()[0]] = letter[root];
   //use.pop_back();
 
   for(int i = 0;i < sz(go[root]);++i)
     Lay(go[root][i], use[i]);
 }
 
 int CASE = 0;
 void Doit(){
   ++CASE;
   cerr << "Case: " << CASE << endl;
 
   vi roots;
   vi szs;
 
   scanf("%d", &n);
   for(int i = 0;i < n;++i) go[i].clear();
   for(int i = 0;i < n;++i){
     int p;
     scanf("%d", &p);
     if(p) go[p - 1].pb(i);
     else roots.pb(i);
   }
   scanf("%s", letter);
   current = string(n, '?');
 
   for(int root : roots)
     szs.pb(Dfs(root));
 
   vector<string> base;
   int m;
   scanf("%d", &m);
   for(int i = 0;i < m;++i){
     scanf("%s", buf);
     base.pb(string(buf));
   }
   vector<double> ans(m, 0);
 
   int STEPS = 3000;
   for(int s = 0;s < STEPS;++s){
     auto sub = Subsets(Ival(n), szs);
     for(int i = 0;i < sz(roots);++i)
       Lay(roots[i], sub[i]);
     //cout << current << endl;
     for(int i = 0;i < m;++i)
       if(current.find(base[i]) != string::npos)
         ++ans[i];
   }
 
   printf("Case #%d: ", CASE);
   for(int i = 0;i < m;++i)
     printf("%.12f%c", ans[i] / STEPS,
                       (i + 1 == m) ? '\n' : ' ');
 }
 
 int main(){
   srand(13331);
 
   int q;
   scanf("%d", &q);
   while(q-- > 0) Doit();
   return 0;
 }
