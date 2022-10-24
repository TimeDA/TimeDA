#include <stdio.h>
 char m[5][5];
 bool win(char c)
 {
 	int i, j;
 	for(i=0; i<4; i++)
 	{
 		for(j=0; j<4 && (m[i][j]==c || m[i][j]=='T'); j++);
 		if(j==4) return 1;
 		for(j=0; j<4 && (m[j][i]==c || m[j][i]=='T'); j++);
 		if(j==4) return 1;
 	}
 	for(i=0; i<4 && (m[i][i]==c || m[i][i]=='T'); i++);
 	if(i==4) return 1;
 	for(i=0; i<4 && (m[i][3-i]==c || m[i][3-i]=='T'); i++);
 	if(i==4) return 1;
 	return 0;
 }
 int main()
 {
 	int t, ts, i, j, f;
 	for(scanf("%d", &ts), t=1; t<=ts; t++)
 	{
 		printf("Case #%d: ", t);
 		for(f=0, i=0; i<4; i++)
 			for(scanf("%s", m[i]), j=0; j<4; f|=m[i][j]=='.', j++);
 		if(win('X')) printf("X won\n");
 		else if(win('O')) printf("O won\n");
 		else if(f) printf("Game has not completed\n");
 		else printf("Draw\n");
 	}
 	return 0;
 }