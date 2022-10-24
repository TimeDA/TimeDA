//
 // google codejam - 2017 - round 0 - B
 // John Smith
 //
 
 #include <bits/stdc++.h>
 #include <gmpxx.h>
 
 using namespace std;
 
 bool is_tidy( uint64_t x )
 {
      stringstream ss;
      ss << x;
 
      char c0='0';
      for (auto c : ss.str())
      {
           if (c < c0) return false;
           c0 = c;
      }
 
      return true;
 }
 
 uint64_t make_tidy_slow( uint64_t x )
 {
      uint64_t y = x;
      while (!is_tidy(y))
      {
           y--;
      }
      return y;
 }
 
 uint64_t make_tidy( uint64_t x)
 {
      stringstream ss;
      ss << x;
      if (is_tidy(x)) return x;
 
      char c0='0';
 
      string s = ss.str();
 
      bool flip = false;
      for (auto& c : s)
      {
           if (flip || c < c0)
           {
                flip = true;
                c = '0';
           }
           else
           {
                c0 = c;
           }
      }
 
      stringstream ss2(s);
      ss2 >> x;
      x--;
      return make_tidy(x);
 }
 
 int main(int argc, char ** argv)
 {
      if (0)
      {
           for (auto x=0; x<100; x++)
           {
                cout << x << " " << is_tidy(x) << endl;
           }
           return 0;
      }
 
      uint32_t T;
      cin >> T;
      for (uint32_t j=1; j<=T; j++)
      {
           uint64_t x;
           cin >> x;
           uint64_t y = make_tidy(x);
 
           cout << "Case #" << j << ": ";
           {
                cout << y;
           }
 
           cout << endl;
      }
 
      return 0;
 }
