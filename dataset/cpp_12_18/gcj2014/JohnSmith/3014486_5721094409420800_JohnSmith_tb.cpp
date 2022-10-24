//
 // 2014 round 2 problem B
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
 
 unsigned int count( vector<unsigned int> p )
 {
      unsigned int a=0;
 
      unsigned int n = p.size();
      unsigned int i,j;
      for (i=1; i<n; i++)
      {
 	  j=i;
 	  while (j > 0 && p.at(j) < p.at(j-1))
 	  {
 	       swap(p.at(j), p.at(j-1));
 	       j--;
 	       a++;
 	  }
      }
      return a;
 		    
 }
 
 bool is_up_down( const vector<unsigned int> &w)
 {
      unsigned int i;
      for (i=1; i<w.size(); i++)
      {
 	  if (w[i] < w[i-1]) break;
      }
      for (; i<w.size(); i++)
      {
 	  if (w[i] >w[i-1]) return false;
      }
      return true;
 }
 
 unsigned int solve( vector<unsigned int> v)
 {
      unsigned int n = v.size();
      vector<unsigned int> p(v.size());
      vector<unsigned int> w(v.size());
      vector<unsigned int> w0;
      unsigned int i;
      for (i=0; i<p.size(); i++) 
 	  p.at(i) = i;
 
      unsigned int c0=n*n;
      
      do {
 	  //for (auto i : p) cerr << i << " ";
 	  //cerr << endl;
 
 	  for (i=0; i<n; i++)
 	  {
 	       w[i] = v[p[i]];
 	  }
 
 	  if (is_up_down(w))
 	  {
 	       //for (auto &e : w) cerr<< setw(2) << e << " ";
 	       //cerr << endl;
 	       unsigned int c = count(p);
 	       if (c < c0) {
 		    c0=c;
 		    w0 = w;
 	       }
 	  }
 
      } while (next_permutation(p.begin(), p.end()));
 
      //for (auto &x : v) cerr << setw(3) << x ; cerr << endl;
      //for (auto &x : w0) cerr << setw(3) << x ; cerr << endl;
      //cerr << c0 << endl;
      
 
      return c0;
 }
 
 int main( int argc, char ** argv )
 {
      unsigned int n;
      unsigned int i;
 
      cin >> n;
 
      for (i=1; i<=n; i++) 
      {
 	  unsigned int N;
 
 	  cin >> N;
 	  vector<unsigned int> v(N);
 	  for (auto &x : v) cin >> x ;
 
 	  unsigned int e = solve(v);
 	  
 	  cout << "Case #" << i << ": ";
 	  cout << e;
 	  cout << endl;
      }
 
      return 0;
 }
 
