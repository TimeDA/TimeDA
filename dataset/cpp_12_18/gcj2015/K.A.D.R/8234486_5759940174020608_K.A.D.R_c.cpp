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
 
 template<typename TT, int V, int E> struct DinicFlow
 {
 	int ds[V + 1], q[V + 1], nx[E + 1], last[V + 1], ver[E + 1], now[V + 1], n, edgesCount, S, T;
 	TT cap[E + 1];
 	DinicFlow() :n(0), S(0), T(0), edgesCount(0){}
 	DinicFlow(int _n) :n(_n), S(0), T(0), edgesCount(0){}
 	inline void reset(int _n = 0)
 	{
 		edgesCount = 0;
 		n = _n;
 		memset(last, -1, n*sizeof(int));
 	}
 	inline void addEdge(int v, int w, TT c, TT rc)
 	{
 		ver[edgesCount] = w; cap[edgesCount] = c;  nx[edgesCount] = last[v]; last[v] = edgesCount++;
 		ver[edgesCount] = v; cap[edgesCount] = rc; nx[edgesCount] = last[w]; last[w] = edgesCount++;
 	}
 	inline bool bfs()
 	{
 		memset(ds, 63, n*sizeof(int));
 		int a = 0, b = 0;
 		ds[T] = 0;
 		q[0] = T;
 		while (a <= b)
 		{
 			int v = q[a++];
 			for (int w = last[v]; w >= 0; w = nx[w])
 			{
 				if (cap[w ^ 1] && ds[ver[w]]>ds[v] + 1)
 				{
 					ds[ver[w]] = ds[v] + 1;
 					q[++b] = ver[w];
 				}
 			}
 		}
 		return ds[S]<1000000000;
 	}
 	TT dfs(int v, TT cur)
 	{
 		if (v == T) return cur;
 		for (int &w = now[v]; w >= 0; w = nx[w])
 		{
 			if (cap[w] && ds[ver[w]] == ds[v] - 1)
 			{
 				TT rr = dfs(ver[w], min(cur, cap[w]));
 				if (rr)
 				{
 					cap[w] -= rr;
 					cap[w ^ 1] += rr;
 					return rr;
 				}
 			}
 		}
 		return 0;
 	}
 	inline TT maxFlow()
 	{
 		TT ans = 0;
 		while (bfs())
 		{
 			memcpy(now, last, n*sizeof(int));
 			TT tf;
 			while (tf = dfs(S, 1000000000)) ans += tf;
 		}
 		return ans;
 	}
 };
 
 struct Solver {
 	DinicFlow<int, 9002, 400002> q;
 	int _numberOfThread;
 	Answer *pAns;
 	int n, k;
 	map<string, int> nm;
 	VI words[202];
 	char str[200002];
 	inline int num(const string& s) {
 		auto it = nm.find(s);
 		if (it != nm.end()) return it->y;
 		return nm[s] = k++;
 	}
 	inline void readInput() {
 		nm.clear();
 		gets(str);
 		sscanf(str, "%d", &n);
 		k = 0;
 		rept(i, n) {
 			gets(str);
 			words[i].clear();
 			istringstream iss(str);
 			string s;
 			while (iss >> s) {
 				words[i].pb(num(s));
 			}
 		}
 	}
 
 	void run() {
 		q.reset(2 * k + 3);
 		q.S = 2 * k;
 		q.T = q.S + 1;
 		rept(i, k) {
 			q.addEdge(i, i + k, 1, INF);
 		}
 		rept(i, L(words[0])) {
 			q.addEdge(q.S, words[0][i], INF, 0);
 		}
 		rept(i, L(words[1])) {
 			q.addEdge(words[1][i] + k, q.T, INF, 0);
 		}
 		FOR(i, 2, n - 1) {
 			rept(j1, L(words[i])) {
 				rept(j2, L(words[i])) {
 					if (j1 == j2) continue;
 					q.addEdge(words[i][j1] + k, words[i][j2], INF, 0);
 				}
 			}
 		}
 		int ans = q.maxFlow();
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
 	freopen("C-small-attempt0.in", "r", stdin);
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
 
