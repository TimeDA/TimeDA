#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
#define DEB printf
#else
#define DEB(...)
#endif

typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inft = 1000000009;
const int MOD = 1000000007;
const int MAXN = 206;

int T[MAXN];
char OUT[MAXN][MAXN];

void solve(){
    int n;
    scanf("%d",&n);
    fru(i,n) scanf("%d",&T[i]);
    if(T[0]==0 || T[n-1]==0){
        printf("IMPOSSIBLE\n");
        return;
    }
    vector<pii> L,P;
    int last=-1;
    fru(i,n) if(T[i]){
        int beg=last+1;
        int end=beg+T[i];
//        printf("dla i = %d (%d) mam przedzial %d %d\n",i,T[i],beg,end);
        for(int j=beg;j<i;++j) L.pb(pii(i-j,j));
        for(int j=i+1;j<end;++j) P.pb(pii(j-i,j));
        last=end-1;
    }
    int wys=0;
    tr(it,L) wys=max(wys,it->x);
    tr(it,P) wys=max(wys,it->x);
    wys++;
    fru(i,wys) fru(j,n) OUT[i][j]='.';
    fru(i,wys) OUT[i][n]=0;
    tr(it,L) OUT[it->x][it->y]='\\';
    tr(it,P) OUT[it->x][it->y]='/';
    printf("%d\n",wys);
    fru(i,wys) printf("%s\n",OUT[wys-i-1]);
}

int main(){
    int o;
    scanf("%d",&o);
    fru(oo,o){
        printf("Case #%d: ",oo+1);
        solve();
    }
    return 0;
}
