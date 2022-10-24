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
 
 typedef pair<double, double> mpr;
 
 vector<mpr> solve( unsigned int width,
 		   unsigned int length,
 		   vector<unsigned int> vr )
 {
      unsigned int nx0 = 1;
      unsigned int ny0 = 1;
 
 again_again:
      nx0 *= 2;
      ny0 *= 2;
 
      unsigned int nx = nx0;
      unsigned int ny = ny0;
 
      vector<mpr> vp;
 
      //vp.push_back(make_pair(0.0,0.0));
 
      //sort(vr.begin(), vr.end());
 
      vector<double> vr2;
      //for (unsigned int i=vr.size(); i-->0; )
      //{
      //vr2.push_back(vr.at(i));
      //}
 
      for (auto r : vr) vr2.push_back(r);
 
      for (auto r : vr2)
      {
 	  //cout << r << endl;
 
 	  while (true)
 	  {
 	       for (auto ix=0u; ix<=nx; ix++)
 	       {
 		    for (auto iy=0u; iy<=ny; iy++)
 		    {
 			 double x = ix*width*1.0/nx;
 			 double y = iy*length*1.0/nx;
 
 			 for (auto j=0u; j<vp.size(); j++)
 			 {
 			      double rr = vr2.at(j)+r;
 			      rr *= rr;
 			      double xx = x-vp.at(j).first;
 			      double yy = y-vp.at(j).second;
 			      xx *= xx;
 			      yy *= yy;
 
 			      if (xx+yy <= rr)
 			      {
 				   goto try_another;
 			      }
 			 }
 			 vp.push_back(make_pair(x,y));
 			 goto next_one;
 
 		    try_another:
 			 ;
 		    }
 	       }
 	       nx*=2;
 	       ny*=2;
 
 	       if (nx > 32768) 
 		    goto again_again;
 	  }
 
      next_one:
 	  ;
      }
 
      return vp;
 }
 
 void check( vector<mpr> pos, vector<unsigned int> vr )
 {
      //cerr << pos.size() << " " << vr.size() << endl;
 
      for (unsigned int j=0; j<pos.size(); j++)
      {
 	  for (unsigned int k=0; k<pos.size(); k++)
 	  {
 	       if (j != k)
 	       {
 		    double dx = pos.at(j).first  - pos.at(k).first ;
 		    double dy = pos.at(j).second - pos.at(k).second ;
 
 		    double rr = vr.at(j) + vr.at(k);
 		    if (dx*dx+dy*dy < rr*rr)
 		    {
 			 cerr << "Error!!" << endl;
 			 cerr <<"j = " << j << "   k = " << k << endl;
 			 cerr << pos.at(j).first << "," << pos.at(j).second << endl;
 			 cerr << pos.at(k).first << "," << pos.at(k).second << endl;
 			 cerr << "r = " << vr.at(j) << endl;
 			 cerr << "r = " << vr.at(k) << endl;
 			 exit(1);
 		    }
 	       }
 	  }
      }
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
 
 	  unsigned int n,w,l;
 	  cin >> n >> w >> l;
 
 	  vector<unsigned int> vr;
 	  for (auto j=0u; j<n; j++)
 	  {
 	       unsigned int r;
 	       cin >> r;
 	       vr.push_back(r);
 	  }
 
 	  vector<mpr> pos;
 	  pos = solve( w, l, vr );
 
 	  check(pos, vr );
 
 	  cout << "Case #" << i << ": ";
 	  for (auto p : pos )
 	  {
 	       cout << p.first << " " << p.second << " ";
 	  }
 
 	  cout << endl;
      }
 
      cout << setw(4) ;
 
      return 0;
 }
 
