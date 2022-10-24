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
 
 int enter(int cur, int tar) {
 	int t2 = 1<<tar;
 	if (cur & t2) {
 		return -1;
 	} else {
 		return cur | t2;
 	}
 }
 
 int out(int cur, int tar) {
 	int t2 = 1<<tar;
 	if (cur & t2) {
 		return cur ^ t2;
 	} else {
 		return -1;
 	}
 }
 
 int main(){
     int caseNumber;
     //scanf("%d", &caseNumber);
     cin>>caseNumber;
     REP(caseN, caseNumber) {
     	int N;
     	cin>>N;
     	vector<int> x, y;
     	map<int, int> k;
     	REP(i, N) {
     		string s; int l;
     		cin>>s>>l;
     		if (s[0] == 'E') x.pb(1); else x.pb(2);
     		if (l == 0) y.pb(-1); else {
     			if (k.count(l) == 0) {
     				int cnt = k.size();
     				k[l] = cnt;
     			}
     			y.pb(k[l]);
     		}
     	}
 
     	int tot = k.size();
     	set<int> s1, s2;
     	s1.clear(); s2.clear();
     	REP(i, (1<<N))
     		s1.insert(i);
     	REP(i, N) {
     		for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
     			int cur = *it;
     			if (cur == -1) continue;
     			if (x[i] == 1) {
     				int tar  = y[i];
     				if (tar == -1) {
     					REP(t2, N) {
     						s2.insert(enter(cur, t2));
     					}
     				} else {
     					s2.insert(enter(cur, tar));
     				}
     			} else {
     				int tar  = y[i];
     				if (tar == -1) {
     					REP(t2, N) {
     						s2.insert(out(cur, t2));
     					}
     				} else {
     					s2.insert(out(cur, tar));
     				}
     			// cout<<i<<' '<<cur<<' '<<out(cur, tar)<<' '<<s2.size()<<endl;
     			}
     		}
 
     		// for (set<int>::iterator i = s2.begin(); i != s2.end(); i++) {
     		// 	if (*i == -1) continue;
     		// 	cout<<"possible"<<*i<<' '<<__builtin_popcount(*i)<<endl;
     		// }
     		// for (set<int>::iterator i = s1.begin(); i != s1.end(); i++) {
     		// 	if (*i == -1) continue;
     		// 	cout<<"possiblexx"<<*i<<' '<<__builtin_popcount(*i)<<endl;
     		// }
     		s1 = s2;
     		s2.clear();
     	}
 
 // cout<<"tot"<<tot<<' '<<s1.size()<<endl;
     	if (s1.size() == 0) {
     	printf("Case #%d: CRIME TIME\n",caseN + 1);
 
     	} else {
     		int best = 1000;
     		for (set<int>::iterator i = s1.begin(); i != s1.end(); i++) {
     			if (*i == -1) continue;
     			// cout<<"possible"<<*i<<' '<<__builtin_popcount(*i)<<endl;
     			best = min(best, __builtin_popcount(*i));
     		}
     	if (best == 1000) 
     	printf("Case #%d: CRIME TIME\n",caseN + 1); else
     		printf("Case #%d: %d\n", caseN + 1, best);
 
     	}
     }
     return 0;
 }