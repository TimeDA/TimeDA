/*
 LANG: C++
 */
 
 #include<cstdio>
 #include<cstdlib>
 #include<algorithm>
 #include<cmath>
 #include<functional>
 #include<vector>
 #include<list>
 #include<set>
 #include<queue>
 #include<map>
 #include<cctype>
 #include<cstring>
 #include<string>
 #include<sstream>
 #include<iostream>
 #include<ctime>
 
 using namespace std;
 
 int n,s,p;
 int t[105];
 
 bool solve(){
     scanf("%d %d %d",&n,&s,&p);
     for(int i=0;i<n;i++)
         scanf("%d",&t[i]);
 //    sort(t,t+n,greater<int>());
     int mm,mm2;
     if(p==0)
     {
         mm=0;
         mm2=0;
     }
     else if(p==1)
     {
         mm=1;
         mm2=1;
     }
     else
     {
         mm=p+2*(p-1);
         mm2=p+2*(p-2);
     }
     int sol=0;
     for(int i=0;i<n;i++)
     {
         if(t[i]>=mm)
         {
             sol++;
         }else if(t[i]>=mm2)
         {
             if(s>0)
             {
                 sol++;
                 s--;
             }
         }
     }
     printf("%d\n",sol);
     return true;
 }
 
 int main(){
 
     freopen("B-small-attempt0.in","r",stdin);
     freopen("B-small-attempt0.out","w",stdout);
     int t;
     scanf("%d",&t);
     for(int i=1;i<=t;i++)
     {
         printf("Case #%d: ",i);
         solve();
     }
     return 0;
 }
