#include <bits/stdc++.h>
using namespace std;
#define pb push_back 
#define REP(i,n) for(int i=0;i<(n);i++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

pll got(LL N) {
    N--;
    LL l = N / 2; 
    LL r = N - l;
    return make_pair(l, r);
}

int main(){
    int caseNumber;
    cin>>caseNumber;
    REP(caseN, caseNumber) {
        LL N, K;
        cin>>N>>K;
        map<LL, LL> m; m[N] = 1;
        LL final = 0;
        while (K) {
            LL now = m.rbegin()->first;
            LL v = m[now];
            m.erase(now);
            pll p = got(now);
            m[p.first] += v; m[p.second] += v;
            K -= v;
            if (K <= 0) {
                final = now;
                break;
            }
        }
        pll p = got(final);
        printf("Case #%d: %lld %lld\n", caseN + 1, p.second, p.first);
    }
    return 0;
}