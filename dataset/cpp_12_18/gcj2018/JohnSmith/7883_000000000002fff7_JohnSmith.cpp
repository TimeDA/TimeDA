//
// google codejam 2018 - round 1a - 
// John Smith
//

#include <bits/stdc++.h>

const bool debug = false;

using namespace std;

int solve( uint32_t D )
{
     int k=0;
     return k;
}

struct Cookie {
     double lo;
     double hi;
     Cookie( double lo=0.0, double hi=0.0) :lo(lo), hi(hi) {}
} ;

int main(int argc, char ** argv)
{
     uint32_t T;
     cout << setprecision(10);
     cout << fixed;
     cin >> T;
     for (uint32_t j=1; j<=T; j++)
     {
          uint32_t N, P;
          cin >> N >> P;

          vector<Cookie> v(N);
          double offset=0.0;
          for (uint32_t i=0; i<N; i++)
          {
               uint32_t x, y;
               cin >> x >> y;
               if (x > y) swap(x,y);

               P -= 2*x;
               P -= 2*y;

               offset += 2*x;
               offset += 2*y;
               double xx=x;
               double yy=y;
               v.at(i).lo = 2.0*x;
               v.at(i).hi = 2.0*sqrt(xx*xx+yy*yy);
          }

          vector<Cookie> R;
          R.push_back(Cookie(0.0,0.0));
          for (auto i=0u; i<N; i++)
          {
               if (debug) {
                    for (auto x : R) cerr << x.lo << " to " << x.hi << endl;
                    cerr << endl;
               }
               vector<Cookie> RR(R);
               for (auto &r : R)
               {
                    RR.push_back( Cookie( r.lo+v.at(i).lo, r.hi+v.at(i).hi ) );
               }

               vector<pair<double,int>> ss;
               for (auto r : RR)
               {
                    ss.push_back(make_pair(r.lo,-1));
                    ss.push_back(make_pair(r.hi,1));
               }
               sort(ss.begin(), ss.end());

               if (debug) {
                    for (auto s : ss) cerr << s.first << " " << s.second << endl;
                    cerr << endl;
               }

               R.resize(0);
               int32_t c=0;
               double my_lo=0.0;
               double my_hi=0.0;
               for (auto p : ss)
               {
                    if (c==0 && p.second == -1) {
                         my_lo = p.first;
                    }
                    if (c==-1 && p.second == 1) {
                         my_hi = p.first;
                         if (my_hi > P) my_hi = P;
                         if (my_lo <= P)
                              R.push_back(Cookie(my_lo,my_hi));
                    }
                    c += p.second;
               }
          }

          if (debug) {
               for (auto x : R) cerr << x.lo << " to " << x.hi << endl;
               cerr << endl;
          }

          cout << "Case #" << j << ": ";

          cout << setw(24) << offset + R.at(R.size()-1).hi;
          cout << endl;
     }

     return 0;
}
