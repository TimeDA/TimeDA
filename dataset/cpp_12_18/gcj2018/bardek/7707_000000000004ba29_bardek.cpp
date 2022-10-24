#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 0
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

pii E[1234];
int deg[213],e;
int Q[123];
set<pii> byla;
bool krawedz(int a,int b){
    assert(deg[a]<4);
    assert(deg[b]<4);
    if(byla.find(minmax(a,b))!=byla.end()) return 0;
    ++deg[a];
    ++deg[b];
    E[e++]=pii(a,b);
    byla.insert(minmax(a,b));
    return 1;
}
//t www=20;
bool K[22][22];
int n=10;
pii E2[121231];

void solve(){
    int L,U;
    scanf("%d%d",&L,&U);
    assert(L<=10 && 10<=U);
    printf("%d\n",n);
    fru(i,e) printf("%d %d\n",E[i].x+1,E[i].y+1);
    fflush(stdout);
    int nn;
    scanf("%d",&nn);
    fru(i,e) scanf("%d%d",&E2[i].x,&E2[i].y);
    fru(i,e){
        E2[i].x--;
        E2[i].y--;
    }

    fru(i,n) fru(j,n) K[i][j]=0;
    fru(i,e) {
        K[E[i].x][E[i].y]=1;
        K[E[i].y][E[i].x]=1;
    }
    int W[n];
    fru(i,n) W[i]=i;
///    fprintf(stderr,"szukam morfimu\n");
    int steps=1<<28;
    do{
        bool ok=1;
        fru(i,e) if(K[W[E2[i].x]][W[E2[i].y]]==0) {
            ok=0;
            break;
        }
        if(ok){
            fru(i,n) printf("%d ",W[i]+1); // ?
            fflush(stdout);
            return;
        }
    }
    while(next_permutation(W,W+n));
//    fprintf(stderr,"niezznalame :(\n");
    assert(0);
}

int main(){
    while(1){
        //      printf("zaczynamy\n");
        e=0;
    int W[n];
    fru(i,n) W[i]=i;
    random_shuffle(W,W+n);
    byla.clear();
    fru(i,n) deg[i]=0;
    for(int i=1;i<n;++i){
        int c;
        do{
            c=rand()%i;
        }
        while(deg[W[c]]==4);
        krawedz(W[i],W[c]);
    }
    //        DEB("tuataj\n");
    bool bad_luck=0;
    fru(_,n+1){
        int qs=0;
        fru(i,n) if(deg[i]<3) Q[qs++]=i;
        if(qs<=1)  fru(i,n) if(deg[i]==3) Q[qs++]=i;
        assert(qs>1);
        random_shuffle(Q,Q+qs); 
        int p=0;
        fru(i,qs) if(deg[Q[i]]<3){
            p=i;
            break;
        }
        swap(Q[0],Q[p]);
        if(krawedz(Q[0],Q[rand()%(qs-1)+1])==0) {
            _--;
            if(qs==2) {
                bad_luck=1;
                break;
            }
        }
        //            printf("degs: "); fru(i,n) printf("%d",deg[i]); puts("");            printf("qs = %d\n",qs);
        //(www--==0) return 0;
    }
    if(bad_luck) DEB("bad luck\n");
    else{
        DEB("luck!\n");
        int aut=0;
        sort(W,W+n);
        fru(i,n) fru(j,n) K[i][j]=0;
        fru(i,e) {
            K[E[i].x][E[i].y]=1;
            K[E[i].y][E[i].x]=1;
        }
        do{
            bool ok=1;
            fru(i,e) if(K[W[E[i].x]][W[E[i].y]]==0) {
                ok=0;
                break;
            }
            if(ok) ++aut;
        }
        while(next_permutation(W,W+n));
        /*printf("aut = %d\n",aut);
          fru(i,e) printf("%d %d\n",E[i].x,E[i].y);
          printf("----\n");*/
        if(aut==1) break;
    }
}
int o;
scanf("%d",&o);
fru(oo,o){
//    printf("Case #%d: ",oo+1);
    solve();
    int w;
  //  fflush(stdout);
//    if(oo+1!=o) scanf("%d",&w);
    //fpr
//    assert(w==-1);
//    exit(0);
}
return 0;
}
