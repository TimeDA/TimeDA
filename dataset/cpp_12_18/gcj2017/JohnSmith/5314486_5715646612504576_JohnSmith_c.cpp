//
 // google codejam - 2017 - round 2 - C
 // John Smith
 //
 
 #include <bits/stdc++.h>
 //#include <gmpxx.h>
 
 using namespace std;
 
 struct Beam {
      bool m1_valid;
      set<uint32_t> m1;
 
      bool m2_valid;
      set<uint32_t> m2;
 
      Beam() : m1_valid(false), m2_valid(false) {};
 };
 
 vector<Beam> vb;
 
 vector<string> V;
 uint32_t R, C;
 
 vector<uint32_t> beams;  // 0 horizontal, 1 vertical
 uint32_t n_targets;
 vector<uint32_t> targets(1000000);
 
 uint32_t cell( uint32_t i, uint32_t j )
 {
      return i*1000 + j;
 }
 set<uint32_t> trace_beam( uint32_t i, uint32_t j, uint32_t dir, bool &is_good )
 {
      cerr << "trace_beam: " << i << "," << j << "  " << dir << endl;
      set<uint32_t> s;
 
      is_good = true;
      while (1)
      {
           uint32_t i1=i; uint32_t j1=j;
           if (dir == 0) i1++;   // down
           if (dir == 1) i1--;   // up
           if (dir == 2) j1++;   // right
           if (dir == 3) j1--;   // left
 
           if (i1 >= R || j1 >= C) break;
           char c = V.at(i1).at(j1);
           if (c == '-' || c == '|') {
                is_good = false;
                break;
           }
           if (c == '#') break;
           if (c == '/') {
                if (dir == 0) dir = 3;
                else if (dir == 1) dir = 2;
                else if (dir == 2) dir = 1;
                else if (dir == 3) dir = 0;
           }
           if (c == '\\') {
                if (dir == 0) dir = 2;
                else if (dir == 1) dir = 3;
                else if (dir == 2) dir = 0;
                else if (dir == 3) dir = 1;
           }
           if (c == '.')
           {
                s.insert(targets.at(cell(i1,j1)));
           }
           i = i1;
           j = j1;
      }
      return s;
 }
 
 void trace_beams( uint32_t i, uint32_t j )
 {
      bool good1a;
      bool good1b;
      bool good2a;
      bool good2b;
      set<uint32_t> s1a = trace_beam( i,j,0,good1a);
      set<uint32_t> s1b = trace_beam( i,j,1,good1b);
      set<uint32_t> s2a = trace_beam( i,j,2,good2a);
      set<uint32_t> s2b = trace_beam( i,j,3,good2b);
 
      Beam b;
 
      if (good1a == true && good1b == true)
      {
           set<uint32_t> s;
           s.insert(begin(s1a), end(s1a));
           s.insert(begin(s1b), end(s1b));
 
           b.m1_valid = true;
           b.m1=s;
      }
      if (good2a == true && good2b == true)
      {
           set<uint32_t> s;
           s.insert(begin(s2a), end(s2a));
           s.insert(begin(s2b), end(s2b));
 
           b.m2_valid = true;
           b.m2=s;
      }
 
      vb.push_back(b);
 }
 
 
 bool searcher( vector<uint32_t> unmatched_targets, vector<uint32_t> unfixed_beams )
 {
      cerr << "Searcher: unmatched_targets ";
      for (auto &x : unmatched_targets) cerr << x << " "; cerr << endl;
      cerr << "          unfixed beams ";
      for (auto &x : unfixed_beams) cerr << x << " "; cerr << endl;
 
      if (unmatched_targets.size() == 0) return true;
      if (unfixed_beams.size() == 0) return false;
 
      uint32_t t = unmatched_targets.at(0);
 
      for (auto b : unfixed_beams)
      {
           auto &s1 = vb.at(b).m1;
           bool tested=false;
           cerr << "Target " << t << "  beam " << b << endl;
           if (s1.find(t) != s1.end())
           {
                beams.at(b) = 0;
                vector<uint32_t> more_targets;
                for (auto tt : unmatched_targets)
                {
                     if (s1.find(tt) == s1.end())
                     {
                          more_targets.push_back(tt);
                     }
                }
                vector<uint32_t> more_beams;
                for (auto bb : unfixed_beams)
                {
                     if (bb != b) more_beams.push_back(bb);
                }
                if (searcher( more_targets, more_beams )) return true;
                tested = true;
           }
 
           auto &s2 = vb.at(b).m2;
           if (tested || s2.find(t) != s2.end())
           {
                beams.at(b) = 1;
                vector<uint32_t> more_targets;
                for (auto tt : unmatched_targets)
                {
                     if (s2.find(tt) == s2.end())
                     {
                          more_targets.push_back(tt);
                     }
                }
                vector<uint32_t> more_beams;
                for (auto bb : unfixed_beams)
                {
                     if (bb != b) more_beams.push_back(bb);
                }
                if (searcher( more_targets, more_beams )) return true;
                tested = true;
           }
           if (tested) return false;
      }
      return false;
 }
 
 bool solver()
 {
      if (1)
      {
           cerr << "n_targets = " << n_targets << endl;
 
           for (auto i=0u; i<vb.size(); i++)
           {
                cerr << "Beam " << i << ":" << endl;
                auto &b = vb.at(i);
                if (b.m1_valid)
                {
                     cerr << "valid" << " : ";
                     for (auto x : b.m1) cerr << setw(3) << x << " ";
                     cerr << endl;
                }
                else
                {
                     cerr << "not valid";
                     cerr << endl;
                }
 
                if (b.m2_valid)
                {
                     cerr << "valid" << " : ";
                     for (auto x : b.m2) cerr << setw(3) << x << " ";
                     cerr << endl;
                }
                else
                {
                     cerr << "not valid";
                     cerr << endl;
                }
           }
      }
 
      beams.resize(vb.size());
 
      for (auto i=0u; i<vb.size(); i++)
      {
           auto &b = vb.at(i);
           if (b.m1_valid == false && b.m2_valid == false) return false;
           if (b.m1_valid == true  && b.m2_valid == false) beams.at(i) = 0;
           if (b.m1_valid == false && b.m2_valid == true) beams.at(i) = 1;
           if (b.m1_valid == true  && b.m2_valid == true) beams.at(i) = 2;
      }
 
      vector<uint32_t> unmatched_targets;
      vector<uint32_t> unfixed_beams;
 
      vector<uint32_t> target_mask(n_targets);
      for (auto &x : target_mask) x=0;
 
      for (auto i=0u; i<vb.size(); i++)
      {
           if (beams.at(i) == 2)
           {
                unfixed_beams.push_back(i);
           }
           else if (beams.at(i) == 0)
           {
                for (auto x : vb.at(i).m1)
                {
                     target_mask.at(x) = 1;
                }
           }
           else if (beams.at(i) == 1)
           {
                for (auto x : vb.at(i).m2)
                {
                     target_mask.at(x) = 1;
                }
           }
      }
 
      for (uint32_t t=0u; t<n_targets; t++)
      {
           if (target_mask.at(t) == 0) unmatched_targets.push_back(t);
      }
 
      auto b = searcher( unmatched_targets, unfixed_beams);
      cerr << "Searcher returned " << (b?"TRUE":"FALSE") << endl;
      return b;
 }
 
 void solve()
 {
      beams.resize(0);
      vb.resize(0);
      n_targets = 0;
 
      for (auto i=0u; i<R; i++)
      {
           for (auto j=0u; j<C; j++)
           {
                if (V.at(i).at(j) == '.')
                {
                     targets.at(cell(i,j))=n_targets++;
                }
           }
      }
 
      for (auto i=0u; i<R; i++)
      {
           for (auto j=0u; j<C; j++)
           {
                if (V.at(i).at(j) == '|' ||
                    V.at(i).at(j) == '-')
                {
                     trace_beams(i,j);
                }
           }
      }
 
      auto b = solver();
 
      if (b) {
           cout << "POSSIBLE" << endl;
 
           uint32_t nb=0;
           for (auto i=0u; i<R; i++)
           {
                for (auto j=0u; j<C; j++)
                {
                     if (V.at(i).at(j) == '|' ||
                         V.at(i).at(j) == '-')
                     {
                          if (beams.at(nb) == 0)
                          {
                               cout << "|";
                          }
                          else
                          {
                               cout << "-";
                          }
                          nb++;
                     }
                     else
                     {
                          cout << V.at(i).at(j);
                     }
                }
                cout << endl;
           }
      }
      else
      {
           cout << "IMPOSSIBLE" << endl;
      }
      return;
 }
 
 int main(int argc, char ** argv)
 {
      cout << setprecision(12);
      uint32_t T;
      cin >> T;
      for (uint32_t j=1; j<=T; j++)
      {
 
           cin >> R >> C;
 
           V.resize(0);
           V.resize(R);
           for (auto &s : V) cin >> s;
 
           cout << "Case #" << j << ": ";
           cerr << endl;
           solve();
 
 
      }
 
      return 0;
 }
