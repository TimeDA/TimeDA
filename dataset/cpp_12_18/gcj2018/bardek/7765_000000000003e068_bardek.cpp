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

int ile[MAXN];
bool czy[MAXN];

void wez(int a){
    if(a!=-1) czy[a]=1;
    printf("%d\n",a);
    fflush(stdout);
}

void solve(){
    int n;
    scanf("%d",&n);
    fru(i,n) ile[i]=czy[i]=0;
    fru(i,n){
        int d;
        scanf("%d",&d);
        if(d==0){
            wez(-1);
            continue;
        }
        vi tu;
        fru(j,d){
            int a;
            scanf("%d",&a);
            ++ile[a];
            tu.pb(a);
        }
        vi A;
        int r=555;
        tr(it,tu) if(!czy[*it]){
            if(ile[*it]<r){
                A.clear();
                r=ile[*it];
            }
            if(ile[*it]==r) A.pb(*it);
        }
        if(A.empty()){
            wez(-1);
            continue;
        }
        wez(A[rand()%A.size()]);
    }
}

int main(){
    srand(303);
    int o;
    scanf("%d",&o);
    fru(oo,o){
//      printf("Case #%d: ",oo+1);
        solve();
    }
    return 0;
}
