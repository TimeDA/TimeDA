//
// google codejam 2018 - round 1a - 
// John Smith
//

#include <bits/stdc++.h>

using namespace std;

const bool debug=false;

bool check_valid( vector<vector<uint32_t>> a, vector<uint32_t> h_cuts,
                  uint32_t v0, uint32_t v1,
                  uint32_t chips_each )
{
     if (debug)
     {
          cerr << "    check_valid(" << v0 << "," << v1 << ")" << endl;
     }
     for (auto i=0u; i<h_cuts.size()-1; i++)
     {
          uint32_t h0 = h_cuts.at(i);
          uint32_t h1 = h_cuts.at(i+1);

          uint32_t chips = 0;
          for (auto h=h0; h<h1; h++)
          {
               for (auto v=v0; v<v1; v++)
               {
                    chips += a.at(h).at(v);
               }
          }
          if (debug) {
               cerr << "      " << h0 << " " << h1 << " " << v0 << " " << v1 << "     " << chips << endl;
          }
          if (chips != chips_each) return false;
     }
     return true;
}

bool solve_v( vector<vector<uint32_t>> &a, vector<uint32_t> h_cuts, vector<uint32_t> v_cuts,
              uint32_t chips_each,
              uint32_t h, uint32_t v )
{
     if (debug) {
          cerr << "  solve_v: v_cuts.size() = " << v_cuts.size() << endl;
          cerr << "   h_cuts = " ; for (auto x : h_cuts) cerr << x << " "; cerr << endl;
          cerr << "   v_cuts = " ; for (auto x : v_cuts) cerr << x << " "; cerr << endl;
     }
     if (v_cuts.size() == v+1)
     {
          uint32_t v0 = v_cuts.at(v_cuts.size()-1);
          uint32_t v1 = a.at(0).size();
          if (check_valid( a, h_cuts, v0, v1, chips_each)) return true;
          return false;
     }

     auto v0 = v_cuts.at(v_cuts.size()-1);
     auto v_cuts1=v_cuts;
     v_cuts1.push_back(0);
     for (auto v1 = v0+1; v1<a.at(0).size(); v1++)
     {
          if (check_valid( a, h_cuts, v0, v1, chips_each))
          {
               v_cuts1.at(v_cuts1.size()-1) = v1;
               if (solve_v( a, h_cuts, v_cuts1, chips_each, h, v )) return true;
          }
     }
     return false;
}

bool solve_h( vector<vector<uint32_t>> &a, vector<uint32_t> &aa, vector<uint32_t> h_cuts,
              uint32_t chips_each,
              uint32_t h, uint32_t v )
{
     if (debug) {
          cerr << "solve_h: h_cuts.size() = " << h_cuts.size() << "   : ";
          for (auto x : h_cuts) cerr << x << " "; cerr << endl;
     }
     if (h_cuts.size()==h+1)
     {
          h_cuts.push_back(a.size());
          vector<uint32_t> v_cuts;
          v_cuts.push_back(0);
          return solve_v( a, h_cuts, v_cuts, chips_each, h, v );
     }

     uint32_t h0 = h_cuts.at(h_cuts.size()-1);
     auto h_cuts1 = h_cuts;
     h_cuts1.push_back(0);
     bool done_once = false;
     for (auto x=h0; x<a.size(); x++)
     {
          uint32_t chips = 0;
          for (auto i=h0; i<x; i++)
          {
               chips += aa.at(i);
          }
          if (chips != (v+1)*chips_each) {
               if (done_once) break;
               continue;
          }
          done_once = true;
          h_cuts1.at(h_cuts1.size()-1) = x;
          if (solve_h(a, aa, h_cuts1, chips_each, h, v )) return true;
     }
     return false;
}

bool solve( vector<vector<uint32_t>> A, uint32_t H, uint32_t V )
{
     vector<vector<uint32_t>> AA;

     uint32_t chips2=0;
     uint32_t customers = (H+1)*(V+1);
     vector<uint32_t> aa;
     for (auto &r : A)
     {
          uint32_t chips=0;
          for (auto x : r)
          {
               chips += x;
          }
          if (chips != 0)
          {
               aa.push_back(chips);
               AA.push_back(r);
          }
          chips2 += chips;
     }

     if (chips2 % customers != 0) return false;
     if (chips2 == 0) return true;

     vector<uint32_t> h_cuts;
     h_cuts.push_back(0);

     uint32_t chips_each = chips2 / customers;

     return solve_h( AA, aa, h_cuts, chips_each, H, V );
}

int main(int argc, char ** argv)
{
     uint32_t T;
     cin >> T;
     for (uint32_t j=1; j<=T; j++)
     {
          uint32_t R,C;
          uint32_t H, V;
          cin >> R >> C;
          cin >> H >> V;
          vector<vector<uint32_t>> v;
          v.resize(R);
          for (auto &r : v)
          {
               string s;
               cin >> s;
               r.resize(C,0);
               for (auto i=0u; i<C; i++)
               {
                    if (s.at(i) == '@') r.at(i) = 1;
               }
          }

          bool r = solve( v, H, V );
          cout << "Case #" << j << ": ";
          if (r)
          {
               cout << "POSSIBLE";
          }
          else
          {
               cout << "IMPOSSIBLE";
          }
          cout << endl;
     }

     return 0;
}
