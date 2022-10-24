#include <cstdio>
 #include <sstream>
 #include <vector>
 #include <string>
 #include <unordered_map>
 #include <set>
 using namespace std;
 
 const int MAXN = 110;
 const int MAXW = 3000;
 vector<int> s[MAXN];
 char buf[1000010];
 int mp[MAXW], tmp[MAXW];
 int N;
 unordered_map<string,int> wmp;
 
 int main() {
 	int T;
 	scanf("%d", &T);
 	for (int ca = 1 ; ca <= T ; ++ca) {
 		scanf("%d", &N);
 		gets(buf);
 		// mp.clear();
 		memset(mp, 0, sizeof(mp));
 		int word_cnt = 0;
 		wmp.clear();
 		for (int i = 0 ; i < N ; ++i) {
 			s[i].clear();
 			gets(buf);
 			istringstream iss(buf);
 			string word;
 			while (iss >> word) {
 				if (wmp.find(word) == wmp.end()) {
 					wmp[word] = word_cnt++;
 				}
 				s[i].push_back(wmp[word]);
 			}
 			for (int j = 0 ; j < s[i].size() ; ++j)
 				if (i == 0) {
 					mp[s[i][j]] |= 1;
 				} else if (i == 1) {
 					mp[s[i][j]] |= 2;
 				}
 		}
 		int oc = 0;
 		for (int i = 0 ; i < word_cnt ; ++i) 
 			if (mp[i] == 3) ++oc;
 
 		// for (auto itr= mp.begin() ; itr != mp.end() ; ++itr) {
 		// 	if (itr->second == 3) ++oc;
 		// }
 
 		vector<vector<int> > ss;
 		set<int> ws;
 		for (int i = 2 ; i < N ; ++i) {
 			vector<int> tmp;
 			for (int j = 0 ; j < s[i].size() ; ++j) {
 				if (mp[s[i][j]] == 3) continue;
 				tmp.push_back(s[i][j]);
 				ws.insert(s[i][j]);
 			}
 			ss.push_back(tmp);
 		}
 
 		int best = 1e9;
 			for (int mask = 0 ; mask < 1<<(N-2) ; ++mask) {
 				// tmp = mp;
 				// unordered_map<int, int> tmp;
 				memset(tmp, 0, sizeof(tmp));
 				for (int i = 0 ; i < N-2 ; ++i) {
 					int flg;
 					if (mask & (1<<i)) flg = 1;
 					else flg = 2;
 					for (int j = 0 ; j < ss[i].size() ; ++j) {
 						tmp[ss[i][j]] |= flg;
 						// ws.insert(ss[i][j]);
 					}
 				}
 				int cnt = 0;
 				for (auto item : ws) {
 					if (tmp[item] == 3)
 						++cnt;
 					else if ((tmp[item] | mp[item]) == 3)
 						++cnt;
 				}
 /*
 				for (auto itr = tmp.begin() ; itr != tmp.end() ; ++itr) {
 					if (itr->second == 3) {
 						// printf("%s\n", itr->first.c_str());
 						++cnt;
 					} else {
 						if ((itr->second | mp[itr->first]) == 3)
 							++cnt;
 					}
 					}
 */
 				
 				// printf("mask:%d cnt:%d\n", mask, cnt);
 				if (oc + cnt < best) best = oc + cnt;
 			}
 
 		printf("Case #%d: %d\n", ca, best);
 	}
 	return 0;
 }