//
 // google codejam - 2016 - round 2 - A
 // John Smith
 //
 
 #include <bits/stdc++.h>
 #include <gmpxx.h>
 
 using namespace std;
 
 bool solution(string s)
 {
      while (s.size() != 1)
      {
           string t;
           for (auto i=0u; i<s.size(); i+=2)
           {
                char c1 = s.at(i);
                char c2 = s.at(i+1);
                char c;
                if (c1 == c2) return false;
                if (c1 == 'R' && c2 == 'S') c = c1;
                else if (c1 == 'S' && c2 == 'R') c = c2;
                else if (c1 == 'R' && c2 == 'P') c = c2;
                else if (c1 == 'P' && c2 == 'R') c = c1;
                else if (c1 == 'S' && c2 == 'P') c = c1;
                else if (c1 == 'P' && c2 == 'S') c = c2;
                else
                {
                     cerr << "Error!";
                     exit(1);
                }
                t += c;
           }
           s = t;
      }
      return true;
 }
                
 int main(int argc, char ** argv)
 {
      uint32_t T;
      cin >> T;
      for (uint32_t j=1; j<=T; j++)
      {
           uint32_t N;
           uint32_t R, P, S;
           cin >> N;
           cin >> R >> P >> S;
 
           string s;
           for (auto i=0u; i<R; i++) s += 'R';
           for (auto i=0u; i<P; i++) s += 'P';
           for (auto i=0u; i<S; i++) s += 'S';
 
           sort(begin(s), end(s));
           bool good = false;
           do {
                if (solution(s))
                {
                     good = true;
                     break;
                }
           } while (next_permutation(s.begin(), s.end()));
 
           cout << "Case #" << j << ": ";
           if (good)
           {
                cout << s;
           }
           else
           {
                cout << "IMPOSSIBLE";
           }
                     
           cout << endl;
      }
      
      return 0;
 }
