#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

bool FindMatch(int i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (int j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

int BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  int ct = 0;
  for (int i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

vector<pair<int,int> > A[300];
int main () {
	int T;
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		int N;
		scanf("%d",&N);
		for (int i=0;i<=2*N;++i) A[i].clear();
		for (int i=1;i<=N;++i) for (int j=1;j<=N;++j) {
			int x;
			scanf("%d",&x);
			A[x + N].push_back(make_pair(i-1,j-1));
		}
		int cnt = 0;
		for (int i=0;i<=2*N;++i) {
			VVI w(N);
			for (int j=0;j<N;++j) for (int k=0;k<N;++k) w[j].push_back(0);
			for (int p=0;p<A[i].size();++p) w[A[i][p].first][A[i][p].second] = 1;
			vector<int> a, b;
			cnt += BipartiteMatching(w, a, b);
		}
		printf("Case #%d: %d\n",z, N * N - cnt);
	}
	return 0;
}
