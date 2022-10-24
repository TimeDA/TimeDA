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
 #pragma comment(linker, "/STACK:267108864")
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
 
 	int w, h, b;
 	vector<pair<pii, pii> > rect;
 	int ds[1002];
 	bool used[1002];
 	int gx[4], gy[4];
 	inline void readInput() {
 		scanf("%d%d%d", &w, &h, &b);
 		rect.clear();
 		rept(i, b) {
 			int x1, y1, x2, y2;
 			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
 			rect.pb(mp(mp(x1, y1), mp(x2, y2)));
 		}
 	}
 
 	inline int calc(pair<pii, pii> a, pair<pii, pii> b) {
 		int cx = 0, cy = 0;
 		gx[cx++] = a.x.x;
 		gx[cx++] = a.y.x;
 		gx[cx++] = b.x.x;
 		gx[cx++] = b.y.x;
 
 		gy[cy++] = a.x.y;
 		gy[cy++] = a.y.y;
 		gy[cy++] = b.x.y;
 		gy[cy++] = b.y.y;
 
 		int ans = 2 * INF;
 		rept(_x1, cx) {
 			int x1 = gx[_x1];
 			if (x1 < a.x.x || x1 > a.y.x) continue;
 			rept(_y1, cy) {
 				int y1 = gy[_y1];
 				if (y1 < a.x.y || y1 > a.y.y) continue;
 				rept(_x2, cx) {
 					int x2 = gx[_x2];
 					if (x2 < b.x.x || x2 > b.y.x) continue;
 					rept(_y2, cy) {
 						int y2 = gy[_y2];
 						if (y2 < b.x.y || y2 > b.y.y) continue;
 						ans = min(ans, max(abs(x1 - x2), abs(y1 - y2)) - 1);
 					}
 				}
 			}
 		}
 		return ans;
 	}
 	void run() {
 		// put an answer into pAns
 		rept(i, L(rect)) {
 			ds[i] = rect[i].x.x;
 		}
 		C(used);
 		rept(it, L(rect)) {
 			int v = -1, mn = 2 * INF;
 			rept(i, L(rect)) {
 				if (used[i]) continue;
 				if (ds[i] < mn) {
 					mn = ds[i];
 					v = i;
 				}
 			}
 			if (v == -1) break;
 			used[v] = 1;
 			rept(i, L(rect)) {
 				if (used[i]) continue;
 				int cur = calc(rect[i], rect[v]);
 				ds[i] = min(ds[i], cur + ds[v]);
 			}
 		}
 		
 		int ans = 2 * INF;
 		rept(i, L(rect)) {
 			ans = min(ans, ds[i] + w - rect[i].y.x - 1);
 		}
 		if (ans > w) ans = w;
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
 	freopen("C-small-attempt1.in", "r", stdin);
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
