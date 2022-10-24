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
     char str[128];
 
     scanf("%s",str);
     int sol=0;
     int len = strlen(str);
     for(int i=0;i<len-1;i++){
         if(str[i]!=str[i+1]){
             sol++;
         }
     }
     if(str[len-1]=='-'){
         sol++;
     }
     printf("Case #%d: %d\n",cc,sol);
     return 1;
 }
 
 int main(){
 
 //	freopen("input.txt","r",stdin);
 //	freopen("output.txt","w",stdout);
 
     int T;
     scanf("%d",&T);
     for(int i=0;i<T;i++){
         solve(i+1);
     }
 
 	return 0;
 }
