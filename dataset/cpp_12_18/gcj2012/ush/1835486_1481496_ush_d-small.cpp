
 #include <cstdio>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <cstring>
 #include <cctype>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <list>
 #include <cmath>
 #include <complex>
 #include <numeric>
 #include <cassert>
 using namespace std;
 
 #define REP(i,n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 
 typedef long long ll;
 
 int n;
 string line;
 
 int main(void) {
 
   map<char, char> table;
   table['o'] = '0';
   table['i'] = '1';
   table['e'] = '3';
   table['a'] = '4';
   table['s'] = '5';
   table['t'] = '7';
   table['b'] = '8';
   table['g'] = '9';
 
 
   int nCases;
   cin >> nCases;
   REP(iCase, nCases) {
     int K; // 2
     cin >> K >> line;
     n = line.size();
     set<string> ss;
     REP(i, n-1){
       string s = line.substr(i, 2);
       ss.insert(s);
       char ch = s[0];
       if(table.count(ch)){
 	s[0] = table[ch];
 	ss.insert(s);
 	s[0] = ch;
       }
       
       ch = s[1];
       if(table.count(ch)){
 	s[1] = table[ch];
 	ss.insert(s);
 	char ch0 = s[0];
 	if(table.count(ch0)){
 	  s[0] = table[ch0];
 	  ss.insert(s);;
 	}
       }
     }
     
     int res = ss.size() + 1;
     map<char, int> deg;
     FOR(it, ss){
       ++deg[(*it)[0]];
       --deg[(*it)[1]];
     }
 
     int degIn = 0;
     int degOut = 0;
     FOR(it, deg){
       if(it->second != 0){
 	if(it->second < 0){
 	  degIn -= it->second;
 	}else{
 	  degOut += it->second;
 	}
       }
     } 
     
     assert(degIn == degOut);
     cerr << ">" << degIn << endl;
     if(degIn > 0){
       res += degIn - 1;
     }
     
     cout << "Case #" << (iCase+1) << ": " << res << endl;
   }
   
   return 0;
 }
