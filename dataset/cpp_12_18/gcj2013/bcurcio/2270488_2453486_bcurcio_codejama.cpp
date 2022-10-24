#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 string ans[]={"X won", "O won","Draw","Game has not completed"};
 
 char bd[20];
 void solve(){
   int state = 2;
   int i;
   int tx=0,to=0;
   for(i=0;i<16;i++){
     bd[i]=0;
     while(bd[i]<'!')scanf("%c",bd+i);
     if(bd[i]=='.') state=3;
     if(bd[i]=='X') tx++;
     if(bd[i]=='O') to++;
   }
   //puts("leyo");
   //for(i=0;i<16;i++) putchar(bd[i]);
   //puts("leyo");
   
   int j;
   bool vale;
   for(i=0;i<4;i++){
     vale=true;
     for(j=0;j<4;j++) if(bd[i*4+j]=='X' || bd[i*4+j]=='.') vale=false;
     if(vale) state = 1;
     vale=true;
     for(j=0;j<4;j++) if(bd[j*4+i]=='X' || bd[j*4+i]=='.') vale=false;
     if(vale) state = 1;
   }
   vale=true;
   for(j=0;j<4;j++) if(bd[j*4+j]=='X' || bd[j*4+j]=='.') vale=false;
   if(vale) state = 1;
   vale=true;
   for(j=0;j<4;j++) if(bd[j*4+(3-j)]=='X' || bd[j*4+(3-j)]=='.') vale=false;
   if(vale) state = 1;
   
   
   for(i=0;i<4;i++){
     vale=true;
     for(j=0;j<4;j++) if(bd[i*4+j]=='O' || bd[i*4+j]=='.') vale=false;
     if(vale) state = 0;
     vale=true;
     for(j=0;j<4;j++) if(bd[j*4+i]=='O' || bd[j*4+i]=='.') vale=false;
     if(vale) state = 0;
   }
   vale=true;
   for(j=0;j<4;j++) if(bd[j*4+j]=='O' || bd[j*4+j]=='.') vale=false;
   if(vale) state = 0;
   vale=true;
   for(j=0;j<4;j++) if(bd[j*4+(3-j)]=='O' || bd[j*4+(3-j)]=='.') vale=false;
   if(vale) state = 0;
   
   cout << ans[state] << endl;
   
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
       cout << "Case #"<<i+1<<": ";
       solve();
     }
 }
