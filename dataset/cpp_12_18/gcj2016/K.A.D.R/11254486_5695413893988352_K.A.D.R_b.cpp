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
 	string s1, s2;
 	inline void output() {
 		printf("Case #%d: %s %s\n", numberOfTest + 1, s1.c_str(), s2.c_str());
 	}
 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	char s1[22], s2[22];
 	tuple<ll, string, string> dp[22][2];
 	int n;
 	inline void readInput() {
 		scanf("%s%s", s1, s2);
 	}
 
 	template <class T>
 	inline void upd(T& a, T b) {
 		if (a > b) a = b;
 	}
 
 	std::tuple<ll, std::string, std::string> solve(string s1, string s2) {
 		rept(i, 22) {
 			rept(j, 2) {
 				dp[i][j] = make_tuple(2LL * INF * INF, "", "");
 			}
 		}
 		reverse(all(s1));
 		reverse(all(s2));
 		dp[0][0] = make_tuple(0, "", "");
 		ll p10 = 1;
 		int n = L(s1);
 		rept(i, n) {
 			rept(j, 2) {
 				if (get<0>(dp[i][j]) >= (ll)INF * INF) continue;
 				rept(d1, 10) {
 					if (s1[i] != '?' && s1[i] - '0' != d1) continue;
 					rept(d2, 10) {
 						if (s2[i] != '?' && s2[i] - '0' != d2) continue;
 						int diff = d1 - d2 - j;
 						int nj = 0;
 						if (diff < 0) {
 							nj = 1;
 							diff += 10;
 						}
 						ll nd = get<0>(dp[i][j]) + p10 * diff;
 						string n1 = get<1>(dp[i][j]);
 						reverse(all(n1));
 						n1 += (char)(d1 + '0');
 						reverse(all(n1));
 						string n2 = get<2>(dp[i][j]);
 						reverse(all(n2));
 						n2 += (char)(d2 + '0');
 						reverse(all(n2));
 						upd(dp[i + 1][nj], make_tuple(nd, n1, n2));
 					}
 				}
 			}
 			p10 *= 10;
 		}
 		return dp[n][0];
 	}
 
 	void run() {
 		// put an answer into pAns		
 		auto r1 = solve(s1, s2);
 		auto r2 = solve(s2, s1);
 
 		swap(std::get<1>(r2), std::get<2>(r2));
 
 		if (r1 < r2) {
 			pAns->s1 = std::get<1>(r1);
 			pAns->s2 = std::get<2>(r1);
 		}
 		else {
 			pAns->s1 = std::get<1>(r2);
 			pAns->s2 = std::get<2>(r2);
 		}
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