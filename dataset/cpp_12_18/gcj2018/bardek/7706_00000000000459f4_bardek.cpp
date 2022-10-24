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

char S[25][25];

#define FOR(a) for(char a:col)

bool ok[25][25];
pii Q[25*25];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

char SS[100][100];

void solve(){
    string col="BW";
    int ret=0;
    int n,m;
    scanf("%d%d",&n,&m);
    fru(i,n) scanf("%s",S[i]);
    fru(i,n) fru(j,m) fru(a,2) fru(b,2) SS[2*i+a][2*j+b]=S[i][j];
    set<string> kwadr;
    fru(i,2*n-1) fru(j,2*m-1){
        char s[5]={SS[i][j],SS[i][j+1],SS[i+1][j],SS[i+1][j+1]};
        kwadr.insert(s);
    }
    for(string s:kwadr){
//        cout<<s<<endl;
//        if(string(s)!="BBBB") continue;
        fru(a,n+1) fru(b,m+1){
            fru(i,n) fru(j,m){
                int d=0;
                if(i>=a) d+=2;
                if(j>=b) d+=1;
                ok[i+1][j+1]=(S[i][j]==s[d]);
            }
            fru(i,n+2) fru(j,m+2) if(ok[i][j]){
                int qs=0;
                Q[qs++]=pii(i,j);
                ok[i][j]=0;
                fru(e,qs) fru(k,4){
                    int ii=Q[e].x+dx[k],
                        jj=Q[e].y+dy[k];
                    if(ok[ii][jj]) {
                        Q[qs++]=pii(ii,jj);
                        ok[ii][jj]=0;
                    }
                }
                ret=max(ret,qs);
            }
        }
    }
    printf("%d\n",ret);
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
