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

typedef pair<pii,pii> tri;

tri P[20],aa;

LL M[3][3];

void wpisz(int p, tri t){
//    printf("aa = %d %d %d i wpisuje t = %d %d %d\n",aa.x.x,aa.x.y,aa.y.x,t.x.x,t.x.y,t.y.x);
    M[p][0]=t.x.x-aa.x.x;
    M[p][1]=t.x.y-aa.x.y;
    M[p][2]=t.y.x-aa.y.x;
}

int znak(tri t){
    wpisz(2,t);
/*    fru(i,3){
        fru(j,3) printf("%d ",M[i][j]);
        puts("");
    }  puts("");*/
    LL ret=0;
    ret+=M[0][0]*M[1][1]*M[2][2];
    ret+=M[0][1]*M[1][2]*M[2][0];
    ret+=M[0][2]*M[1][0]*M[2][1];

    ret-=M[0][2]*M[1][1]*M[2][0];
    ret-=M[0][1]*M[1][0]*M[2][2];
    ret-=M[0][0]*M[1][2]*M[2][1];

    if(ret>0) return 1;
    if(ret<0) return -1;
    return 0;
}

void solve(){
    int n;
    scanf("%d",&n);
    fru(i,n) scanf("%d%d%d",&P[i].x.x,&P[i].x.y,&P[i].y.x);
    fru(i,n) P[i].y.y=i+1;
    sort(P,P+n);
//    puts("");
    do{
        bool ok=1;
        for(int j=1;j+2<n;++j){
            aa=P[j];
            tri w=aa;
            w.y.x--;
            wpisz(0,P[j+1]);
            wpisz(1,P[j+2]);
            int z=znak(w);
            w.y.x+=2;
        //    printf("znak(w)= %d, znak(aa) = %d\n",znak(w),znak(aa));
            fru(i,j) if(znak(P[i])!=z){
                ok=0;
                break;
            }
        }
        if(ok){
            fru(i,n) printf(" %d",P[i].y.y);
            puts("");
            return;
        }
    }
    while(next_permutation(P,P+n));
    assert(0);
}

int main(){
    int o;
    scanf("%d",&o);
    fru(oo,o){
        printf("Case #%d:",oo+1);
        solve();
    }
    return 0;
}
