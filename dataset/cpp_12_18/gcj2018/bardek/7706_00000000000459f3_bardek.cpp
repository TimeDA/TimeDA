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
const int N = 501;

char dp[N][N];

int main(){
    fru(i,N) fru(j,N) if(i+j)
        for(int a=N-1;a>=i;--a)
            for(int b=N-1;b>=j;--b)
                if(dp[a][b]<1+dp[a-i][b-j])
                    dp[a][b]=1+dp[a-i][b-j];
    int o;
    scanf("%d",&o);
    fru(oo,o){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("Case #%d: %d\n",oo+1,dp[a][b]);
    }
    return 0;
}
