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
 	string ans;
 	inline void output() {
 		printf("Case #%d: %s\n", numberOfTest + 1, ans.c_str());
 	}
 };
 
 struct Solver {
 	int _numberOfThread;
 	Answer *pAns;
 	char str[2002];
 	vector<string> ts;
 	VI words[26];
 	int cnt[26];
 	bool used[10];
 	inline void readInput() {
 		scanf("%s", str);
 	}
 
 	void run() {
 		ts = vector<string>({ "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" });
 		C(cnt);
 		int m = (int)strlen(str);
 		rept(i, m) {
 			++cnt[str[i] - 'A'];
 		}
 		
 		std::string ans;
 		
 		auto f = [&](char let, int dig) {
 			while (cnt[let - 'A'] > 0) {
 				ans += (char)(dig + '0');
 				int l = L(ts[dig]);
 				rept(i, l) {
 					--cnt[ts[dig][i] - 'A'];
 				}
 			}
 		};
 
 		f('Z', 0);
 		f('G', 8);
 		f('X', 6);
 		f('W', 2);
 		f('U', 4);
 		f('O', 1);
 		f('H', 3);
 
 		auto sub = [&](int dig, int c) {
 			int l = L(ts[dig]);
 			bool ok = 1;
 			rept(i, l) {
 				cnt[ts[dig][i] - 'A'] -= c;
 				if (cnt[ts[dig][i] - 'A'] < 0) {
 					ok = 0;
 				}
 			}
 
 			if (!ok) {
 				rept(i, l) {
 					cnt[ts[dig][i] - 'A'] += c;
 				}
 				return 0;
 			}
 
 			return 1;
 		};
 
 		rept(i5, INF) {
 			if (!sub(5, i5)) break;
 
 			rept(i7, INF) {
 				if (!sub(7, i7)) break;
 				
 				int t0 = cnt['I' - 'A'], t1 = cnt['E' - 'A'], t2 = cnt['N' - 'A'];
 				if (t0 == t1 && 2 * t0 == t2) {
 					bool ok = 1;
 					rept(i, 26) {
 						if (i + 'A' == 'I' || i + 'A' == 'E' || i + 'A' == 'N') continue;
 						if (cnt[i]) {
 							ok = 0;
 							break;
 						}
 					}
 					if (ok) {
 						rept(z, i5) ans += '5';
 						rept(z, i7) ans += '7';
 						rept(z, t0) ans += '9';
 						SORT(ans);
 						pAns->ans = ans;
 						return;
 					}
 				}
 				
 				sub(7, -i7);
 			}
 
 			sub(5, -i5);
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