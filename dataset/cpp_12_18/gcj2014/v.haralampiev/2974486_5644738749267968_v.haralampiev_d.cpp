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
 int stupid(vector<double> my , vector<double> his){
   int scr = 0;
   for(int i=sz(my)-1;i>=0;--i){
    int pos = lower_bound(all(his) , my[i]) - his.begin();
    if(pos == sz(his))
     ++scr,
     his.erase(his.begin());
    else
     his.erase(his.begin() + pos);
                               }
   return scr;
 }
 int smart(vector<double> my , vector<double> his){
   for(int i=sz(my);i>0;--i){
    bool OK = true;
    for(int p=0;p<i;++p)
     if(my[p + sz(my) - i] < his[p]){
      OK = false;
      break;
                                    }
    if(OK) return i;
                            }
   return 0;
 }
 void doit(int CASE = 1){
   int N;
   scanf("%d" , &N);
   vector<double> my(N) , his(N);
   for(int i=0;i<N;++i)
    scanf("%lf" , &my[i]);
   for(int i=0;i<N;++i)
    scanf("%lf" , &his[i]);
   sort(all(my)) , sort(all(his));
   int norm = stupid(my , his);
   int bst = smart(my , his);
   printf("Case #%d: " , CASE);
   printf("%d %d\n" , bst , norm);
 }
 int main(){
   int Q;
   scanf("%d" , &Q);
   for(int i=1;i<=Q;++i)
    doit(i);
   return 0;
 }
