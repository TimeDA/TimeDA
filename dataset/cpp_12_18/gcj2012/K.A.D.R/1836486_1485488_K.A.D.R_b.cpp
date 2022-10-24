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
 #define eps 1e-8
 
 
 int numThreads = 0;
 const int _maxNumberOfThreads = 8;
 const int _maxNumberOfTests = 201;
 bool threadsUsed[_maxNumberOfThreads];
 HANDLE nowRunning[_maxNumberOfThreads];
 struct Answer {
 	int numberOfTest;
 	double ans;
 	inline void output() {
 		printf("Case #%d: %.12lf\n", numberOfTest + 1, ans);
 	}
 };
 
 const int di[] = {0, 1, 0, -1};
 const int dj[] = {1, 0, -1, 0};
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	int n, m, h;
 	int ch[101][101], fh[101][101];
 	inline void readInput() {
 		scanf("%d%d%d", &h, &n, &m);
 		rept(i, n) {
 			rept(j, m) {
 				scanf("%d", &ch[i][j]);
 			}
 		}
 		rept(i, n) {
 			rept(j, m) {
 				scanf("%d", &fh[i][j]);
 			}
 		}
 	}
 
 	priority_queue<pair<double, pii>, vector<pair<double, pii> > , greater<pair<double, pii> > > q;
 	double ds[101][101];
 	void run() {
 		// put an answer into pAns
 		while (!q.empty()) q.pop();
 		rept(i, n) rept(j, m) ds[i][j] = 1e100;
 		ds[0][0] = 0.0;
 		q.push(mp(0.0, mp(0, 0)));
 		while (!q.empty()) {
 			int ci = q.top().y.x, cj = q.top().y.y;
 			double cd = q.top().x;
 			q.pop();
 			if (abs(cd - ds[ci][cj]) > eps) continue;
 
 			double water = (double)h - cd * 10;
 			if (water < 0) water = 0;
 			rept(i, 4) {
 				int ni = ci + di[i];
 				int nj = cj + dj[i];
 				if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
 
 				if (ch[ni][nj] - fh[ni][nj] < 50) continue;
 				if (ch[ni][nj] - fh[ci][cj] < 50) continue;
 				if (ch[ci][cj] - fh[ni][nj] < 50) continue;
 				
 				double next_step = cd;
 				if (ch[ni][nj] - water + eps < 50) {
 					next_step += (50.0 - ch[ni][nj] + water) / 10.0;
 				}
 				
 				double new_water = (double)h - next_step * 10;
 				bool needToWait = true;
 				if (abs(new_water - h) < eps) needToWait = false;
 				double add = 10.0;
 				if (fh[ci][cj] + 20 < new_water + eps) add = 1.0;
 				if (!needToWait) add = 0.0;
 				next_step += add;
 				if (next_step + 1e-9 < ds[ni][nj]) {
 					ds[ni][nj] = next_step;
 					q.push(mp(next_step, mp(ni, nj)));
 				}
 			}
 		}
 
 		pAns->ans = ds[n - 1][m - 1];
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
 		cerr << "Test " << hod << " " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
 		solvers[0]._numberOfThread = 1;
 		solvers[0].readInput();
 		answers[hod].numberOfTest = hod;
 		solvers[0].pAns = &answers[hod];
 		solvers[0].run();
 	}
 
 	for (int i = 0; i < kolt; ++i) answers[i].output();
 }
 int main() {
 	freopen("B-small-attempt0.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	char tmp[333];
 	int kolt = 0;
 	gets(tmp);
 	sscanf(tmp, "%d", &kolt);
 	solveParallel(kolt);
 	//solveSequential(kolt);
 }
