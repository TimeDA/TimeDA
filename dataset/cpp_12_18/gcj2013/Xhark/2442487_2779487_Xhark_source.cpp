#include <algorithm>
 #include <vector>
 #include <string>
 #include <map>
 
 using namespace std;
 
 #include <stdio.h>
 int A[2000], B[2000];
 int M[2000][2000];
 
 int sol[2000];
 
 void solve(vector<int> set, int s) {
 	if (set.size() == 0) return;
 	int pos = set[0];
 	vector<int> fset, sset;
 	for (int i=1;i<(int)set.size();i++) {
 		if (M[set[i]][pos]) fset.push_back(set[i]);
 		else sset.push_back(set[i]);
 	}
 	sol[pos] = s + (int)fset.size();
 	solve(fset, s);
 	solve(sset, sol[pos] + 1);
 }
 int main() {
 	freopen("C-small-attempt0.in","r",stdin);
 	freopen("C-small-attempt0.out","w",stdout);
 	int T;
 	scanf("%d",&T);
 	while (T-- > 0) {
 		int n;
 		scanf("%d",&n);
 		for (int i=0;i<n;i++) for (int j=0;j<n;j++) M[i][j] = 0;
 		for (int i=0;i<n;i++)scanf("%d",&A[i]);
 		for (int i=0;i<n;i++)scanf("%d",&B[i]);
 		for (int i=0;i<n;i++) {
 			for (int j=i+1;j<n;j++) {
 				if (A[i] >= A[j]) {
 					M[j][i] = 1;
 				}
 				if (B[i] <= B[j]) {
 					M[i][j] = 1;
 				}
 			}
 		}
 
 		for (int i=0;i<n;i++) {
 			for (int j=i-1;j>=0;j--) {
 				if (A[i] == A[j] + 1){ M[j][i] = 1; break;}
 			}
 		}
 		for (int i=0;i<n;i++) {
 			for (int j=i+1;j<n;j++) {
 				if (B[i] == B[j] + 1){ M[j][i] = 1;break;}
 			}
 		}
 
 		for (int i=0;i<n;i++) {
 			for (int j=0;j<n;j++) {
 				for (int k=0;k<n;k++) {
 					M[i][j] |= (M[i][k] & M[k][j]);
 				}
 			}
 		}
 
 		vector<int> set;
 		for (int i=0;i<n;i++) {
 			set.push_back(i);
 		}
 		solve(set, 1);
 		static int cs = 1;
 		printf("Case #%d:", cs ++);
 		for (int i=0;i<n;i++) printf(" %d", sol[i]);
 		printf("\n");
 	}
 	return 0;
 }