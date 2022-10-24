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

const int MX = 500, MY = 500;
const int SX = 14, SY = 15;
//const int SX = 5, SY = 5;

pii Dig(int x, int y){
  printf("%d %d\n", x, y);
  fflush(stdout);
  scanf("%d%d", &x, &y);
  return mp(x, y);
}

int put[100][100];

void Solve(){
  int a;
  scanf("%d", &a);

  for(int i = 0;i < SX;++i)
    for(int j = 0;j < SY;++j)
      put[i][j] = 0;

  int bst;
  vector<pii> bpos;

  while(true){
    bst = 0;
    bpos.clear();

    for(int i = 1;i + 1 < SX;++i)
      for(int j = 1;j + 1 < SY;++j){
        int emp = 0;
        for(int dx = -1;dx <= 1;++dx)
          for(int dy = -1;dy <= 1;++dy)
            if(put[i + dx][j + dy] == 0)
              ++emp;

        if(emp > bst) bst = emp, bpos.clear();
        if(emp == bst) bpos.pb(mp(i, j));
      }

    pii use = bpos[rand() % sz(bpos)];
    use = Dig(use.fi + MX, use.se + MY);
    if(use.fi == -1) exit(0);
    if(use.fi == 0 && use.se == 0) break;

    use.fi -= MX, use.se -= MY;
    put[use.fi][use.se] = 1;
  }
}

int main(){
  srand(13331);
  int q;
  scanf("%d", &q);

  for(int i = 1;i <= q;++i)
    Solve();

  return 0;
}
