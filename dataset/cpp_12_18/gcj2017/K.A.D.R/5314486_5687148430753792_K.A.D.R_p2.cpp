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
 
 template<typename Cap, typename Cost, int V, int E> struct MinCostFlow
 {
 	int last[V + 1], nx[2 * E + 2], ver[2 * E + 2], pr[V + 1], S, T, ec;
 	Cap cap[2 * E + 2], curcap[V + 1];
 	Cost cost[2 * E + 2], ds[2 * E + 2];
 	queue<pair<Cost, Cap> > q;
 	inline void reset()
 	{
 		memset(last, -1, sizeof(last));
 		ec = 0;
 		while (!q.empty()) q.pop();
 	}
 	inline void addEdge(int v, int w, int cp, int cs)
 	{
 		if (max(v, w) >= V) {
 			cerr << "TOO FEW V" << endl;
 			exit(0);
 		}
 		if (ec + 2 > E) {
 			cerr << "TOO FEW E" << endl;
 			exit(0);
 		}
 		ver[ec] = w; cap[ec] = cp; cost[ec] = cs; nx[ec] = last[v]; last[v] = ec++;
 		ver[ec] = v; cap[ec] = 0; cost[ec] = -cs; nx[ec] = last[w]; last[w] = ec++;
 	}
 	inline bool dijkstra()
 	{
 		memset(pr, -1, sizeof(pr));
 		memset(ds, 63, sizeof(ds));
 		memset(curcap, 0, sizeof(curcap));
 		Cost inf;
 		memset(&inf, 63, sizeof(inf));
 		curcap[S] = inf;
 		ds[S] = 0;
 		while (!q.empty()) q.pop();
 		q.push(make_pair(0, S));
 		pr[S] = -1;
 		while (!q.empty())
 		{
 			int v = q.front().y;
 			if (q.front().x != ds[v])
 			{
 				q.pop();
 				continue;
 			}
 			q.pop();
 			for (int w = last[v]; w >= 0; w = nx[w])
 			{
 				if (cap[w] && ds[v] + cost[w]<ds[ver[w]])
 				{
 					pr[ver[w]] = w;
 					ds[ver[w]] = ds[v] + cost[w];
 					q.push(make_pair(ds[ver[w]], ver[w]));
 					if (cap[w]<curcap[v]) curcap[ver[w]] = cap[w]; else
 						curcap[ver[w]] = curcap[v];
 				}
 			}
 		}
 		return curcap[T]>0;
 	}
 	inline pair<Cap, Cost> minCostFlow()
 	{
 		Cap fl = 0;
 		Cost cs = 0;
 		while (dijkstra())
 		{
 			Cap add = curcap[T];
 			fl += add;
 			cs += ds[T] * add;
 			int a = T, b = pr[T];
 			while (b != -1)
 			{
 				cap[b] -= add;
 				cap[b ^ 1] += add;
 				a = ver[b ^ 1];
 				b = pr[a];
 			}
 		}
 		return make_pair(fl, cs);
 	}
 };
 
 //int numThreads = 0;
 int HOD;
 const int _maxNumberOfThreads = 4;
 const int _maxNumberOfTests = 201;
 struct Answer {
 	int numberOfTest;
 	int a1, a2;
 	inline void output() {
 		printf("Case #%d: %d %d\n", numberOfTest + 1, a1, a2);
 	}
 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	MinCostFlow<int, int, 3333, 30002> q;
 	int n, c, m;
 	pii mas[1002];
 	int cnt[1002];
 	inline void readInput() {
 		scanf("%d%d%d", &n, &c, &m);
 		C(cnt);
 		rept(i, m) {
 			scanf("%d%d", &mas[i].x, &mas[i].y); --mas[i].x; --mas[i].y;
 			++cnt[mas[i].y];
 		}
 	}
 
 	inline int check(int xx) {
 		q.reset();
 		q.S = c + 2 * n;
 		q.T = q.S + 1;
 		rept(i, c) {
 			q.addEdge(q.S, i, INF, 0);
 		}
 		rept(i, m) {
 			q.addEdge(mas[i].y, c + n + mas[i].x, 1, 0);
 		}
 		rept(i, n) {
 			if (i) {
 				q.addEdge(c + i, c + i - 1, INF, 0);
 				q.addEdge(c + n + i, c + i - 1, INF, 1);
 			}
 			q.addEdge(c + i, c + n + i, INF, 0);
 			q.addEdge(c + n + i, q.T, xx, 0);
 		}
 		
 		pii t = q.minCostFlow();
 		if (t.x != m) return -1;
 		return t.y;
 	}
 
 	void run() {
 		// put an answer into pAns
 		int l = max(0, *max_element(cnt, cnt + c) - 1), r = m;
 		while (r - l > 1) {
 			int xx = (r + l) / 2;
 			if (check(xx) != -1) r = xx; else
 				l = xx;
 		}
 		int t = check(r);
 		pAns->a1 = r;
 		pAns->a2 = t;
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
 	gets_s(tmp);
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