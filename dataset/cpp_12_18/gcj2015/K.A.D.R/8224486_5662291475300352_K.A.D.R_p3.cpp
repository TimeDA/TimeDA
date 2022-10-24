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
 	inline void output() {
 		printf("Case #%d: %d\n", numberOfTest + 1, ans);
 	}
 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int n;
 	vector<pii> pl;
 	inline void readInput() {
 		scanf("%d", &n);
 		pl.clear();
 		rept(i, n) {
 			int a, b, c;
 			scanf("%d%d%d", &a, &b, &c);
 			rept(j, b) {
 				pl.pb(mp(c + j, a));
 			}
 		}
 	}
 
 	void run() {
 		// put an answer into pAns
 		sort(all(pl), [](const pii &a, const pii &b) { if (a.x != b.x) return a.x < b.x; else return a.y > b.y; });
 		pii t = pl.back();
 		bool ok = 1;
 		rept(i, L(pl)) {
 			if (pl[i].x == t.x) continue;
 			ok = 1;
 			int v1 = pl[i].x;
 			int x1 = pl[i].y;
 
 			int v2 = t.x;
 			int x2 = t.y;
 
 			x2 += 360;
 
 			ll ch = (ll)(x2 - 360) * (v2 - v1) + (ll)(x2 - x1) * v1;
 			ll zn = v2 - v1;
 			if (ch <= zn * 360) {
 				ok = 0;
 				break;
 			}
 		}
 		if (ok) {
 			pAns->ans = 0;
 			return;
 		}
 
 		int ans = L(pl);
 		rept(i, L(pl)) {
 			int v1 = pl[i].x;
 			int x1 = pl[i].y;
 			int cur = 0;
 			FOR(j, i + 1, L(pl) - 1) {
 				if (pl[j].x <= pl[i].x) continue;
 
 				int v2 = pl[j].x;
 				int x2 = pl[j].y;
 				x2 += 360;
 
 				ll ch = (ll)(x2 - 360) * (v2 - v1) + (ll)(x2 - x1) * v1;
 				ll zn = v2 - v1;
 				if ((ll)ch > zn * 360) {
 					continue;
 				}
 				++cur;
 				rept(iter, INF) {
 					ch += 360;
 					if ((ll)ch * zn > 360) break;
 					++cur;
 					if (cur >= ans) break;
 				}
 				if (cur >= ans) break;
 			}
 			if (cur >= ans) continue;
 			rept(j, i) {
 				if (pl[j].x >= pl[i].x) continue;
 				
 				ll t1 = (ll)(360 - pl[j].y) * pl[j].x;
 				ll t2 = (ll)(360 - pl[i].y) * pl[i].x;
 
 				if (t1 <= t2) ++cur;
 			}
 			ans = min(ans, cur);
 		}
 		pAns->ans = ans;
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
 	freopen("C-small-1-attempt0.in", "r", stdin);
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
 	//solveParallel(kolt);
 	solveSequential(kolt);
 	//stressTest();
 }
 
