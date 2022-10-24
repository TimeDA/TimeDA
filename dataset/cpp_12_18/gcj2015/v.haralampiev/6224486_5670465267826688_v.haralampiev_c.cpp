#define LL "%lld"
 
 #include <iostream>
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <cstring>
 #include <ctime>
 #include <vector>
 #include <deque>
 #include <set>
 #include <map>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <string>
 #include <algorithm>
 #include <complex>
 #include <utility>
 #include <cassert>
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
 typedef vector<int> vi;
 typedef pair<int,int> pii;
 typedef long long ll;
 string YES = "YES";
 string NO = "NO";
 pii GO[4][4] = {{mp(0 , +1) , mp(1 , +1) , mp(2 , +1) , mp(3 , +1)},
                 {mp(1 , +1) , mp(0 , -1) , mp(3 , +1) , mp(2 , -1)},
                 {mp(2 , +1) , mp(3 , -1) , mp(0 , -1) , mp(1 , +1)},
                 {mp(3 , +1) , mp(2 , +1) , mp(1 , -1) , mp(0 , -1)}};
 pii toNUM(char w){
   switch(w){
    case 'i': return mp(1 , +1);
    case 'j': return mp(2 , +1);
    case 'k': return mp(3 , +1);
            }
 }
 pii mul(const pii& f , const pii& s){
   pii ret = GO[f.fi][s.fi];
   ret.se *= f.se * s.se;
   return ret;
 }
 pii POW(pii w , ll step){
   pii ret(0 , +1);
   for(;step > 0;step >>= 1 , w = mul(w , w))
    if(step & 1) ret = mul(w , ret);
   return ret;
 }
 ll L , X;
 char in[10010];
 ll pref(){
   set<pii> beg;
   ll gp = -1;
   pii prod(0 , +1);
   while(true){
    if(beg.count(prod)) return -1;
    beg.insert(prod);
    for(int i=0;i<L;++i){
     ++gp;
     prod = mul(prod , toNUM(in[i]));
     if(prod == toNUM('i')) goto END1;
                        }
              }
   END1:;
   if(gp >= L*X) return -1;
   return gp;
 }
 ll suff(){
   set<pii> beg;
   ll gp = L*X;
   pii prod(0 , +1);
   while(true){
    if(beg.count(prod)) return -1;
    beg.insert(prod);
    for(int i=L-1;i>=0;--i){
     --gp;
     prod = mul(toNUM(in[i]) , prod);
     if(prod == toNUM('k')) goto END2;
                           }
              }
   END2:;
   if(gp < 0) return -1;
   return gp;
 }
 string doit(){
   scanf(LL LL , &L , &X);
   scanf("%s" , &in);
   pii prod(0 , +1);
   for(int i=0;i<L;++i)
    prod = mul(prod , toNUM(in[i]));
   prod = POW(prod , X);
   if(prod != mp(0 , -1)) return NO;
   ll p = pref() , s = suff();
   if(p < 0 || s < 0) return NO;
   return p+1 < s ? YES : NO;
 }
 int main(){
   int Q; scanf("%d" , &Q);
   for(int i=1;i<=Q;++i){
    string ans = doit();
    printf("Case #%d: %s\n" , i , ans.c_str());
                        }
   return 0;
 }
