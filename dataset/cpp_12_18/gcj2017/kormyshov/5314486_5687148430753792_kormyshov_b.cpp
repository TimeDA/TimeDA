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
 
 ifstream in("input.txt");
 ofstream out("output.txt");
 
 // Не забудь в main добавить вызов gcj_solve()
 #define MAX_T 109
 #define MAX_Threads 4
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
 	pair<int,int> ans;
 	friend ostream& operator <<(ostream& out, const Answer &a){
 		out << a.ans.first << " " << a.ans.second;
 		//out<< setprecision(12) <<a.ans;
 		return out;
 	}
 };
 Answer ans[MAX_T];
 
 struct rib {
 	int b, u, c, f;
 	size_t back;
 };
 
 void add_rib (vector < vector<rib> > & g, int a, int b, int u, int c) {
 	rib r1 = { b, u, c, 0, g[b].size() };
 	rib r2 = { a, 0, -c, 0, g[a].size() };
 	g[a].push_back (r1);
 	g[b].push_back (r2);
 }
 
 void* solve(void *_id){
 	const int id = *(int*)_id;
 	const int num_th = thread_pop();
 	// считывание данных из потока in
 
 	int N, C, M;
 	in >> N >> C >> M;
 	vector<pair<int,int> > vp(M);
 	for (int i = 0; i < M; ++i)
 	{
 		in >> vp[i].first >> vp[i].second;
 	}
 
 	// завершение считывания
 	sem_post(&sem[id+1]);
 	// основное решение
 
 
 	int l = 1, r = M;
 	while(l < r)
 	{
 		int mid = (l + r) / 2;
 
 		set<pair<int,int>> s;
 		int cnt = 0;
 		vector<int> used(mid, 0);
 		for (int i = 0; i < M; ++i)
 		{
 			if (vp[i].second == 1)
 			{
 				s.insert(make_pair(cnt, vp[i].first));
 				if (cnt < mid)
 					used[cnt]++;
 				++cnt;
 			}
 		}
 		int cost = 0;
 		if (cnt <= mid)
 		{
 			sort(vp.begin(), vp.end());
 			vector<int> f(mid, 0);
 			for (int i = 0; i < M; ++i)
 			{
 				if (vp[i].second == 2)
 				{
 					bool fl = false;
 					for (int j = 0; j < mid; ++j)
 					{
 						if (f[j]) continue ;
 						if (s.count(make_pair(j, vp[i].first)) == 0)
 						{
 							s.insert(make_pair(j, vp[i].first));
 							f[j] = 1;
 							used[j]++;
 							fl = true;
 							break;
 						}
 					}
 					if (!fl && vp[i].first > 1)
 					{
 						for (int j = 0; j < mid; ++j)
 						{
 							if (!f[j] && used[j] < N)
 							{
 								f[j] = 1;
 								used[j]++;
 								fl = true;
 								cost++;
 								break;
 							}
 						}
 					}
 					if (!fl)
 					{
 						//++cnt;
 						cnt = mid + 1;
 						break;
 					}
 				}
 			}
 		}
 		if (cnt > mid)
 		{
 			l = mid + 1;
 		}
 		else
 		{
 			r = mid;
 		}
 
 	}
 		int mid = l;
 		set<pair<int,int>> s;
 		int cnt = 0;
 		vector<int> used(mid, 0);
 		for (int i = 0; i < M; ++i)
 		{
 			if (vp[i].second == 1)
 			{
 				s.insert(make_pair(cnt, vp[i].first));
 				if (cnt < mid)
 					used[cnt]++;
 				++cnt;
 			}
 		}
 		int cost = 0;
 		if (cnt <= mid)
 		{
 			sort(vp.begin(), vp.end());
 			vector<int> f(mid, 0);
 			for (int i = 0; i < M; ++i)
 			{
 				if (vp[i].second == 2)
 				{
 					bool fl = false;
 					for (int j = 0; j < mid; ++j)
 					{
 						if (f[j]) continue ;
 						if (s.count(make_pair(j, vp[i].first)) == 0)
 						{
 							s.insert(make_pair(j, vp[i].first));
 							f[j] = 1;
 							used[j]++;
 							fl = true;
 							break;
 						}
 					}
 					if (!fl)
 					{
 						for (int j = 0; j < mid; ++j)
 						{
 							if (!f[j] && used[j] < N)
 							{
 								f[j] = 1;
 								used[j]++;
 								fl = true;
 								cost++;
 								break;
 							}
 						}
 					}
 				}
 			}
 		}
 
 
 	//int n = 2 + C + N + M;
 	//vector < vector<rib> > g(n);
 	//int s, t;
 
 	//s = 0;
 	//t = n - 1;
 	//sort(vp.begin(), vp.end());
 	//int cnt = 0;
 	//for (int i = 0; i < M; ++i)
 	//{
 		//if (i + 1 < M && vp[i + 1] != vp[i] || i + 1 == M)
 		//{
 			//add_rib(g, vp[i].second, C + vp[i].first, cnt, 0);
 			//cnt = 0;
 		//}
 		//else
 		//{
 			//cnt++;
 		//}
 	//}
 	//for (int i = 1; i <= N; ++i)
 	//{
 		//for (int j = 1; j < i; ++j)
 		//{
 			//add_rib(g, C + i, C + j, 1009, 1);
 		//}
 	//}
 	//for (int i = 1; i <= M; ++i)
 	//{
 		//for (int j = 1; j <= N; ++j)
 		//{
 			//add_rib(g, C + j, C + N + i, 1, 0);
 		//}
 		//add_rib(g, C + N + i, t, 1009, 1009 * i);
 	//}
 
 
 	//int flow = 0,  cost = 0;
 	//while (flow < k) {
 		//vector<int> id (n, 0);
 		//vector<int> d (n, INF);
 		//vector<int> q (n);
 		//vector<int> p (n);
 		//vector<size_t> p_rib (n);
 		//int qh=0, qt=0;
 		//q[qt++] = s;
 		//d[s] = 0;
 		//while (qh != qt) {
 			//int v = q[qh++];
 			//id[v] = 2;
 			//if (qh == n)  qh = 0;
 			//for (size_t i=0; i<g[v].size(); ++i) {
 				//rib & r = g[v][i];
 				//if (r.f < r.u && d[v] + r.c < d[r.b]) {
 					//d[r.b] = d[v] + r.c;
 					//if (id[r.b] == 0) {
 						//q[qt++] = r.b;
 						//if (qt == n)  qt = 0;
 					//}
 					//else if (id[r.b] == 2) {
 						//if (--qh == -1)  qh = n-1;
 						//q[qh] = r.b;
 					//}
 					//id[r.b] = 1;
 					//p[r.b] = v;
 					//p_rib[r.b] = i;
 				//}
 			//}
 		//}
 		//if (d[t] == INF)  break;
 		//int addflow = k - flow;
 		//for (int v=t; v!=s; v=p[v]) {
 			//int pv = p[v];  size_t pr = p_rib[v];
 			//addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
 		//}
 		//for (int v=t; v!=s; v=p[v]) {
 			//int pv = p[v];  size_t pr = p_rib[v],  r = g[pv][pr].back;
 			//g[pv][pr].f += addflow;
 			//g[v][r].f -= addflow;
 			//cost += g[pv][pr].c * addflow;
 		//}
 		//flow += addflow;
 	//}
 
 
 
 	// окончание решения
 	//sem_wait(&sem[id]);
 	// вывод данных
 
 	ans[id].ans = make_pair(l, cost);
 
 
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
 
