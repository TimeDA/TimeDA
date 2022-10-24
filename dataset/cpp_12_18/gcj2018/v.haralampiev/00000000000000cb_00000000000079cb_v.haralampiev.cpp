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

void Solve(int id = 0){
  int n;
  scanf("%d", &n);
  vi in(n);
  for(int& e : in) scanf("%d", &e);

  vi even, odd;
  for(int i = 0;i < n;++i)
    if(i & 1) odd.pb(in[i]);
    else even.pb(in[i]);

  sort(all(even));
  sort(all(odd));

  in.clear();
  int ep = 0, op = 0;
  while(ep < sz(even) || op < sz(odd)){
    if(ep < sz(even)) in.pb(even[ep++]);
    if(op < sz(odd)) in.pb(odd[op++]);
  }

  int ans = -1;
  for(int i = 0;i + 1 < sz(in);++i){
    if(in[i] > in[i + 1]){
      ans = i;
      break;
    }
  }

  printf("Case #%d: ", id);
  if(ans == -1) printf("OK\n");
  else printf("%d\n", ans);
}

int main(){
  int q;
  scanf("%d", &q);
  for(int i = 1;i <= q;++i)
    Solve(i);

  return 0;
}
