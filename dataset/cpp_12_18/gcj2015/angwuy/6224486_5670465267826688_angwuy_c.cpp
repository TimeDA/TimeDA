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
 const string Qur[4][4] = {
     { "+1" , "+i" , "+j" , "+k" } ,
     { "+i" , "-1" , "+k" , "-j" } ,
     { "+j" , "-k" , "-1" , "+i" } ,
     { "+k" , "+j" , "-i" , "-1" }
 } ;
 struct Tq {
     int o ;
     int t ;
 } ;
 Tq str_T(char c) {
     Tq ret ;
     ret.o = 1 ;
     if ( c == '1' ) ret.t = 0 ;
     if ( c == 'i' ) ret.t = 1 ;
     if ( c == 'j' ) ret.t = 2 ;
     if ( c == 'k' ) ret.t = 3 ;
     return ret ;
 }
 string T_str(Tq q) {
     string u ;
     if ( q.o == 1 ) u = "+" ; else u = "-" ;
     if ( q.t == 0 ) return u + "1" ;
     if ( q.t == 1 ) return u + "i" ;
     if ( q.t == 2 ) return u + "j" ;
     if ( q.t == 3 ) return u + "k" ;
 }
 Tq str_T(string s) {
     Tq ret = str_T(s[1]) ;
     ret.o = (s[0] == '+'?+1:-1) ;
     return ret ;
 }
 Tq operator * (Tq p, Tq q) {
     Tq ret = str_T(Qur[p.t][q.t][1]) ;
     ret.o = (Qur[p.t][q.t][0] == '+' ? +1 : -1) * p.o * q.o ;
     return ret ;
 }
 bool operator == (Tq p, Tq q) {
     return (p.o == q.o && p.t == q.t) ;
 }
 bool operator != (Tq p, Tq q) {
     return !(p == q) ;
 }
 long long N , L ;
 string _S , S ;
 Tq A[200000] ;
 bool Solve() {
     A[0] = str_T("+1") ;
     for ( int i = 1 ; i <= N ; i ++ ) A[i] = A[i-1] * str_T(S[i-1]) ;
     if ( A[N] != str_T("-1") ) return false ;
     for ( int i = 1 , u = 0 ; i < N ; i ++ ) {
         if ( A[i] == str_T("+k") && u == 1 ) return true ;
         if ( A[i] == str_T("+i") ) u = 1 ;
     }
     return false ;
 }
 int main() {
     freopen("C-small-attempt0.in","r",stdin) ; freopen("C-small-attempt0.out","w",stdout) ;
     int Test ; cin >> Test ;
     for ( int i = 1 ; i <= Test ; i ++ ) {
         cin >> N >> L ; if ( L >= 12 ) L = 12 + L % 4 ;
         cin >> _S ; S = "" ;
         for ( int j = 1 ; j <= L ; j ++ ) S = S + _S ;
         N = N * L ;
         if ( Solve() ) cout << "Case #" << i << ": YES\n" ;
         else           cout << "Case #" << i << ": NO\n" ;
     }
 }
