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

const int MAX = 100010;

int n, l;
int cnt[MAX];

int part[110];
vector<pii> proc;

int part1[110];
vector<pii> proc1;

int Zakr(int w){
  auto it = lower_bound(all(proc), mp(w + 1, -1));
  --it;
  return it->se;
}

int Gap(int w){
  auto it = lower_bound(all(proc), mp(w + 1, -1));
  return it->fi - w;
}

int Solve(){
  proc.clear();
  proc1.clear();

  scanf("%d%d", &n, &l);
  //n = 13230, l = 0;
  int have = n;

  for(int i = 0;i < n;++i) cnt[i] = 0;
  for(int i = 0;i < l;++i){
    scanf("%d", &cnt[i]);
    have -= cnt[i];
  }

  // part
  part[0] = 0;
  for(int i = 1;i <= 100;++i){
    int how = i * 10 - 5;
    part[i] = (how * n + 999) / 1000;
  }

  for(int i = 0;i <= 100;++i)
    if(i + 1 > 100 || part[i + 1] != part[i])
      proc.pb(mp(part[i], i));

  vi up(n + 1);
  for(int i = 0;i <= n;++i)
    up[i] = Zakr(i);

  vi dp(have + 1, 0);
  for(int i = 0;i < n;++i)
    for(int nal = have;nal >= 0;--nal)
      for(int give = 0;give <= nal;++give)
        relaxMax(dp[nal], dp[nal - give] + up[cnt[i] + give]);

  return dp[have];

  //int ans = 0;
  //for(int i = 0;i < n;++i)
  //  ans += Zakr(cnt[i]);
  //return ans;
}

int main(){
  int q;
  scanf("%d", &q);
  for(int i = 1;i <= q;++i){
    int ans = Solve();
    printf("Case #%d: %d\n", i, ans);
  }
  return 0;
}
