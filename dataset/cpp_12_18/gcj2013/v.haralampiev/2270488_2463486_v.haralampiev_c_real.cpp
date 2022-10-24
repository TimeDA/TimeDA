#ifdef _WIN32
 #  define LL "%I64d"
 #else
 #  define LL "%Ld"
 #endif
 
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
 // Big integers
 #define BASE 1000000000
 struct big{
   vi C;
   void kill0(){
    while(sz(C) > 1 && !C.back())C.pop_back();
               }
   big(ll from = 0){
    if(!from)C.pb(0);
    else while(from){C.pb(from%BASE); from /= BASE;}
    kill0();
                   }
   big(string from){
    for(int i=sz(from);i>0;i-=9)
     if(i-9 >= 0)C.pb( atoi( from.substr(i-9 , 9).c_str() ) );
     else C.pb( atoi( from.substr(0 , i).c_str() ) );
    kill0();
                   }
   void out(){
    printf("%d" , C.back());
    for(int i=sz(C)-2;i>=0;--i)
     printf("%09d" , C[i]);
             }
   bool operator<(const big& w)const{
    if(sz(C) != sz(w.C))return sz(C) < sz(w.C);
    for(int i=sz(C)-1;i>=0;--i)
     if(C[i] != w.C[i])return C[i] < w.C[i];
    return false;
                                    }
   bool operator==(const big& w)const{
    if(sz(C) != sz(w.C))return false;
    for(int i=sz(C)-1;i>=0;--i)
     if(C[i] != w.C[i])return false;
    return true;
                                     }
   big operator+(big w){
    big ret; ret = *this;
    int carry = 0;
    for(int i=0;i<max(sz(ret.C) , sz(w.C)) || carry;++i){
     if(i >= sz(ret.C))ret.C.pb(0);
     ret.C[i] += carry + ((i<sz(w.C)) ? w.C[i] : 0);
     carry = ret.C[i] >= BASE;
     if(carry)ret.C[i] -= BASE;
                                                        }
    ret.kill0(); return ret;
                       }
   big operator-(big w){
    big ret; ret = *this;
    int carry = 0;
    for(int i=0;i<sz(ret.C) || carry;++i){
     ret.C[i] -= carry + ((i<sz(w.C)) ? w.C[i] : 0);
     carry = ret.C[i] < 0;
     if(carry)ret.C[i] += BASE;
                                         }
    ret.kill0(); return ret;
                       }
   big operator*(big w){
     big ret; ret.C.resize( sz(C) + sz(w.C) );
     for(int i=0;i<sz(C);++i)
      for(int j=0 , carry=0;j<sz(w.C)||carry;++j){
       ll cur = ret.C[i+j] + carry + C[i] *1LL* (j<sz(w.C) ? w.C[j] : 0);
       ret.C[i+j] = cur%BASE;
       carry = cur/BASE;
                                                 }
     ret.kill0(); return ret;
                       }
   big operator/(big w){
    big T = *this;
    int norm = BASE / (w.C.back() + 1);
    T = T * norm; w = w * norm;
    big ret , tmp; ret.C.resize(sz(T.C) , 0);
    for(int i=sz(T.C)-1;i>=0;--i){
     tmp = tmp * BASE + T.C[i];
     int s1 = (sz(tmp.C) <= sz(w.C) ? 0 : tmp.C[sz(w.C)]);
     int s2 = (sz(tmp.C) < sz(w.C) ? 0 : tmp.C[sz(w.C)-1]);
     int koef = (s1*1LL*BASE + s2)/(w.C.back());
     while(tmp < w*koef)--koef;
     tmp = tmp - w*koef;
     ret.C[i] = koef;
                                 }
    ret.kill0(); return ret;
                       }
   void operator*=(int w){
    int carry = 0;
    for(int i=0;i<sz(C) || carry;++i){
     if(i>=sz(C))C.pb(0);
     ll cur = C[i]*1LL*w + carry;
     C[i] = cur % BASE;
     carry = cur / BASE;
                                     }
    kill0();
                         }
   void operator/=(int w){
    int carry = 0;
    for(int i=sz(C)-1;i>=0;--i){
     ll cur = C[i] + carry*1LL*BASE;
     C[i] = cur / w;
     carry = cur % w;
                               }
    kill0();
                         }
 };
 // Solution
 #define c1 0
 #define c2 1
 #define c3 2
 #define MAX_LEN 51
 vector<vi> avb;
 // Generation
 string base;
 vector<string> wrds;
 void gen_all(int lo , int hi , vi use){
   if(lo > hi){
    if(use[0] + use[1] + use[2] == 0)
     wrds.pb(base);
    return;
              }
   if(use[0] + use[1] + use[2] > hi-lo+1)
    return;
   if(lo > 0){
    base[lo] = base[hi] = '0';
    gen_all(lo+1 , hi-1, use);
             }
   if(lo == hi && use[0] + use[1] + use[2] == 1){
    if(use[c1] == 1)base[lo] = '1' , --use[c1];
    if(use[c2] == 1)base[lo] = '2' , --use[c2];
    if(use[c3] == 1)base[lo] = '3' , --use[c3];
    gen_all(lo+1 , hi-1 , use);
    return;
                                                }
   if(use[c1] >= 2){
    base[lo] = base[hi] = '1';
    use[c1] -= 2;
    gen_all(lo+1 , hi-1 , use);
    use[c1] += 2;
                   }
   if(use[c2] >= 2){
    base[lo] = base[hi] = '2';
    use[c2] -= 2;
    gen_all(lo+1 , hi-1 , use);
    use[c2] += 2;
                   }
   if(use[c3] >= 2){
    base[lo] = base[hi] = '3';
    use[c3] -= 2;
    gen_all(lo+1 , hi-1 , use);
    use[c3] += 2;
                   }
 }
 // </end>
 vector<big> dat;
 void init(){
   for(int C1=0;C1<10;++C1)
    for(int C2=0;C2<10;++C2)
     for(int C3=0;C3<10;++C3){
      if(C1 + C2 + C3 == 0)continue;
      if(C1 + 4*C2 + 9*C3 >= 10)continue;
      int brn = 0;
      if(C1 & 1)++brn;
      if(C2 & 1)++brn;
      if(C3 & 1)++brn;
      if(brn > 1)continue;
      avb.pb(vi());
      avb.back().pb(C1);
      avb.back().pb(C2);
      avb.back().pb(C3);
                             }
   for(int len = 1; len <= MAX_LEN; ++len){
    base = string(len , '?');
    for(int U=0;U<sz(avb);++U)
     gen_all(0 , len-1 , avb[U]);
                                          }
   for(int i=0;i<sz(wrds);++i){
    dat.pb( big(wrds[i]) );
    dat.back() = dat.back() * dat.back();
                              }
   sort( all(dat) );
 }
 // Querry part
 int querry(string LO , string HI){
   big lo(LO) , hi(HI);
   hi = hi + 1;
   vector<big>::iterator le = lower_bound(all(dat) , lo),
                         ri = lower_bound(all(dat) , hi);
   return (int)(ri-le);
 }
 int main(){
   init();
   int Q; scanf("%d" , &Q);
   for(int CASE=1;CASE<=Q;++CASE){
    string lo , hi;
    cin >> lo >> hi;
    printf("Case #%d: %d\n" , CASE , querry(lo , hi));
                                 }
   return 0;
 }
