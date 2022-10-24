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

int A[MAXN];
int M[103];

set<pii> S;
int n;
int rnd(int x){
    return (200*x+n)/(2*n);
}
vector<pii> P;
int R[201];
int gdzie[101];
#define popraw(a,b) a=min(a,b)
void solve(){
    int L;
    scanf("%d%d",&n,&L);
    fru(i,n) A[i]=0;
    fru(i,L) scanf("%d",&A[i]);
    fru(i,103) M[i]=-1;
    fru(x,n+1){
        int q=rnd(x);
//        printf("rnd(%d) = %d\n",x,q);
        if(M[q]==-1) M[q]=x;
    }
    int left=n;
    fru(i,L) left-=A[i];
    fru(i,101) if(M[i]!=-1) P.pb(pii(i,M[i]));
    fru(i,101) gdzie[i]=0;
    fru(i,P.size()) gdzie[P[i].x]=i;
//    printf("P:\n"); fru(i,P.size()) printf("%d %d\n",P[i].x,P[i].y);
    fru(i,200) R[i+1]=n+3;
    R[0]=0;
//    printf("lef t= %d\n",left);
    fru(i,L+left){
        int tu=rnd(A[i]);
//        printf("\n i=%d A = %d tu = %d\n",i,A[i],tu);
        for(int p=200;p>=0;--p) {
            if(R[p]<=left){
        //        printf("ma sens p = %d lda i = %d\n",p,i);
          //      printf("opprawiam R[%d] na %d\n",p+tu,R[p]);
                popraw(R[p+tu],R[p]);
                int e=gdzie[tu]+1;
      //          printf("e = %d, tu=%d\n",e,tu);
                while(e<P.size()){
    //                printf("A[i]= %d e = %d: %d %d\n",A[i],e,P[e].x,P[e].y);
                    int rr=R[p]+P[e].y-A[i];
                    if(rr>left) break;// ?
  //                  printf("probuje zrobic ruch (i=%d, M = %d) i laczeni bedzie rr = %d\n",P[e].x,P[e].y,rr);
//                    printf("poprawiam R[%d] na %d\n",p+P[e].x,rr);
                    popraw(R[p+P[e].x],rr);

                    e++;
                }
            }
            if(tu!=0) R[p]=n+1;
        }
    }
    for(int i=200;i>=0;--i) if(R[i]<=left){
        printf("%d\n",i);
        return;
    }
    assert(0);
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
