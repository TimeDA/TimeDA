//
 // Round 2 2015  problem C
 // John Smith
 //
 // Usually built with g++ 4.4.5 on Linux
 //
 #include <iostream>
 #include <iomanip>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <map>
 
 #include <cstdlib>
 
 using namespace std;
 
 typedef pair<int,int> pii;
 
 map<string,unsigned int> xxx;
 vector<unsigned int> fff(5000);
 
 vector<unsigned int> get_words(string s )
 {
      vector<unsigned int> ss;
 
      string w;
      for (auto i=0u; i<s.size(); i++)
      {
 	  if (s.at(i) == ' ')
 	  {
 	       if (w.size() > 0) {
 		    unsigned int val;
 		    auto p = xxx.find(w);
 		    if (p == xxx.end())
 		    {
 			 val = xxx.size()+1;
 			 xxx[w] = val;
 		    }
 		    else
 		    {
 			 val = p->second;
 		    }
 		    ss.push_back(val);
 		    fff.at(val) ++;
 		    w.clear();
 	       }
 	  }
 	  else
 	  {
 	       w += s.at(i);
 	  }
      }
 
      if (w.size() > 0)
      {
 	  unsigned int val;
 	  if (xxx.find(w) == xxx.end())
 	  {
 	       val = xxx.size()+1;
 	       xxx[w] = val;
 	  }
 	  else
 	  {
 	       val = xxx[w];
 	  }
 	  ss.push_back(val);
 	  fff.at(val) ++;
      }
 
      sort(ss.begin(), ss.end());
 
      return ss;
 }
 
 unsigned int solve(vector<string> v)
 {
      xxx.clear();
      for (auto &u : fff) u=0;
 
      //cout << "xxx.size = " << xxx.size() << endl;
 
      unsigned int a=1000000;
 
      unsigned int n;
      n = v.size();
 
      vector<unsigned int> se;
      vector<unsigned int> sf;
 
      vector<vector<unsigned int>> vs;
      for (auto i=0u; i<v.size(); i++)
      {
 	  auto sw = get_words(v.at(i));
 	  vs.push_back(sw);
      }
 
      for (auto i=0u; i<v.size(); i++)
      {
 	  vector<unsigned int> v1 = vs.at(i);
 	  vector<unsigned int> v2;
 	  for (auto x : v1) {
 	       if (fff.at(x) != 1) {
 		    v2.push_back(x);
 	       }
 	       vs.at(i) = v2;
 	  }
      }
 
      unsigned int m;
      unsigned int mk = 0;
      for (auto i=2u; i<n; i+=2)
      {
 	  mk |= 1<<i;
      }
 
      for (m=1; m<(1<<n); m+=4)
      {
 	  unsigned int mm = m ^ mk;
 	  se.clear();
 	  sf.clear();
 	  for (auto i=0u; i<n; i++)
 	  {
 	       if (mm&(1<<i))
 	       {
 		    //cerr << "i = " << i << endl;
 		    //cerr << "vs.size() = " << vs.size() << endl;
 		    for (auto x : vs.at(i)) se.push_back(x);
 	       }
 	       else
 	       {
 		    for (auto x : vs.at(i)) sf.push_back(x);
 	       }
 	  }
 
 	  
 	  //cerr << "se.size() = " << se.size() << endl;
 	  //cerr << "sf.size() = " << sf.size() << endl;
 	  sort(se.begin(), se.end());
 	  sort(sf.begin(), sf.end());
 
 	  if(0)
 	  {
 	       vector<unsigned int> sb;
 	       set_intersection( se.begin(), se.end(),
 				 sf.begin(), sf.end(),
 				 inserter(sb, sb.end()) );
 	       a = min(sb.size(), a );
 	  }
 	  else
 	  {
 	       unsigned int k=0;
 	       auto p1 = se.begin();
 	       auto p2 = sf.begin();
 	       while (p1 != se.end() && p2 != sf.end())
 	       {
 		    if (*p1 < *p2) p1++;
 		    else if (*p2 < *p1) p2++;
 		    else
 		    {
 			 k++;
 			 if (k > a) break;
 			 while (p1 != se.end() && *p1 == *p2)
 			 {
 			      p1++;
 			 }
 		    }
 	       }
 	       a = min(k, a );
 	  }
 	  
 	  if (a==xxx.size()) break;
      }
 
      return a;
 }
 
 int main( int argc, char ** argv )
 {
      unsigned int i;
      unsigned int T;
 
      cin >> T;
 
      for (i=1; i<=T; i++) {
 	  unsigned int n;
 
 	  cin >> n;
 
 	  vector<string> vs(n);
 
 	  string s;
 	  getline( cin, s );
 
 	  for (auto &s1 : vs) {
 	       getline( cin, s1 );
 	       //cerr << "s1 = " << s1 << endl;
 	  }
 
 	  auto a = solve(vs);
 
 	  cout << "Case #" << i << ": ";
 	  cout << a << " "  ;
 	  cout << endl;
      }
 
      return 0;
 }
 
