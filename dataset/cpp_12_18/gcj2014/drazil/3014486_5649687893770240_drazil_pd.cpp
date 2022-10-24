#include <iostream>
 #include <string>
 #include <cstdio>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cstring>
 #include <stack>
 #include <queue>
 
 using namespace std ;
 
 string str[10] ;
 
 int g ;
 int gid[10] ;
 int n ;
 int ans, cnt ;
 
 struct trie
 {
 	trie *next[30] ;
 } ;
 
 void buildtrie(const char *str, trie *t)
 {
 	if(*str=='\0')
 		return ;
 	if(t->next[*str-'A']==NULL)
 	{
 		t->next[*str-'A'] = new trie ;
 		memset(t->next[*str-'A']->next,0,sizeof(trie *)*30) ;
 	}
 	buildtrie(str+1,t->next[*str-'A']) ;
 }
 
 int cnttrie(trie *t)
 {
 	int ans = 1 ;
 	
 	for(int i=0;i<26;i++)
 		if(t->next[i]!=NULL)
 			ans += cnttrie(t->next[i]) ;
 	delete t ;
 	return ans ;
 }
 
 int build(int bgid)
 {
 	trie *t = new trie ;
 	memset(t->next,0,sizeof(trie *)*30) ;
 	for(int i=0;i<n;i++)
 		if(gid[i]==bgid)
 		{
 			buildtrie(str[i].c_str(),t) ;
 		}
 	return cnttrie(t) ;
 }
 
 void gotest()
 {
 	int myans = 0 ;
 	for(int i=0;i<g;i++)
 		myans += build(i) ;
 	if(myans>ans)
 	{
 		ans = myans ;
 		cnt = 1 ;
 	}
 	else if(myans==ans)
 		cnt++ ;
 }
 
 void go(int id)
 {
 	if(id==n)
 	{
 		int fit[10] ;
 		for(int i=0;i<g;i++)
 			fit[i] = 0 ;
 		for(int i=0;i<n;i++)
 			fit[gid[i]] = 1 ;
 		for(int i=0;i<g;i++)
 			if(fit[i]==0)
 				return ;
 		gotest() ;
 	}
 	else
 	{
 		for(int i=0;i<g;i++)
 		{
 			gid[id] = i ;
 			go(id+1) ;
 		}
 	}
 }
 
 int main(void)
 {
 	int tc ;
 	cin >> tc ;
 	
 	for(int c=1;c<=tc;c++)
 	{
 		cin >> n ;
 		cin >> g ;
 		for(int i=0;i<n;i++)
 			cin >> str[i] ;
 		
 		ans = 0 ;
 		cnt = 0 ;
 		
 		go(0) ;	
 		
 		printf("Case #%d: %d %d\n",c,ans,cnt) ;
 	}
 	
 	return 0 ;
 }
