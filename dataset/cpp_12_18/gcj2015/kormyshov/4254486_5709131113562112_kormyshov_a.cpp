#include <iostream>
 #include <fstream>
 #include <sstream>
 #include <cstdio>
 #include <cstring>
 #include <memory.h>
 #include <cmath>
 #include <iomanip>
 #include <pthread.h>
 #include <semaphore.h>
 
 #include <vector>
 #include <queue>
 #include <deque>
 #include <stack>
 #include <set>
 #include <map>
 #include <unordered_set>
 #include <unordered_map>
 #include <list>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 
 #define ABS(a) ((a)<0?(-(a)):(a))
 #define SIGN(a) (((a)>0)-((a)<0))
 #define SQR(a) ((a)*(a))
 #define MAX(a,b) ((a)>(b)?(a):(b))
 #define MIN(a,b) ((a)<(b)?(a):(b))
 
 #define PI (3.1415926535897932384626433832795)
 #define INF (2147483647)
 #define LLINF (9223372036854775807LL)
 #define INF2 (1073741823)
 #define EPS (0.00000001)
 
 #define MOD (1000000007)
 
 #define y1 stupid_cmath
 #define y0 stupid_cmath_too
 
 using namespace std;
 
 typedef long long LL;
 template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> &t) {return O<<"("<<t.first<<","<<t.second<<")";}
 template<typename T> ostream& operator<<(ostream &O,vector<T> &t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }
 void dout(){cout<<endl;} template<typename Head, typename... Tail> void dout(Head H, Tail... T){cout<<H<<" "; dout(T...);}
 
 class RMaxQAdd{
 	int *m, *mt;
 	int N;
 public:
 	RMaxQAdd(int n = 1000500){	// {{{
 		N = n;
 		m = new int[4*N];
 		mt = new int[4*N];
 		memset(m, 0, sizeof(int)*4*N);
 		memset(mt, 0, sizeof(int)*4*N);
 	}
 	void clear(){
 		memset(m, 0, sizeof(int)*4*N);
 		memset(mt, 0, sizeof(int)*4*N);
 	}
 						// }}}
 	RMaxQAdd(int a[], int n){	// {{{
 		N = n;
 		m = new int[4*N];
 		mt = new int[4*N];
 		init(a, 1, 0, N-1);
 		memset(mt, 0, sizeof(int)*4*N);
 	}
 								// }}}
 	RMaxQAdd(vector<int> &v){	// {{{
 		N = v.size();
 		m = new int[4*N];
 		mt = new int[4*N];
 		init(v, 1, 0, N-1);
 		memset(mt, 0, sizeof(int)*4*N);
 	}
 								// }}}
 	// {{{
 	void init(int a[], int v, int vl, int vr){
 		if(vl==vr){
 			m[v] = a[vl];
 			return ;
 		}
 		int mid = (vl+vr)>>1;
 		init(a, v<<1, vl, mid);
 		init(a, v<<1|1, mid+1, vr);
 		m[v] = MAX(m[v<<1], m[v<<1|1]);
 	}
 	void init(vector<int> &a, int v, int vl, int vr){
 		if(vl==vr){
 			m[v] = a[vl];
 			return ;
 		}
 		int mid = (vl+vr)>>1;
 		init(a, v<<1, vl, mid);
 		init(a, v<<1|1, mid+1, vr);
 		m[v] = MAX(m[v<<1], m[v<<1|1]);
 	}
 	// }}}
 	void add(int i, int d){	// {{{
 		add(i, d, 1, 0, N-1);
 	}
 	void add(int i, int d, int v, int vl, int vr){
 		if(vl==i && vr==i){
 			m[v] += d;
 			return ;
 		}
 		int mid = (vl+vr)>>1;
 		if(i<=mid) add(i, d, v<<1, vl, mid);
 		else add(i, d, v<<1|1, mid+1, vr);
 		m[v] = MAX(m[v<<1], m[v<<1|1]);
 	}
 							// }}}
 	void add(int l, int r, int d){	// {{{
 		add(l, r, d, 1, 0, N-1);
 	}
 	void add(int l, int r, int d, int v, int vl, int vr){
 		if(l>r) return ;
 		if(l<=vl && r>=vr){
 			mt[v] += d;
 			m[v] += d;
 			return ;
 		}
 		int mid = (vl+vr)>>1;
 		add(l, MIN(r, mid), d, v<<1, vl, mid);
 		add(MAX(l, mid+1), r, d, v<<1|1, mid+1, vr);
 		m[v] = MAX(m[v<<1], m[v<<1|1]) + mt[v];
 	}
 									// }}}
 	int max(int l, int r){	// {{{
 		return max(l, r, 1, 0, N-1);
 	}
 	int max(int l, int r, int v, int vl, int vr){
 		if(l>r) return -INF;
 		if(l<=vl && r>=vr) return m[v];
 		int mid = (vl+vr)>>1;
 		return std::max(max(l, MIN(r, mid), v<<1, vl, mid),
 				max(MAX(l, mid+1), r, v<<1|1, mid+1, vr))
 			  + mt[v];
 	}
 							// }}}
 };
 
 
 ifstream in("input.txt");
 ofstream out("output.txt");
 
 // Не забудь в main добавить вызов gcj_solve()
 #define MAX_T 101
 #define MAX_Threads 6
 // {{{
 sem_t sem[MAX_T], sem_count, sem_stack;
 pthread_t pthread[MAX_T];
 stack<int> thread_stack;
 
 int thread_pop(){
 	sem_wait(&sem_stack);
 	int r = thread_stack.top();
 	thread_stack.pop();
 	sem_post(&sem_stack);
 	return r;
 }
 void thread_push(int a){
 	sem_wait(&sem_stack);
 	thread_stack.push(a);
 	sem_post(&sem_stack);
 }
 // }}}
 class Answer{
 public:
 	int ans;
 	friend ostream& operator <<(ostream& out, const Answer &a){
 		out<<a.ans;
 		//out<< setprecision(12) <<a.ans;
 		return out;
 	}
 };
 Answer ans[MAX_T];
 
 LL s[MAX_Threads][1000500], m[MAX_Threads][1000500];
 LL n[MAX_Threads], d[MAX_Threads];
 RMaxQAdd rmq[MAX_Threads];
 vector<int> g[MAX_Threads][1000500];
 
 void dfs(int num_th, LL v = 0, LL mn = INF, LL mx = -INF){
 	LL l = 0;
 	l = MAX(l, s[num_th][v]);
 	l = MAX(l, mx);
 	LL r = 1000000;
 	r = MIN(r, mn+d[num_th]);
 	r = MIN(r, MIN(1000000, s[num_th][v]+d[num_th]));
 	if(l>r) return ;
 	rmq[num_th].add(l, r, 1);
 	for(auto to : g[num_th][v])
 		dfs(num_th, to, MIN(mn, s[num_th][v]), MAX(mx, s[num_th][v]));
 }
 
 void* solve(void *_id){
 	const int id = *(int*)_id;
 	const int num_th = thread_pop();
 	// считывание данных из потока in
 
 	in >> n[num_th] >> d[num_th];
 	LL s0, as, cs, rs;
 	LL m0, am, cm, rm;
 	in >> s0 >> as >> cs >> rs;
 	in >> m0 >> am >> cm >> rm;
 
 	// завершение считывания
 	sem_post(&sem[id+1]);
 	// основное решение
 
 	for(int i=0;i<n[num_th];++i)
 		g[num_th][i].clear();
 
 	s[num_th][0] = s0;
 	m[num_th][0] = -1;
 	for(int i=1;i<n[num_th];++i){
 		s0 = (s0*as + cs) % rs;
 		m0 = (m0*am + cm) % rm;
 		s[num_th][i] = s0;
 		m[num_th][i] = m0 % i;
 		g[num_th][m0%i].push_back(i);
 	}
 
 	rmq[num_th].clear();
 
 	dfs(num_th);
 
 
 
 	// окончание решения
 	//sem_wait(&sem[id]);
 	// вывод данных
 
 	ans[id].ans = rmq[num_th].max(s[num_th][0], MIN(s[num_th][0]+d[num_th], 1000000));
 
 	cout<<"Write in "<<id<<endl;
 	// окончание вывода
 	thread_push(num_th);
 	sem_post(&sem[id+1]);
 	sem_post(&sem_count);
 	pthread_exit(0);
 }
 // {{{
 void gcj_solve(){
 	cout<<"Start solver.\n";
 	int T;
 	char s[99];
 	in>>T;
 
 	sem_init(&sem_count, 0, MAX_Threads);
 	sem_init(&sem_stack, 0, 1);
 	sem_init(&sem[1], 0, 2);
 	for(int ii=2; ii<=T; ++ii) sem_init(&sem[ii], 0, 0);
 	for(int ii=0; ii<MAX_Threads; ++ii) thread_stack.push(ii);
 
 	for(int ii=0; ii<T;){
 		cout<<"Wait start "<<ii<<" thread.\n";
 		sem_wait(&sem[ii+1]);
 		sem_wait(&sem_count);
 		++ii;
 		cout<<"Go "<<ii<<" thread.\n";
 		if(pthread_create(&pthread[ii], NULL, solve, &ii) != 0){
 			sprintf(s, "Creating the %d thread", ii);
 			perror(s);
 			return ;
 		}
 	}
 	for(int ii=1; ii<=T; ++ii){
 		if(pthread_join(pthread[ii], NULL) != 0){
 			sprintf(s, "Joining the %d thread", ii);
 			perror(s);
 			return ;
 		}
 	}
 	for(int ii=1; ii<=T; ++ii) out<<"Case #"<<ii<<": "<<ans[ii]<<endl;
 	cout<<"End solver.\n";
 }
 // }}}
 int main()
 {
 	//ios_base::sync_with_stdio(0);
 
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 
 	gcj_solve();
 
 	return 0;
 }
 
 int cpp4cf_main()
 {
 	freopen("A.cpp","r",stdin);
 
 	char s[99];
 	bool f;
 
 	while(true) {
 		cin>>s;
 		if(cin.eof()) break;
 		if(strstr(s,"/*")) {
 			cin>>s;
 			if(strstr(s,"Test")) {
 				cin>>s;
 				if(strstr(s,"on")) {
 					cout<<"Output: ";
 					cpp4cf_main();
 					cout<<"\nAnswer: ";
 					f = false;
 					while(true) {
 						cin>>s;
 						if(strstr(s,"*/")) break;
 						if(strstr(s,"//")) {
 							if(f) cout<<endl;
 							else f = true;
 						}else cout<<s<<" ";
 					}
 					cout<<"\n\n";
 				}
 			}
 		}
 	}
 
 	return 0;
 }
 
