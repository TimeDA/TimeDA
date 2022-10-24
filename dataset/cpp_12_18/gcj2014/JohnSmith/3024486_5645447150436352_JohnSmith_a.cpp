//
 // 2014 round 3 problem A
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
 
 double max3( uint64_t t0, uint64_t t1, uint64_t t2)
 {
      return max(max(t0,t1),t2);
 }
 
 double evaluate( vector<unsigned int> v, unsigned int a, unsigned int b )
 {
      uint64_t t0, t1, t2;
      unsigned int i;
      t0 = t1 = t2 = 0;
 
 
      for (i=0; i<a; i++) t0 += v.at(i);
      for (i=a; i<=b; i++) t1 += v.at(i);
      for (i=b+1; i<v.size(); i++) t2 += v.at(i);
 
      uint64_t tt = t0+t1+t2;
 
      return (double) max3(t0,t1,t2)/ (double) tt;
 }
 
 double solve( vector<unsigned int> v )
 {
      double xx = 1.0;
      unsigned int a,b;
      for (a=0; a<v.size(); a++)
      {
 	  for (b=0;b<v.size(); b++)
 	  {
 	       double x = evaluate(v,a,b);
 	       if (x<xx) xx=x;
 	  }
      }
      return 1.0 - xx;
 }
 
 int main( int argc, char ** argv )
 {
      unsigned int n;
 
      unsigned int i,j;
 
      cin >> n;
 
      for (i=1; i<=n; i++) 
      {
 	  unsigned int N, p, q, r, s;
 	  cin >> N >> p >> q >> r >> s;
 
 	  vector<unsigned int> v(N);
 	  for (j=0; j<N; j++)
 	  {
 	       v.at(j) = (j*p+q)%r + s;
 	  }
 
 	  if (0)
 	  {
 	       for (j=0; j<N; j++)
 	       {
 		    cout << v.at(j) << " ";
 	       }
 	       cout << endl;
 	  }
 
 	  double e = solve(v);
 	  
 	  cout << "Case #" << i << ": ";
 	  cout << setprecision(12) << e;
 	  cout << endl;
      }
 
      return 0;
 }
 
