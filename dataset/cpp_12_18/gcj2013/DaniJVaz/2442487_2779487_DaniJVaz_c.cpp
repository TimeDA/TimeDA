#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <bitset>
 
 typedef long long ll;
 
 using namespace std;
 
 vector<int> topoSort; // global vector to store the toposort in reverse order
 int dfs_num [5000];
 
 void dfs2(int u, vector<int> * AdjList) { // change function name to differentiate with original dfs
 	dfs_num[u] = 1;
 	for (int j = 0; j < (int)AdjList[u].size(); j++) {
 		int v = AdjList[u][j];
 		if (dfs_num[v] == 0)
 			dfs2(v, AdjList);
 	}
 	topoSort.push_back(u); 
 } // that is, this is the only change
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n;
 		scanf("%d", &n);
 
 		int A[n], B[n];
 		for (int i=0; i<n; i++) scanf("%d", A+i);
 		for (int i=0; i<n; i++) scanf("%d", B+i);
 
 		vector<int> outbound[n], inbound[n];
 		int lastFound[n+1];
 
 		fill(lastFound, lastFound+n+1, -1);
 		for (int i=0; i<n; i++) {
 			if (A[i] > 1 and lastFound[A[i]-1] != -1) {
 				outbound[i].push_back(lastFound[A[i]-1]);
 				inbound[lastFound[A[i]-1]].push_back(i);
 			}
 
 			if (lastFound[A[i]] != -1) {
 				inbound[i].push_back(lastFound[A[i]]);
 				outbound[lastFound[A[i]]].push_back(i);
 			}
 			lastFound[A[i]] = i;
 		}
 
 		fill(lastFound, lastFound+n, -1);
 		for (int i=n-1; i>=0; i--) {
 			if (B[i] > 1 and lastFound[B[i]-1] != -1) {
 				outbound[i].push_back(lastFound[B[i]-1]);
 				inbound[lastFound[B[i]-1]].push_back(i);
 			}
 			if (lastFound[B[i]] != -1) {
 				inbound[i].push_back(lastFound[B[i]]);
 				outbound[lastFound[B[i]]].push_back(i);
 			}
 			lastFound[B[i]] = i;
 		}
 
 		fill(dfs_num, dfs_num + n, 0);
 		topoSort.resize(0);
 		for (int i=0; i<n; i++) {
 			if (!dfs_num[i])
 				dfs2(i, outbound);
 		}
 		for (int i=0; i<n; i++)
 			dfs_num[topoSort[i]] = i+1;
 
 		printf("Case #%d:", iC);
 		for (int i=0; i<n; i++)
 			printf(" %d", dfs_num[i]);
 		printf("\n");
 	}
 	return 0;
 }