//
 // google codejam - 2017 - round 1a - A
 // John Smith
 //
 
 #include <bits/stdc++.h>
 //#include <gmpxx.h>
 
 using namespace std;
 
 void solve(vector<string> &v)
 {
      uint32_t r = v.size();
      uint32_t c = v.at(0).size();
      for (auto i=0u; i<r; i++)
      {
           for (auto j=0u; j+1<c; j++)
           {
                if (v.at(i).at(j) != '?' && v.at(i).at(j+1) == '?') v.at(i).at(j+1) = v.at(i).at(j);
           }
      }
      for (auto i=0u; i<r; i++)
      {
           for (auto j=c-1; j>0; j--)
           {
                if (v.at(i).at(j) != '?' && v.at(i).at(j-1) == '?') v.at(i).at(j-1) = v.at(i).at(j);
           }
      }
 
      for (auto i=1u; i<r; i++)
      {
           bool OK=false;
           for (auto j=0u; j<c; j++)
           {
                if (v.at(i).at(j) != '?')
                {
                     OK = true;
                     break;
                }
           }
           if (!OK)
           {
                v.at(i) = v.at(i-1);
           }
      }
 
      for (auto i=r-1; i>0; i--)
      {
           bool OK=false;
           for (auto j=0u; j<c; j++)
           {
                if (v.at(i-1).at(j) != '?')
                {
                     OK = true;
                     break;
                }
           }
           if (!OK)
           {
                v.at(i-1) = v.at(i);
           }
      }
      return;
 }
 int main(int argc, char ** argv)
 {
      uint32_t T;
      cin >> T;
      for (uint32_t j=1; j<=T; j++)
      {
           uint32_t r, c;
           cin >> r >> c;
 
           vector<string> v(r);
           for (auto &r : v) cin >> r;
 
           solve(v);
 
           cout << "Case #" << j << ": ";
           cout << endl;
 
           for (auto s : v) cout << s << endl;
      }
 
      return 0;
 }
