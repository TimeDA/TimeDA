//
 // google codejam - 2017 - round 1c - A
 // John Smith
 //
 
 #include <bits/stdc++.h>
 //#include <gmpxx.h>
 
 using namespace std;
 
 struct Pancake {
      uint64_t r;
      uint64_t h;
 };
 
 bool operator<(Pancake &p1, Pancake &p2)
 {
      return p1.r*p1.h > p2.r*p2.h;
 }
 
 uint64_t solve( vector<Pancake> v, uint32_t K )
 {
      uint32_t N=v.size();
      sort(v.begin(), v.end());
 
      uint64_t best = 0;
 
      for (auto i=0u; i<N; i++)
      {
           uint32_t jj=1;
           auto area = 2*v.at(i).r * v.at(i).h;
           area += v.at(i).r*v.at(i).r;
 
           for (auto j=0u; j<N&&jj<K; j++)
           {
                if (j != i && v.at(j).r <= v.at(i).r)
                {
                     area += 2 * v.at(j).r * v.at(j).h;
                     jj++;
                }
           }
           if (jj == K)
           {
                if (area > best)
                {
                     best = area;
                }
           }
      }
 
      return best;
 }
 
 int main(int argc, char ** argv)
 {
      cout << setprecision(14);
 
      uint32_t T;
      cin >> T;
      for (uint32_t j=1; j<=T; j++)
      {
           uint32_t N, K;
 
           cin >> N >> K;
 
           vector<Pancake> v(N);
           for (auto &p : v)
           {
                cin >> p.r >> p.h ;
           }
 
           double a = solve( v, K );
 
           a *= M_PI;
 
           cout << "Case #" << j << ": ";
           cout << a;
 
           cout << endl;
      }
 
      return 0;
 }
