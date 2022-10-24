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
  int c;
  scanf("%d", &c);

  vi in(c);
  for(int& e : in) scanf("%d", &e);

  printf("Case #%d: ", CASE);

  if(in[0] == 0 || in[c - 1] == 0){
    printf("IMPOSSIBLE\n");
    return;
  }

  vi to(c);
  int pos = 0;
  for(int i = 0;i < c;++i){
    while(in[i] > 0){
      to[pos] = i;
      --in[i];
      ++pos;
    }
  }

  bool fail = false;
  vector<vector<char>> go;

  for(int i = 0;i < c;++i){
    if(fail) break;
    int cp = i, tar = to[i];
    for(int r = 0;cp != tar;++r){
      if(sz(go) > 2 * 100 * 100){
        fail = true;
        break;
      }

      if(r == sz(go)) go.pb(vector<char>(c, '.'));

      if(cp < tar){
        if(cp > 0 && cp < c - 1 && go[r][cp + 1] != '/'){
          go[r][cp] = '\\';
          ++cp;
        }
      }

      if(cp > tar){
        if(cp > 0 && cp < c - 1 && go[r][cp - 1] != '\\'){
          go[r][cp] = '/';
          --cp;
        }
      }
    }
  }

  if(fail){
    printf("IMPOSSIBLE\n");
    return;
  }

  go.pb(vector<char>(c, '.'));

  printf("%d\n", sz(go));
  for(int i = 0;i < sz(go);++i){
    for(int j = 0;j < c;++j)
      printf("%c", go[i][j]);
    printf("\n");
  }
}

int main(){
  int q;
  scanf("%d", &q);
  for(int i = 1;i <= q;++i){
    Solve(i);
  }

  return 0;
}
