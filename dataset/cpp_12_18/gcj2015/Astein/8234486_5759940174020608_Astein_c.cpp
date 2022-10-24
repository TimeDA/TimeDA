#include <cstdio>
 #include <vector>
 #include <algorithm>
 #include <set>
 #include <map>
 #include <cstring>
 
 using namespace std;
 
 int n;
 char s[11005], word[15];
 
 int a[105][105];
 vector<string> words[201];
 map<string, int> all_words;
 int cnts[2][11005];
 int ret;
 int minret;
 
 void backtr(int k, int v)
 {
 	if (k == n)
 	{
 		if (minret > v) minret = v;
 		return;
 	}
 	for (int p = 0; p < 2; ++p)
 	{
 		int pp = 0;
 		for (auto i : words[k])
 		{
 			if (cnts[p][all_words[i]] == 0 && cnts[1 - p][all_words[i]] != 0) pp++;
 			cnts[p][all_words[i]]++;
 		}
 		backtr(k + 1, v + pp);
 		for (auto i : words[k])
 		{
 			cnts[p][all_words[i]]--;
 		}
 	}
 }
 
 int main()
 {
 	freopen("c.in", "r", stdin);
 	freopen("c.out", "w", stdout);
 	int T;
 
 	fgets(s, 100, stdin);
 	sscanf(s, "%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		memset(cnts, 0, sizeof(cnts));
 
 		int N;
 		fgets(s, 100, stdin);
 		sscanf(s, "%d", &N);
 		n = N;
 		
 		set<string> sset;
 		for (int i = 0; i < N; ++i)
 		{
 			words[i].clear();
 
 			fgets(s, 11005, stdin);
 			int slen = strlen(s);
 
 			set<string> cset;
 			for (int j = 0; j < slen;)
 			{
 				if (sscanf(s + j, " %s", word) == 0) break;
 				sset.insert(word);
 				cset.insert(word);
 				j = j + strlen(word) + 1;
 			}
 			for (auto word : cset)
 				words[i].push_back(word);
 		}
 		int idx = 0;
 		for (auto it : sset)
 			all_words[it] = idx++;
 
 		minret = 987987;
 		ret = 0;
 		for (auto i : words[0]) cnts[0][all_words[i]]++;
 		for (auto i : words[1])
 		{
 			if (cnts[0][all_words[i]] == 1) ret++;
 			cnts[1][all_words[i]]++;
 		}
 
 		backtr(2, ret);
 		printf("Case #%d: %d\n", cn, minret);
 	}
 	return 0;
 }