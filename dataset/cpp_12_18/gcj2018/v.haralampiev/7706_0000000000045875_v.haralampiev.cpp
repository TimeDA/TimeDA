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

#define SZ 220
#define INF 100000000

// Max flow
struct edge{
  int f,t,cap,fl;
  edge(int _f=0,int _t=0,int _cap=0){
   f=_f; t=_t; cap=_cap; fl=0;
                                    }
  int rc(){return cap-fl;}
};

int N = 0 , F , T;
vector<edge> E;
vi fo[SZ];
void add_edge(int f,int t,int cap){
  E.pb(edge(f,t,cap)); E.pb(edge(t,f,0));
  fo[f].pb(sz(E)-2); fo[t].pb(sz(E)-1);
}
int lev[SZ] , Q[SZ] , QL , QR;
bool bfs(){
  memset(lev , -1 , N*sizeof(int));
  QL = QR = 0;
  lev[F] = 1; Q[QR++] = F;
  while(QL<QR){
   int V = Q[QL++];
   for(int i=0;i<sz(fo[V]);++i)
    if(E[fo[V][i]].rc()){
     int to = E[fo[V][i]].t;
     if(lev[to]==-1){
      lev[to] = lev[V]+1;
      Q[QR++] = to;
                    }
                        }
              }
  return lev[T]!=-1;
}
int pos[SZ];
int dfs(int vr , int htp=INF){
  if(htp == 0 || vr==T)return htp;
  for(;pos[vr]<sz(fo[vr]);++pos[vr]){
   edge& e = E[ fo[vr][pos[vr]] ];
   if(lev[e.f]+1 == lev[e.t] && e.cap > e.fl){
    int pushed = dfs(e.t , min(htp , e.rc()));
    if(pushed){
     e.fl += pushed;
     E[ fo[vr][pos[vr]] ^ 1 ].fl -= pushed;
     return pushed;
              }
                                             }
                                    }
  return 0;
}
int max_flow(){
  int FLOW = 0 , how;
  while(bfs()){
   memset(pos , 0 , N*sizeof(int));
   while(how = dfs(F))FLOW += how;
              }
  return FLOW;
}

void Reset(){
  for(int i = 0;i < N;++i)
    fo[i].clear();
  E.clear();
  N = 0;
}
// </end>

const int MAX_SZ = 110;

int n;
int in[MAX_SZ][MAX_SZ];

void Solve(int CASE = 0){
  scanf("%d", &n);
  //n = 100;
  for(int i = 0;i < n;++i)
    for(int j = 0;j < n;++j)
      scanf("%d", &in[i][j]);
      //in[i][j] = rand() % 3 + 1;

  set<int> known;
  for(int i = 0;i < n;++i)
    for(int j = 0;j < n;++j)
      known.insert(in[i][j]);

  int fine = 0;
  for(int e : known){
    N = 2 * n + 2;
    F = N - 2, T = N - 1;

    for(int i = 0;i < n;++i)
      add_edge(F, i, 1),
      add_edge(i + n, T, 1);

    for(int i = 0;i < n;++i)
      for(int j = 0;j < n;++j)
        if(in[i][j] == e)
          add_edge(i, j + n, 1);

    fine += max_flow();
    Reset();
  }

  printf("Case #%d: %d\n", CASE, n * n - fine);
}

int main(){
  int q;
  scanf("%d", &q);
  for(int i = 1;i <= q;++i)
    Solve(i);

  return 0;
}
