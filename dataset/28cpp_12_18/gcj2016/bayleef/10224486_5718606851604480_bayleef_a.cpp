#define _USE_MATH_DEFINES
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include <iostream>
 #include <sstream>
 #include <vector>
 #include <algorithm>
 #include <set>
 #include <queue>
 #include <map>
 #include <string>
 #include <unordered_map>
 #include <unordered_set>
 
 using namespace std;
 
 int T,ts,n,r,p,s,i,u[300],j;
 string ans,str;
 
 string lexmin(string s)
 {
 	if(s.size()==1)
 		return s;
 	string s1=lexmin(s.substr(0,s.size()/2));
 	string s2=lexmin(s.substr(s.size()/2));
 	if(s1<s2)
 		return s1+s2;
 	else
 		return s2+s1;
 }
 
 string generate(string s,int n)
 {
 	int i;
 	while(n--)
 	{
 		string t="";
 		for(i=0;i<s.size();i++)
 			if(s[i]=='P')
 			{
 				t+='P';
 				t+='R';
 			}
 			else if(s[i]=='R')
 			{
 				t+='R';
 				t+='S';
 			}
 			else 
 			{
 				t+='S';
 				t+='P';
 			}
 		s=t;
 	}
 	return lexmin(s);
 }
 
 int main()
 {
 	freopen("a.in","r",stdin);
 	freopen("a.out","w",stdout);
 	scanf("%d",&T);
 	for(ts=1;ts<=T;ts++)
 	{
 		scanf("%d%d%d%d",&n,&r,&p,&s);
 		ans="Z";
 		string temp="PRS";
 		for(j=0;j<3;j++)
 		{
 			str=generate(temp.substr(j,1),n);
 			memset(u,0,sizeof(u));
 			for(i=0;i<str.size();i++)
 				u[str[i]]++;
 			if(u['P']==p && u['R']==r && u['S']==s)
 				ans=min(ans,str);
 		}
 		printf("Case #%d: %s\n",ts,ans=="Z"?"IMPOSSIBLE":ans.c_str());
 	}
 	return 0;
 }