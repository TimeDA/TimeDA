#ifdef _MSC_VER
 #define _CRT_SECURE_NO_DEPRECATE
 #pragma comment(linker, "/STACK:66777216")
 #else
 #pragma GCC optimize("O3")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
 #endif
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
 #include <ctime>
 #include <cstring>
 #include <functional>
 
 #include <thread>
 #include <mutex>
 #include <condition_variable>
 #include <atomic>
 #include <chrono>
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
 
 //int numThreads = 0;
 int HOD;
 const int _maxNumberOfThreads = 4;
 const int _maxNumberOfTests = 201;
 struct Answer {
 	int numberOfTest;
 	int ans;
 	vector<pair<pii, char>> r;
 	inline void output() {
 		printf("Case #%d: %d %d\n", numberOfTest + 1, ans, r.size());
 		rept(i, L(r)) {
 			printf("%c %d %d\n", r[i].y, r[i].x.x + 1, r[i].x.y + 1);
 		}
 	}
 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int n, m;
 	pair<pii, char> g[1002];
 	char tmp[3];
 	int lp[202], q[202];
 	bool used[202];
 	VI sm[202];
 	char fl[102][102], beg[102][102];
 	inline void readInput() {
 		scanf("%d%d", &n, &m);
 		if (m > 4 * n) {
 			cerr << "HER" << endl;
 			exit(0);
 		}
 		C(fl); C(beg);
 		rept(i, m) {
 			scanf("%s%d%d", tmp, &g[i].x.x, &g[i].x.y); --g[i].x.x; --g[i].x.y;
 			g[i].y = tmp[0];
 			fl[g[i].x.x][g[i].x.y] = g[i].y;
 			beg[g[i].x.x][g[i].x.y] = g[i].y;
 		}
 	}
 
 	bool dfs(int v) {
 		if (used[v]) return 0;
 		used[v] = 1;
 		rept(i, L(sm[v])) {
 			int w = sm[v][i];
 			if (q[w] == -1 || dfs(q[w])) {
 				lp[v] = w;
 				q[w] = v;
 				return 1;
 			}
 		}
 		return 0;
 	}
 	void pm(int n) {
 		memset(lp, -1, sizeof(lp));
 		memset(q, -1, sizeof(q));
 		int ans = 0, old = -1;
 		while (ans != old) {
 			old = ans;
 			memset(used, 0, n);
 			rept(i, n) {
 				if (lp[i] == -1 && dfs(i)) ++ans;
 			}
 		}
 	}
 
 	void run() {
 		rept(i, n) sm[i].clear();
 		rept(i, n) {
 			rept(j, n) {
 				bool ok = 1;
 				rept(z, m) {
 					if (g[z].y == 'o' || g[z].y == 'x') {
 						if (g[z].x.x == i || g[z].x.y == j) {
 							ok = 0;
 							break;
 						}
 					}
 				}
 				if (ok) {
 					sm[i].pb(j);
 				}
 			}
 		}
 
 		pm(n);
 		rept(i, n) {
 			if (lp[i] != -1) {
 				if (fl[i][lp[i]] == '+') {
 					fl[i][lp[i]] = 'o';
 				}
 				else {
 					fl[i][lp[i]] = 'x';
 				}
 			}
 		}
 
 		rept(i, 202) sm[i].clear();
 		rept(i, 2 * n - 1) {
 			rept(j, 2 * n - 1) {
 				if (i % 2 != (j + n - 1) % 2) continue;
 				int r = (i + (j - (n - 1))) / 2;
 				int c = (i - (j - (n - 1))) / 2;
 				if (r < 0 || r >= n || c < 0 || c >= n) continue;
 				bool ok = 1;
 				rept(z, m) {
 					if (g[z].y == 'o' || g[z].y == '+') {
 						if (g[z].x.x + g[z].x.y == i || g[z].x.x - g[z].x.y + n - 1 == j) {
 							ok = 0;
 							break;
 						}
 					}
 				}
 				if (ok) {
 					sm[i].pb(j);
 				}
 			}
 		}
 
 		pm(2 * n - 1);
 		rept(i, 2 * n - 1) {
 			if (lp[i] != -1) {
 				int r = (i + (lp[i] - (n - 1))) / 2;
 				int c = (i - (lp[i] - (n - 1))) / 2;
 				if (fl[r][c] == 'x') {
 					fl[r][c] = 'o';
 				}
 				else {
 					fl[r][c] = '+';
 				}
 			}
 		}
 
 		pAns->r.clear();
 		int s = 0;
 		rept(i, n) {
 			rept(j, n) {
 				if (fl[i][j] == 'o') s += 2; else
 				if (fl[i][j] == 'x' || fl[i][j] == '+') ++s;
 				if (fl[i][j] != beg[i][j]) {
 					pAns->r.pb(mp(mp(i, j), fl[i][j]));
 				}
 			}
 		}
 		pAns->ans = s;
 	}
 };
 
 Solver solvers[_maxNumberOfThreads];
 Answer answers[_maxNumberOfTests];
 
 thread threadPool[_maxNumberOfThreads];
 atomic<bool> threadsUsed[_maxNumberOfThreads];
 atomic<int> busyThreads;
 mutex Mutex;
 condition_variable CV;
 
 struct CheckIfThereIsAFreeThread {
 	const int totalNumberOfThreads;
 	CheckIfThereIsAFreeThread() : totalNumberOfThreads(0) {}
 	CheckIfThereIsAFreeThread(int numberOfThreads) : totalNumberOfThreads(numberOfThreads) {}
 	inline bool operator ()() const {
 		return busyThreads.load() < totalNumberOfThreads;
 	}
 };
 void solverWrapper(Solver *solver, int id) {
 	solver->run();
 	threadsUsed[id].store(false);
 	--busyThreads;
 	CV.notify_all();
 }
 chrono::high_resolution_clock::time_point _startTime = chrono::high_resolution_clock::now();
 inline double _getTime() {
 	auto cur = chrono::high_resolution_clock::now();
 	return 1e-6 * chrono::duration_cast<chrono::microseconds>(cur - _startTime).count();
 }
 void solveParallel(int numberOfTests, int maxThreads = _maxNumberOfThreads) {
 	for (int i = 0; i < maxThreads; ++i) {
 		threadsUsed[i].store(false);
 	}
 	busyThreads.store(0);
 	for (int currentTest = 0; currentTest < numberOfTests; ++currentTest) {
 		unique_lock<mutex> lock(Mutex);
 		CV.wait(lock, CheckIfThereIsAFreeThread(maxThreads));
 		int threadNumber = -1;
 		for (int i = 0; i < maxThreads; ++i) {
 			if (!threadsUsed[i].load()) {
 				threadNumber = i;
 				break;
 			}
 		}
 		if (threadPool[threadNumber].joinable()) {
 			threadPool[threadNumber].join();
 		}
 		threadsUsed[threadNumber].store(true);
 		++busyThreads;
 		cerr << "Test #" << currentTest + 1 << " was taken by thread #" << threadNumber << " at " << _getTime() << endl;
 		solvers[threadNumber]._numberOfThread = threadNumber;
 		solvers[threadNumber].readInput();
 		answers[currentTest].numberOfTest = currentTest;
 		solvers[threadNumber].pAns = &answers[currentTest];
 		threadPool[threadNumber] = thread(solverWrapper, &solvers[threadNumber], threadNumber);
 	}
 	for (int i = 0; i < maxThreads; ++i) {
 		if (threadPool[i].joinable()) {
 			threadPool[i].join();
 		}
 	}
 
 	for (int i = 0; i < numberOfTests; ++i) answers[i].output();
 	cerr << _getTime() << endl;
 }
 inline void solveSequential(int kolt) {
 	for (int hod = 0; hod < kolt; ++hod) {
 		cerr << hod << " " << _getTime() << endl;
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
 		cerr << hod << " " << _getTime() << endl;
 		HOD = hod;
 		answers[0].numberOfTest = 0;
 		solvers[0]._numberOfThread = 1;
 		solvers[0].pAns = &answers[0];
 		solvers[0].run();
 	}
 }
 int main() {
 	freopen("D-small-attempt1.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	char tmp[333];
 	int kolt = 0;
 	gets_s(tmp);
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