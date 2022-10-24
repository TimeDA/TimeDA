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

struct node{
    unordered_map<char,node*> M;
    int ile;
    node()  {
        DEB("creating %d\n",this);
        M.clear();
        ile=0;
    }
    ~node(){
        DEB("deleting %d\n",this);
        tr(it,M) delete it->second;
    }
    void add(int q,char *S)  {
        DEB("jestem w %s na pozycji %d\n",S,q);
        ++ile;
        if(S[q]){
            if(M.find(S[q])==M.end()) M[S[q]]=new node();
            M[S[q]]->add(q+1,S);
        }
    }
};

char S[20];
set<int> LIT[20];
char ANS[20];

void solve(){
    int n,L;
    scanf("%d%d",&n,&L);
    node* A = new node();
    fru(i,20) LIT[i].clear();
    fru(i,n){
        scanf(" %s",S);
        A->add(0,S);
        fru(j,L) LIT[j].insert(S[j]);
    }
    node *B=A;
    ANS[L]=0;
    fru(i,L){
        char kto='.';
        int ile=n+3;
        tr(it,LIT[i]){
            char c=*it;
            if(B->M.find(c)==B->M.end()) {
                ANS[i]=c;
                while(++i<L)
                    ANS[i]=*(LIT[i].begin());
                printf("%s\n",ANS);
                return;
            }
            if(B->M[c]->ile<ile){
                kto=c;
                ile=B->M[c]->ile;
            }
        }
        assert(kto!='.');
        ANS[i]=kto;
        B=B->M[kto];
    }
    printf("-\n");
    delete A;
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
