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

int T[MAXN];
int A[MAXN],B[MAXN];

int main(){
    int o;
    scanf("%d",&o);
    fru(oo,o){
        printf("Case #%d: ",oo+1);
        int n;
        scanf("%d",&n);
        fru(i,n) scanf("%d",&T[i]);
        fru(i,n) if(i%2==0) A[i/2]=T[i];
        else B[i/2]=T[i];
        sort(A,A+(n+1)/2);
        sort(B,B+(n/2));
        fru(i,n) T[i]=(i%2==0)?A[i/2]:B[i/2];
        int ret=-1;
        fru(i,n-1) if(T[i]>T[i+1]){
            ret=i;
            break;
        }
        if(ret==-1) printf("OK\n");
        else printf("%d\n",ret);
    }
    return 0;
}
