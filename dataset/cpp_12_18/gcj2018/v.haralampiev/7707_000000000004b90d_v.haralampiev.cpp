#include <bits/stdc++.h>
using namespace std;
#define null NULL
#define mp make_pair
#define pb(a) push_back(a)
#define sz(a) ((int)(a).size())
#define all(a) a.begin() , a.end()
#define fi first
#define se second
#define relaxMin(a , b) (a) = min((a),(b))
#define relaxMax(a , b) (a) = max((a),(b))
#define SQR(a) ((a)*(a))
#define PI 3.14159265358979323846
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

struct Point {
  ll x, y, z;

  bool operator<(const Point& w) const {
    return mp(x, mp(y, z)) <
           mp(w.x, mp(w.y, w.z));
  }

  bool operator==(const Point& w) const {
    return x == w.x &&
           y == w.y &&
           z == w.z;
  }

  bool operator!=(const Point& w) const {
    return x != w.x ||
           y != w.y ||
           z != w.z;
  }

  Point(ll _x = 0, ll _y = 0, ll _z = 0){
    x = _x, y = _y, z = _z;
  }

  Point operator-(const Point& w) const {
    return Point(x - w.x, y - w.y, z - w.z);
  }

  Point operator+(const Point& w) const {
    return Point(x + w.x, y + w.y, z + w.z);
  }

  void Neg(){
    x *= -1;
    y *= -1;
    z *= -1;
  }

  void Print() const{
    cout << x << ' ' << y << ' ' << z << endl;
  }
};

ll Sp(const Point& f, const Point& s){
  return f.x * s.x + f.y * s.y + f.z * s.z;
}

Point Vp(const Point& a, const Point& b){
  return Point(+(a.y * b.z - a.z * b.y),
               -(a.x * b.z - a.z * b.x),
               +(a.x * b.y - a.y * b.x));
}

Point Perp(const Point& a, const Point& b, const Point& c){
  Point dir = Vp(b - a, c - a);
  if(Sp(dir, Point(0, 0, 1)) < 0) dir.Neg();
  return dir;
}

// Plane
Point perp;

void InitPlane(const Point& a, const Point& b, const Point& c){
  perp = Perp(a, b, c);
}

bool IsAbove(const Point& w, const Point& base){
  return Sp(perp, w - base) > 0;
}

// Solving
int n;
vector<Point> in;
vector<char> alive;

bool Validate(const vector<Point>& w){
  for(int i = 3;i < sz(w);++i){
    InitPlane(w[i - 2], w[i - 1], w[i]);
    for(int j = 0;j < i;++j)
      if(IsAbove(w[j], w[i])){
        w[j].Print();
        w[i].Print();
        w[i - 1].Print();
        w[i - 2].Print();
        return false;
      }
  }
  return true;
}

void Solve(int CASE = 0){
  scanf("%d", &n);

  map<Point, int> id;

  in.resize(n);
  for(int i = 0;i < n;++i){
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    in[i].x = x;
    in[i].y = y;
    in[i].z = z;
    id[in[i]] = i + 1;
  }

  alive.resize(n);
  fill(all(alive), true);

  random_shuffle(all(in));

  Point tall = in[0];
  for(int i = 1;i < n;++i)
    if(tall.z < in[i].z)
      tall = in[i];

  Point a = tall, b, c;
  for(int i = 0;i < n;++i){
    if(tall == in[i]) continue;
    b = in[i];

    for(int j = 0;j < n;++j)
      if(in[j] != a && in[j] != b){
        c = in[j];
        break;
      }

    InitPlane(a, b, c);

    for(int j = 0;j < n;++j){
      if(in[j] == a || in[j] == b) continue;
      if(IsAbove(in[j], a)){
        c = in[j];
        InitPlane(a, b, c);
      }
    }

    bool fine = true;
    for(int j = 0;j < n;++j)
      if(in[j] != a && in[j] != b && in[j] != c){
        if(IsAbove(in[j], a)){
          fine = false;
          break;
        }
      }

    if(fine) {
      break;
    }
  }

  vector<Point> ans;
  for(int i = 0;i < n;++i){
    if(in[i] == a) alive[i] = false;
    if(in[i] == b) alive[i] = false;
    if(in[i] == c) alive[i] = false;
  }

  while(true){
    if(count(all(alive), true) == 0){
      ans.pb(a);
      ans.pb(b);
      ans.pb(c);
      break;
    }

    ans.pb(a);

    Point na = b;
    Point nb = c;
    Point nc;
    for(int j = 0;j < n;++j)
      if(alive[j]){
        nc = in[j];
        break;
      }

    InitPlane(na, nb, nc);

    for(int j = 0;j < n;++j){
      if(!alive[j]) continue;
      if(IsAbove(in[j], na)){
        nc = in[j];
        InitPlane(na, nb, nc);
      }
    }

    a = na;
    b = nb;
    c = nc;
    for(int i = 0;i < n;++i)
      if(in[i] == c){
        alive[i] = false;
        break;
      }
  }

  reverse(all(ans));
  //cout << Validate(ans) << endl;

  printf("Case #%d:", CASE);
  for(int i = 0;i < n;++i){
    printf(" %d", id[ans[i]]);
  }
  printf("\n");
}

int main(){
  /*
  Point x = Point(3, -1, 2);
  Point a = Point(-1, 0, 3);
  Point b = Point(1, -2, 4);
  Point c = Point(3, 1, 3);

  InitPlane(c, b, a);
  //InitPlane(a, b, c);
  perp.Print();
  cout << Sp(perp, a - b) << endl;
  cout << Sp(perp, b - c) << endl;
  cout << Sp(perp, a - c) << endl;
  //cout << IsAbove(x, a) << endl;
  */
  /*
  vector<Point> w;
  w.pb(Point(3, -1, 2));
  w.pb(Point(3, 1, 3));
  w.pb(Point(1, -2, 4));
  w.pb(Point(-1, 0, 3));
  w.pb(Point(1, 2, 4));
  cout << Validate(w) << endl;
  */

  int q;
  scanf("%d", &q);
  for(int i = 1;i <= q;++i)
    Solve(i);

  return 0;
}
