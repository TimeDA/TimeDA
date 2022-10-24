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
 
 bool solve(){
 
     int n,w,l;
     pair<int,int> r[1005],sol[1005];
 
     scanf("%d %d %d",&n,&w,&l);
     for(int i=0;i<n;i++)
     {
         scanf("%d",&r[i].first);
         r[i].second=i;
     }
     sort(r,r+n,greater<pair<int,int> >());
 //    for(int i=0;i<n;i++)
 //    {
 //        printf("%d %d\n",r[i].first,r[i].second);
 //    }
     bool rev=(l>w)?true:false;
     if(rev)
     {
         int t=w;
         w=l;
         l=t;
     }
     int kobbon=0,kobsai=0;
     int curx=-1;
     int nextkobsai=0;
     for(int i=0;i<n;i++)
     {
         int ind=r[i].second;
         int rad=r[i].first;
         if(kobbon==0&&kobsai==0)
         {
             kobbon=rad;
             curx=0;
             nextkobsai=rad;
             sol[ind].first=curx;
             sol[ind].second=0;
         }else if(kobbon==0)
         {
             kobbon=rad;
             curx=kobsai+rad;
             nextkobsai=kobsai+(2*rad);
             sol[ind].first=curx;
             sol[ind].second=0;
         }else
         {
             if(l-kobbon>=rad)
             {
                 sol[ind].first=curx;
                 sol[ind].second=kobbon+rad;
                 kobbon+=(2*rad);
                 if(kobbon>l)
                 {
                     kobbon=0;
                     kobsai=nextkobsai;
                     curx=-1;
                 }
             }else
             {
                 kobbon=0;
                 kobsai=nextkobsai;
                 curx=-1;
                 i--;
             }
         }
     }
     for(int i=0;i<n;i++)
     {
         if(rev)
         {
             printf(" %d %d",sol[i].second,sol[i].first);
         }else
         {
             printf(" %d %d",sol[i].first,sol[i].second);
         }
     }
     printf("\n");
     return true;
 }
 
 int main(){
 
     freopen("B-small-attempt0.in","r",stdin);
     freopen("B-small-attempt0.out","w",stdout);
 
     int t;
     scanf("%d",&t);
     for(int i=0;i<t;i++)
     {
         printf("Case #%d:",i+1);
         solve();
     }
 
     return 0;
 }
