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
 #define INF 10000000
 char buf[100];
 int ML = 0;
 set<string> avb;
 void init(){
   FILE* rfile = fopen("dic.txt" , "r");
   while(fscanf(rfile , "%s" , &buf) == 1){
    string tmp(buf);
    avb.insert(tmp);
    relaxMax(ML , sz(tmp));
                                          }
   fclose(rfile);
 }
 int min_shift(string wrd , int begi , int endi){
   if(begi > endi)return INF;
   if(avb.count(wrd))return 0;
   string wrd_cpy = wrd;
   for(int lo=0;lo<sz(wrd);++lo){
    if(lo < begi || lo > endi)continue;
    for(char put='a';put<='z';++put){
     wrd[lo] = put;
     if(avb.count(wrd))return 1;
     wrd[lo] = wrd_cpy[lo];
                                    }
                                }
   for(int lo=0;lo<sz(wrd);++lo){
    if(lo < begi || lo > endi)continue;
    for(int hi=lo+5;hi<sz(wrd);++hi){
     if(hi < begi || hi > endi)continue;
     for(char put1='a';put1<='z';++put1)
      for(char put2='a';put2<='z';++put2){
       wrd[lo] = put1;
       wrd[hi] = put2;
       if(avb.count(wrd))return 2;
       wrd[lo] = wrd_cpy[lo];
       wrd[hi] = wrd_cpy[hi];
 
                                         }
                                    }
                                }
   return INF;
 }
 int dp[100][5];
 int doit(){
   string str;
   cin>>str;
   for(int i=0;i<100;++i)
    for(int j=0;j<5;++j)
     dp[i][j] = INF;
   dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 0;
   for(int i=1;i<=sz(str);++i)
    for(int sft=0;sft<5;++sft){
     for(int L=1;L<=10;++L)
      for(int psft=0;psft<5;++psft){
       int pp = i - L;
       if(pp < 0)break;
       int ibeg=0 , iend = L-1;
       relaxMin(iend , L - 1 - sft);
       relaxMax(ibeg , 5 - psft - 1);
       string tmp = str.substr(pp , L);
       relaxMin(dp[i][sft] , dp[pp][psft] + min_shift(str.substr(pp , L) , ibeg , iend));
       if(avb.count(tmp)){
        int NL = min(4 , psft + L);
        if(NL >= sft)
         relaxMin(dp[i][sft] , dp[pp][psft]);
                         }
                                   }
                              }
   //cout<<dp[4][2]<<endl;
   int ret = dp[sz(str)][0];
   relaxMin(ret , dp[sz(str)][1]);
   relaxMin(ret , dp[sz(str)][2]);
   relaxMin(ret , dp[sz(str)][3]);
   relaxMin(ret , dp[sz(str)][4]);
   return ret;
 }
 int main(){
   init();
   int CASE , T;
   scanf("%d" , &T);
   for(CASE=1;CASE<=T;++CASE)
   printf("Case #%d: %d\n" , CASE , doit());
   return 0;
 }
