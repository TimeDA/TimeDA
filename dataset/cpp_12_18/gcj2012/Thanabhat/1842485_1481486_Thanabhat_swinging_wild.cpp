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
 
 int n;
 int d[10005],l[10005];
 int ar[10005];
 int dd;
 
 bool solve(){
 
     scanf("%d",&n);
     for(int i=0;i<n;i++)
         scanf("%d %d",&d[i],&l[i]);
     for(int i=0;i<n;i++)
         ar[i]=0;
     scanf("%d",&dd);
     ar[0]=d[0];
     for(int i=0;i<n;i++)
     {
 //        printf("*%d*\n",i);
         if(ar[i]+d[i]>=dd)
             return true;
         int p=i+1;
         while(p<n&&d[p]<=d[i]+ar[i])
         {
             int tmp=min(l[p],d[p]-d[i]);
             ar[p]=max(ar[p],tmp);
             p++;
         }
     }
 
     return false;
 }
 
 int main(){
 
     freopen("A-small-attempt0.in","r",stdin);
     freopen("A-small-attempt0.out","w",stdout);
     int t;
     scanf("%d",&t);
     for(int i=0;i<t;i++)
     {
         printf("Case #%d: ",i+1);
         if(solve())
             printf("YES\n");
         else
             printf("NO\n");
     }
     return 0;
 }
