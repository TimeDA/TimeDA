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
 #include <functional>
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
 int HOD;
 const int _maxNumberOfThreads = 4;
 const int _maxNumberOfTests = 241;
 bool threadsUsed[_maxNumberOfThreads];
 HANDLE nowRunning[_maxNumberOfThreads];
 struct Answer {
 	int numberOfTest;
 	vector<string> res;
 	inline void output() {
 		printf("Case #%d:\n", numberOfTest + 1);
 		rept(i, L(res)) {
 			printf("%s\n", res[i].c_str());
 		}
 	}
 };
 
 const int di[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
 const int dj[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int n, m, k;
 	inline void readInput() {
 		scanf("%d%d%d", &n, &m, &k);
 	}
 	
 	bool used[11][11];
 	inline bool cool() {
 		int bi = -1, bj = -1;
 		rept(i, n) {
 			rept(j, m) {
 				if (pAns->res[i][j] == 'c') {
 					bi = i;
 					bj = j;
 					break;
 				}
 			}
 			if (bi != -1) break;
 		}
 		
 		int fc = 0;
 		rept(i, n) {
 			rept(j, m) {
 				if (pAns->res[i][j] != '*') ++fc;
 			}
 		}
 		C(used);
 		queue<pii> q;
 		used[bi][bj] = 1;
 		--fc;
 		bool ok = 1;
 		rept(i, 8) {
 			int ni = bi + di[i];
 			int nj = bj + dj[i];
 			if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
 			if (pAns->res[ni][nj] == '*') {
 				ok = 0;
 				break;
 			}
 		}
 		if (ok) q.push(mp(bi, bj));
 		while (!q.empty()) {
 			int ci = q.front().x;
 			int cj = q.front().y;
 			q.pop();
 			rept(i, 8) {
 				int ni = ci + di[i];
 				int nj = cj + dj[i];
 				if (ni < 0 || ni >= n || nj < 0 || nj >= m || used[ni][nj] || pAns->res[ni][nj] == '*') continue;
 				--fc;
 				used[ni][nj] = 1;
 				bool ok = 1;
 				rept(j, 8) {
 					int zi = ni + di[j];
 					int zj = nj + dj[j];
 					if (zi < 0 || zi >= n || zj < 0 || zj >= m) continue;
 					if (pAns->res[zi][zj] == '*') {
 						ok = 0;
 						break;
 					}
 				}
 				if (ok) q.push(mp(ni, nj));
 			}
 		}
 		if (!fc) return 1; else
 		return 0;
 	}
 	bool rec(int ci, int cj, int rmines, int rcells) {
 		if (rmines > rcells) return 0;
 		if (cj >= m) {
 			++ci;
 			cj = 0;
 		}
 		if (ci >= n) {
 			if (cool()) return 1; else
 			return 0;
 		}
 		if (pAns->res[ci][cj] == 'c') {
 			return rec(ci, cj + 1, rmines, rcells);
 		}
 		pAns->res[ci][cj] = '*';
 		if (rmines && rec(ci, cj + 1, rmines - 1, rcells - 1)) return 1;
 		pAns->res[ci][cj] = '.';
 		return rec(ci, cj + 1, rmines, rcells - 1);
 	}
 	bool check(int ci, int cj) {
 		pAns->res.clear();
 		rept(i, n) {
 			string s = "";
 			rept(j, m) {
 				s += '.';
 			}
 			pAns->res.pb(s);
 		}
 		pAns->res[ci][cj] = 'c';
 		return rec(0, 0, k, n * m - 1);
 	}
 
 	void run() {
 		// put an answer into pAns
 		pAns->res.clear();
 		rept(i, n) {
 			string s = "";
 			rept(j, m) {
 				s += '.';
 			}
 			pAns->res.pb(s);
 		}
 		if (!k) {
 			pAns->res[0][0] = 'c';
 			return;
 		}
 		
 		static bool u[51][51];
 		C(u);
 		rept(i, n) {
 			rept(j, m) {
 				if (u[i][j]) continue;
 				if (check(i, j)) return;
 				u[i][j] = u[n - i - 1][j] = u[i][m - j - 1] = u[n - i - 1][m - j - 1] = 1;
 			}
 		}
 		pAns->res.clear();
 		pAns->res.pb("Impossible");
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
 
 inline void solveParallel(int kolt, int maxThreads = 4) {
 	memset(threadsUsed, 0, sizeof(threadsUsed));
 	int p = 0;
 
 	while (p < kolt) {
 		if (numThreads < maxThreads) {
 			int num = 0;
 			for (; num < maxThreads && threadsUsed[num]; ++num);
 			if (num == maxThreads) continue;
 
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
 
 inline void stressTest() {
 	for (int hod = 0; hod < INF; ++hod) {
 		cerr << hod << " " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 		HOD = hod;
 		answers[0].numberOfTest = 0;
 		solvers[0]._numberOfThread = 1;
 		solvers[0].pAns = &answers[0];
 		solvers[0].run();
 	}
 }
 int main() {
 	freopen("C-small-attempt2.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	char tmp[333];
 	int kolt = 0;
 	gets(tmp);
 	sscanf(tmp, "%d", &kolt);
 	if (kolt > _maxNumberOfTests) {
 		cerr << "_maxNumberOfTests = " << _maxNumberOfTests << ", but kolt = " << kolt << endl;
 		int t = 0;
 		while (1) ++t;
 	}
 	solveParallel(kolt);
 	//solveSequential(kolt);
 	//stressTest();
 }
