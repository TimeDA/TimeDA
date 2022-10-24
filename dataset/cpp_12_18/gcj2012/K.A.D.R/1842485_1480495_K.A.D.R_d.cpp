#define _CRT_SECURE_NO_DEPRECATE
 #include <algorithm>
 #include <string>
 #include <set>
 #include <map>
 #include <vector>
 #include <queue>
 #include <iostream>
 #include <iterator>
 #include <cmath>
 #include <cstdio>
 #include <cstdlib>
 #include <sstream>
 #include <fstream>
 #include <process.h>
 #include <windows.h>
 #include <ctime>
 #include <cstring>
 #include <bitset>
 #pragma comment(linker, "/STACK:67108864")
 using namespace std;
 #define pb push_back
 #define ppb pop_back
 #define pi 3.1415926535897932384626433832795028841971
 #define mp make_pair
 #define x first
 #define y second
 #define pii pair<int,int>
 #define pdd pair<double,double>
 #define INF 1000000000
 #define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
 #define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
 #define all(c) (c).begin(), (c).end()
 #define SORT(c) sort(all(c))
 #define rep(i,n) FOR(i,1,(n))
 #define rept(i,n) FOR(i,0,(n)-1)
 #define L(s) (int)((s).size())
 #define C(a) memset((a),0,sizeof(a))
 #define VI vector <int>
 #define ll long long
 
 
 int numThreads = 0;
 const int _maxNumberOfThreads = 2;
 const int _maxNumberOfTests = 201;
 bool threadsUsed[_maxNumberOfThreads];
 HANDLE nowRunning[_maxNumberOfThreads];
 struct Answer {
 	int numberOfTest;
 	vector<pair<int, string> > ans;
 	inline void output() {
 		printf("Case #%d:\n", numberOfTest + 1);
 		rept(i, L(ans)) {
 			printf("%d: %d %s\n", i, ans[i].x, ans[i].y.c_str());
 		}
 	}
 };
 
 const int di[] = {0, 1, 0, -1};
 const int dj[] = {1, 0, -1, 0};
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 
 	char mas[62][62];
 	int n, m;
 	bool used[62][62], cur[62][62], tmp[62][62];
 	inline void readInput() {
 		scanf("%d%d", &n, &m);
 		rept(i, n) {
 			scanf("%s", mas[i]);
 		}
 	}
 
 	inline void move(int d) {
 		rept(i, n) memset(tmp[i], 0, m);
 		rept(i, n) {
 			rept(j, m) {
 				if (!cur[i][j]) continue;
 				int ni = i + di[d], nj = j + dj[d];
 				if (ni < 0 || ni >= n || nj < 0 || nj >= m || mas[ni][nj] == '#') {
 					tmp[i][j] = 1;
 					continue;
 				}
 				tmp[ni][nj] = 1;
 			}
 		}
 
 		rept(i, n) memmove(cur[i], tmp[i], m);
 	}
 	inline bool bad_down() {
 		rept(i, n - 1) {
 			rept(j, m) {
 				if (!cur[i][j]) continue;
 				if (mas[i + 1][j] == '#') continue;
 				if (!used[i + 1][j]) return 1;
 			}
 		}
 		return 0;
 	}
 	inline bool can_move(int row) {
 		rept(j, m) {
 			if (!cur[row][j]) continue;
 			if (mas[row + 1][j] != '#') return 1;
 		}
 		return 0;
 	}
 	pair<int, string> solve(int bi, int bj) {
 		queue<pii> q;
 		vector<pii> rc;
 		q.push(mp(bi, bj));
 		C(used);
 		used[bi][bj] = 1;
 		while (!q.empty()) {
 			int ci = q.front().x, cj = q.front().y;
 			q.pop();
 			rept(i, 4) {
 				if (i == 1) continue;
 				int ni = ci + di[i];
 				int nj = cj + dj[i];
 				if (ni < 0 || ni >= n || nj < 0 || nj >= m || used[ni][nj]) continue;
 				if (mas[ni][nj] == '#') continue;
 				q.push(mp(ni, nj));
 				used[ni][nj] = 1;
 			}
 		}
 
 		int cnt = 0;
 		rept(i, n) {
 			rept(j, m) {
 				cur[i][j] = used[i][j];
 				if (cur[i][j]) ++cnt;
 			}
 		}
 		
 		rept(i, bi) {
 			bool found = 0;
 			rept(j, m) {
 				if (cur[i][j]) {
 					found = 1;
 					break;
 				}
 			}
 			if (!found) continue;
 			
 			
 			while (1) {
 				bool good = 0;
 				rept(z, m) {
 					rept(j, m) move(0);
 					rept(j, m) move(2);
 					rept(j, z) move(0);
 					rept(j, m) {
 						if (!bad_down() && can_move(i)) {
 							move(1);
 							good = 1;
 						}
 						move(2);
 					}
 				}
 				if (!good) return mp(cnt, "Unlucky");
 				rept(j, m) move(0);
 				rept(j, m) move(2);
 				int c = 0;
 				rept(j, m) if (cur[i][j]) ++c;
 				if (!c) break;
 			}
 		}
 		return mp(cnt, "Lucky");
 	}
 	void run() {
 		// put an answer into pAns
 		pAns->ans.clear();
 		rept(h, 10) {
 			bool found = 0;
 			rept(i, n) {
 				rept(j, m) {
 					if (mas[i][j] == h + '0') {
 						pAns->ans.pb(solve(i, j));
 						found = 1;
 						break;
 					}
 				}
 			}
 			if (!found) break;
 		}
 	}
 };
 
 
 
 void run(void* _p) {
 	Solver* s = (Solver*)(_p);
 	s->run();
 	--numThreads;
 	threadsUsed[s->_numberOfThread] = false;
 	_endthread();
 }
 inline void execute(Solver* s) {
 	threadsUsed[s->_numberOfThread] = true;
 	++numThreads;
 	nowRunning[s->_numberOfThread] = (HANDLE)_beginthread(run, 0, s);
 }
 
 Solver solvers[_maxNumberOfThreads];
 Answer answers[_maxNumberOfTests];
 
 inline void solveParallel(int kolt, int maxThreads = 2) {
 	memset(threadsUsed, 0, sizeof(threadsUsed));
 	int p = 0;
 
 	while (p < kolt) {
 		if (numThreads < maxThreads) {
 			int num = 0;
 			for (;num < maxThreads && threadsUsed[num]; ++num);
 
 			cerr << "Test #" << p + 1 << " was taken by thread #" << num << " at " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 
 			solvers[num]._numberOfThread = num;
 			solvers[num].readInput();
 			answers[p].numberOfTest = p;
 			solvers[num].pAns = &answers[p++];
 			execute(&solvers[num]);
 		}
 
 		if (numThreads == maxThreads) WaitForMultipleObjects(numThreads, nowRunning, false, INFINITE);
 	}
 	while (numThreads) {
 		for (int i = 0; i < maxThreads; ++i) if (threadsUsed[i]) WaitForSingleObject(nowRunning[i], INFINITE);
 	}
 	
 	for (int i = 0; i < kolt; ++i) answers[i].output();
 
 	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 }
 
 inline void solveSequential(int kolt) {
 	for (int hod = 0; hod < kolt; ++hod) {
 		cerr << hod << " " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 		solvers[0]._numberOfThread = 1;
 		solvers[0].readInput();
 		answers[hod].numberOfTest = hod;
 		solvers[0].pAns = &answers[hod];
 		solvers[0].run();
 	}
 
 	for (int i = 0; i < kolt; ++i) answers[i].output();
 }
 int main() {
 	freopen("D-small-attempt0.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	char tmp[333];
 	int kolt = 0;
 	gets(tmp);
 	sscanf(tmp, "%d", &kolt);
 	solveParallel(kolt);
 	//solveSequential(kolt);
 }
