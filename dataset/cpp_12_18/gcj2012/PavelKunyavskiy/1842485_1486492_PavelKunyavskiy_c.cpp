#include <iostream>
 #include <fstream>
 #include <vector>
 #include <set>
 #include <map>
 #include <string>
 #include <cmath>
 #include <cassert>
 #include <ctime>
 #include <algorithm>
 #include <queue>
 #include <iterator>
 #include <cstdio>
 #include <cstdlib>
 #include <memory.h>
 #include <stack>
 #define mp make_pair
 #define pb push_back   
 #define setval(a,v) memset(a,v,sizeof(a))
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 const string TASKNAME = "C";
 const string TASKMOD = "small";
 const string INFILE = TASKNAME+"-"+TASKMOD+".in";
 const string OUTFILE = TASKNAME+"-"+TASKMOD+".out";
 
 
 
 void PreCalc(){
 }
 
 int n;
 int a[2100];
 int ans[2100];
 
 void solve(){
     scanf("%d",&n);
     for (int i = 0; i < n-1; i++)
         scanf("%d",&a[i]),--a[i];
 
     for (int i = 0; i < n-1; i++)
         for (int j = i+1; j < n-1; j++)
             if (a[i] > j && a[j] > a[i]){
                 printf("Impossible\n");
                 return;
             }
                     
 
 
     for (int i = 0; i < n; i++)
         ans[i] = i*i;
     
     for (int i = n-2; i >= 0; i--){
         int id = -1;
         for (int j = 0; j < i; j++)
             if (a[j] == i){
                 id = j;
                 break;
             }
         if (id == -1)
             continue;
 
         int mv = 0;
 
         for (int j = id; j < i; j++){
             ll ch = (ans[i]*1LL*(a[i]-j) - ans[a[i]]*1LL*(i - j));
             int val = ch/(a[i] - i);
             val += 2;
             while (val * 1LL * (a[i] - i) > ch)
                 val--;                                                           
             mv = max(mv,ans[j] - val);
         }
 
         //cerr <<"!!!"<<mv<<endl;
 
         for (int j = id; j < i; j++)
             ans[j] -= mv;
 
         mv = *min_element(ans,ans+n);
         for (int j = 0; j < n; j++)
             ans[j] -= mv;//,cerr<<ans[j] <<" ";
         //cerr<<endl;
     }
 
     for (int i = 0; i < n; i++)
         printf("%d ",ans[i]);
     printf("\n");
 
 }
 
 int main(){
     freopen(INFILE.data(),"r",stdin);
     freopen(OUTFILE.data(),"w",stdout);
     PreCalc();
     int t;
     cin>>t;
     for (int i=1;i<=t;i++)
         {
             printf("Case #%d: ",i);
             solve();
             if (i>t-20 || i%10==0)
                 cerr<<"SOLVED:"<<i<<endl;
         }
 
   return 0;
 }