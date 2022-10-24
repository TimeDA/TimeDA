/*
 AUTHOR: THANABHAT KOOMSUBHA
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
 
 int solve(int cc){
     int a,aa[4],aaa[20];
     vector<int> aaaa;
     for(int i=1;i<=16;i++)
         aaa[i]=0;
     scanf("%d",&a);
     for(int i=1;i<=4;i++)
     {
         for(int j=0;j<4;j++)
             scanf("%d",&aa[j]);
         if(i==a)
         {
             for(int j=0;j<4;j++)
                 aaa[aa[j]]++;
         }
     }
     scanf("%d",&a);
     for(int i=1;i<=4;i++)
     {
         for(int j=0;j<4;j++)
             scanf("%d",&aa[j]);
         if(i==a)
         {
             for(int j=0;j<4;j++)
                 aaa[aa[j]]++;
         }
     }
     for(int i=1;i<=16;i++)
         if(aaa[i]==2)
             aaaa.push_back(i);
     printf("Case #%d: ",cc);
     if(aaaa.size()==0)
         printf("Volunteer cheated!\n");
     else if(aaaa.size()==1)
         printf("%d\n",aaaa[0]);
     else
         printf("Bad magician!\n");
 
     return 1;
 }
 
 int main(){
 
 //	freopen("input.txt","r",stdin);
 //	freopen("output.txt","w",stdout);
 
     int t;
     scanf("%d",&t);
     for(int i=0;i<t;i++)
         solve(i+1);
 
 	return 0;
 }
