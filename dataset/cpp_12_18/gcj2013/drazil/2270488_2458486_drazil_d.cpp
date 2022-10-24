#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <vector>
 #include <algorithm>
 #include <math.h>
 
 using namespace std ;
 
 int k, n ;
 int kcnt[210] ;
 char used[2100000] ;
 int ans[210] ;
 vector<int> chest[210] ;
 int kofc[210] ;
 
 bool go(int id, unsigned int val)
 {
     if(id==n) return true ;
     
     if(used[val]==1) return false ;
     used[val] = 1 ;
     
     int cid ;
     for(cid=0;cid<n;cid++)
     {
         if((val&(1<<cid))!=0) continue ;
         if(kcnt[kofc[cid]]==0) continue ;
         kcnt[kofc[cid]]-- ;
         int i ;
         for(i=0;i<(int)chest[cid].size();i++)
         {
             kcnt[chest[cid][i]]++ ;
         }
         ans[id] = cid ;
         if(go(id+1,(val|(1<<cid)))==true) return true ;
         kcnt[kofc[cid]]++ ;
         for(i=0;i<(int)chest[cid].size();i++)
         {
             kcnt[chest[cid][i]]-- ;
         }
     }
     
     return false ;
 }
 
 int main(void)
 {
     int tc, cas ;
     int i ;
     
     scanf("%d",&tc) ;
     for(cas=1;cas<=tc;cas++)
     {
         scanf("%d%d",&k,&n) ;
         memset(kcnt,0,sizeof(kcnt)) ;
         memset(used,0,sizeof(used)) ;
         
         for(i=0;i<k;i++)
         {
             int kid ;
             
             scanf("%d",&kid) ;
             kcnt[kid]++ ;
         }
         
         for(i=0;i<n;i++)
         {
             int tn ;
             
             scanf("%d%d",&kofc[i],&tn) ;
             chest[i].clear() ;
             while(tn--)
             {
                 int kid ;
                 scanf("%d",&kid) ;
                 chest[i].push_back(kid) ;
             }
         }
         
         if(go(0,0)==false)
         {
             printf("Case #%d: IMPOSSIBLE\n",cas) ;
         }
         else
         {
             printf("Case #%d:",cas) ;
             for(i=0;i<n;i++)
             {
                 printf(" %d",ans[i]+1) ;
             }
             printf("\n") ;
         }
     }
 
 	return 0 ;
 }
