#include <cstdio>
 #include <string>
 #include <cstring>
 #include <vector>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <vector>
 
 using namespace std;
 
 vector<string> i2s;
 map<string, int> s2i;
 
 char line[1048576];
 
 vector<int> words[202];
 int main()
 {
 	int TT;
 	fgets(line, sizeof(line), stdin);
 	sscanf(line, "%d", &TT);
 	for (int testcase = 1; testcase <= TT; testcase++)
 	{
 		int n;
 		fgets(line, sizeof(line), stdin);
 		sscanf(line, "%d", &n);
 		for (int i = 0; i < n; i++) words[i].clear();
 		i2s.clear(); s2i.clear();
 		for (int i = 0; i < n; i++) {
 			fgets(line, sizeof(line), stdin);
 			auto token = strtok(line, " \n\r");
 			while (token != nullptr)
 			{
 				string cur(token);
 				if (s2i.count(cur) == 0) {
 					i2s.emplace_back(cur);
 					s2i[cur] = i2s.size() - 1;
 				}
 				int ind = s2i[cur];
 				words[i].push_back(ind);
 				token = strtok(nullptr, " \n\r");
 			}
 			sort(words[i].begin(), words[i].end());
 		}
 		int ans = i2s.size();
 		for (int bs = 1; bs < (1 << n); bs += 4)
 		{
 			vector<int> color(i2s.size());
 			for (int i = 0; i < n; i++) {
 				for (auto w : words[i]){
 					if (bs & (1 << i)){
 						color[w] |= 2;
 					}
 					else {
 						color[w] |= 1;
 					}
 				}
 			}
 			ans = min(ans, count(color.begin(), color.end(), 3));
 		}
 		printf("Case #%d: %d\n", testcase, ans);
 	}
 	return 0;
 }