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

const int MAXN = 100010;
const int oo = 1E9 + 2471;

int n;
int d[MAXN], a[MAXN], b[MAXN];

pii Extend(pii t, int a, int b){
  if(t.fi == a || t.se == b) return t;

  if(t.fi == oo){
    t.fi = a;
    return t;
  }

  if(t.se == oo){
    t.se = b;
    return t;
  }

  return mp(oo, oo);
}

int Go(int pos, pii e){
  int endp = pos;

  while(endp + 1 < n){
    e = Extend(e, a[endp + 1], b[endp + 1]);
    if(e.fi == oo && e.se == oo) break;
    ++endp;
  }

  return endp;
}

int GetMax(int pos){
  int p1 = Go(pos, mp(a[pos], oo));
  int p2 = Go(pos, mp(oo, b[pos]));

  return max(p1, p2) - pos + 1;
}

pii Solve(){
  scanf("%d", &n);
  for(int i = 0;i < n;++i){
    scanf("%d%d%d", &d[i], &a[i], &b[i]);
    a[i] = d[i] + a[i];
    b[i] = d[i] - b[i];
  }

  int ml = 0, cnt = 0;
  for(int i = 0;i < n;++i){
    int len = GetMax(i);
    if(len > ml) ml = len, cnt = 0;
    if(len == ml) ++cnt;
  }

  return mp(ml, cnt);
}

int main(){
  int q;
  scanf("%d", &q);

  for(int i = 1;i <= q;++i){
    auto ans = Solve();
    printf("Case #%d: %d %d\n", i, ans.fi, ans.se);
  }

  return 0;
}
