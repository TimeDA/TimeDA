#include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <set>
 
 typedef long long ll;
 
 using namespace std;
 
 typedef struct {
 	int u,v;
 } coord;
 
 // Greedy on the first and last line works
 vector<coord> matchPlusses(int n, vector<coord> used) {
 	bool rowUp[n], rowDown[n];
 	fill(rowUp, rowUp+n, false);
 	fill(rowDown, rowDown+n, false);
 
 	vector<coord> sol;
 	for (coord p: used) {
 		if (p.v - p.u >= 0)         rowUp  [p.v - p.u] = true;
 		if (p.v + p.u <  n)         rowUp  [p.v + p.u] = true;
 		if ((n-1) + p.v - p.u <  n) rowDown[(n-1) + p.v - p.u] = true;
 		if (p.v - p.u - (n-1) >= 0) rowDown[p.v - p.u - (n-1)] = true;
 	}
 
 	for (int i=0; i<n; i++) {
 		if (!rowUp[i]) {
 			coord p;
 			p.u = 0;
 			p.v = i;
 			sol.push_back(p);
 		}
 		if (i>0 and i<n-1 and !rowDown[i]) {
 			coord p;
 			p.u = n-1;
 			p.v = i;
 			sol.push_back(p);
 		}
 	}
 
 	return sol;
 }
 
 // Just check which lines and columns are not available and combine arbitrarily
 vector<coord> matchCrosses(int n, vector<coord> used) {
 	bool rows[n], cols[n];
 	vector<coord> sol;
 	fill(rows, rows+n, false);
 	fill(cols, cols+n, false);
 	for (coord p: used) {
 		rows[p.u] = true;
 		cols[p.v] = true;
 	}
 
 	int i=0, j=0;
 	while (i<n and j<n) {
 		while (i<n and rows[i]) ++i;
 		while (j<n and cols[j]) ++j;
 		if (i>=n or j>=n) break;
 
 		coord p;
 		p.u = i;
 		p.v = j;
 		sol.push_back(p);
 		++i; ++j;
 	}
 	return sol;
 }
 
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int n, m;
 		scanf("%d %d", &n, &m);
 
 		vector<coord> crosses, plusses;
 		coord p;
 		char c[10];
 
 		int score = 0;
 
 		char map[n][n+1];
 		bool changed[n][n];
 		for (int i=0; i<n; i++) {
 			fill(&map[i][0], &map[i][n], '.');
 			fill(&changed[i][0], &changed[i][n], false);
 			map[i][n] = '\0';
 		}
 
 		for (int i=0; i<m; i++) {
 			scanf("%s %d %d", c, &p.u, &p.v);
 			
 			--p.u; --p.v;
 			if (c[0] == '+' or c[0] == 'o') {
 				plusses.push_back(p);
 				++score;
 			}
 			if (c[0] == 'x' or c[0] == 'o') {
 				crosses.push_back(p);
 				++score;
 			}
 			map[p.u][p.v] = c[0];
 		}
 
 		for (coord p: matchCrosses(n, crosses)) {
 			++score;
 			map[p.u][p.v] = (map[p.u][p.v] == '.')?'x':'o';
 			changed[p.u][p.v] = true;
 		}
 
 		for (coord p: matchPlusses(n, plusses)) {
 			++score;
 			map[p.u][p.v] = (map[p.u][p.v] == '.')?'+':'o';
 			changed[p.u][p.v] = true;
 		}
 
 		vector<coord> listChanged;
 		for (int i=0; i<n; i++) {
 			for (int j=0; j<n; j++) {
 				if (!changed[i][j])
 					continue;
 				p.u = i;
 				p.v = j;
 				listChanged.push_back(p);
 			}
 		}
 
 		printf("Case #%d: %d %d\n", iC, score, (int) listChanged.size());
 		for (coord p: listChanged)
 			printf("%c %d %d\n", map[p.u][p.v], p.u+1, p.v+1);
 	}
 	return 0;
 }