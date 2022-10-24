//
// google codejam 2018 - round 1a - 
// John Smith
//

#include <bits/stdc++.h>

using namespace std;

const uint64_t MMM = 2000000000000000000ull;

struct Cashier {
     uint32_t m;
     uint32_t s;
     uint32_t p;
};

int solve( uint32_t D )
{
     int k=0;
     return k;
}

int main(int argc, char ** argv)
{
     uint32_t T;
     cin >> T;
     for (uint32_t j=1; j<=T; j++)
     {
          uint32_t R, B, C;
          cin >> R >> B >> C;

          vector<Cashier> v(C);
          for (auto &c : v)
          {
               cin >> c.m >> c.s >> c.p;
          }

          uint64_t t_lo = 0;
          uint64_t t_hi = MMM+1;

          while (t_hi - t_lo > 1)
          {
               uint64_t t = (t_hi+t_lo) / 2;

               cerr << "Try with time " << t << endl;
               vector<uint64_t> w;
               for (auto c : v)
               {
                    uint64_t x=0;
                    if (t < c.p)
                    {
                         x = 0;
                    }
                    else
                    {
                         x = (t - c.p) / c.s;
                    }
                    if (x > c.m) x = c.m;
                    w.push_back(x);
               }
               sort(w.begin(), w.end());
               reverse(w.begin(), w.end());

               uint64_t total=0;
               for (auto i=0u; i<w.size() && i<R; i++)
               {
                    total += w.at(i);
                    if (total >= B) break;
               }

               if (total < B)
               {
                    t_lo = t;
               }
               else
               {
                    t_hi = t;
               }
          }

          cout << "Case #" << j << ": ";

          cout << t_hi << endl;
     }

     return 0;
}
