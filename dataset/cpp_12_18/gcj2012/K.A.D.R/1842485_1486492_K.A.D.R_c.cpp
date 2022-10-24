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
 #include <process.h>
 #include <windows.h>
 #include <ctime>
 #include <cstring>
 #pragma comment(linker, "/STACK:67108864")
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
 
 
 int numThreads = 0;
 const int _maxNumberOfThreads = 8;
 const int _maxNumberOfTests = 201;
 bool threadsUsed[_maxNumberOfThreads];
 HANDLE nowRunning[_maxNumberOfThreads];
 struct Answer {
 	int numberOfTest;
 	VI ans;
 	inline void output() {
 		printf("Case #%d:", numberOfTest + 1);
 		if (ans.empty()) {
 			printf(" Impossible\n");
 			return;
 		}
 		rept(i, L(ans)) {
 			printf(" %d", ans[i]);
 		}
 		printf("\n");
 	}
 };
 
 inline pii operator -(const pii &a, const pii &b) {
 	return mp(a.x - b.x, a.y - b.y);
 }
 inline ll vec(const pii &a, const pii &b) {
 	return (ll)a.x * b.y - (ll)b.x * a.y;
 }
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int n;
 	int mas[11], ans[11];
 	inline void readInput() {
 		scanf("%d", &n);
 		rept(i, n - 1) scanf("%d", &mas[i]), --mas[i];
 	}
 
 	inline bool check(int v) {
 		if (v == n - 1) return 1;
 		int w = mas[v];
 		pii v1 = mp(w, ans[w]) - mp(v, ans[v]);
 		FOR(i, v + 1, w - 1) {
 			pii v2 = mp(i, ans[i]) - mp(v, ans[v]);
 			if (vec(v2, v1) <= 0) return 0;
 		}
 
 		FOR(i, w + 1, n - 1) {
 			pii v2 = mp(i, ans[i]) - mp(v, ans[v]);
 			if (vec(v2, v1) < 0) return 0;
 		}
 		return 1;
 	}
 	inline bool check() {
 		rept(i, n - 1) if (!check(i)) return 0;
 		return 1;
 	}
 	
 	bool used[21];
 	bool rec(int v, int mx = 0, int dub = 0) {
 		//int mun = n - dub;
 		//if (mx >= mun) return 0;
 		if (v >= n) {
 			return 1;
 			//return check();
 		}
 		
 		rept(i, 3 * n / 2) {
 			ans[n - v - 1] = i;
 			//ans[v] = i;
 			if (!check(n - v - 1)) continue;
 			if (used[i]) {
 				if (rec(v + 1, max(mx, i), dub + 1)) return 1;
 			} else {
 				used[i] = 1;
 				if (rec(v + 1, max(mx, i), dub)) return 1;
 				used[i] = 0;
 			}
 		}
 		return 0;
 	}
 	void run() {
 		// put an answer into pAns
 
 		pAns->ans.clear();
 		C(used);
 		if (!rec(0)) return;
 		rept(i, n) pAns->ans.pb(ans[i]);
 	}
 };
 
 
 
 void run(void* _p) {
 	Solver* s = (Solver*)(_p);
 	s->run();
 	--numThreads;
 	threadsUsed[s->_numberOfThread] = false;
 	_endthread();
 }
 inline void execute(Solver* s) {
 	threadsUsed[s->_numberOfThread] = true;
 	++numThreads;
 	nowRunning[s->_numberOfThread] = (HANDLE)_beginthread(run, 0, s);
 }
 
 Solver solvers[_maxNumberOfThreads];
 Answer answers[_maxNumberOfTests];
 
 inline void solveParallel(int kolt, int maxThreads = 2) {
 	memset(threadsUsed, 0, sizeof(threadsUsed));
 	int p = 0;
 
 	while (p < kolt) {
 		if (numThreads < maxThreads) {
 			int num = 0;
 			for (;num < maxThreads && threadsUsed[num]; ++num);
 
 			cerr << "Test #" << p + 1 << " was taken by thread #" << num << " at " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 
 			solvers[num]._numberOfThread = num;
 			solvers[num].readInput();
 			answers[p].numberOfTest = p;
 			solvers[num].pAns = &answers[p++];
 			execute(&solvers[num]);
 		}
 
 		if (numThreads == maxThreads) WaitForMultipleObjects(numThreads, nowRunning, false, INFINITE);
 	}
 	while (numThreads) {
 		for (int i = 0; i < maxThreads; ++i) if (threadsUsed[i]) WaitForSingleObject(nowRunning[i], INFINITE);
 	}
 	
 	for (int i = 0; i < kolt; ++i) answers[i].output();
 
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
 int main() {
 	srand(25091992);
 	freopen("C-small-attempt2.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	char tmp[333];
 	int kolt = 0;
 	gets(tmp);
 	sscanf(tmp, "%d", &kolt);
 	solveParallel(kolt);
 	//solveSequential(kolt);
 }
