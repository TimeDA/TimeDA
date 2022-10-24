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
const int MAXN = 1000006;

char S[MAXN];int n,d;

LL hit(){
    LL s=0,q=1;
    fru(i,n){
        if(S[i]=='S') s+=q;
        else q*=2;
    }
    return s;
}
int solve(){
    int ret=0;
    while(hit()>d){
        bool any=0;
        for(int i=n-2;i>=0;--i){
            if(S[i]=='C' && S[i+1]=='S'){
                swap(S[i],S[i+1]);
                any=1;
                ++ret;
                break;
            }
        }
        if(!any) return -1;
    }
    return ret;
}

int main(){
    int o;
    scanf("%d",&o);
    fru(oo,o){
        printf("Case #%d: ",oo+1);
        scanf("%d %s",&d,S);
        n=strlen(S);
        int ret=solve();
        if(ret==-1) printf("IMPOSSIBLE\n");
        else printf("%d\n",ret);
    }
    return 0;
}
