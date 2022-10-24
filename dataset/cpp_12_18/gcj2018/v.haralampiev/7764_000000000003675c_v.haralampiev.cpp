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

const int MAX = 110;

int m;
int a[MAX], b[MAX];
int has[MAX];

// Try
ll nal[MAX];
ll need[MAX], need1[MAX];

bool Can(ll how){
  for(int i = 1;i <= m;++i)
    nal[i] = has[i];

  fill(need, need + m + 1, 0);
  need[1] = how;

  while(true){
    fill(need1, need1 + m + 1, 0);
    for(int i = 1;i <= m;++i){
      ll take = min(need[i], nal[i]);
      need[i] -= take;
      nal[i] -= take;
      if(need[i] > 0){
        need1[a[i]] += need[i];
        need1[b[i]] += need[i];
      }
    }

    if(count(need1, need1 + m + 1, 0) == m + 1)
      return true;

    ll sum = 0;
    for(int i = 1;i <= m;++i)
      sum += nal[i];

    for(int i = 1;i <= m;++i){
      sum -= need1[i];
      if(sum < 0) return false;
    }

    for(int i = 1;i <= m;++i)
      need[i] = need1[i];
  }

  return false;
}

ll Solve(){
  scanf("%d", &m);

  for(int i = 1;i <= m;++i)
    scanf("%d%d", &a[i], &b[i]);

  for(int i = 1;i <= m;++i)
    scanf("%d", &has[i]);

  ll lo = 0, hi = 1, mid;
  while(Can(hi)) hi <<= 1;

  for(;;){
    if(lo + 1 >= hi){
      if(Can(hi)) return hi;
      return lo;
    }
    mid = (lo + hi) >> 1;
    if(Can(mid)) lo = mid;
    else hi = mid;
  }
}

int main(){
  int q;
  scanf("%d", &q);
  for(int i = 1;i <= q;++i){
    ll ans = Solve();
    cout << "Case #" << i << ": " << ans << '\n';
  }
  return 0;
}
