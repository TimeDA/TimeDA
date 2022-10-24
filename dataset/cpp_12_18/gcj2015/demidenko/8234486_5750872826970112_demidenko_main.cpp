#include<iostream>
 #include<cstdio>
 #include<cstdlib>
 #include<algorithm>
 #include<vector>
 #include<string>
 #include<set>
 #include<map>
 #include<cmath>
 #include<memory.h>
 #include <unistd.h>
 #include <wait.h>
 using namespace std;
 typedef long long ll;
 const int __limitofthreads = 8;
 vector<pid_t> __ids;
 char __str[256];
 int __tests, __testsdone;
 void __inctests(){
     ++__testsdone;
     sprintf(__str, "\033[1;1Htests %d/%d done.%c",__testsdone,__tests,10);
     cerr<<__str;
 }
 
 const int N = 1e6+6;
 
 
 double r[N], c[N];
 void solve(int test){
     /*+++start read data+++*/
     
     int n;
     cin>>n;
     double X, V;
     cin>>V>>X;
     for(int i=0;i<n;++i) cin>>r[i]>>c[i];
     
     /*---end read data---*/
     if(__ids.size()>=__limitofthreads) if(wait(0)!=-1) __inctests();
     pid_t __id = fork();
     if(__id>0){
         __ids.push_back(__id);
         return ;
     }else{
         sprintf(__str, "thread%d.out", test);
         freopen(__str,"w",stdout);
     }
     /*+++start solution and write output+++*/
     cout<<"Case #"<<test<<": ";
     
     double ans = -1, eps = 1e-9;
     
     if(n==1){
         if(c[0]==X){
             ans = V/r[0];
         }
     }else{
         double t1 = (X*V-c[0]*V)/(r[1]*c[1]-r[1]*c[0]);
         double t0 = (V-t1*r[1])/r[0];
         if(t1>-eps && t0>-eps) ans = max(t1, t0);
     }
     
     if(ans==-1) printf("IMPOSSIBLE\n");
     else printf("%.12lf\n",ans);
     
     /*---end solution---*/
     exit(0);
 }
 
 int main(){
     freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
     
     
     cin>>__tests;
     for(int i=1;i<=__tests;++i){
         solve(i);
     }
     
     /*combining outputs*/
     for(pid_t __id : __ids) if(waitpid(__id,0,0)!=-1) __inctests();
     int __bufsize = 1<<16;
     char *__buf = new char[__bufsize];
     for(int i=1;i<=__tests;++i){
         sprintf(__str, "thread%d.out", i);
         FILE *f = fopen(__str, "r");
         while(fgets(__buf, __bufsize, f)) printf("%s",__buf);
         fclose(f);
         remove(__str);
     }
     
     return 0;
 }
