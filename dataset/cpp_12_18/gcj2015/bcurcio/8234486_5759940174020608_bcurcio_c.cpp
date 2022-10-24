#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <unordered_set>
 #include <sstream>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 vector<string> readsentence(){
   string str;
   getline(cin,str);
   
   stringstream ss(str);
   vector<string> ans;
   while(ss>>str) ans.push_back(str);
   
   return ans;
 }
 
 void solve(){
   int N = in();
   vector<string> english = readsentence();
   vector<string> french = readsentence();
   
   sort(english.begin(),english.end());
   int k = unique(english.begin(),english.end()) - english.begin();
   english.resize(k);
   
   sort(french.begin(),french.end());
   k = unique(french.begin(),french.end()) - french.begin();
   french.resize(k);
   
   vector<string> both(min(french.size(),english.size()));
 
   k = set_intersection(english.begin(),english.end(),french.begin(),french.end(),both.begin()) - both.begin();
   both.resize(k);
   
   
   unordered_set<string> E(english.begin(),english.end());
   unordered_set<string> F(french.begin(),french.end());
   unordered_set<string> I(both.begin(),both.end());
   
   
   
   int ans = 1<<30;
   
   vector<vector<string> > unk;
   N -=2;
   int i;
   for(i=0;i<N;i++) unk.push_back(readsentence());
   
   int started = k;
   
   if(N==0){
     cout << k << endl;
     return;
   }
   
   for(i=0;i<(1<<N);i++){
     
     int j;
     unordered_set<string> fr;
     unordered_set<string> en;
     unordered_set<string> ibo;
     
     int cur = started;
     int l;
     for(j=0;j<N;j++) if(i&(1<<j)){
       //french
       
       for(l=0;l<unk[j].size();l++) if(ibo.find(unk[j][l])==ibo.end()){
         fr.insert(unk[j][l]);
         if(en.find(unk[j][l])!=en.end() || E.find(unk[j][l])!=E.end()){
           
           if(I.find(unk[j][l])==I.end() && ibo.find(unk[j][l])==ibo.end()){
             cur++;
             if(cur>ans) break;
           }
           
           ibo.insert(unk[j][l]);
         }
       }
       
     }else{
       //english
       
       for(l=0;l<unk[j].size();l++) if(ibo.find(unk[j][l])==ibo.end()){
         en.insert(unk[j][l]);
         if(fr.find(unk[j][l])!=fr.end() || F.find(unk[j][l])!=F.end()){
           
           if(I.find(unk[j][l])==I.end() && ibo.find(unk[j][l])==ibo.end()){
             cur++;
             if(cur>ans) break;
           }
           
           ibo.insert(unk[j][l]);
         }
       }
       
     }
     
     ans = min(ans,cur);
     
   }
   
   cout << ans << endl;
   
 }
 
 int main(){
   //~ freopen("test","r",stdin);
   for(int i=0,T=in();i<T;i++){
     cout << "Case #"<<i+1<<": ";
       solve();
     }
 }
