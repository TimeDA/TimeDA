//
 // google codejam - 2017 - round 1c - C
 // John Smith
 //
 
 #include <bits/stdc++.h>
 //#include <gmpxx.h>
 
 using namespace std;
 
 double solve( vector<double> v, uint32_t K, double u )
 {
 
      double hi=1.0;
      double lo=0.0;
 
      while (hi-lo > 1e-12)
      {
           double m = (hi+lo)/2;
 
           double d = 0;
           for (auto x : v)
           {
                if (x < m) d+=m-x;
           }
           if (d < u)
           {
                lo = m;
           }
           else
           {
                hi = m;
           }
           //cerr << setw(10) << hi << " ";
           //cerr << setw(10) << lo << " ";
           //cerr << endl;
      }
 
      double p=1.0;
      double m = (hi+lo)/2;
      for (auto x : v)
      {
           if (x < m)
                p *= m;
           else
                p *= x;
      }
      return p;
 }
 
 int main(int argc, char ** argv)
 {
      cout << setprecision(12);
      uint32_t T;
      cin >> T;
      for (uint32_t j=1; j<=T; j++)
      {
           uint32_t N, K;
 
           cin >> N >> K;
           double u;
 
           cin >> u;
           vector<double> v(N);
           for (auto &x : v) cin >> x;
 
           auto a = solve( v, K, u );
 
           cout << "Case #" << j << ": ";
           cout << a;
 
           cout << endl;
      }
 
      return 0;
 }
