#include <bits/stdc++.h>

#define INF 1000000010
#define INFLL ((1LL<<62)-5)
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define OF(i,a,b) for (int (i) = (a)-1; (i) >= (b); --(i))
#define SZ(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/


const int MAXN = 105;

// return hash:
ll MOD = 1000000007;
ll mypow = 1333;

ll nextbase(ll cbase) {
    return (cbase * mypow) % MOD;
}


// returns if good.
int N;

vector<int> levels;
vector<pii> pairededges;
vector<int> sumlevels;
vector<int> mylevel;

vector<pii> allE;
vector<int> adjE[MAXN];

ll gethash(int c) {
    mylevel = vector<int>(N, -1);
    levels = vector<int>(N, 0);
    pairededges.clear();
    // bfs:
    queue<int> q;
    q.push(c);
    mylevel[c] = 0;
    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (int nxt : adjE[c]) {
            if (mylevel[nxt] == -1) {
                mylevel[nxt] = mylevel[c]+1;
                q.push(nxt);
            }
        }
    }
    sumlevels = vector<int>(N, 0);
    FO(i,0,N) {
        levels[mylevel[i]]++;
        for (int nxt : adjE[i]) {
            int a = mylevel[i];
            int b = mylevel[nxt];
            if (a > b) swap(a,b);
            pairededges.push_back({a,b});
            sumlevels[i] += mylevel[nxt];
            for (int nxtnxt : adjE[nxt]) {
                sumlevels[i] += mylevel[nxtnxt]*1000;
            }
        }
    }

    FO (i,0,N) if (mylevel[i] == -1) return -1;
    sort(pairededges.begin(), pairededges.end());
    sort(sumlevels.begin(), sumlevels.end());
    ll myhash = 0;
    ll mybase = 1;
    for (int a : levels) {
        myhash = (myhash + mybase*a) % MOD;
        mybase = nextbase(mybase);
    }
    for (auto pr : pairededges) {
        int a = pr.first;
        int b = pr.second;
        myhash = (myhash + mybase*a) % MOD;
        mybase = nextbase(mybase);
        myhash = (myhash + mybase*b) % MOD;
        mybase = nextbase(mybase);
    }
    for (auto c : sumlevels) {
        myhash = (myhash + mybase*c) % MOD;
        mybase = nextbase(mybase);
    }
    return myhash;
}

bool checkuniqueness() {
    set<ll> seenhashes;
    FO (i,0, N) {
        ll chash = gethash(i);
        if (chash == -1) return false;
        seenhashes.insert(chash);
    }
    return seenhashes.size() == N;
}

bool construct(int cN, int seed) {
    N = cN;
    srand(seed);
    FO(i,0,N) adjE[i].clear();
    allE.clear();
    vector<int> degs(N, 0);
    set<pii> edges;
    FO(i,0,2*N) {
        int tries = 0;
        for (; tries < 100; tries++) {
            int a = abs(rand())%N;
            int b = abs(rand())%N;
            if (degs[a] == 4 || degs[b] == 4) continue;
            if (a == b) continue;
            if (a > b) swap(a,b);
            pii edg {a,b};
            if (edges.find(edg) != edges.end()) continue;
            allE.push_back(edg);
            edges.insert(edg);
            degs[a]++;
            degs[b]++;
            break;
        }
        if (tries == 100) {
            return false;
        }
    }
    for (auto pr : allE) {
        adjE[pr.first].push_back(pr.second);
        adjE[pr.second].push_back(pr.first);
    }
    // check goodness of other things now:
    if (!checkuniqueness()) return false;
    return true;
}

int T;


map<int, int> seeds;
void precomp() {
    FO(N,10,51) {
        FO(cseed,0,10000000) {
            if (construct(N,cseed)) {
                seeds[N] = cseed;
                //fprintf (stderr, "%d: %d\n", N, cseed);
                break;
            }
        }
    }
}

struct soln {
    void solve() {
        int L, H;
        scanf("%d %d", &L, &H);
        N = L;
        assert(construct(N, seeds[N]));
        printf("%d\n", N);
        for (auto pr : allE) {
            printf ("%d %d\n", pr.first+1, pr.second+1);
        }
        fflush(stdout);
        map<ll, int> hashToId;
        FO(i,0,N) {
            hashToId[gethash(i)] = i;
            //fprintf (stderr, "%d: %lld\n", i, gethash(i));
            for (int a : levels) {
                //fprintf(stderr, "%d ", a);
            }
            for (int a: sumlevels) {
                //fprintf(stderr, "%d ", a);
            }
            //fprintf(stderr, "\n");
        }
        scanf("%d", &N);
        FO (i,0,N) adjE[i].clear();
        allE.clear();
        FO (i,0,2*N) {
            int a, b;
            scanf ("%d %d", &a, &b);
            adjE[a-1].push_back(b-1);
            adjE[b-1].push_back(a-1);
        }
        FO (i,0,N) assert(adjE[i].size() == 4);
        //fprintf(stderr, "HERE\n");
        vector<int> answers(N,0);
        FO (i,0,N) {
            ll chash = gethash(i);
            //fprintf (stderr, "%d: %lld\n", i, gethash(i));
            for (int a : levels) {
                //fprintf(stderr, "%d ", a);
            }
            for (int a: sumlevels) {
                //fprintf(stderr, "%d ", a);
            }
            //fprintf(stderr, "\n");
            answers[hashToId[chash]] = i+1;
        }
        FO (i,0,N) {
            printf ("%d ", answers[i]);
        }
        printf("\n");
        fflush(stdout);
    }
};

int main() {
    precomp();
    scanf("%d", &T);
    FO (_z,0,T) {
        //printf("Case #%d: ", _z+1);
        soln s;
        s.solve();
    }
    return 0;
}
