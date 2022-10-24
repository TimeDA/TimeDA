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
 
 struct vine
 {
      unsigned int d;
      unsigned int l;
      bool reached;
      unsigned int h;
      vine(unsigned int d, unsigned int l) : d(d), l(l)
 	  {
 	       reached = false;	       
 	       h = 0;
 	  }
 };
 
 bool solve( vector<vine> vs, unsigned int d )
 {
      vs.at(0).reached = true;
      vs.at(0).h = vs.at(0).d;
 
      for (auto i=0u; i<vs.size(); i++)
      {
 	  //cout << "Vine " << i ;
 	  //cout << " Reached " << (vs.at(i).reached ? "TRUE" : "FALSE" )<< endl;
 	  if (!vs.at(i).reached)
 	  {
 	       continue;
 	  }
 
 	  
 	  if (vs.at(i).d + vs.at(i).h >= d) {	       
 	       return true;
 	  }
 
 	  for (auto j=i+1; (j<vs.size() ) && (vs.at(j).d-vs.at(i).d) <= vs.at(i).h; j++)
 	  {
 	       //cout << "Can reach vine " << j << " from " << i << endl;
 	       unsigned int dd = vs.at(j).d-vs.at(i).d;
 	       if (!vs.at(j).reached)
 	       {
 		    vs.at(j).reached = true;
 		    if (dd <= vs.at(j).l)
 		    {
 			 vs.at(j).h = dd;
 		    }
 		    else
 		    {
 			 vs.at(j).h = vs.at(j).l;
 		    }
 	       }
 	  }
      }
      return false;
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
 
 	  vector<vine> vs;
 	  for (auto j=0u; j<n; j++)
 	  {
 	       unsigned int d;
 	       unsigned int l;
 	       cin >> d >> l;
 	       vine v(d,l);
 	       vs.push_back(v);
 	  }
 	  unsigned int D;
 	  cin >> D;
 
 	  bool b = solve( vs, D );
 	  cout << "Case #" << i << ": ";
 	  cout << (b ? "YES" : "NO") << endl;
 
      }
 
      cout << setw(4) ;
 
      return 0;
 }
 
