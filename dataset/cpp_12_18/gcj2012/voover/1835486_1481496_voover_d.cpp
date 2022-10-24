#include <algorithm>
 #include <cstdio>
 #include <cstdlib>
 #include <list>
 #include <map>
 #include <queue>
 #include <set>
 #include <stack>
 #include <vector>
 #include <cstring>
 #include <string>
 #include <iostream>
 using namespace std;
  
 typedef long long LL;
 typedef long double LD;
 typedef vector<int> VI;
 typedef pair<int,int> PII;
  
 #define REP(i,n) for(int i=0;i<(n);++i)
 #define SIZE(c) ((int)((c).size()))
 #define FOR(i,a,b) for (int i=(a); i<(b); ++i)
 #define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
 #define FORD(i,a,b) for (int i=((int)(a))-1; i>=(b); --i)
  
 #define pb push_back
 #define mp make_pair
 #define st first
 #define nd second
 
 vector<char> sub[256];
 
 char buf[10000];
 void scase(int CID) {
   int K;
   scanf("%d",&K);
   scanf("%s",buf);
   int N = strlen(buf);
   
   set<string> S;
   REP(i,N-K+1) {
     S.insert(string(buf+i, K));
   }
   
   int in[256], out[256];
   REP(i,256) in[i] = out[i] = 0;
   int result = 1;
   FOREACH(it, S) {
   //  cout << *it << endl;
         string s = *it;
     result += sub[s[0]].size() * sub[s[1]].size();
     FOREACH(jt,sub[s[0]])FOREACH(jt2,sub[s[1]]) ++out[*jt], ++in[*jt2];
 //     ++in[*jt];    
   }
   //printf("%d!\n", result);
   int result2 = 0;
   REP(i,256) {
     //if (in[i] + out[i]) printf("%c %d %d\n",i,in[i],out[i]);
     result2 += abs(in[i] - out[i]);
   }printf("Case #%d: %d\n", CID, result + max(0, result2/2-1));
 }
 
 int main() {
   REP(i,256) sub[i].push_back(i);
   sub['o'].push_back('0');
   sub['i'].push_back('1');
   sub['e'].push_back('3');
   sub['a'].push_back('4');
   sub['s'].push_back('5');
   sub['t'].push_back('7');
   sub['b'].push_back('8');            
   sub['g'].push_back('9');
   int Z;
   scanf("%d",&Z);
   FOR(z,1,Z+1) scase(z);
 }
