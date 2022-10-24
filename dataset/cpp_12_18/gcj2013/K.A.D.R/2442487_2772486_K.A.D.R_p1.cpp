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
 #include <functional>
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
 int HOD;
 const int _maxNumberOfThreads = 4;
 const int _maxNumberOfTests = 201;
 bool threadsUsed[_maxNumberOfThreads];
 HANDLE nowRunning[_maxNumberOfThreads];
 struct Answer {
 	int numberOfTest, ans;
 	inline void output() {
 		printf("Case #%d: %d\n", numberOfTest + 1, ans);
 	}
 };
 const int mod = 1000002013;
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int n, m;
 	pair<pii, int> mas[100002], tmp[100002];
 	inline void readInput() {
 		scanf("%d%d", &n, &m);
 		rept(i, m) {
 			scanf("%d%d%d", &mas[i].x.x, &mas[i].x.y, &mas[i].y);
 		}
 	}
 
 	inline bool intersect(pii a, pii b) {
 		if (a.x > b.x) swap(a, b);
 		if (a.x == b.x || a.y == b.y) return 0;
 		if (a.y >= b.x && a.y <= b.y) return 1;
 		return 0;
 	}
 	inline void prepare() {
 		int k = 0;
 		sort(mas, mas + m);
 		rept(i, m) {
 			if (i && mas[i - 1].x == mas[i].x) tmp[k - 1].y += mas[i].y; else
 			tmp[k++] = mas[i];
 		}
 		rept(i, k)  mas[i] = tmp[i];
 		m = k;
 	}
 	void run() {
 		rand();
 		// put an answer into pAns
 
 		int beg = 0;
 		rept(i, m) {
 			int c = mas[i].x.y - mas[i].x.x;
 			if (c == 0) continue;
 			ll cur = (ll)n * c - (ll)(c - 1) * c / 2;
 			cur %= mod;
 			if (cur < 0) cur += mod;
 			beg = (beg + cur * mas[i].y) % mod;
 		}
 
 
 		while (1) {
 			bool upd = 0;
 			prepare();
 			random_shuffle(mas, mas + m);
 			for (int i = 0; i < m; ++i) {
 				for (int j = 0; j < m; ++j) {
 					if (i == j) continue;
 					if (intersect(mas[i].x, mas[j].x)) {
 						pii t1 = mas[i].x, t2 = mas[j].x;
 						if (t1.x > t2.x) swap(t1, t2);
 
 						int s = min(mas[i].y, mas[j].y);
 
 						if (mas[i].y > mas[j].y) {
 							mas[m++] = mas[i];
 							mas[m - 1].y -= s;
 						} else
 						if (mas[j].y > mas[i].y) {
 							mas[m++] = mas[j];
 							mas[m - 1].y -= s;
 						}
 
 						mas[i].x = mp(t1.x, t2.y);
 						mas[j].x = mp(t2.x, t1.y);
 						mas[i].y = s;
 						mas[j].y = s;
 						upd = 1;
 					}
 				}
 			}
 			if (!upd) break;
 		}
 
 		
 		int ans = 0;
 		rept(i, m) {
 			int c = mas[i].x.y - mas[i].x.x;
 			if (c == 0) continue;
 			ll cur = (ll)n * c - (ll)(c - 1) * c / 2;
 			ans = (ans + cur * mas[i].y) % mod;
 		}
 		pAns->ans = (beg - ans + mod) % mod;
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
 
 inline void solveParallel(int kolt, int maxThreads = 4) {
 	memset(threadsUsed, 0, sizeof(threadsUsed));
 	int p = 0;
 
 	while (p < kolt) {
 		if (numThreads < maxThreads) {
 			int num = 0;
 			for (;num < maxThreads && threadsUsed[num]; ++num);
 			if (num == maxThreads) continue;
 
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
