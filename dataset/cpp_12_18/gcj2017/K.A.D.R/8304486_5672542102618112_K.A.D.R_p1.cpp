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
 	int numberOfTest;
 	ll ans;
 	inline void output() {
 		printf("Case #%d: %lld\n", numberOfTest + 1, ans);
 	}
 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	char str[11];
 	int cur[10];
 	int n, T;
 	map<VI, int> nm;
 	vector<VI> ov;
 	VI sm[50002];
 	inline void readInput() {
 		scanf("%s", str);
 		n = (int)strlen(str);
 	}
 
 	void rec(int v, int s) {
 		if (v >= n) {
 			int t = nm.size();
 			nm[VI(cur, cur + n)] = t;
 			ov.pb(VI(cur, cur + n));
 			return;
 		}
 		rept(i, 10) {
 			if (s + i > n) break;
 			cur[v] = i;
 			rec(v + 1, s + i);
 		}
 	}
 
 	inline VI dd(const VI& o) {
 		VI nx(n, 0);
 		rept(i, L(o)) {
 			if (o[i] > 0) {
 				++nx[o[i] - 1];
 			}
 		}
 		return nx;
 	}
 
 	bool used[50002];
 	ll ce[11][11];
 
 	ll calc(int v) {
 		const VI& o = ov[v];
 		int s = 0;
 		rept(i, n) {
 			s += (i + 1) * o[i];
 		}
 		if (s <= n) return 1LL;
 		
 		int rem = n;
 		ll cur = 1;
 		rept(i, n) {
 			cur *= ce[rem][o[i]];
 			rem -= o[i];
 		}
 		return cur + 1;
 	}
 	ll dfs(int v) {
 		if (used[v]) return 0;
 		used[v] = 1;
 		ll ans = 0;
 		ans += calc(v);
 		rept(i, L(sm[v])) {
 			ans += dfs(sm[v][i]);
 		}
 		return ans;
 	}
 
 	void run() {
 		C(ce);
 		rept(i, 11) {
 			ce[i][0] = ce[i][i] = 1;
 			rep(j, i - 1) {
 				ce[i][j] = ce[i - 1][j - 1] + ce[i - 1][j];
 			}
 		}
 		nm.clear(); ov.clear();
 		// put an answer into pAns
 		C(cur);
 		rec(0, 0);
 		rept(i, (int)nm.size()) sm[i].clear();
 		rept(i, L(ov)) {
 			VI nx = dd(ov[i]);
 			int nn = nm.at(nx);
 			sm[nn].pb(i);
 		}
 		
 		VI beg(n, 0);
 		int s = 0;
 		rept(i, n) {
 			beg[i] = str[i] - '0';
 			s += beg[i];
 		}
 		if (s > n) {
 			pAns->ans = 1;
 			return;
 		}
 		int bv = nm.at(beg);
 		C(used);
 		ll ans = dfs(bv);
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
 	freopen("A-small-attempt0.in", "r", stdin);
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
 	solveParallel(kolt);
 	//solveSequential(kolt);
 	//stressTest();
 }