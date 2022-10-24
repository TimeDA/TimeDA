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
 #include <ctime>
 #include <cstring>
 #include <functional>
 
 #include <thread>
 #include <mutex>
 #include <condition_variable>
 #include <atomic>
 #pragma comment(linker, "/STACK:567108864")
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
 #define MOD 1000000007
 
 
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
 
 
 inline void upd(pii &a, pii b) {
 	if (b.x > a.x) {
 		a.x = b.x;
 		a.y = 0;
 	}
 	if (a.x == b.x) {
 		a.y += b.y;
 		if (a.y >= MOD) a.y -= MOD;
 	}
 }
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int m, n, k;
 	int nx[100002][26];
 	int en[100002], cs[100002];
 	int ce[102][102];
 	vector<pii> mem[100002];
 	char str[1002][102];
 	inline void readInput() {
 		scanf("%d%d", &m, &n);
 		rept(i, m) {
 			scanf("%s", str[i]);
 		}
 	}
 
 	void dfs(int v) {
 		cs[v] = en[v];
 		rept(i, 26) {
 			if (nx[v][i] == -1) continue;
 			dfs(nx[v][i]);
 			cs[v] += cs[nx[v][i]];
 		}
 	}
 	void rec(int v) {
 		if (!mem[v].empty()) return;
 		rept(i, 26) {
 			if (nx[v][i] != -1) rec(nx[v][i]);
 		}
 		vector<pii> cur;
 		if (!en[v]) {
 			cur.resize(1);
 			cur[0] = mp(0, 1);
 		}
 		else {
 			cur.resize(2);
 			cur[0] = mp(0, 0);
 			cur[1] = mp(1, 1);
 		}
 		//cur[1] = mp(1, 1);
 		rept(i, 26) {
 			if (nx[v][i] == -1) continue;
 			int w = nx[v][i];
 			vector<pii> nx(min(n + 1, L(cur) + L(mem[w]) + 1), mp(0, 0));
 			rept(p, L(cur)) {
 				if (!cur[p].y) continue;
 				rept(now, L(mem[w])) {
 					if (now > n) break;
 					if (now > cs[w]) break;
 					if (!mem[w][now].y) continue;
 					int t = (ll)cur[p].y * mem[w][now].y % MOD;
 
 					int lim = min(p, now);
 					FORD(overlap, lim, 0) {
 						if (p + now - overlap > n) break;
 						int ns = p + now - overlap;
 						if (ns >= L(nx)) nx.resize(ns + 1);
 						//upd(nx[ns], mp(cur[p].x + ns - p + mem[w][now].x, (int)((ll)t * ce[p][overlap] % MOD)));
 						upd(nx[ns], mp(cur[p].x + ns - p + mem[w][now].x, (int)((ll)t * ce[ns][overlap] % MOD * ce[ns - overlap][p - overlap] % MOD)));
 					}
 					
 				}
 			}
 			while (L(nx) && nx.back().y == 0) nx.ppb();
 			cur.swap(nx);
 		}
 		mem[v].swap(cur);
 	}
 	void run() {
 		rept(i, 102) {
 			ce[i][0] = ce[i][i] = 1;
 			rep(j, i - 1) {
 				ce[i][j] = (ce[i - 1][j - 1] + ce[i - 1][j]) % MOD;
 			}
 		}
 		// put an answer into pAns
 		k = 1;
 		memset(nx, -1, sizeof(nx));
 		C(en);
 		rept(i, m) {
 			int l = (int)strlen(str[i]);
 			int v = 0;
 			rept(j, l) {
 				if (nx[v][str[i][j] - 'A'] == -1) {
 					nx[v][str[i][j] - 'A'] = k++;
 				}
 				v = nx[v][str[i][j] - 'A'];
 			}
 			++en[v];
 		}
 		dfs(0);
 		rept(i, k) {
 			mem[i].clear();
 		}
 		rec(0);
 		
 		pii ans = mem[0][n];
 		//rep(i, n) ans.y = (ll)ans.y * i % MOD;
 		pAns->a1 = ans.x; pAns->a2 = ans.y;
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
 void solveParallel(int numberOfTests, int maxThreads = 4) {
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
 		cerr << "Test #" << currentTest + 1 << " was taken by thread #" << threadNumber << " at " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
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
 	//freopen("input.txt", "r", stdin);
 	freopen("D-small-attempt3.in", "r", stdin);
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
