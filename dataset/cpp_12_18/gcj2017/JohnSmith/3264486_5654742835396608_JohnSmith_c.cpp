//
 // google codejam - 2017 - round 0 - C
 // John Smith
 //
 
 #include <bits/stdc++.h>
 #include <gmpxx.h>
 
 using namespace std;
 
 pair<uint64_t,uint64_t> solve1( uint64_t n, uint64_t k )
 {
      uint64_t d = n;
      uint64_t m0 = 1;
      uint64_t m1 = 0;
 
      while (k > m0+m1)
      {
           if (0) {
                cerr << "k = " << setw(4) << k << "  ";
                cerr << "d " << setw(4) << d << ", ";
                cerr << "m0 " << setw(4) << m0 << ", ";
                cerr << "m1 " << setw(4) << m1 << endl;
           }
           uint64_t dd = (d-1) - (d-1)/2;
           uint64_t mm0, mm1;
           if (d%2 == 1)
           {
                mm0 = 2*m0 + m1;
                mm1 = m1;
           }
           else
           {
                mm0 = m0;
                mm1 = m0+2*m1;
           }
           k -= m0;
           k -= m1;
           m0 = mm0;
           m1 = mm1;
           d = dd;
      }
      if (0) {
           cerr << "k = " << setw(4) << k << "  ";
           cerr << "d " << setw(4) << d << ", ";
           cerr << "m0 " << setw(4) << m0 << ", ";
           cerr << "m1 " << setw(4) << m1 << endl;
      }
      if (k <= m0) return make_pair((d-1)/2, (d-1)-(d-1)/2);
      return make_pair((d-2)/2, (d-2)-(d-2)/2);
 }
 
 pair<uint64_t,uint64_t> solve0( uint64_t n, uint64_t k )
 {
      vector<uint32_t> r(n+2);
      for (auto &x : r) x=0;
      r.at(0) = 1;
      r.at(n+1) = 1;
 
      pair<uint64_t,uint64_t> p0;
      uint64_t j0 = 0;
      while (k--)
      {
           p0 = make_pair(0,0);
           j0 = 0;
           for (uint64_t j=1; j<=n; j++)
           {
                uint64_t d0;
                uint64_t d1;
                for (d0=0; r.at(j-d0)==0; d0++)
                     ;
                for (d1=0; r.at(j+d1)==0; d1++)
                     ;
 
                //cerr << j << " " << d0 << " " << d1 << endl;
                auto p = make_pair(min(d0,d1), max(d0,d1));
                if (p > p0)
                {
                     j0 = j;
                     p0 = p;
                }
           }
           r.at(j0) = 1;
           //for (auto  t : r) cerr << t; cerr << endl;
      }
      return make_pair(p0.first-1, p0.second-1);
 }
 
 int main(int argc, char ** argv)
 {
      uint32_t T;
      cin >> T;
      for (uint32_t j=1; j<=T; j++)
      {
           uint64_t n,k;
           cin >> n >> k;
 
           auto p1 = solve1(n,k);
 
           cout << "Case #" << j << ": ";
           cout << p1.second << " " << p1.first;
 
           cout << endl;
      }
 
      return 0;
 }
