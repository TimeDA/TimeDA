//
// google codejam 2018 - qualification - Cubic UFO
// John Smith
//

#include <bits/stdc++.h>

using namespace std;

struct Pt {
     double x;
     double y;
     double z;

     Pt( double x, double y, double z ) : x(x), y(y), z(z) {}
     Pt( Pt p1, Pt p2, Pt p3) : x(p1.x+p2.x+p3.x), y(p1.y+p2.y+p3.y), z(p1.z+p2.z+p3.z) {}
};

struct Pt2 {
     double x;
     double y;
     Pt2( double x=0.0, double y=0.0 ) : x(x), y(y) {}
     Pt2( const Pt2 &p ) : x(p.x), y(p.y) {}
};

bool operator <( const Pt2 &p1, const Pt2 &p2 )
{
     return (p1.x < p2.x ||
             (p1.x == p2.x && p1.y < p2.y));
}

Pt operator-(Pt &p)
{
     return Pt(-p.x, -p.y, -p.z);
}

double dist(Pt p )
{
     double h = sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
     return h;
}

double dist( Pt p1, Pt p2 )
{
     double dx = p1.x-p2.x;
     double dy = p1.y-p2.y;
     double dz = p1.z-p2.z;

     return sqrt(dx*dx+dy*dy+dz*dz);
}

double dot( Pt p1, Pt p2 )
{
     return p1.x*p2.x + p1.y*p2.y + p1.z*p2.z;
}

double triangle_area( Pt2 p1, Pt2 p2, Pt2 p3 )
{
     double dx1 = p2.x-p1.x;
     double dx2 = p3.x-p1.x;
     double dy1 = p2.y-p1.y;
     double dy2 = p3.y-p1.y;

     double a = dx1*dy2 - dx2*dy1;
     a /= 2.0;
     if (a < 0) a=-a;
     return a;
}

vector<Pt2> convex_hull( vector<Pt2> v )
{
     sort(v.begin(), v.end());

     vector<Pt2> hull0;
     vector<Pt2> hull1;
     hull0.push_back(v.at(0));
     for (uint32_t i=1; i<v.size(); i++)
     {
          while (hull0.size() > 1)
          {
               Pt2 p0 = v.at(i);
               Pt2 p1 = hull0.at(hull0.size()-1);
               Pt2 p2 = hull0.at(hull0.size()-2);
               if ((p0.y-p1.y)/(p0.x-p1.x) > (p1.y-p2.y)/(p1.x-p2.x))
               {
                    hull0.resize(hull0.size()-1);
               }
               else
               {
                    break;
               }
          }
          hull0.push_back(v.at(i));
     }

     hull1.push_back(v.at(0));
     for (uint32_t i=1; i<v.size(); i++)
     {
          while (hull1.size() > 1)
          {
               Pt2 p0 = v.at(i);
               Pt2 p1 = hull1.at(hull1.size()-1);
               Pt2 p2 = hull1.at(hull1.size()-2);
               if ((p0.y-p1.y)/(p0.x-p1.x) < (p1.y-p2.y)/(p1.x-p2.x))
               {
                    hull1.resize(hull1.size()-1);
               }
               else
               {
                    break;
               }
          }
          hull1.push_back(v.at(i));
     }

     reverse(hull1.begin(), hull1.end());
     for (auto p : v)
     {
          cout << setw(12) << p.x << " ";
          cout << setw(12) << p.y << " ";
          cout << endl;
     }

     cout << endl;

     for (auto p : hull0)
     {
          cout << setw(12) << p.x << " ";
          cout << setw(12) << p.y << " ";
          cout << endl;
     }

     cout << endl;

     for (auto p : hull1)
     {
          cout << setw(12) << p.x << " ";
          cout << setw(12) << p.y << " ";
          cout << endl;
     }

     hull0.resize(hull0.size()-1);
     hull1.resize(hull1.size()-1);
     vector<Pt2> hull;
     for (auto p : hull0) hull.push_back(p);
     for (auto p : hull1) hull.push_back(p);
     return hull;
}

