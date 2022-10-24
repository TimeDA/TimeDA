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

struct soln {
    int N;
    int score;
    priority_queue<pii> pq;
    int threshold;
    soln() {
        score = 0;
    }
    int getscore(int c) {
        return (c*100)/N + ((c*100)%N * 2 >= N);
    }
    int getrem(int c) {
        c = (c*100)%N;
        if (c == threshold) return N;
        return (threshold-c+N)%N;
    }
    void solve() {
        int L;
        scanf("%d %d", &N, &L);
        threshold = N/2 + N%2;
        int sum = 0;
        FO(i,0,L) {
            int c;
            scanf("%d", &c);
            score += getscore(c);
            pq.push({-getrem(c),c});
            sum += c;
        }
        FO(i,0,N) {
            pq.push({-getrem(0),0});
        }
        FO(i,0,N-sum) {
            pii cp = pq.top();
            pq.pop();
            int c = cp.second;
            score -= getscore(c);
            c++;
            score += getscore(c);
            pq.push({-getrem(c),c});
        }
        printf("%d\n", score);
    }

};

int T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    scanf("%d", &T);
    FO (_z,0,T) {
        printf("Case #%d: ", _z+1);
        soln s;
        s.solve();
    }
    return 0;
}
