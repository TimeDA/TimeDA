//
 // google codejam - 2016 - round 2 - D
 // John Smith
 //
 #include <bits/stdc++.h>
 #include <gmpxx.h>
 
 using namespace std;
 
 typedef pair<uint32_t,uint32_t> pii;
 
 
 uint32_t min_combiner( vector<pii> v )
 {
      if (v.size() == 0) return 0;
      
      pii p = v.at(0);
      if (p.first == p.second)
      {
           vector<pii> w(v.begin()+1,v.end());
           return p.first*p.second + min_combiner(w);
      }
 
      uint32_t best = 1000000000;
      for (auto i=1u; i<v.size(); i++)
      {
           vector<pii> w(v.begin()+1,v.end());
           w.at(i-1) = make_pair(p.first+v.at(i).first, p.second+v.at(i).second);
           uint32_t b = min_combiner(w);
           if (b < best) best = b;
      }
      return best;
 }
      
 
 bool clash( string s1, string s2 )
 {
      for (auto i=0u; i<s1.size(); i++)
      {
           if (s1.at(i) == '1' && s2.at(i) == '1')
           {
                return true;
           }
      }
      return false;
 }
 string merge( string s1, string s2 )
 {
      for (auto i=0u; i<s1.size(); i++)
      {
           if (s1.at(i) == '0' && s2.at(i) == '1')
           {
                s1.at(i) = '1';
           }
      }
      return s1;
 }
 
 uint32_t count( vector<string> v )
 {
      uint32_t n = v.size();
 
      vector<uint32_t> e(n);
      vector<uint32_t> m(n);
      for (auto &x : e) x=0;
      for (auto &x : m) x=0;
 
      vector<pii> k;
      while (true)
      {
           uint32_t idx;
           for (auto i=0u; i<n; i++)
           {
                if (e.at(i) == 0) {
                     idx = i;
                     goto got_idx;
                }
           }
           break;
           
      got_idx:
           e.at(idx) = 1;
           string s = v.at(idx);
           bool looping = true;
           uint32_t clique_e = 1;
           uint32_t clique_m = 0;
           while (looping)
           {
                looping = false;
                for (auto j=0u; j<n; j++)
                {
                     if (e.at(j) == 0)
                     {
                          if (clash(s,v.at(j)))
                          {
                               s = merge(s,v.at(j));
                               e.at(j) = 1;
                               looping = true;
                               clique_e ++;
                          }
                     }
                }
           }
           for (auto c : s) if (c == '1') clique_m++;
 
           k.push_back(make_pair(clique_e,clique_m));
      }
 
      {
           uint32_t t=n;
           for (auto p : k )
                t -= p.second;
 
           while (t-- > 0)
           {
                k.push_back(make_pair(0,1));
           }
      }
 
      if (0) {
           cerr << "Cliques" << endl;
           for (auto p : k)
           {
                cerr << setw(2) << p.first << " " << p.second << endl;
           }
      }
 
      uint32_t a = min_combiner(k);
      
      return a;
 }
 
 int main(int argc, char ** argv)
 {
 
      uint32_t T;
      cin >> T;
      for (uint32_t k=1; k<=T; k++)
      {
           uint32_t N;
           cin >> N;
 
           uint32_t t = 0;
           vector<string> v(N);
           for (auto &x : v) {
                cin >> x;
                for (auto c : x) if (c == '1') t++;
           }
           
           uint32_t a = count(v);
           
           cout << "Case #" << k << ": ";
           cout << a-t;
           cout << endl;
      }
      
      return 0;
 }
