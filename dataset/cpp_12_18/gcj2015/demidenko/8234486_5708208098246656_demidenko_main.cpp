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
 
 const int N = 111;
 
 char s[N][N];
 int n,m;
 
 int check(int x, int y, int dx, int dy){
     for(;;){
         x+=dx;
         y+=dy;
         if(x<0 || x>=n || y<0 || y>=m) return 0;
         if(s[x][y]!='.') break;
     }
     return 1;
 }
 
 int dx[] = {-1,0,1,0};
 int dy[] = {0,-1,0,1};
 
 void solve(int test){
     /*+++start read data+++*/
     
     cin>>n>>m;
     for(int i=0;i<n;++i) cin>>s[i];
     
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
     
     int ans = 0;
     for(int i=0;i<n;++i)
     for(int j=0;j<m;++j) if(s[i][j]!='.'){
         bool all = true;
         for(int k=0;k<4;++k){
             int c = check(i,j,dx[k],dy[k]);
             if(c){
                 all = false;
             }
         }
         if(all){
             ans = -1;
             i = j = 1e9;
             break;
         }
         int t;
         if(s[i][j]=='>') t = 3;
         if(s[i][j]=='<') t = 1;
         if(s[i][j]=='^') t = 0;
         if(s[i][j]=='v') t = 2;
         for(int k=0;k<4;++k){
             int c = check(i,j,dx[(k+t)%4],dy[(k+t)%4]);
             if(c){
                 if(k) ++ans;
                 break;
             }
         }
     }
     
     if(ans==-1) cout<<"IMPOSSIBLE"<<endl;
     else cout<<ans<<endl;
     
     
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
