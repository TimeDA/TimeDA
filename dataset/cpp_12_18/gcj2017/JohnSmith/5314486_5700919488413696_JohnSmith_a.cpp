//
 // google codejam - 2017 - round 2 - A
 // John Smith
 //
 
 #include <bits/stdc++.h>
 //#include <gmpxx.h>
 
 using namespace std;
 
 uint32_t solve2( vector<uint32_t> G)
 {
      uint32_t n=0;
      uint32_t s=0;
      for (auto x : G)
      {
           if (x%2 == 0) n++;
 
           if (x%2 == 1)
           {
                if (s==0)
                {
                     n++;
                     s=1;
                }
                else
                {
                     s=0;
                }
           }
      }
      return n;
 }
 
 uint32_t solve3( vector<uint32_t> G)
 {
      uint32_t n=0;
      uint32_t n1=0;
      uint32_t n2=0;
 
      for (auto x : G)
      {
           if (x==0) n++;
           if (x==1) n1++;
           if (x==2) n2++;
      }
 
      uint32_t d = min(n1,n2);
      n += d;
      n1 -= d;
      n2 -= d;
 
      d = n1+n2;
      n += (d+2)/3;
      return n;
 }
 
 uint32_t solve4( vector<uint32_t> G)
 {
      return 0;
 }
 
 uint32_t solve( vector<uint32_t> G, uint32_t P )
 {
      switch (P)
      {
      case 2:
           return solve2(G);
      case 3:
           return solve3(G);
      case 4:
           return solve4(G);
      default:
           ;
      }
      cerr << "Error!" << endl;
      exit(1);
 }
 
 int main(int argc, char ** argv)
 {
      cout << setprecision(12);
      uint32_t T;
      cin >> T;
      for (uint32_t j=1; j<=T; j++)
      {
           uint32_t N, P;
 
           cin >> N >> P;
 
           vector<uint32_t> G(N);
           for (auto &x : G) cin >> x;
 
           for (auto &x : G) x %= P;
           sort(begin(G), end(G));
 
           auto a = solve( G, P );
 
           cout << "Case #" << j << ": ";
           cout << a;
 
           cout << endl;
      }
 
      return 0;
 }
