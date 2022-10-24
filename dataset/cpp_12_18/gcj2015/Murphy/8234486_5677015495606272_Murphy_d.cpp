#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <cmath>
 #include <algorithm>
 #include <cassert>
 #include <set>
 #include <map>
 #include <queue>
 #include <iostream>
 #include <fstream>
 using namespace std;
 #define pb push_back 
 #define REP(i,n) for(int i=0;i<(n);i++ )
 typedef long long LL;
 typedef pair<int, int> pii;
 int mod = 1000000007;
 
 int R, C;
 vector<string> p;
 int res = 0;
 
 void gao(string s, int d) {
 	if (d == C) {p.pb(s); return;}
 	REP(i, 3) {
 		s[d] = '1' + i;
 		gao(s, d + 1);
 	}
 }
 
 int dp[10][1000][256];
 vector<string> ans[10][1000][256];
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	memset(dp, 0, sizeof dp);
     	REP(i, 10) REP(j, 1000) REP (k, 256) ans[i][j][k].clear();
     	cin>>R>>C;
     	p.clear(); string s(C, ' ');
     	gao(s, 0);
     	res = 0;
     	// cerr<<p.size()<<endl;
     	REP(i, p.size()) {
     		string s = p[i];
     		int mask = 0;
     		REP(j, C) {
     			int need = s[j] - '0';
     			int have = s[(j + 1) % C] == s[j];
     			have += s[(j + C - 1) % C] == s[j];
     			if (have > need || have < need - 1) {
     				goto fail;
     			}
     			mask <<= 1;
     			mask |= (have == need - 1);
     		}
     		// cerr<<"first"<<i<<' '<<s<<' '<<mask<<endl;
     		dp[1][i][mask] = 1;
     		ans[1][i][mask].pb(p[i]);
     		fail:;
     	}
     	// cout<<dp[1][13][26]<<endl;
     	REP(i, R) {
     		if (i)
     		REP(id, p.size()) {
     			REP(msk, 1 << C) {
     				// if (i == 1 && id == 13) {
     				// 	cout<<"xxxxxsssssss"<<msk<<endl;
     				// }
     				if (dp[i][id][msk] == 0) continue;
     	   //          cout<<'x'<<dp[1][40][0]<<' '<<p.size()<<' '<<(1<<C)<<endl;
     				// cout<<i<<' '<<id<<' '<<msk<<' '<<p[id]<<' '<<dp[i][id][msk]<<endl;
     				REP(nxt, p.size()) { //continue;
 			    		string spre = p[id], s = p[nxt];
 			    		int msk2 = 0, mm = 0;
 			    		REP(j, C) {
 			    			int need = s[j] - '0';
 			    			int have = s[(j + 1) % C] == s[j];
 			    			have += s[(j + C - 1) % C] == s[j];
 			    			int mutal = s[j] == spre[j];
 			    			// if (id == 80 && nxt == 80) {
 			    			// 	cout<<p[id]<<' '<<p[nxt]<<' '<<j<<' '<<need<<' '<<have<<' '<<mutal<<endl;
 			    			// }
 			    			mm = 2 * mm + mutal;
 			    			// if (mutal ^ !!(msk & (1 <<j))) {
 			    			// 	// cerr<<"bad1";
 			    			// 		goto fail2;
 
 			    			// }
 			    			have += mutal;
 			    			if (have > need || have < need - 1) {
 			    				// cerr<<"bad2";
 			    				goto fail2;
 			    			}
 			    			msk2 <<= 1;
 			    			msk2 |= (have == need - 1);
 			    		}
 			    		// cerr<<"second "<<p[id]<<"==>"<<p[nxt]<<' '<<msk<<' '<<msk2<<'@'<<i<<endl;
     					// cout<<"second"<<i<<' '<<nxt<<' '<<msk2<<' '<<p[nxt]<<' '<<dp[i][id][msk]<<
     					// ' '<<dp[i + 1][nxt][msk2]<<endl;
     					if (mm != msk) goto fail2;
 			    		dp[i + 1][nxt][msk2] += dp[i][id][msk];
 			    		dp[i + 1][nxt][msk2] %= mod;
 			    		REP(b, ans[i][id][msk].size()) {
 			    			ans[i+1][nxt][msk2].pb(ans[i][id][msk][b] + p[nxt]);
 			    		}
 			    		fail2:;
 
     				}
     			}    			
     		}
     	}
     	set<string> st;
     	REP(i, p.size()) {
     		// res += dp[R][i][0];
     		if (dp[R][i][0]) {
     			assert(ans[R][i][0].size() == dp[R][i][0]);
     			REP(b, ans[R][i][0].size()) {
     				string xx = "";
 	    			string x = ans[R][i][0][b];
 	    			REP(r, C) {
 	    				string cur = "";
 	    				REP(i, R) {
 	    					REP(j, C) {
 	    						int jj = j + r;
 	    						jj %= C;
 	    						cur += x[i * C + jj];
 	    					}
 	    				}
 	    				if (xx == "" || xx > cur) {
 	    					xx = cur;
 	    				}
 	    			}
 	    			// xx = x;
 	    			st.insert(xx);
 	    		}
 	    		// cerr<<xx<<endl;
     		}
     		// 		cout<<i<<' '<<dp[R][i][0]<<' '<<p[i]<<endl;
     		// res %= mod;
     	}
     	res = st.size();
     	printf("Case #%d: %d\n", caseN + 1, res);
     }
     return 0;
 }