double area( Pt c1, Pt c2, Pt c3 )
{
     Pt p1( c1, c2, c3);
     Pt p2(-c1, c2, c3);
     Pt p3( c1,-c2, c3);
     Pt p4(-c1,-c2, c3);
     Pt p5( c1, c2,-c3);
     Pt p6(-c1, c2,-c3);
     Pt p7( c1,-c2,-c3);
     Pt p8(-c1,-c2,-c3);

     vector<Pt2> v;
     v.push_back(Pt2(p1.x, p1.z));
     v.push_back(Pt2(p2.x, p2.z));
     v.push_back(Pt2(p3.x, p3.z));
     v.push_back(Pt2(p4.x, p4.z));
     v.push_back(Pt2(p5.x, p5.z));
     v.push_back(Pt2(p6.x, p6.z));
     v.push_back(Pt2(p7.x, p7.z));
     v.push_back(Pt2(p8.x, p8.z));

     auto hull = convex_hull( v );
     double a = 0.0;
     for (auto i=1u; i<hull.size()-1; i++)
     {
          Pt2 p1 = hull.at(0);
          Pt2 p2 = hull.at(i);
          Pt2 p3 = hull.at(i+1);
          a += triangle_area( p1, p2, p3 );
     }
     cout << "Area = " << a << endl;
     return a;
}

