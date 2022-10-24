#include<cstdio>
 
 using namespace std;
 
 char ch[5][5];
 
 bool check_won(char p)
 {
 	//row
 	for(int i=0;i<4;i++)
 	{
 		bool ok=true;
 		for(int j=0;j<4;j++)
 		{
 			if(ch[i][j]!='T'&&ch[i][j]!=p) ok=false;
 		}
 		if(ok) return true;
 	}
 	//col
 	for(int j=0;j<4;j++)
 	{
 		bool ok=true;
 		for(int i=0;i<4;i++)
 		{
 			if(ch[i][j]!='T'&&ch[i][j]!=p) ok=false;
 		}
 		if(ok) return true;
 	}
 	//diag
 	bool ok=true;
 	for(int i=0;i<4;i++) if(ch[i][i]!='T'&&ch[i][i]!=p) ok=false;
 	if(ok) return true;
 	ok=true;
 	for(int i=0;i<4;i++) if(ch[i][3-i]!='T'&&ch[i][3-i]!=p) ok=false;
 	if(ok) return true;
 	return false;
 }
 
 bool check_ended()
 {
 	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
 	{
 		if(ch[i][j]=='.') return false;
 	}
 	return true;
 }
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int datano=0;datano<T;datano++)
 	{
 		for(int i=0;i<4;i++) scanf("%s",&ch[i]);
 		printf("Case #%d: ",datano+1);
 		if(check_won('O')) printf("O won\n");
 		else if(check_won('X')) printf("X won\n");
 		else if(check_ended()) printf("Draw\n");
 		else printf("Game has not completed\n");
 	}
 	return 0;
 }
