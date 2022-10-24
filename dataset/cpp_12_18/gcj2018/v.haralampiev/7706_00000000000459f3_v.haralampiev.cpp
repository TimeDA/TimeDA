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

int dp[510][510][510]; // a, b, lo

int Eval(int a, int b, int lo){
  if(dp[a][b][lo] >= 0) return dp[a][b][lo];

  int& ans = dp[a][b][lo];
  ans = 0;

  for(int take = 1;;++take){
    a -= lo;
    b -= (take - 1);
    if(a < 0 || b < 0) break;
    relaxMax(ans, take + Eval(a, b, lo + 1));
  }

  return ans;
}

void Solve(int CASE = 0){
  int a, b;
  scanf("%d%d", &a, &b);

  printf("Case #%d: %d\n", CASE, Eval(a, b, 0) - 1);
}

int main(){
  memset(dp, -1, sizeof dp);

  int q;
  scanf("%d", &q);

  for(int i = 1;i <= q;++i)
    Solve(i);

  return 0;
}
