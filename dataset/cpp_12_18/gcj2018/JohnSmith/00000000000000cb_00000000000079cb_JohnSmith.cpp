//
// google codejam 2018 - qualification - trouble sort
// John Smith
//

#include <bits/stdc++.h>

using namespace std;

void trouble_sort( vector<uint32_t> &v )
{
     bool done = false;
     while (!done)
     {
          done = true;
          for (auto i=0u; i<v.size()-2; i++)
          {
               if (v.at(i) > v.at(i+2)) {
                    done = false;
                    swap(v.at(i), v.at(i+2));
               }
          }
     }
}

void fast_trouble_sort( vector<uint32_t> &v )
{
     vector<uint32_t> w0;
     vector<uint32_t> w1;

     for (auto i=0u; i<v.size(); i++)
     {
          if (i%2 == 0)
               w0.push_back(v.at(i));
          else
               w1.push_back(v.at(i));
     }

     sort(w0.begin(), w0.end());
     sort(w1.begin(), w1.end());

     for (auto i=0u; i<v.size(); i++)
     {
          if (i%2 == 0)
               v.at(i) = w0.at(i/2);
          else
               v.at(i) = w1.at(i/2);
     }
}

int main(int argc, char ** argv)
{
     ios_base::sync_with_stdio(false);

     uint32_t T;
     cin >> T;
     for (uint32_t j=1; j<=T; j++)
     {
          uint32_t N;
          cin >> N;
          vector<uint32_t> v(N);
          for (auto &x : v) cin >> x;

          fast_trouble_sort(v);

          cout << "Case #" << j << ": ";

          uint32_t r = N;
          for (auto i=0u; i<v.size()-1; i++)
          {
               if (v.at(i) > v.at(i+1))
               {
                    r = i;
                    break;
               }
          }

          if (r == N)
          {
               cout << "OK";
          }
          else
          {
               cout << r;
          }
          cout << endl;
     }

     return 0;
}