int main(int argc, char ** argv)
{
     ios_base::sync_with_stdio(false);
     cout << fixed ;

     if (0)
     {
          vector<Pt2> v;
          for (auto i=0u; i<30; i++)
          {
               double x = (rand()%1000000 - 500000)/ 1000000.0;
               double y = (rand()%1000000 - 500000)/ 1000000.0;
               v.push_back(Pt2(x,y));
          }

          auto w = convex_hull(v);
          for (auto p : v)
          {
               cout << p.x << " " << p.y << endl;
          }
          cout << endl;
          for (auto p : w)
          {
               cout << p.x << " " << p.y << endl;
          }
          cout << endl;
          exit(0);
     }

     uint32_t T;
     cin >> T;
     for (uint32_t j=1; j<=T; j++)
     {
          double A;
          cin >> A;

          // vertex at  ( x,  h,  0.0)
          // vertex at  ( h, -x,  0.0)
          // vertex at  (-x, -h,  0.0)
          // vertex at  (-h,  x,  0.0)
          // mid point of opposite edge
          //            ( 0,  0,  0.5)
          //            ( 0,  0, -0.5)
          // vertex at  ( h+x, h-x, 1.0)/2
          // vertex at -( h+x, h-x, 1.0)/2
          // vertex at  ( x-h, x+h, 1.0)/2
          // vertex at -( x-h, x+h, 1.0)/2
#if 1
          double h = A/2.0;
          double x = sqrt(0.75-h*h);

          double c = ( sqrt(0.5) * x + 0.5 * h) / 0.75;
          double s = (-sqrt(0.5) * h + 0.5 * x) / 0.75;

          // ( c s 0 )  ( sqrt(0.5) sqrt(0.5)
          // (-s c 0 )  (      0.5      -0.5
          // ( 0 0 1 )  (      0.0       0.0
          // x =  0.5 cos + sqrt(0.5) sin  -> cos = ( 0.5 x + sqrt(0.5) h) / 0.75
          // h = -0.5 sin + sqrt(0.5) cos  -> sin = (-0.5 h + sqrt(0.5) x) / 0.75
          Pt p1(  sqrt(0.5)*c+0.5*s, -sqrt(0.5)*s+0.5*c, 0.0);
          Pt p2(  sqrt(0.5)*c-0.5*s, -sqrt(0.5)*s-0.5*c, 0.0);
          Pt p3( -sqrt(0.5)*c-0.5*s,  sqrt(0.5)*s-0.5*c, 0.0);
          Pt p4( -sqrt(0.5)*c+0.5*s,  sqrt(0.5)*s+0.5*c, 0.0);

          Pt p5(  (p3.x+p2.x)/2,  (p3.y+p2.y)/2,   sqrt(0.5));
          Pt p6( -(p3.x+p2.x)/2, -(p3.y+p2.y)/2,   sqrt(0.5));
          Pt p7( -(p3.x+p2.x)/2, -(p3.y+p2.y)/2,  -sqrt(0.5));
          Pt p8(  (p3.x+p2.x)/2,  (p3.y+p2.y)/2,  -sqrt(0.5));
#else
          Pt p1(  0.5,  0.5,  0.5);
          Pt p2( -0.5,  0.5,  0.5);
          Pt p3(  0.5, -0.5,  0.5);
          Pt p4( -0.5, -0.5,  0.5);
          Pt p5(  0.5,  0.5, -0.5);
          Pt p6( -0.5,  0.5, -0.5);
          Pt p7(  0.5, -0.5, -0.5);
          Pt p8( -0.5, -0.5, -0.5);
#endif

#if 0
          cout << "c = " << c << endl;
          cout << "s = " << s << endl;
          cout << c*c + s*s << endl;

          cout << dist(p1) << endl;
          cout << dist(p2) << endl;
          cout << dist(p3) << endl;
          cout << dist(p4) << endl;
          cout << dist(p5) << endl;
          cout << dist(p6) << endl;
          cout << dist(p7) << endl;
          cout << dist(p8) << endl;
          cout << endl;

          cout << setw(10) << p1.x << " " << setw(10) << p1.y << " " << setw(10) << p1.z << endl;
          cout << setw(10) << p2.x << " " << setw(10) << p2.y << " " << setw(10) << p2.z << endl;
          cout << setw(10) << p3.x << " " << setw(10) << p3.y << " " << setw(10) << p3.z << endl;
          cout << setw(10) << p4.x << " " << setw(10) << p4.y << " " << setw(10) << p4.z << endl;
          cout << setw(10) << p5.x << " " << setw(10) << p5.y << " " << setw(10) << p5.z << endl;
          cout << setw(10) << p6.x << " " << setw(10) << p6.y << " " << setw(10) << p6.z << endl;
          cout << setw(10) << p7.x << " " << setw(10) << p7.y << " " << setw(10) << p7.z << endl;
          cout << setw(10) << p8.x << " " << setw(10) << p8.y << " " << setw(10) << p8.z << endl;
          cout << endl;

          Pt* a[8] = { &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8 };
          for (auto i=0u; i<8; i++)
          {
               for (auto j=0u; j<8; j++)
               {
                    cout << setw(10) << dot(*a[i], *a[j]) << " ";
               }
               cout << endl;
          }
#endif
          cout << "Case #" << j << ": " << endl;
          cout << setprecision(9);

          Pt c1( (p1.x+p4.x)/2, (p1.y+p4.y)/2, (p1.z+p4.z)/2 );
          Pt c2( (p1.x+p5.x)/2, (p1.y+p5.y)/2, (p1.z+p5.z)/2 );
          Pt c3( (p1.x+p8.x)/2, (p1.y+p8.y)/2, (p1.z+p8.z)/2 );
          cout << setw(12) << c1.x << " " << setw(12) << c1.y << " " << setw(12) << c1.z << endl;
          cout << setw(12) << c2.x << " " << setw(12) << c2.y << " " << setw(12) << c2.z << endl;
          cout << setw(12) << c3.x << " " << setw(12) << c3.y << " " << setw(12) << c3.z << endl;

          if (0) {
               cout << dist(p1, p1) << " " << dist(p1, p1) << endl;
               cout << dist(p1, p2) << " " << dist(p2, p1) << endl;
               cout << dist(p1, p3) << " " << dist(p3, p1) << endl;
               cout << dist(p1, p4) << " " << dist(p4, p1) << endl;
               cout << dist(p1, p5) << " " << dist(p5, p1) << endl;
               cout << dist(p1, p6) << " " << dist(p6, p1) << endl;
               cout << dist(p1, p7) << " " << dist(p7, p1) << endl;
               cout << dist(p1, p8) << " " << dist(p8, p1) << endl;
               cout << "c1 length = " << dist(c1) << endl;
               cout << "c2 length = " << dist(c2) << endl;
               cout << "c3 length = " << dist(c3) << endl;
               cout << "c1.c2  = " << dot(c1,c2) << endl;
               cout << "c1.c3  = " << dot(c1,c3) << endl;
               cout << "c2.c3  = " << dot(c2,c3) << endl;
               area( c1, c2, c3);
          }
     }
     return 0;
}
