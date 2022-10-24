#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 int searchNextColWithLetter(char ** matrix, int r, int c, int i, int j) {
 	if (j<0) j=0;
 	for (; j<c; j++)
 		if (matrix[i][j] != '?')
 			return j;
 	return c;
 }
 
 int searchNextLineWithLetter(char ** matrix, int r, int c, int i) {
 	if (i<0) i=0;
 	for (; i<r; i++)
 		if (searchNextColWithLetter(matrix, r, c, i, 0) != c)
 			return i;
 	return r;
 }
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int r, c;
 		scanf("%d %d", &r, &c);
 
 		char _matrix[r*(c+2)];
 		char * matrix[r];
 		for (int i=0; i<r; i++) {
 			matrix[i] = &_matrix[i*(c+2)];
 			scanf("%s", matrix[i]);
 		}
 
 		int i=-1;
 		while (1) {
 			int i2 = searchNextLineWithLetter(matrix, r, c, i+1);
 			// printf("%d\n", i2);
 			if (i2 == r) {
 				for (int l=i+1; l<r; l++)
 					for (int j=0; j<c; j++)
 						matrix[l][j] = matrix[l-1][j];
 				break;
 			}
 
 			int j = -1;
 			while (1) {
 				int j2 = searchNextColWithLetter(matrix, r, c, i2, j+1);
 				if (j2 == c) {
 					for (int k = i+1; k<=i2; k++)
 						for (int l = j+1; l<c; l++)
 							matrix[k][l] = matrix[k][l-1];
 					break;
 				}
 
 				char c = matrix[i2][j2];
 				// printf("%d %d %c\n", i2, j2, c);
 				for (int k = i+1; k<=i2; k++)
 					for (int l = j+1; l<=j2; l++)
 						matrix[k][l] = c;
 				j = j2;
 			}
 			i = i2;
 		}
 
 		printf("Case #%d:\n", iC);
 		for (int i=0; i<r; i++)
 			printf("%s\n", matrix[i]);
 	}
 	return 0;
 }