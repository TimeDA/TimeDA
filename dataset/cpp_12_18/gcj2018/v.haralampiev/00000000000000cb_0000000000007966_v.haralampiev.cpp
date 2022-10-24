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

ll d;
string cmds;

bool Fine(){
  ll tot = 0;
  ll cur = 1;

  for(char c : cmds){
    if(c == 'C') cur *= 2;
    if(c == 'S') tot += cur;
    if(tot > d) return false;
  }

  return tot <= d;
}

void Solve(int id){
  cin >> d >> cmds;

  int ans = 0;
  while(true){
    if(Fine()) break;

    int sp = -1;
    for(int i = sz(cmds) - 1;i > 0;--i)
      if(cmds[i] == 'S' && cmds[i - 1] == 'C'){
        sp = i;
        break;
      }

    if(sp == -1){
      ans = -1;
      break;
    } else {
      ++ans;
      swap(cmds[sp - 1], cmds[sp]);
    }
  }

  cout << "Case #" << id << ": ";
  if(ans == -1) cout << "IMPOSSIBLE\n";
  else cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);

  int q;
  cin >> q;
  for(int i = 1;i <= q;++i){
    Solve(i);
  }

  return 0;
}
