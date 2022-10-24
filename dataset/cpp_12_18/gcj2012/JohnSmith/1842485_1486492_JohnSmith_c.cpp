//
 // Google codejam - 2012 - Round 2 - question  - John.Smith
 //
 #include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <string>
 #include <vector>
 #include <iostream>
 #include <iomanip>
 #include <map>
 #include <set>
 #include <algorithm>
 #include <queue>
 #include <sstream>
 #include <gmpxx.h>
 using namespace std;
 typedef unsigned long long big_int;
 typedef pair<big_int,big_int> pii;
 #define SZ(x) (int)(x.size())
 const int inf = 1000000009;
 const double pi = atan(1.0)*4.0;
 const double eps = 1e-8;
 big_int gcd(big_int x, big_int y) { return y ? gcd(y, x%y) : x; }
 int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }
 
 mpz_class total = 0;
 
 vector<unsigned int> genv( vector<unsigned int> hh )
 {
      vector<unsigned int> vh;
 
      for (auto i=0u; i<hh.size()-1; i++)
      {
 	  unsigned long long dx0 = 0;
 	  unsigned long long dy0 = 0;
 	  unsigned int i0=0;
 	  for (auto j=i+1; j<hh.size(); j++)
 	  {
 	       unsigned int dx = j-i;
 	       unsigned int dy = hh.at(j)-hh.at(i);
 
 	       if (j == i+1)
 	       {
 		    dx0 = dx;
 		    dy0 = dy;
 		    i0 = i+1;
 	       }
 	       else if (dy0*dx < dx0*dy)
 	       {
 		    dx0 = dx;
 		    dy0 = dy;
 		    i0 = j;
 	       }
 	  }
 	  vh.push_back(i0+1);		    
      }
      if (0)
      {
 	  for (auto h : hh) cerr << h << " ";
 	  cerr << "   gives ";
 	  for (auto k : vh) cerr << k << " ";
 	  cerr << endl;
      }
 
      return vh;
 }
 
 vector<unsigned int> solve( vector<unsigned int> vh, unsigned int m )
 {
      unsigned int n = vh.size()+1;
 
      vector<unsigned int> hh(n);
 
      for (unsigned int i=0; i<n; i++)
      {
 	  if (m==0)
 	  {
 	       hh.at(i) = 10000 + 100*i;
 	  }
 	  else if (m==1)
 	  {
 	       hh.at(i) = 10000 + i*i;
 	  }
 	  else
 	  {
 	       hh.at(i) = 10000 - (n-i)*(n-i);
 	  }
      }
 
      do
      {
 	  vector<unsigned int> vh2 = genv(hh);
 	  if (vh2 == vh) return hh;
      } while (next_permutation(hh.begin(), hh.end()));
 
 
      vector<unsigned int> vnull;
      return vnull;
 }
 
 int main( int argc, char ** argv )
 {
      unsigned int t;
      unsigned int i;
 
      string w;
      char s[200];
 
      cout << fixed;
      cout << setprecision(9);
 
      cin >> t;
      cin.getline( s, 200 );
 
      for (i=1; i<=t; i++) {
 
 	  unsigned int n;
 	  cin >> n ;
 
 	  vector<unsigned int> vh;
 	  for (auto j=0u; j<n-1; j++)
 	  {
 	       unsigned int h;
 	       cin >> h;
 	       vh.push_back(h);
 	  }
 
 	  vector<unsigned int> vt;
 
 	  vt = solve(vh,0);
 	  if (vt.size() == 0)
 	  {
 	       cerr << "Try again"<< endl;
 	       vt = solve(vh,1);
 	  }
 	  if (vt.size() == 0)
 	  {
 	       cerr << "Try again"<< endl;
 	       vt = solve(vh,2);
 	  }
 
 	  cout << "Case #" << i << ": ";
 
 
 	  if (vt.size())
 	  {
 	       for (auto x : vt) cout << x << " ";
 	  }
 	  else
 	  {
 	       cout << "Impossible";
 	  }
 	  cout << endl;
      }
 
      cout << setw(4) ;
 
      return 0;
 }
 
