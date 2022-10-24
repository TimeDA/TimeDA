#include <iostream>
 #include <string>
 #include <sstream>
 #include <cstring>
 using namespace std;
 char buf[200];
 string go[30]={
 "ay",
 "bh",
 "ce",
 "ds",
 "eo",
 "fc",
 "gv",
 "hx",
 "id",
 "ju",
 "ki",
 "lg",
 "ml",
 "nb",
 "ok",
 "pr",
 "qz",
 "rt",
 "sn",
 "tw",
 "uj",
 "vp",
 "wf",
 "xm",
 "ya",
 "zq"
 };
 void read(string& w){
   gets(buf);
   w=string(buf);
 }
 void doit(int CASE){
   string S; read(S);
   cout<<"Case #"<<CASE<<": ";
   for(int i=0;i<S.size();++i)
    if(S[i]>='a' && S[i]<='z')S[i]=go[S[i]-'a'][1];
   cout<<S<<'\n';
 }
 int main(){
   int Q; cin>>Q; gets(buf);
   for(int i=1;i<=Q;++i)doit(i);
   //system("pause");
   return 0;
 }
