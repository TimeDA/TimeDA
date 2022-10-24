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
 char str[200];
 char rep[27]="yhesocvxduiglbkrztnwjpfmaq";
 
 int main(){
 
     freopen("A-small-attempt1.in","r",stdin);
     freopen("A-small-attempt1.out","w",stdout);
 //    cin>>n;
     scanf("%d\n",&n);
     for(int i=0;i<n;i++)
     {
 //        cin.getline(str,200);
         gets(str);
         int len=strlen(str);
         for(int j=0;j<len;j++)
         {
             if(str[j]!=' ')
             {
                 str[j]=rep[str[j]-'a'];
             }
         }
         printf("Case #%d: %s\n",i+1,str);
     }
     return 0;
 }
