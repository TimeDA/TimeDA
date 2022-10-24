#include <iostream>
 #include <algorithm>
 #include <cmath>
 #include <cstring>
 #include <cstdlib>
 #include <string>
 #include <vector>
 #include <cstdio>
 #include <cassert>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 
 #ifdef WIN32
 #define LLD "%I64d"
 #else
 #define LLD "%lld"
 #endif
 
 const int maxn = 4;
 const int maxm = 8;
 const int maxlen = 11;
 
 struct tnode
 {
 	int id;
 	tnode *next[26];
 	bool used[maxn];
 	
 	tnode()
 	{
 		for (int i = 0; i < 26; i++) next[i] = NULL;
 		id = -1;
 	}
 };
 
 typedef tnode* pnode;
 
 char s[maxm][maxlen];
 int c[maxm];
 int n, m;
 int answer, kvans, curans;
 pnode root;
 
 void add(pnode cur, char *s, int id)
 {
 	if (*s == '\0')
 	{
 		cur->id = id;
 		return;
 	}
 	if (cur->next[*s - 'A'] == NULL)
 	{
 		cur->next[*s - 'A'] = new tnode();
 	}
 	add(cur->next[*s - 'A'], s + 1, id);
 }
 
 void calcans(pnode cur)
 {
 	for (int i = 0; i < n; i++) cur->used[i] = false;
 	if (cur->id != -1)
 	{
 		cur->used[c[cur->id]] = true;
 	}
 	for (int i = 0; i < 26; i++) if (cur->next[i] != NULL)
 	{
 		calcans(cur->next[i]);
 		for (int j = 0; j < n; j++) cur->used[j] |= cur->next[i]->used[j];
 	}
 	for (int i = 0; i < n; i++) curans += cur->used[i];
 }
 
 void go(int cur)
 {
 	if (cur == m)
 	{
 		curans = 0;
 		calcans(root);
 		if (curans > answer)
 		{
 			answer = curans;
 			kvans = 0;
 		}
 		if (curans == answer) kvans++;
 		return;
 	}
 	for (int i = 0; i < n; i++)
 	{
 		c[cur] = i;
 		go(cur + 1);
 	}
 }
 
 int main()
 {
 	int NT = 0;
 	scanf("%d", &NT);
 	for (int T = 1; T <= NT; T++)
 	{
 		printf("Case #%d:", T);
 		
 		scanf("%d%d", &m, &n);
 		for (int i = 0; i < m; i++) scanf("%s", s[i]);
 // 		deleteall(root);
 		root = new tnode();
 		for (int i = 0; i < m; i++) add(root, s[i], i);
 		answer = 0;
 		kvans = 0;
 		go(0);
 		
 		printf(" %d %d\n", answer, kvans);
 		
 		fprintf(stderr, "%d/%d cases done!\n", T, NT);
 	}
 	return 0;
 }
