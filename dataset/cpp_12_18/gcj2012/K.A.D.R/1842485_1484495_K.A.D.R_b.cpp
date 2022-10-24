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
 	vector<pii> ans;
 	inline void output() {
 		printf("Case #%d:", numberOfTest + 1);
 		rept(i, L(ans)) printf(" %d %d", ans[i].x, ans[i].y);
 		printf("\n");
 	}
 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	vector<pii> ans;
 	int n, w, l;
 	pii mas[11];
 	inline void readInput() {
 		scanf("%d%d%d", &n, &w, &l);
 		rept(i, n) {
 			scanf("%d", &mas[i].x);
 			mas[i].y = i;
 		}
 	}
 
 	
 	inline ll ds(pii t1, pii t2) {
 		return (ll)(t1.x - t2.x) * (t1.x - t2.x) + (ll)(t1.y - t2.y) * (t1.y - t2.y);
 	}
 	bool solve() {
 		ans.clear();
 		rept(h, n) {
 			int cr = mas[h].x;
 			bool found = 0;
 			FOR(x, 0, w) {
 				int ly = 0;
 				rept(i, h) {
 					int x0 = ans[i].x, y0 = ans[i].y, r = mas[i].x + cr;
 					double a = 1.0, b = -2.0 * y0;
 					double c = (double)y0 * y0 - (double)r * r + (double)(x - x0) * (x - x0);
 
 					double d = b * b - 4.0 * a * c;
 					if (d < 1e-8) continue;
 					d = sqrt(d);
 					double y = (-b + d) / (2.0 * a);
 					int iy = (int)y;
 					if (iy > ly) ly = iy;
 				}
 				FOR(y, ly, l) {
 					int r = mas[h].x;
 					bool ok = 1;
 					rept(i, L(ans)) {
 						ll cur = ds(ans[i], mp(x, y));
 						ll sum = (ll)(mas[i].x + r) * (mas[i].x + r);
 						if (cur < sum) {
 							ok = 0;
 							break;
 						}
 					}
 					if (ok) {	
 						ans.pb(mp(x, y));
 						found = 1;
 						break;
 					}
 				}
 				if (found) break;
 			}
 			if (!found) return 0;
 		}
 
 		vector<pii> tmp(n);
 		rept(i, n) tmp[mas[i].y] = ans[i];
 		ans = tmp;
 		return 1;
 	}
 	void run() {
 		// put an answer into pAns
 		sort(mas, mas + n);
 		if (solve()) {
 			pAns->ans = ans;
 			return;
 		}
 		reverse(mas, mas + n);
 		if (solve()) {
 			pAns->ans = ans;
 			return;
 		}
 		while (1) {
 			random_shuffle(mas, mas + n);
 			if (solve()) {
 				pAns->ans = ans;
 				return;
 			}
 		}
 		
 		pAns->ans = ans;
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
 	freopen("B-small-attempt1.in", "r", stdin);
 	freopen("output.txt", "w", stdout);
 
 	char tmp[333];
 	int kolt = 0;
 	gets(tmp);
 	sscanf(tmp, "%d", &kolt);
 	solveParallel(kolt);
 	//solveSequential(kolt);
 }
