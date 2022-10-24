#define _CRT_SECURE_NO_WARNINGS
 #pragma comment(linker, "/STACK:100000000")
 #include <stdio.h>
 #include <vector>
 #include <string>
 #include <set>
 #include <map>
 #include <queue>
 #include <algorithm>
 #include <string.h>
 #include <math.h>
 #include <fstream>
 #include <iostream>
 #include <ctime>
 #include <fstream>
 using namespace std;
 #define N 13
 string d[N][3];
 void build()
 {
 	d[0][0]="0";
 	d[0][1]="1";
 	d[0][2]="2";
 	for(int k=1; k<N; k++)
 	{
 		string s;
 		d[k][0]=d[k-1][0]+d[k-1][1];
 		s=d[k-1][1]+d[k-1][0];
 		if(s<d[k][0]) d[k][0]=s;
 		d[k][1]=d[k-1][2]+d[k-1][1];
 		s=d[k-1][1]+d[k-1][2];
 		if(s<d[k][1]) d[k][1]=s;
 		d[k][2]=d[k-1][0]+d[k-1][2];
 		s=d[k-1][2]+d[k-1][0];
 		if(s<d[k][2]) d[k][2]=s;
 	}
 }
 void sol()
 {
 	int n, r, p, s;
 	scanf("%d%d%d%d", &n, &r, &p, &s);
 	string w;
 	for(int i=0; i<3; i++)
 	{
 		string t=d[n][i];
 		int u[3]={0, 0, 0};
 		for(int j=0; j<t.size(); u[t[j]-'0']++, j++);
 		if(u[0]==p && u[1]==r && u[2]==s)
 		{
 			if(!w.size() || t<w) w=t;
 		}
 	}
 	if(!w.size()) printf("IMPOSSIBLE\n");
 	else
 	{
 		for(int i=0; i<w.size(); i++)
 			if(w[i]=='0') w[i]='P';
 			else if(w[i]=='1') w[i]='R';
 			else w[i]='S';
 		printf("%s\n", w.c_str());
 	}
 }
 int main()
 {
 	int ts;
 	scanf("%d", &ts);
 	build();
 	for(int t=1; t<=ts; t++)
 	{
 		printf("Case #%d: ", t);
 		sol();
 	}
 	return 0;
 }