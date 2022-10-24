//
 // Round-2 2013  problem C
 //
 // Usually built with g++ 4.4.5 on Linux
 //
 #include <iostream>
 #include <iomanip>
 #include <algorithm>
 #include <vector>
 #include <set>
 #include <gmpxx.h>
 
 #include <cstdlib>
 #include <math.h>
 
 using namespace std;
 typedef mpz_class bigint;
 
 int longest_increasing( const vector<int> &x )
 {
      unsigned int xs = x.size();
      if (xs == 0) return 0;
      if (xs == 1) return 1;
      if (xs == 2)
      {
 	  if (x.at(0) < x.at(1)) return 2;
 	  return 1;
      }
 
      unsigned int i,j;
      int k = x.at(xs-1);
      
      vector<int> y;
      int rr = 0;
      for (i=0;i<xs-1; i++)
      {
 	  if (x.at(i) <= k) 
 	  {
 	       y.push_back(x.at(i));
 
 	       for (j=i+1; j<xs-1; j++)
 	       {
 		    if (x.at(j) < k && x.at(i) <x.at(j))
 		    {
 			 break;
 		    }
 	       }
 	       if (j == xs-1)
 	       {
 		    int r = longest_increasing(y);
 		    rr = max(rr, r);
 	       }
 	  }
      }
 
      if (0)
      {
 	  cerr << "longest_increasing: ";
 	  for (auto u : x) cerr << u << " ";
 	  cerr << " is ";
 
 	  cerr << rr+1 << endl;
      }
 
      return rr+1;
 }
 
 int longest_decreasing( const vector<int> &x, unsigned int idx )
 {
      if (x.size() == 0) return 0;
      vector<int> y;
      for (auto i=x.size(); i>idx; i--)
      {
 	  y.push_back(x.at(i-1));
      }
      return longest_increasing(y);
 }
 
 vector<int> search( const vector<int> &x, const set<int> &s, const vector<int> &a, const vector<int> &b )
 {
      if (0)
      if (x.size() < 8) 
      {
 	  for (auto u : x) cerr << setw(3) << u ;
 	  cerr << endl;
      }
 
      if (s.size() == 0) 
      {
 	  vector<int> y;
 
 	  bool good = true;
 	  for (auto i=0u; i<x.size(); i++)
 	  {
 	       y.push_back(x.at(x.size()-1-i));
 
 	       if (0)
 	       {
 		    cerr << "longest_increasing ";
 		    for (auto u : y) cerr << u << " ";
 		    cerr << " is " << longest_increasing(y) << endl;
 	       }
 
 	       if (longest_increasing(y) != b.at(x.size()-1-i)) 
 	       {
 		    good = false;
 		    break;
 	       }
 	  }
 	       
 	  if (good) return x;
      }
 
      if (0)
      {
 	  cerr << "search : ";
 	  for (auto u : x) cerr << u << " ";
 	  cerr << endl;
      }
      
      int r = 0;
      for (auto i : s)
      {
 	  r++;
 	  if (b.at(x.size()) > r) continue;
 	  vector<int> y = x;
 	  y.push_back(i);
 
 	  if (longest_increasing(y) == a.at(x.size()))
 	  {
 	       bool good = true;
 	       int d=0;
 	       if (i!=0 && *s.begin() == 0) d=1;
 	       for (auto j=0u; j<y.size(); j++)
 	       {
 		    if (longest_decreasing(y,j)+d > b.at(j))
 		    {
 			 good = false;
 			 break;
 		    }
 	       }
 	       
 	       if (good)
 	       {
 		    set<int> ss = s;
 		    ss.erase(i);
 		    vector<int> w = search( y, ss, a, b );
 		    if (w.size()) return w;
 	       }
 	  }
      }
 	  
      vector<int> w;
      return w;
 }
 
 vector<int> solve( vector<int> a, vector<int> b )
 {
      set<int> s;
      for (auto i=0u; i<a.size(); i++)
      {
 	  s.insert(i);
      }
 
      vector<int> x;
      vector<int> w = search( x, s, a, b );
      return w;
 }
 
 int main( int argc, char ** argv )
 {
      unsigned int nnn;
      unsigned int iii;
      string w;
      string s1,s2,s3,s4;
      char s[200];
 
      cin >> nnn;
 
      cin.getline( s, 200 );
 
      for (iii=1u; iii<=nnn; iii++) {
 	  int n;
 	  cin >> n;
 	  vector<int> a(n);
 	  vector<int> b(n);
 
 	  for (auto& x : a) cin >> x;
 	  for (auto& x : b) cin >> x;
 
 	  auto w = solve( a, b);
 
 	  cout << "Case #" << iii << ": ";
 
 	  for (auto x : w) cout << x+1 << " ";
 
 	  cout << endl;
      }
 
      return 0;
 }
 
