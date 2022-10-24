#include <cstdio>
 #include <algorithm>
 #include <vector>
 
 typedef long long ll;
 
 using namespace std;
 
 bool explore (char ** river, int h, int w);
 
 int main() {
 	int iC=0, nC;
 	scanf("%d", &nC);
 	for (iC=1; iC<=nC; iC++) {
 		int w, h, b;
 		scanf("%d %d %d", &w, &h, &b);
 		char * river[h];
 		char _river[h*w];
 		for (int i=0; i<h; i++) {
 			river[i] = &_river[i*w];
 			fill(river[i], river[i]+w, ' ');
 		}
 
 		for (int i=0; i<b; i++) {
 			int x0, x1, y0, y1;
 			scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
 			for (int i=x0; i<=x1; i++)
 				for (int j=y0; j<=y1; j++)
 					river[j][i] = 'B';
 		}
 
 		int c = 0;
 		while (explore(river, h, w)) {
 			/*for (int i=0; i<h; i++) {
 				for (int j=0; j<w; j++)
 					printf("%c", river[i][j]);
 				printf("\n");
 			}*/
 			c++;
 		}
 
 		printf("Case #%d: %d\n", iC, c);
 	}
 	return 0;
 }
 
 bool explore (char ** river, int h, int w) {
 	for (int i=0; i<h; i++) {
 		for (int j=0; j<w; j++) {
 			if (river[i][j] != ' ')
 				continue;
 			if (i==0 or (river[i-1][j] != ' ' and river[i-1][j] != 'B' and river[i-1][j] != 'R')) {
 				river[i][j] = 'u';
 			}
 		}
 
 		for (int j=1; j<w; j++) {
 			if (river[i][j] == 'B' or river[i][j] == 'R')
 				continue;
 			if (river[i][j-1] != ' ' and river[i][j-1] != 'B' and river[i][j-1] != 'R') {
 				river[i][j] = 'l';
 			}
 		}
 
 		for (int j=w-2; j>=0; j--) {
 			if (river[i][j] == 'B' or river[i][j] == 'R')
 				continue;
 			if (river[i][j+1] != ' ' and river[i][j+1] != 'B' and river[i][j+1] != 'R') {
 				if (river[i][j] == ' ')
 					river[i][j] = 'r';
 			}
 		}
 	}
 
 	int j;
 	for (j=0; j<w; j++) {
 		if (river[h-1][j] == 'u' or river[h-1][j] == 'l' or river[h-1][j] == 'r')
 			break;
 	}
 
 	if (j == w)
 		return false;
 
 	int i=h-1;
 	while (i >= 0) {
 		char c = river[i][j];
 		river[i][j] = 'R';
 		if (c == 'u')
 			i--;
 		else if (c == 'l')
 			j--;
 		else if (c == 'r')
 			j++;
 	}
 
 	for (int i=0; i<h; i++)
 		for (int j=0; j<w; j++)
 			if (river[i][j] == 'u' or river[i][j] == 'l' or river[i][j] == 'r')
 				river[i][j] = ' ';
 
 	return true;
 }