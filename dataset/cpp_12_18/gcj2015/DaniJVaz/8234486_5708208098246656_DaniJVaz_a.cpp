#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 bool checkSafe(char ** grid, int r, int c, int i, int j, int di, int dj) {
 	i += di;
 	j += dj;
 	while (i >= 0 and j>= 0 and i < r and j < c) {
 		if (grid[i][j] != '.')
 			return true;
 		i += di;
 		j += dj;
 	}
 	return false;
 }
 
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int r, c;
 		scanf("%d %d", &r, &c);
 
 		char _grid[r][c+1];
 		char *grid[r];
 		for (int i=0; i<r; i++) {
 			grid[i] = &_grid[i][0];
 			scanf("%s", grid[i]);
 		}
 
 		int count = 0;
 		for (int i=0; i<r; i++) {
 			for (int j=0; j<c; j++) {
 				int di = 0, dj = 0;
 
 				if (grid[i][j] == '.')
 					continue;
 
 				if (grid[i][j] == '<')
 					dj --;
 				else if (grid[i][j] == '>')
 					dj ++;
 				else if (grid[i][j] == '^')
 					di --;
 				else if (grid[i][j] == 'v')
 					di ++;
 
 				if (checkSafe(grid, r, c, i, j, di, dj))
 					continue;
 
 				if (checkSafe(grid, r, c, i, j, 0, -1) or
 					checkSafe(grid, r, c, i, j, 0, 1) or
 					checkSafe(grid, r, c, i, j, -1, 0) or
 					checkSafe(grid, r, c, i, j, 1, 0) )
 					count ++;
 				else
 					count = -1;
 
 				if (count == -1)
 					break;
 			}
 			if (count == -1)
 				break;
 		}
 
 		printf("Case #%d: ", iC);
 		if (count == -1)
 			printf("IMPOSSIBLE\n");
 		else
 			printf("%d\n", count);
 	}
 	return 0;
 }