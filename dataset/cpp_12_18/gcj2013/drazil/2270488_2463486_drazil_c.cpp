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
 
 using namespace std ;
 
 typedef struct tmp
 {
     int n[310] ;
     int len ;
 } bn ;
 
 bn sq(bn a)
 {
     bn out ;
     int i, j ;
     
     memset(out.n,0,sizeof(out.n)) ;
     
     for(i=0;i<a.len;i++)
     {
         for(j=0;j<a.len;j++)
         {
             out.n[i+j] += a.n[i]*a.n[j] ;
         }
     }
     
     for(i=0;i<310;i++)
     {
         out.n[i+1] += out.n[i]/10 ;
         out.n[i] %= 10 ;
     }
     
     for(i=309;i>=0&&out.n[i]==0;i--) ;
     out.len = i+1 ;
     
     return out ;
 }
 
 char pool[45000][110] ;
 int plen[45000] ;
 int tcnt = 0 ;
 
 bool uperequal(char *str, int len, int id)
 {
     if(plen[id]>len) return true ;
     if(plen[id]<len) return false ;
 
     int i ;
 
     for(i=0;i<len;i++)
     {
         if(pool[id][i]>str[i]-'0')
         {
             return true ;
         }
         else if(pool[id][i]<str[i]-'0')
         {
             return false ;
         }
     }
 
     return true ;
 }
 
 bool lowerequal(char *str, int len, int id)
 {
     if(plen[id]<len) return true ;
     if(plen[id]>len) return false ;
 
     int i ;
 
     for(i=0;i<len;i++)
     {
         if(pool[id][i]<str[i]-'0')
         {
             return true ;
         }
         else if(pool[id][i]>str[i]-'0')
         {
             return false ;
         }
     }
 
     return true ;
 }
 
 int getuperequal(char *str, int len)
 {
     int a = 0, b = tcnt-1 ;
     int m ;
     
     while(a!=b)
     {
         m = (a+b)/2 ;
         if(uperequal(str,len,m)==true)
         {
             b = m ;
         }
         else
         {
             a = m+1 ;
         }
     }
     
     return a ;
 }
 
 int getlowerequal(char *str, int len)
 {
     int a = 0, b = tcnt-1 ;
     int m ;
 
     while(a!=b)
     {
         m = (a+b)/2 ;
         if(lowerequal(str,len,m)==true)
         {
             a = m ;
             if(b==a+1)
             {
                 if(lowerequal(str,len,b)==true) return b ;
                 else return a ;
             }
         }
         else
         {
             b = m-1 ;
         }
     }
 
     return a ;
 }
 
 int main(void)
 {
     bn a, b ;
     int len ;
     int cnt ;
     
     for(len=1;len<=14;len++)
     {
         fprintf(stderr,"CHECKING LEN OF %d : ",len) ;
         a.len = len ;
         cnt = 0 ;
         int p = (len-1)/2 ;
         memset(a.n,0,sizeof(a.n)) ;
         a.n[0] = 1 ;
         while(1)
         {
             //make palidrome
             int pos ;
             for(pos=p+1;pos<len;pos++)
             {
                 a.n[pos] = a.n[len-pos-1] ;
             }
             b = sq(a) ;
             //check palidrome
             for(pos=0;pos<b.len;pos++)
             {
                 if(b.n[pos]!=b.n[b.len-pos-1]) break ;
             }
             if(pos==b.len)
             {
                 cnt++ ;
                 for(pos=0;pos<b.len;pos++)
                 {
                     pool[tcnt][pos] = b.n[pos] ;
                 }
                 plen[tcnt] = b.len ;
                 tcnt++ ;
             }
             //plus 1
             pos = p ;
             while(pos>=0)
             {
                 a.n[pos]++ ;
                 if(pos==0)
                 {
                     if((a.n[pos]==3&&len>=2)||(a.n[pos]==4&&len==1))
                     {
                         a.n[pos] = 0 ;
                         pos-- ;
                     }
                     else break ;
                 }
                 else if(pos==p)
                 {
                     if((a.n[pos]==2&&len>=2&&len%2==0)||(a.n[pos]==3&&len>=2&&len%2==1)||(a.n[pos]==4&&len==1))
                     {
                         a.n[pos] = 0 ;
                         pos-- ;
                     }
                     else break ;
                 }
                 else
                 {
                     if(a.n[pos]==2)
                     {
                         a.n[pos] = 0 ;
                         pos-- ;
                     }
                     else break ;
                 }
             }
             if(len>2&&a.n[0]==2&&a.n[p-1]!=0) break ;
             if(pos<0) break ;
         }
         fprintf(stderr,"%d\n",cnt) ;
     }
     fprintf(stderr,"%d\n",tcnt) ;
     plen[tcnt++] = 110 ; //dummy for binary search
     
     int tc, cas ;
 
     scanf("%d",&tc) ;
     char A[110], B[110] ;
     for(cas=1;cas<=tc;cas++)
     {
         scanf("%s%s",A,B) ;
         int a = getuperequal(A,strlen(A)) ;
         int b = getlowerequal(B,strlen(B)) ;
         printf("Case #%d: %d\n",cas,max(0,b-a+1)) ;
     }
     return 0;
 }
