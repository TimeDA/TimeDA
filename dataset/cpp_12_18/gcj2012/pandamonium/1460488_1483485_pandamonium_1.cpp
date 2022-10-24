#include <cstdio>
 #include <cstring>
 #include <iostream>
 using namespace std;
 char str[205];
 char decrypt[]={"yhesocvxduiglbkrztnwjpfmaq"};
 int t,x,y,len;
 int main(){
     scanf("%d\n",&t);
     for(x=1;x<=t;x++){
         cin.getline(str,205,'\n');
         printf("Case #%d: ",x);
         len=strlen(str);
         for(y=0;y<len;y++){
             if(str[y]==' ') printf(" ");
             else printf("%c",decrypt[int(str[y])-97]);
         }
         printf("\n");
     }
     return 0;
 }
             
