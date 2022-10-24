#ifdef _MSC_VER
 #define _CRT_SECURE_NO_DEPRECATE
 #pragma comment(linker, "/STACK:66777216")
 #define GETS gets_s
 #else
 #pragma GCC optimize("O3")
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
 #define GETS gets
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
 	VI ans;
 	int numberOfTest;
 	inline void output() {
 		printf("Case #%d: ", numberOfTest + 1);
 		if (ans.empty()) {
 			printf("IMPOSSIBLE\n");
 			return;
 		}
 		rept(i, L(ans)) {
 			if (i) printf(" ");
 			printf("%d", ans[i]);
 		}
 		printf("\n");
 	}
 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int n, m;
 	VI sm[1002];
 	VI rsm[1002];
 	int cc[1002][1002];
 	int fl[1002][1002];
 	int path[1002];
 	int k;
 	bool used[1002];
 	vector<pii> ee, oe;
 	inline void readInput() {
 		scanf("%d%d", &n, &m);
 		rept(i, n) sm[i].clear(), rsm[i].clear();
 		memset(cc, -1, sizeof(cc));
 		ee.clear();
 		rept(i, m) {
 			int a, b;
 			scanf("%d%d", &a, &b); --a; --b;
 			sm[a].pb(b);
 			rsm[b].pb(a);
 			cc[a][b] = i;
 			ee.pb(mp(a, b));
 		}
 		oe = ee;
 		rept(i, n) {
 		//	random_shuffle(all(sm[i]));
 		}
 		//random_shuffle(all(ee));
 	}
 
 	bool dfs(int v, int t, int bn) {
 		if (v == t) {
 			path[k++] = v;
 			return 1;
 		}
 		if (used[v]) return 0;
 		used[v] = 1;
 		path[k++] = v;
 		rept(i, L(sm[v])) {
 			int w = sm[v][i];
 			if (cc[v][w] == bn) continue;
 			if (dfs(w, t, bn)) return 1;
 		}
 		rept(i, L(rsm[v])) {
 			int w = rsm[v][i];
 			if (cc[w][v] == bn) continue;
 			if (dfs(w, t, bn)) return 1;
 		}
 
 		--k;
 		return 0;
 	}
 	void run() {
 		C(fl);
 		// put an answer into pAns
 		rept(i, L(ee)) {
 			int a = ee[i].x, b = ee[i].y;
 			if (fl[a][b] != 0 || fl[b][a] != 0) continue;
 			k = 0;
 			C(used);
 			if (!dfs(b, a, cc[a][b])) {
 				pAns->ans.clear();
 				return;
 			}
 			VI b1, b2;
 			b1.pb(0); b2.pb(0);
 			rept(j, k - 1) {
 				int v1 = path[j], v2 = path[j + 1];
 				int val = 0;
 				if (cc[v1][v2] != -1) {
 					val = fl[v1][v2];
 				}
 				else {
 					val = -fl[v2][v1];
 				}
 				if (val < 0) b1.pb(-val); else b2.pb(val);
 			}
 			SORT(b1); SORT(b2);
 			b1.resize(unique(all(b1)) - b1.begin());
 			b2.resize(unique(all(b2)) - b2.begin());
 
 			int p1 = 0, p2 = 0;
 			int found = 0;
 			rep(j, INF) {
 				while (p1 < L(b1) && b1[p1] < j) ++p1;
 				while (p2 < L(b2) && b2[p2] < j) ++p2;
 
 				if (p1 < L(b1) && b1[p1] == j && p2 < L(b2) && b2[p2] == j) continue;
 				found = j;
 				break;
 			}
 
 			if (p1 < L(b1) && b1[p1] == found) {
 				found = -found;
 			}
 
 			rept(j, k - 1) {
 				int v1 = path[j], v2 = path[j + 1];
 				if (cc[v1][v2] != -1) {
 					fl[v1][v2] += found;
 				}
 				else {
 					fl[v2][v1] -= found;
 				}
 			}
 			fl[a][b] += found;
 		}
 		rept(i, L(ee)) {
 			if (fl[ee[i].x][ee[i].y] == 0 && cc[ee[i].x][ee[i].y] != -1) {
 				if (cc[ee[i].y][ee[i].x] != -1) {
 					while (fl[ee[i].x][ee[i].y] == 0 || fl[ee[i].y][ee[i].x] == 0) {
 						++fl[ee[i].x][ee[i].y];
 						++fl[ee[i].y][ee[i].x];
 					}
 				}
 				else {
 					cerr << "HER" << endl;
 					exit(0);
 				}
 			}
 			if (cc[ee[i].x][ee[i].y] != -1 && abs(fl[ee[i].x][ee[i].y]) > n * n) {
 				cerr << "HER2" << endl;
 				exit(0);
 			}
 		}
 		pAns->ans.clear();
 		rept(i, L(oe)) {
 			pAns->ans.pb(fl[oe[i].x][oe[i].y]);
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
 	freopen("B-small-attempt0.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	char tmp[333];
 	int kolt = 0;
 	GETS(tmp);
 	sscanf(tmp, "%d", &kolt);
 	if (kolt > _maxNumberOfTests) {
 		cerr << "_maxNumberOfTests = " << _maxNumberOfTests << ", but kolt = " << kolt << endl;
 		int t = 0;
 		while (1) ++t;
 	}
 	//solveParallel(kolt);
 	solveSequential(kolt);
 	//stressTest();
 }