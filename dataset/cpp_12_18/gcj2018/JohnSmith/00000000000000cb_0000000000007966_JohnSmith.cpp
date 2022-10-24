//
// google codejam 2018 - qualification - saving the universe again
// John Smith
//

#include <bits/stdc++.h>

using namespace std;

int solve( string s, uint32_t D )
{
     uint32_t ns=0;
     for (auto c : s)
     {
          if (c == 'S') ns++;
     }
     if (ns > D) return -1;

     vector<uint32_t> v;
     v.push_back(0);
     for (auto c : s)
     {
          if (c == 'C')
          {
               v.push_back(0);
          }
          else
          {
               v.at(v.size()-1)++;
          }
     }

     uint32_t score=0;
     for (uint32_t i=0; i<v.size(); i++)
     {
          score += v.at(i) * (1u<<i);
     }

     uint32_t k=0;
     while (score > D)
     {
          for (uint32_t i=v.size(); i-->0;)
          {
               if (v.at(i))
               {
                    score -= (1u<<i);
                    v.at(i)--;
                    v.at(i-1)++;
                    score += 1u<<(i-1);
                    k++;
                    break;
               }
          }
     }

     return k;
}

int main(int argc, char ** argv)
{
     uint32_t T;
     cin >> T;
     for (uint32_t j=1; j<=T; j++)
     {
          uint32_t D;
          cin >> D;
          string s;
          cin >> s;

          cout << "Case #" << j << ": ";

          int r = solve( s, D);
          if (r < 0)
          {
               cout << "IMPOSSIBLE";
          }
          else
          {
               cout << r;
          }
          cout << endl;
     }

     return 0;
}
