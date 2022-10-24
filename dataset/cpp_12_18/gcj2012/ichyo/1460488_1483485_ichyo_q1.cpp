#include <iostream>
 #include <sstream>
 #include <string>
 #include <algorithm>
 #include <vector>
 #include <stack>
 #include <queue>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <cassert>
 
 using namespace std;
 
 #define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
 #define REP(i,n) FOR(i,0,n)
 #define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
 
 template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }
 
 typedef long long ll;
 const int INF = 100000000;
 const double EPS = 1e-8;
 const int MOD = 1000000007;
 
 int main(){
   map<char,char> m;
   m[' '] =' ';
   m['a'] = 'y';
   m['b'] = 'h';
   m['c'] = 'e';
   m['d'] = 's';
   m['e'] = 'o';
   m['f'] = 'c';
   m['g'] = 'v';
   m['h'] = 'x';
   m['i'] = 'd';
   m['j'] = 'u';
   m['k'] = 'i';
   m['l'] = 'g';
   m['m'] = 'l';
   m['n'] = 'b';
   m['o'] = 'k';
   m['p'] = 'r';
   m['q'] = 'z';
   m['r'] = 't';
   m['s'] = 'n';
   m['t'] = 'w';
   m['u'] = 'j';
   m['v'] = 'p';
   m['w'] = 'f';
   m['x'] = 'm';
   m['y'] = 'a';
   m['z'] = 'q';
   int N; cin>>N; cin.ignore();
   int n = 1;
   while(N--){
     printf("Case #%d: ",n++);
     string s1;
     getline(cin, s1);
     REP(i,s1.size()){
       putchar(m[s1[i]]);
     }
     putchar('\n');
   }
   return 0;
 }
 
