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
 		if (ans == -1) printf("Case #%d: IMPOSSIBLE\n", numberOfTest + 1); else
 		printf("Case #%d: %d\n", numberOfTest + 1, ans);
 	}
 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int hd, ad, hk, ak, b, d;
 	int last;
 	int ans;
 	inline void readInput() {
 		scanf("%d%d%d%d%d%d", &hd, &ad, &hk, &ak, &b, &d);
 	}
 	inline void upd(int &a, int b) {
 		if (a == -1 || a > b) a = b;
 	}
 
 	bool rec(int v, int hd, int ad, int hk, int ak) {
 		if (ad >= hk) {
 			upd(ans, v + 1);
 			return 0;
 		}
 		if (v >= 9) return 0;
 		bool res = 0;
 		// not heal
 		if (ak < hd) {
 			if (v >= 4) res = 1;
 			// attack
 			res |= rec(v + 1, hd - ak, ad, hk - ad, ak);
 			// buff
 			if (b) res |= rec(v + 1, hd - ak, min(INF + 1, ad + b), hk, ak);
 			// debuff
 			int nk = max(0, ak - d);
 			if (d) res |= rec(v + 1, hd - nk, ad, hk, nk);
 		}
 		// heal
 		if (hd < this->hd && this->hd - ak > 0) {
 			res |= rec(v + 1, this->hd - ak, ad, hk, ak);
 		}
 
 		return res;
 	}
 	inline bool solve(int X, int chd, int cak) {
 		if (chd <= 0) return 0;
 		if (ad >= hk) return 1;
 		if (ak < chd && 2 * ad >= hk && X >= 2) return 1;
 		if (ak < chd && b + ad >= hk && X >= 2) return 1;
 		if (hd <= 2 * cak) return 0;
 		int g = INF + 1;
 		if (cak) g = (hd - 1) / cak;
 		if (chd <= cak) {
 			--X;
 			chd = hd - cak;
 		}
 		if (X <= 0) return 0;
 
 		int tot = 0;
 		if ((ll)cak * (X - 1) >= chd) {
 			tot = 1;
 			int XX = X - (chd - 1 + cak) / cak;
 			if (XX > 0 && chd == hd) {
 				--XX;
 			}
 			tot += (XX - 1) / g;
 		}
 
 		X -= tot;
 		if (X <= 0) return 0;
 		//if (X == last) return 0;
 		//last = X;
 
 		/*if ((ll)ad * X >= hk) return 1;
 		if (X == 1) return 0;
 		if (!b) return 0;
 		if ((ll)(X - 1) * b + ad >= hk) return 1;
 
 		ll aa = -b;
 		ll bb = (ll)X * b - ad;
 		ll cc = (ll)X * ad - hk;
 
 		if ((long double)4.0 * aa * cc > 8e18) return 0;
 		ll dd = bb * bb - 4LL * aa * cc;
 		ll sqd = (ll)sqrt((long double)dd);
 
 		ll l = (-bb - sqd) / (2LL * aa);
 		ll r = (-bb + sqd) / (2LL * aa);
 		if (l > r) swap(l, r);
 		--l;
 		++r;
 
 		if (r <= 0) return 0;
 		if (l >= X) return 0;
 		if (l < 1) l = 1;
 		if (r > X - 1) r = X - 1;
 
 		// check l
 		ll attk = (ll)l * b + ad;
 		ll need = (hk + attk - 1) / attk;
 		if (need + l <= X) return 1;
 
 		++l;
 		if (l > r) return 0;
 		attk = (ll)l * b + ad;
 		need = (hk + attk - 1) / attk;
 		if (need + l <= X) return 1;
 		return 0;*/
 		rept(j, X) {
 			ll attk = (ll)j * b + ad;
 			ll need = (hk + attk - 1) / attk;
 			if (need + j <= X) return 1;
 		}
 		return 0;
 	}
 	bool check(int X) {
 		int lim = X - 1;
 
 		if (d) {
 		//	lim = min(lim, ak / d + 1);
 		}
 
 		int chd = hd, cak = ak;
 		if (!d) lim = 0;
 		last = -1;
  		rept(i, lim) {
 			if (solve(X - i, chd, cak)) {
 				return 1;
 			}
 
 
 			int nak = max(cak - d, 0);
 			if (chd < nak) {
 				chd = hd - cak;
 				if (chd <= 0) return 0;
 			}
 			else {
 				cak = nak;
 				chd -= cak;
 			}
 		}
 
 		return 0;
 	}
 	void run() {
 		// Check the first few turns
 		ans = -1;
 		if (!rec(0, hd, ad, hk, ak)) {
 			if (ans == -1) {
 				pAns->ans = -1;
 				return;
 			}
 		}
 		if (ans != -1) {
 			pAns->ans = ans;
 			return;
 		}
 		
 		int l = 0, r = 2 * INF + 100;
 		while (r - l > 1) {
 			int xx = ((ll)r + (ll)l) / 2;
 			if (check(xx)) r = xx; else
 				l = xx;
 		}
 		pAns->ans = r;
 	}
 
 	void run2() {
 		hd = rand() % 10 + 1; ad = rand() % 10 + 1; hk = rand() % 10 + 1; ak = rand() % 10 + 1; b = rand() % 10; d = rand() % 10;
 		if (pAns->numberOfTest != 145) {
 		}
 
 		run2();
 		int t = pAns->ans;
 
 		if (ans != -1 && pAns->ans != -1 && ans != pAns->ans) {
 			cerr << "HER " << ans << " " << pAns->ans << endl;
 			exit(0);
 		}
 		cerr << "OK " << ans << endl;
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
 		answers[0].numberOfTest = hod;
 		solvers[0]._numberOfThread = 1;
 		solvers[0].pAns = &answers[0];
 		solvers[0].run();
 	}
 }
 int main() {
 	freopen("C-small-attempt3.in", "r", stdin);
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