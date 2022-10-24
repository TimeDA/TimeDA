//
 // google codejam - 2017 - round 1a - B
 // John Smith
 //
 
 #include <bits/stdc++.h>
 //#include <gmpxx.h>
 
 using namespace std;
 
 static bool debug=false;
 
 vector<vector<uint32_t>> masks(uint32_t mm, uint32_t m0=1 )
 {
      vector<vector<uint32_t>> a;
      for (auto m=m0; m<=mm; m++)
      {
           if ((m&mm) == m)
           {
                if (mm != m)
                {
                     auto a1 = masks(mm-m, m0+1);
                     for (auto r : a1)
                     {
                          r.push_back(m);
                          a.push_back(r);
                     }
                }
                else
                {
                     vector<uint32_t> u;
                     u.push_back(m);
                     a.push_back(u);
                }
           }
      }
      return a;
 }
 
 bool valid( vector<uint32_t> &r, vector<uint32_t> &pkg, uint32_t servings )
 {
      uint32_t n = r.size();
      for (auto i=0u; i<n; i++)
      {
           if (pkg.at(i) * 10 < servings * r.at(i) * 9) return false;
           if (pkg.at(i) * 10 > servings * r.at(i) * 11) return false;
      }
 
      if (0)
      {
           cerr << "pkg:    ";
           for (auto x : pkg) cerr << setw(4) << x << " "; cerr << endl;
           cerr << "recipe: ";
           for (auto x : r) cerr << setw(4) << x << " "; cerr << endl;
      }
 
      return true;
 }
 bool servings_too_high( vector<uint32_t> &r, vector<uint32_t> &pkg, uint32_t servings )
 {
     uint32_t n = r.size();
     for (auto i=0u; i<n; i++)
     {
          if (pkg.at(i) * 10 < servings * r.at(i) * 9) return true;
     }
     return false;
 }
 bool servings_too_low( vector<uint32_t> &r, vector<uint32_t> &pkg, uint32_t servings )
 {
     uint32_t n = r.size();
     for (auto i=0u; i<n; i++)
     {
          if (pkg.at(i) * 10 > servings * r.at(i) * 11) return true;
     }
     return false;
 }
 bool valid( vector<uint32_t> &r, vector<uint32_t> &pkg )
 {
      if (0)
      {
           cerr << "Package: " ;
           for (auto x : pkg) cerr << setw(4) << x << " ";
           cerr << endl;
           cerr << "Limits:  " ;
           for (auto x : r) cerr << setw(4) << x << " ";
           cerr << endl;
      }
 
      uint32_t servings;
      for (servings = 1; ; servings++)
      {
           if (servings_too_low( r, pkg, servings+100)) servings += 100;
           if (servings_too_low( r, pkg, servings+1000)) servings += 1000;
           if (servings_too_low( r, pkg, servings+10000)) servings += 10000;
 
           if (valid(r,pkg,servings)) return true;
           if (servings_too_high( r, pkg, servings)) return false;
      }
 
      //cerr << "Not valid" << endl;
      return false;
 }
 
 vector<uint32_t> package( uint32_t mask, vector<vector<uint32_t>> &q )
 {
      if (0)
      {
           cerr << "Q:" << endl;
           for (auto &qq : q)
           {
                for (auto &x : qq)
                {
                     cerr << setw(4) << x << " ";
                }
                cerr << endl;
           }
      }
      vector<uint32_t> pkg(q.size());
      for (auto &x : pkg) x=0;
      for (uint32_t i=0; (1u<<i)<=mask; i++)
      {
           if (mask & (1<<i))
           {
                for (auto j=0u; j<q.size(); j++)
                {
                     //cerr << "i=" << i << "  j=" << j << endl;
                     pkg.at(j) += q.at(j).at(i);
                }
           }
      }
 
      if (0) {
           cerr << "mask " << mask << " : ";
           for (auto &x : pkg) cerr << setw(4) << x << " ";
           cerr << endl;
      }
 
      return pkg;
 }
 
 map<vector<vector<uint32_t>>, uint32_t> cache;
 
 uint32_t solve( vector<uint32_t> &r,
                 vector<vector<uint32_t>> &q )
 {
      if (cache.find(q) != cache.end())
      {
           return cache[q];
      }
      uint32_t best_ans = 0;
 
      uint32_t n = r.size();
      uint32_t p = q.at(0).size();
 
      uint64_t k=1;
      for (auto i=0u; i<n; i++) k *= p;
 
      for (uint64_t i=0; i<k; i++)
      {
           vector<uint32_t> u;
           auto ii = i;
           for (auto j=0u; j<n; j++)
           {
                u.push_back(ii%p);
                ii/=p;
           }
 
           vector<uint32_t> pkg(n);
           for (auto j=0u; j<n; j++)
           {
                pkg.at(j) = q.at(j).at(u.at(j));
           }
           if (valid(r,pkg))
           {
                auto qq = q;
                for (auto j=0u; j<n; j++)
                {
                     swap(qq.at(j).at(u.at(j)), qq.at(j).at(p-1));
                     qq.at(j).resize(p-1);
                }
                uint32_t ans = 1+solve(r,qq);
                if (ans > best_ans) best_ans = ans;
                if (best_ans == n) break;
           }
      }
      if (debug) {
           cout << "best_ans " << best_ans << " out of " << n << endl;
      }
      cache[q] = best_ans;
 
      return best_ans;
 }
 
 int main(int argc, char ** argv)
 {
      if (0)
      {
           auto a = masks((1<<8)-1);
           for (auto x : a)
           {
                for (auto y : x) cout << y << " ";
                cout << endl;
           }
           return 0;
      }
 
      uint32_t T;
      cin >> T;
      for (uint32_t j=1; j<=T; j++)
      {
           //debug = j==12;
 
           uint32_t n, p;
           cin >> n >> p;
 
           vector<uint32_t> r(n);
           for (auto &x : r) cin >> x;
 
           vector<vector<uint32_t>> q(n);
           for (auto &v : q)
           {
                v.resize(p);
                for (auto &x : v) cin >> x;
           }
 
           if (0)
           {
                cerr << "R:" << endl;
                for (auto &x : r)
                {
                     cerr << setw(7) << x << " ";
                }
                cerr << endl;
 
                cerr << "Q:" << endl;
                for (auto &qq : q)
                {
                     for (auto &x : qq)
                     {
                          cerr << setw(7) << x << " ";
                     }
                     cerr << endl;
                }
           }
 
           cache.clear();
           uint32_t a = solve( r, q );
 
           cout << "Case #" << j << ": ";
           cout << a;
 
           cout << endl;
      }
 
      return 0;
 }
