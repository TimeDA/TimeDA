//
 // 2014 round 2 problem C
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
 
 struct building {
      unsigned int x0;
      unsigned int y0;
      unsigned int x1;
      unsigned int y1;
 };
 
 unsigned int dist( building b0, building b1 )
 {
      unsigned int dx = 0;
      unsigned int dy = 0;
 
      if (b0.x1 < b1.x0) dx = b1.x0 - b0.x1 - 1;
      if (b1.x1 < b0.x0) dx = b0.x0 - b1.x1 - 1;
 
      if (b0.y1 < b1.y0) dy = b1.y0 - b0.y1 - 1;
      if (b1.y1 < b0.y0) dy = b0.y0 - b1.y1 - 1;
 
      return max(dx,dy);
 }
 
 unsigned int solve( unsigned int W, unsigned int H, vector<building> v)
 {
      unsigned int i,j,k;
 
      unsigned int nn = v.size()+2;
      unsigned int k0 = nn-2;
      unsigned int k1 = nn-1;
 
      vector<unsigned int> dd(nn*nn);
 
      for (i=0; i<v.size(); i++)
      {
 	  for (j=i+1; j<v.size(); j++)
 	  {
 	       unsigned int d = dist(v.at(i), v.at(j));
 	       dd.at(i*nn+j) = d;
 	       dd.at(j*nn+i) = d;
 	  }
      }
 
      for (i=0; i<v.size(); i++)
      {
 	  dd.at(k0*nn+i) = v.at(i).x0;
 	  dd.at(i*nn+k0) = v.at(i).x0;
 	  dd.at(k1*nn+i) = W-v.at(i).x1-1;
 	  dd.at(i*nn+k1) = W-v.at(i).x1-1;
      }
      
      dd.at(k0*nn+k1) = W;
      dd.at(k1*nn+k0) = W;
      // At this point dd is a table of distances;
 
      vector<unsigned int> s0(nn);
      vector<unsigned int> ds0(nn);
 
      s0.at(k0) = 1;
      for (i=0; i<nn; i++)
      {
 	  ds0.at(i) = dd.at(k0*nn+i);
      }     
 
      if (0)
      {
 	  for (i=0; i<nn; i++)
 	  {
 	       for (j=0; j<nn; j++)
 	       {
 		    cerr << setw(2) << dd.at(i*nn+j) << " ";
 	       }
 	       cerr << endl;
 	  }
 	  cerr << "===================" << endl;
      }
 
      while (1)
      {
 	  if (0)
 	  {
 	       for (auto x : s0) cerr << setw(2) << x << " "; cerr << endl;
 	       for (auto x : ds0) cerr << setw(2) << x << " "; cerr << endl;
 	  }
 
 	  bool first = true;
 	  unsigned int dmin = 0;
 	  unsigned int i0 = 10000000;
 
 	  for (i=0; i<nn; i++)
 	  {
 	       if (s0.at(i) == 0)
 	       {
 		    if (first ||
 			ds0.at(i) < dmin)
 		    {
 			 first=false;
 			 i0 = i;
 			 dmin = ds0.at(i);
 		    }
 	       }
 	  }
 	  //cerr << "i0 = " << i0 << "   dmin = " << dmin << endl;
 	  s0.at(i0) = 1;
 	  ds0.at(i0) = dmin;
 
 	  if (i0==k1) return dmin;
 	  
 	  for (j=0; j<nn; j++)
 	  {
 	       if (s0.at(j) == 0)
 	       {
 		    bool first = true;
 		    unsigned int dmin = 0;
 		    for (k=0; k<nn; k++)
 		    {
 			 if (s0.at(k) == 1)
 			 {
 			      if (first ||
 				  dd.at(k*nn+j) + ds0.at(k) < dmin)
 			      {
 				   first = false;
 				   dmin = dd.at(k*nn+j) + ds0.at(k);
 			      }
 			 }
 		    }
 		    ds0.at(j) = dmin;
 	       }
 	  }     
      }
 }
 
 int main( int argc, char ** argv )
 {
      unsigned int n;
      unsigned int i;
 
      cin >> n;
 
      for (i=1; i<=n; i++) 
      {
 	  unsigned int W;
 	  unsigned int H;
 	  unsigned int B;
 
 	  cin >> W >> H >> B;
 
 	  vector<building> v(B);
 
 	  for (auto &b : v )
 	  {
 	       cin >> b.x0;
 	       cin >> b.y0;
 	       cin >> b.x1;
 	       cin >> b.y1;
 	  }
 
 	  unsigned int e = solve(W, H, v);
 	  
 	  cout << "Case #" << i << ": ";
 	  cout << e;
 	  cout << endl;
 
      }
 
      return 0;
 }
 
