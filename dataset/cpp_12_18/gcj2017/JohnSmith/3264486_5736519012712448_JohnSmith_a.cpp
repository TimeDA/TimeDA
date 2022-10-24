//
 // google codejam - 2017 - round 0 - A
 // John Smith
 //
 
 #include <bits/stdc++.h>
 #include <gmpxx.h>
 
 using namespace std;
 
 int main(int argc, char ** argv)
 {
      uint32_t T;
      cin >> T;
      for (uint32_t j=1; j<=T; j++)
      {
           string s;
           uint32_t k;
           cin >> s >> k;
 
           bool possible = true;
           uint32_t f=0;
           for (auto i=0u; i<s.size(); i++)
           {
                //cerr << s << endl;
                if (s.at(i) == '-')
                {
                     f++;
                     if (i+k > s.size())
                     {
                          possible = false;
                          break;
                     }
                     for (auto j=i; j<i+k; j++)
                     {
                          s.at(j) = s.at(j) == '+' ? '-' : '+';
                     }
                }
           }
           //cerr << s << endl;
 
           cout << "Case #" << j << ": ";
           if (possible)
           {
                cout << f;
           }
           else
           {
                cout << "IMPOSSIBLE";
           }
 
           cout << endl;
      }
      
      return 0;
 }
