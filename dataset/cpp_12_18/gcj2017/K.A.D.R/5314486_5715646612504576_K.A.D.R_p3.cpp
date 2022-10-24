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
 
 template <int N>
 class TWOSAT {
 public:
 	inline void reset(int _n = N) {
 		n = _n;
 		rept(i, n) {
 			sm[i].clear();
 			rev[i].clear();
 		}
 	}
 	inline void addImplication(int a, int b) {
 		sm[a].pb(b);
 		rev[b].pb(a);
 		sm[b ^ 1].pb(a ^ 1);
 		rev[a ^ 1].pb(b ^ 1);
 	}
 	inline void addOrClause(int a, int b) {
 		addImplication(a ^ 1, b);
 		addImplication(b ^ 1, a);
 	}
 
 
 	bool solve() {
 		memset(used, 0, n);
 		k = 0;
 		for (int i = 0; i < n; ++i) {
 			if (!used[i]) {
 				dfs1(i);
 			}
 		}
 
 		memset(comp, -1, n * sizeof(int));
 		for (int i = 0, j = 0; i < n; ++i) {
 			int v = order[n - i - 1];
 			if (comp[v] == -1) {
 				dfs2(v, j++);
 			}
 		}
 
 		for (int i = 0; i < n; ++i) {
 			if (comp[i] == comp[i ^ 1]) {
 				// No solution
 				return false;
 			}
 		}
 		return true;
 	}
 
 	// Takes X, not 2X
 	inline bool testVal(int X) {
 		return comp[2 * X] > comp[2 * X + 1];
 	}
 private:
 	void dfs1(int v) {
 		used[v] = true;
 		for (size_t i = 0; i < sm[v].size(); ++i) {
 			int w = sm[v][i];
 			if (!used[w]) {
 				dfs1(w);
 			}
 		}
 		order[k++] = v;
 	}
 
 	void dfs2(int v, int cl) {
 		comp[v] = cl;
 		for (size_t i = 0; i < rev[v].size(); ++i) {
 			int w = rev[v][i];
 			if (comp[w] == -1) {
 				dfs2(w, cl);
 			}
 		}
 	}
 
 	vector<int> sm[N + 1], rev[N + 1];
 	bool used[N + 1];
 	int order[N + 1], comp[N + 1];
 	int n, k;
 };
 
 //int numThreads = 0;
 int HOD;
 const int _maxNumberOfThreads = 4;
 const int _maxNumberOfTests = 201;
 struct Answer {
 	int numberOfTest;
 	vector<string> ans;
 	inline void output() {
 		printf("Case #%d: ", numberOfTest + 1);
 		if (ans.empty()) {
 			printf("IMPOSSIBLE\n");
 			return;
 		}
 		printf("POSSIBLE\n");
 		rept(i, L(ans)) {
 			printf("%s\n", ans[i].c_str());
 		}
 	}
 };
 
 
 const int di[] = { 0, 1, 0, -1 };
 const int dj[] = { 1, 0, -1, 0 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int n, m;
 	char mas[55][55];
 	bool chor[55][55], cver[55][55];
 	TWOSAT<10011> q;
 	inline void readInput() {
 		scanf("%d%d", &n, &m);
 		rept(i, n) {
 			scanf("%s", mas[i]);
 		}
 	}
 	
 	bool used[55][55];
 	inline bool validate(int ci, int cj, int d, int tp) {
 		C(used);
 		used[ci][cj] = 1;
 		if (!tp) chor[ci][cj] = 1; else cver[ci][cj] = 1;
 		while (1) {
 			int ni = ci + di[d];
 			int nj = cj + dj[d];
 			if (ni < 0 || ni >= n || nj < 0 || nj >= m) return 1;
 			if (mas[ni][nj] == '#') return 1;
 			if (mas[ni][nj] == '-' || mas[ni][nj] == '|') return 0;
 			if (used[ni][nj]) return 1;
 			ci = ni; cj = nj;
 			used[ci][cj] = 1;
 			if (!tp) chor[ci][cj] = 1; else cver[ci][cj] = 1;
 		}
 
 		return 1;
 	}
 
 	inline bool can(int si, int sj) {
 		rept(i, 4) {
 			if (!di[i] && mas[si][sj] == '|') continue;
 			if (!dj[i] && mas[si][sj] == '-') continue;
 			if (!validate(si, sj, i, !di[i] ? 0 : 1)) return 0;
 		}
 		return 1;
 	}
 
 	void run() {
 		C(chor); C(cver);
 		// put an answer into pAns
 		int tot = n * m;
 		q.reset(tot * 4);
 
 		rept(i, n) {
 			rept(j, m) {
 				if (mas[i][j] != '-' && mas[i][j] != '|') continue;
 				mas[i][j] = '-';
 				can(i, j);
 				mas[i][j] = '|';
 				can(i, j);
 			}
 		}
 		rept(i, n) {
 			rept(j, m) {
 				if (mas[i][j] == '#') continue;
 				if (mas[i][j] == '.' || mas[i][j] == '-' || mas[i][j] == '|') {
 					q.addOrClause((i * m + j) * 2, (i * m + j + tot) * 2);
 					rept(z, 4) {
 						int ni = i + di[z];
 						int nj = j + dj[z];
 						if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
 						if (mas[ni][nj] == '#') continue;
 						if (di[z] == 0) {
 							q.addImplication((i * m + j) * 2, (ni * m + nj) * 2);
 							q.addImplication((i * m + j) * 2 + 1, (ni * m + nj) * 2 + 1);
 						}
 						if (dj[z] == 0) {
 							q.addImplication((i * m + j + tot) * 2, (ni * m + nj + tot) * 2);
 							q.addImplication((i * m + j + tot) * 2 + 1, (ni * m + nj + tot) * 2 + 1);
 						}
 					}
 					if (!chor[i][j]) {
 						q.addImplication((i * m + j) * 2, (i * m + j) * 2 + 1);
 					}
 					if (!cver[i][j]) {
 						q.addImplication((i * m + j + tot) * 2, (i * m + j + tot) * 2 + 1);
 					}
 				}
 				if (mas[i][j] == '-' || mas[i][j] == '|') {
 					mas[i][j] = '-';
 					bool hor = 0, ver = 0;
 					if (can(i, j)) hor = 1;
 					mas[i][j] = '|';
 					if (can(i, j)) ver = 1;
 					if (!hor && !ver) {
 						pAns->ans.clear();
 						return;
 					}
 
 					if (!hor) {
 						q.addImplication((i * m + j) * 2, (i * m + j) * 2 + 1);
 						q.addImplication((i * m + j + tot) * 2 + 1, (i * m + j + tot) * 2);
 					}
 					else if (!ver) {
 						q.addImplication((i * m + j + tot) * 2, (i * m + j + tot) * 2 + 1);
 						q.addImplication((i * m + j) * 2 + 1, (i * m + j) * 2);
 					}
 					else {
 						q.addOrClause((i * m + j) * 2, (i * m + j + tot) * 2);
 						q.addOrClause((i * m + j) * 2 + 1, (i * m + j + tot) * 2 + 1);
 					}
 				}
 			}
 		}
 
 		if (!q.solve()) {
 			pAns->ans.clear();
 			return;
 		}
 		pAns->ans.clear();
 		rept(i, n) {
 			rept(j, m) {
 				if (mas[i][j] != '-' && mas[i][j] != '|') continue;
 				if (q.testVal(i * m + j)) {
 					mas[i][j] = '-';
 				}
 				else {
 					mas[i][j] = '|';
 				}
 			}
 			pAns->ans.pb(mas[i]);
 		}
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
 	freopen("C-small-attempt1.in", "r", stdin);
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