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
 
 const int N = 1000002;
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int n, d;
 	int s0, as, cs, rs;
 	int m0, am, cm, rm;
 	int S[N], M[N];
 	int npr[N];
 	VI nsm[N], sm[N];
 	bool dead[N], alive[N];
 	int pc[N], cc[N];
 	inline void readInput() {
 		scanf("%d%d", &n, &d);
 		scanf("%d%d%d%d", &s0, &as, &cs, &rs);
 		scanf("%d%d%d%d", &m0, &am, &cm, &rm);
 	}
 
 	int gc(int a) {
 		if (pc[a] == -1) return a; else
 			return pc[a] = gc(pc[a]);
 	}
 	inline void add(int v) {
 		if (dead[v]) return;
 		alive[v] = 1;
 		rept(i, L(nsm[v])) {
 			int w = nsm[v][i];
 			if (dead[w]) continue;
 			if (!alive[w]) continue;
 			sm[v].pb(w);
 			cc[v] += cc[w];
 			pc[w] = v;
 		}
 
 		int p = npr[v];
 		if (p == -1) return;
 		if (dead[p]) return;
 		if (!alive[p]) return;
 		pc[v] = p;
 		int root = gc(v);
 		if (!dead[root]) {
 			cc[root] += cc[v];
 		}
 		sm[p].pb(v);
 	}
 	int dfs(int v, bool add = true) {
 		if (dead[v]) return 0;
 		if (!alive[v]) add = 0;
 		int ans = 1;
 		if (!add) ans = 0;
 		dead[v] = 1;
 		rept(i, L(sm[v])) {
 			ans += dfs(sm[v][i], add);
 		}
 		return ans;
 	}
 	inline void rem(int v) {
 		if (dead[v]) return;
 		int c = dfs(v);
 		int root = gc(v);
 		cc[root] -= c;
 	}
 	void run() {
 		S[0] = s0;
 		M[0] = m0;
 		rep(i, n - 1) {
 			S[i] = ((ll)S[i - 1] * as + cs) % rs;
 			M[i] = ((ll)M[i - 1] * am + cm) % rm;
 		}
 		rept(i, n) {
 			nsm[i].clear();
 			sm[i].clear();
 		}
 		npr[0] = -1;
 		rep(i, n - 1) {
 			npr[i] = M[i] % i;
 			nsm[npr[i]].pb(i);
 		}
 		vector<pii> sal;
 		rept(i, n) sal.pb(mp(S[i], i));
 		SORT(sal);
 		int a = 0;
 		memset(pc, -1, n * sizeof(int));
 		rept(i, n) {
 			dead[i] = 0;
 			alive[i] = 0;
 			cc[i] = 1;
 		}
 		int ans = 1;
 		rept(i, n) {
 			add(sal[i].y);
 			while (a < i && sal[i].x - sal[a].x > d) {
 				rem(sal[a].y);
 				++a;
 			}
 			if (dead[0]) break;
 			ans = max(ans, cc[0]);
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
 	freopen("A-small-attempt0.in", "r", stdin);
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
