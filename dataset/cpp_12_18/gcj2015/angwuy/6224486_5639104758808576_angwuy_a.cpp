#include <cstdio>
 #include <cstring>
 #include <string>
 #include <iostream>
 #include <sstream>
 #include <map>
 #include <set>
 #include <vector>
 #include <queue>
 #include <bitset>
 #include <numeric>
 #include <ctime>
 #include <cmath>
 #include <cassert>
 #include <algorithm>
 using namespace std;
 int gao(int n, string s) {
     int cnt = int(s[0]-'0') , ret = 0 ;
     for ( int i = 1 ; i <= n ; i ++ ) {
         if ( cnt < i ) { ret += i-cnt ; cnt += i - cnt ; }
         cnt += int(s[i]-'0') ;
     }
     return ret ;
 }
 int main() {
     freopen("A-small-attempt0.in","r",stdin) ; freopen("A-small-attempt0.out","w",stdout) ;
     //freopen("A-large.in","r",stdin) ; freopen("A-large.out","w",stdout) ;
     int Test , N ; string S ; cin >> Test ;
     for ( int i = 1 ; i <= Test ; i ++ ) {
         cin >> N >> S ;
         cout << "Case #" << i << ": " << gao(N,S) << "\n" ;
     }
 }
