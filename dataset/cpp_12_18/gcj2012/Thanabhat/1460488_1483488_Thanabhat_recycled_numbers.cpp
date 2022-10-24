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
     int a,b,len,p,tmp;
     char str[10],str2[10];
     scanf("%d %d",&a,&b);
     sprintf(str,"%d",a);
     len=strlen(str);
     set<pair<int,int> > ss;
     for(int i=a;i<=b;i++)
     {
         sprintf(str,"%d",i);
         for(int j=1;j<len;j++)
         {
             p=0;
             for(int k=j;k<len;k++)
                 str2[p++]=str[k];
             for(int k=0;k<j;k++)
                 str2[p++]=str[k];
             str2[p]=0;
             if(str2[0]=='0')
                 continue;
 //            printf("%d-%d\n",i,tmp);
             sscanf(str2,"%d",&tmp);
             if(tmp>=a&&tmp<=b&&tmp>i)
             {
 //                sol++;
 //                printf("%d - %d\n",i,tmp);
 //                pair<int,int> p = make_pair(i,tmp);
 //                if(ss.find(p)!=ss.end())
 //                    printf("&&&&&&&& %d %d\n",i,tmp);
                 ss.insert(make_pair(i,tmp));
             }
         }
     }
     printf("%d\n",ss.size());
     return true;
 }
 
 int main(){
 
     freopen("C-small-attempt0.in","r",stdin);
     freopen("C-small-attempt0.out","w",stdout);
     int t;
     scanf("%d",&t);
     for(int i=1;i<=t;i++)
     {
         printf("Case #%d: ",i);
         solve();
     }
     return 0;
 }
