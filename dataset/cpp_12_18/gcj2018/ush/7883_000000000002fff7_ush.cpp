
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;

double wis[110];
double hs[110];


int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase) {
    int n;
    double target;
    scanf("%d%lf", &n, &target);
    double total = 0;
    REP(i, n) {
      scanf("%lf%lf", &wis[i], &hs[i]);
      total += (wis[i] + hs[i]) * 2;
    }
    vector<pair<double,int> > es;
    es.push_back(make_pair(total, 0));
    es.push_back(make_pair(total, 1));
    double best = total;
    REP(i, n) {
      double dmin = min(wis[i], hs[i]) * 2;
      double dmax = sqrt(wis[i]*wis[i] + hs[i]*hs[i]) * 2;
      vector<pair<double,int> > nextEs;
      double lb = total;
      int level = 0;
      REP(ei, es.size()) {
        // cerr << "[" << es[ei].first << ", " << es[ei].second << "], ";
        double x = es[ei].first;
        if(es[ei].second == 0) { // begin
          if(level++ == 0) {
            lb = x;
          }
        } else { // end
          if(--level == 0) {
            double ub = x;
            nextEs.push_back(make_pair(lb, 0));
            nextEs.push_back(make_pair(ub, 1));
            // cerr << "(" << lb << ", " << ub << "), ";
            double nextLb = lb + dmin;
            double nextUb = ub + dmax;
            // cerr << "(" << nextLb << ", " << nextUb << "), ";
            nextEs.push_back(make_pair(nextLb, 0));
            nextEs.push_back(make_pair(nextUb, 1));
            if(nextUb < target) {
              best = max(best, nextUb);
            } else if(nextLb <= target) {
              best = target;
            } else {
              // over
            }
          }
        }
      }
      // cerr << endl;
      es.swap(nextEs);
      sort(es.begin(), es.end());
    }
    printf("Case #%d: %.10f\n", iCase+1, best);
  }
  return 0;
}
