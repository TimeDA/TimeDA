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
 #define double long double
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
 
 #define VD vector<double>
 #define REP rept
 #define SZ L
 #define ALL all
 // Taken from BZFlags ACM ICPC team notebook
 namespace SimplexMethod {
 	const double EPS = 1.0E-12;
 	vector<VD> a; VD b, c, res;
 	VI N, kt; int m;
 	void pivot(int k, int s, int e) {
 		int x = kt[s]; double p = a[s][e];
 		REP(i, k) a[s][i] /= p;
 		b[s] /= p;  N[e] = false;
 		REP(i, m) if (i != s) {
 			b[i] -= a[i][e] * b[s];
 			a[i][x] = -a[i][e] * a[s][x];
 		}
 		REP(j, k) if (N[j]) {
 			c[j] -= c[e] * a[s][j];
 			REP(i, m) if (i != s) a[i][j] -= a[i][e] * a[s][j];
 		}
 		kt[s] = e; N[x] = true; c[x] = -c[e] * a[s][x];
 	}
 	VD doit(int k) {
 		VD res;
 		while (true) {
 			int e = -1, s = -1;
 			REP(i, k) if (N[i] && c[i] > EPS) { e = i; break; }
 			if (e == -1) break;
 			REP(i, m) if (a[i][e] > EPS && (s == -1 || b[i] / a[i][e] < b[s] / a[s][e])) s = i;
 			if (s == -1) return VD();
 			pivot(k, s, e);
 		}
 		res.resize(k, 0);
 		REP(i, m) res[kt[i]] = b[i];
 		return res;
 	}
 	VD simplex(vector<VD> _A, VD _b, VD _c) {
 		a = _A; b = _b; c = _c;
 		m = SZ(a); int n = SZ(a[0]); int k = n + m + 1;
 		c.resize(n + m); kt.resize(m);
 		N = VI(k, true);
 		REP(i, m) {
 			a[i].resize(k); a[i][n + i] = 1; a[i][k - 1] = -1;
 			kt[i] = n + i; N[kt[i]] = false;
 		}
 		int s = min_element(ALL(b)) - b.begin();
 		if (b[s] < -EPS) {
 			c = VD(k, 0); c[k - 1] = -1;
 			pivot(k, s, k - 1);
 			res = doit(k);
 			if (res[k - 1] > EPS) return VD();
 			REP(i, m) if (kt[i] == k - 1) REP(j, k - 1)
 				if (N[j] && (a[i][j] < -EPS || EPS < a[i][j])) {
 				pivot(k, i, j); break;
 				}
 			c = _c; c.resize(k, 0);
 			REP(i, m) REP(j, k) if (N[j])
 				c[j] -= c[kt[i]] * a[i][j];
 		}
 		res = doit(k - 1); if (!res.empty()) res.resize(n);
 		return res;
 	}
 }
 
 
 //int numThreads = 0;
 int HOD;
 const int _maxNumberOfThreads = 4;
 const int _maxNumberOfTests = 201;
 struct Answer {
 	int numberOfTest;
 	double ans;
 	inline void output() {
 		if (ans > 1e90) {
 			printf("Case #%d: IMPOSSIBLE\n", numberOfTest + 1);
 		}
 		else {
 			cout.precision(9);
 			cout << "Case #" << numberOfTest + 1 << ": " << fixed << ans << endl;
 			//printf("Case #%d: %.9lf\n", numberOfTest + 1, ans);
 		}
 	}
 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int n;
 	double V, X;
 	pdd mas[102];
 	inline void readInput() {
 		//scanf("%d%lf%lf", &n, &V, &X);
 		cin >> n >> V >> X;
 		rept(i, n) {
 			//scanf("%lf%lf", &mas[i].x, &mas[i].y);
 			cin >> mas[i].x >> mas[i].y;
 		}
 	}
 
 	void run() {
 		// put an answer into pAns
 		bool gr = 0, ls = 0;
 		rept(i, n) {
 			if (mas[i].y > X + 1e-6) gr = 1;
 			if (mas[i].y < X - 1e-6) ls = 1;
 		}
 		if (!gr || !ls) {
 			double s = 0;
 			rept(i, n) {
 				if (abs(X - mas[i].y) < 1e-6) {
 					s += mas[i].x;
 				}
 			}
 			if (!s) {
 				pAns->ans = 1e100;
 				return;
 			}
 			pAns->ans = V / s;
 			return;
 		}
 
 		vector<double> c(n);
 		rept(i, n) {
 			c[i] = -1.0;
 		}
 		vector<vector<double>> A;
 		vector<double> B;
 		vector<double> tmp(n);
 		rept(i, n) {
 			tmp[i] = mas[i].x;
 		}
 		A.pb(tmp);
 		B.pb(V);
 		rept(i, n) {
 			tmp[i] = -mas[i].x;
 		}
 		A.pb(tmp);
 		B.pb(-V);
 		rept(i, n) {
 			tmp[i] = mas[i].x * mas[i].y;
 		}
 		A.pb(tmp);
 		B.pb(V * X);
 		rept(i, n) {
 			tmp[i] = -tmp[i];
 		}
 		A.pb(tmp);
 		B.pb(-V * X);
 		
 		auto res = SimplexMethod::simplex(A, B, c);
 		if (res.empty()) {
 			pAns->ans = 1e100;
 			return;
 		}
 		double ans = 0.0;
 		rept(i, L(res)) ans = max(ans, res[i]);
 
 		double l = 0.0, r = ans;
 		rept(iter, 100) {
 			double xx = (r + l) / 2;
 			auto AA = A;
 			auto BB = B;
 			vector<double> cc(n, 0);
 			rept(i, n) {
 				vector<double> tt(n);
 				tt[i] = 1.0;
 				AA.pb(tt);
 				BB.pb(xx);
 			}
 			auto ts = SimplexMethod::simplex(AA, BB, cc);
 			if (ts.empty()) l = xx; else
 				r = xx;
 		}
 		pAns->ans = r;
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
 	freopen("B-small-attempt2.in", "r", stdin);
 	//freopen("input.txt", "r", stdin);
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