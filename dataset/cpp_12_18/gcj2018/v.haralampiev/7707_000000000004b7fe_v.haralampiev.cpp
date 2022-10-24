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

void Solve(int CASE){
  int n;
  scanf("%d", &n);

  vector<pii> in(n);
  for(auto& e : in)
    scanf("%d%d", &e.fi, &e.se);

  int minx = in[0].fi, maxx = in[0].fi;
  int miny = in[0].se, maxy = in[0].se;
  for(int i = 1;i < n;++i){
    relaxMin(minx, in[i].fi);
    relaxMin(miny, in[i].se);
    relaxMax(maxx, in[i].fi);
    relaxMax(maxy, in[i].se);
  }

  int dx = (maxx - minx + 1) / 2;
  int dy = (maxy - miny + 1) / 2;

  printf("Case #%d: %d\n", CASE, max(dx, dy));
}

int main(){
  int q;
  scanf("%d", &q);

  for(int i = 1;i <= q;++i)
    Solve(i);

  return 0;
}
