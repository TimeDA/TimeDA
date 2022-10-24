//
 // 2014 round 2 problem A
 //
 // John Smith
 //
 // Usually built with g++ 4.4.5 on Linux
 //
 #include <iostream>
 #include <iomanip>
 #include <algorithm>
 #include <functional>
 #include <set>
 #include <queue>
 #include <map>
 
 using namespace std;
 
 typedef pair<unsigned int,unsigned int> pii;
 
 unsigned int solve( unsigned int x, vector<unsigned int> v )
 {
      vector<unsigned int> w(v.size());
      for (auto &x : w) x = 0;
 
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
 
      unsigned int s=0;
      unsigned int i;
      for (i=0; i<v.size(); i++)
      {
 	  if (w.at(i) == 1) continue;
 
 	  w.at(i) = 1;
 
 	  unsigned int f = v.at(i);
 	  unsigned int hi = i;
 	  unsigned int lo = v.size();
 
 	  //cerr << "f = " << f << endl;
 
 	  while (lo - hi> 1)
 	  {
 	       //cerr << setw(4) << hi << " ";
 	       //cerr << setw(4) << lo << " ";
 	       //cerr << endl;
 	       unsigned int m = (hi+lo+1)/2;
 
 	       if (m == v.size()) break;
 
 	       if (v.at(m) + f <= x)
 	       {
 		    lo = m;
 	       }
 	       else
 	       {
 		    hi = m;
 	       }
 	  }
 
 	  unsigned int u;
 	  for (u=hi; u<v.size(); u++)
 	  {
 	       if (v.at(u) + f <= x) {
 		    if (w.at(u) == 0)
 		    {
 			 break;
 		    }
 	       }
 	  }
 
 	  if (u < v.size())
 	  {
 	       w.at(u) = 1;
 	       //cerr << "match with " << v.at(u) << endl;
 	  }
 	  else
 	  {
 	       //cerr << "no match" << endl;
 	  }
 	  w.at(i) = 1;
 	  s++;
      }	  
      return s;
 }
 
 int main( int argc, char ** argv )
 {
      unsigned int n;
 
      unsigned int i;
 
      cin >> n;
 
      for (i=1; i<=n; i++) 
      {
 	  unsigned int N;
 	  unsigned int X;
 
 	  cin >> N >> X;
 
 	  vector<unsigned int> v(N);
 
 	  for (auto &a : v) cin >> a;
 
 	  unsigned int e = solve(X, v);
 	  
 	  cout << "Case #" << i << ": ";
 	  cout << e;
 	  cout << endl;
      }
 
      return 0;
 }
 
