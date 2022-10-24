#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

struct Trie{
  map<char,Trie> prox;
};

set<char> have[3000];

void insert(Trie &r, string s){
  
  Trie* cur = &r;
  
    //~ cerr << "mete " << s << endl;
  for(int i=0;i<(int)s.size();i++){
    char act = s[i];
    //~ cerr << act << endl;
    have[i].insert(act);
    cur = &cur->prox[act];
    
  }
  
}

void dfs(Trie &r, string &ans, int level,string &curs,int n,int l){
  if(ans!="-") return;
  //~ cerr << curs << ' ' << level <<  endl;
  
  for(auto c: have[level]){
    //~ cerr << "T " << c << ' ' << level << endl;
    if(r.prox.count(c)==0){
      curs+=c;
      for(int i=level+1;i<l;i++) curs+=*have[i].begin();
      if(ans=="-") ans = curs;
      //~ curs.pop_back();
      return;
    }else{
      curs+=c;
      dfs(r.prox[c],ans,level+1,curs,n,l);
      curs.pop_back();
      //~ cerr << " " << curs << endl;
      if(ans!="-") return;
    }
  }
  
}


void solve(){
  int n = in();
  int l = in();
  
  for(int i=0;i<l+2;i++) have[i].clear();
  
  Trie r;
  
  string s;
  for(int i=0;i<n;i++){
    cin >> s;
    insert(r,s);
  }
  
  
  string curs = "";
  string ans = "-";
  
  dfs(r,ans,0,curs,n,l);
  
  cout << ans << endl;
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #" << i+1<<": ";
      solve();
    }
}
