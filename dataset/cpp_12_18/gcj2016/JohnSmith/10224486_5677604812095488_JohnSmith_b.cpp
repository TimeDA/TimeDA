//
 // google codejam - 2016 - round 2 - B
 // John Smith
 //
 #include <bits/stdc++.h>
 #include <gmpxx.h>
 
 using namespace std;
 
 uint32_t bits(uint32_t m )
 {
      return m==0 ? 0 : (1+bits(m&(m-1)));
 }
 
 double score(vector<double> v)
 {
      vector<double> p(v.size()+1);
      for (auto &x : p) x=0.0;
      p.at(0) = 1.0;
 
      for (auto x : v)
      {
           p.at(v.size()) = p.at(v.size()-1)*x;
           for (auto i=v.size()-1; i>0; i--)
           {
                p.at(i) = p.at(i) * (1.0-x) + p.at(i-1) * x;
           }
           p.at(0) = p.at(0) * (1.0-x);
      }
 
      return p.at(v.size()/2);
 }
 
 int main(int argc, char ** argv)
 {
      cout << setprecision(20);
      
      uint32_t T;
      cin >> T;
      for (uint32_t i=1; i<=T; i++)
      {
           uint32_t N, K;
           cin >> N >> K;
           vector<double> p(N);
           for (auto &x : p) cin >> x ;
 
           double pp_best = 0.0;
           for (auto m=0; m<(1<<N); m++)
           {
                if (bits(m) == K)
                {
                     vector<double> w;
                     for (auto i=0u; i<N; i++)
                     {
                          if (m&(1<<i)) {
                               w.push_back(p.at(i));
                          }
                     }
                     double pp = score(w);
                     if (pp > pp_best) pp_best = pp;
                }
           }
           
           cout << "Case #" << i << ": ";
           cout << setw(8) << pp_best;
           cout << endl;
      }
      
      return 0;
 }
