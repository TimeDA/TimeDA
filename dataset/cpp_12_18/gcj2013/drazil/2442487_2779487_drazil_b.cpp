#include <cstdio>
 #include <set>
 #include <string>
 #include <cstring>
 #include <cstdlib>
 #include <iostream>
 #include <cmath>
 #include <vector>
 #include <queue>
 #include <algorithm>
 #include <map>
 #include <stack>
 
 using namespace std ;
 int n ;
 int A[2100] ;
 int B[2100] ;
 int cur[2100] ;
 int pos[2100] ;
 int bv[2100] ;
 
 void getpos()
 {
     int i, j ;
 
     memset(pos,0,sizeof(pos)) ;
     
     for(i=0;i<n;i++)
     {
         if(cur[i]==0)
         {
             bv[i] = 0 ;
         }
         else
         {
             int pv = 0 ;
             for(j=0;j<i;j++)
             {
                 if(cur[j]<cur[i]&&bv[j]>pv) pv = bv[j] ;
             }
             bv[i] = pv+1 ;
         }
     }
     
     int lastval = 0 ;
     
     for(i=0;i<n;i++)
     {
         if(cur[i]==0)
         {
             if(A[i]==lastval+1)
             {
                 pos[i]++ ;
             }
         }
         else
         {
             lastval = max(lastval,bv[i]) ;
         }
     }
     
     lastval = 0 ;
     
     for(i=n-1;i>=0;i--)
     {
         if(cur[i]==0)
         {
             bv[i] = 0 ;
         }
         else
         {
             int pv = 0 ;
             for(j=n-1;j>i;j--)
             {
                 if(cur[j]<cur[i]&&bv[j]>pv) pv = bv[j] ;
             }
             bv[i] = pv+1 ;
         }
     }
     
     for(i=n-1;i>=0;i--)
     {
         if(cur[i]==0)
         {
             if(B[i]==lastval+1)
             {
                 pos[i]++ ;
             }
         }
         else
         {
             lastval = max(lastval,bv[i]) ;
         }
     }
 }
 
 bool go(int id)
 {
     if(id>n) return true ;
     
     int nos = 0 ;
     while(nos<n)
     {
         getpos() ;
         while(nos<n&&pos[nos]!=2) nos++ ;
         if(nos>=n) return false ;
         cur[nos] = id ;
         if(go(id+1)==true) return true ;
         cur[nos] = 0 ;
         nos++ ;
     }
     
     return false ;
 }
 
 int main(void)
 {
     int t, tc ;
 
     scanf("%d",&t) ;
     for(tc=1;tc<=t;tc++)
     {
         scanf("%d",&n) ;
         memset(cur,0,sizeof(cur)) ;
         int i ;
         for(i=0;i<n;i++)
         {
             scanf("%d",&A[i]) ;
         }
         for(i=0;i<n;i++)
         {
             scanf("%d",&B[i]) ;
         }
         go(1) ;
         
         printf("Case #%d:",tc) ;
         for(i=0;i<n;i++)
         {
             printf(" %d",cur[i]) ;
         }
         printf("\n") ;
     }
 
     return 0;
 }
