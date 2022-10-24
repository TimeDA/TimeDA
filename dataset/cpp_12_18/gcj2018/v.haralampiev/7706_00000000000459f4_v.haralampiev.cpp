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

const int MAX = 10;

int r, c;
int ans = 0;

// Max comp
int mrk[MAX][MAX];
int sub;

vector<pii> dlt = {
  mp(-1, 0), mp(+1, 0),
  mp(0, -1), mp(0, +1)
};

void Reset(){
  memset(mrk, 0, sizeof mrk);
}

void Dfs(int x, int y){
  ++sub;
  mrk[x][y] = 0;

  for(const auto& e : dlt){
    int nx = x + e.fi;
    int ny = y + e.se;
    if(nx >= 0 && ny >= 0 &&
       nx < r && ny < c &&
       mrk[nx][ny]){
      Dfs(nx, ny);
    }
  }
}

void Update(){
  for(int i = 0;i < r;++i)
    for(int j = 0;j < c;++j)
      if(mrk[i][j]){
        sub = 0;
        Dfs(i, j);
        relaxMax(ans, sub);
      }
}

// Expansion
vector<vector<char>> Expand(const vector<vector<char>>& of){
  int r = sz(of);
  int c = sz(of[0]);

  vector<vector<char>> res(2 * r, vector<char>(2 * c));

  for(int i = 0;i < r;++i)
    for(int j = 0;j < c;++j){
      res[2 * i][2 * j] = of[i][j];
      res[2 * i + 1][2 * j] = of[i][j];
      res[2 * i][2 * j + 1] = of[i][j];
      res[2 * i + 1][2 * j + 1] = of[i][j];
    }

  return res;
}

char buf[MAX];
void Solve(int CASE = 0){
  ans = 0;

  //int r, c;
  scanf("%d%d", &r, &c);

  vector<vector<char>> in(r, vector<char>(c));
  for(int i = 0;i < r;++i){
    scanf("%s", buf);
    for(int j = 0;j < c;++j)
      in[i][j] = buf[j];
  }

  auto base = in;

  in = Expand(in);
  in = Expand(in);
  in = Expand(in);
  //in = Expand(in);

  int _r = sz(in);
  int _c = sz(in[0]);

  for(int i = -r;i <= _r;++i)
    for(int j = -c;j <= _c;++j){
      //i = 0;
      //j = 0;
      Reset();

      //cout << r << ' ' << c << " : " << _r << ' ' << _c << endl;
      for(int x = 0;x < r;++x)
        for(int y = 0;y < c;++y){
          int _x = i + x, _y = j + y;
          if(_x >= 0 && _y >= 0 &&
             _x < _r && _y < _c){
            if(base[x][y] == in[_x][_y]){
              mrk[x][y] = 1;
            }
          }
        }

      /*
      for(int x = 0;x < r;++x){
        for(int y = 0;y < c;++y){
          cout << mrk[x][y] << ' ';
        }
        cout << endl;
      }
      system("pause");
      */
      Update();
      //cout << ans << endl;
    }

  printf("Case #%d: %d\n", CASE, ans);
}

int main(){
  int q;
  scanf("%d", &q);
  for(int i = 1;i <= q;++i)
    Solve(i);

  return 0;
}
