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
 #define MAX_Threads 1
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
 		if (a.ans == INF) out << "IMPOSSIBLE";
 		else out << a.ans - 1;
 		//out<< setprecision(12) <<a.ans;
 		return out;
 	}
 };
 Answer ans[MAX_T];
 
 	int mm[101][101][101][101];
 void* solve(void *_id){
 	const int id = *(int*)_id;
 	const int num_th = thread_pop();
 	// считывание данных из потока in
 
 	int h1, a1, h2, a2, b, d;
 	in >> h1 >> a1 >> h2 >> a2 >> b >> d;
 
 	// завершение считывания
 	sem_post(&sem[id+1]);
 	// основное решение
 
 	int H = h1;
 	memset(mm, 0, sizeof(mm));
 	queue<pair<pair<int,int>,pair<int,int>>> q;
 	q.push({{h1, a1},{h2, a2}});
 	mm[h1][a1][h2][a2] = 1;
 	while (!q.empty())
 	{
 		auto pp = q.front(); q.pop();
 		auto p1 = pp;
 		p1.second.first -= pp.first.second;
 		p1.second.first = max(0, p1.second.first);
 		p1.first.first -= pp.second.second * (p1.second.first > 0);
 		p1.first.first = max(0, p1.first.first);
 		if (p1.first.first && !mm[p1.first.first][p1.first.second][p1.second.first][p1.second.second])
 		{
 			mm[p1.first.first][p1.first.second][p1.second.first][p1.second.second] = 1 + mm[pp.first.first][pp.first.second][pp.second.first][pp.second.second];
 			q.push(p1);
 		}
 
 		if (b && pp.first.second < pp.second.first){
 		auto p2 = pp;
 		p2.first.second += b;
 		p2.first.second = min(pp.second.first, p2.first.second);
 		p2.first.first -= pp.second.second;
 		p2.first.first = max(0, p2.first.first);
 		if (p2.first.first && !mm[p2.first.first][p2.first.second][p2.second.first][p2.second.second])
 		{
 			mm[p2.first.first][p2.first.second][p2.second.first][p2.second.second] = 1 + mm[pp.first.first][pp.first.second][pp.second.first][pp.second.second];
 			q.push(p2);
 		}
 		}
 
 		if (pp.first.first < H){
 		auto p3 = pp;
 		p3.first.first = H;
 		p3.first.first -= pp.second.second;
 		p3.first.first = max(0, p3.first.first);
 		if (p3.first.first && !mm[p3.first.first][p3.first.second][p3.second.first][p3.second.second])
 		{
 			mm[p3.first.first][p3.first.second][p3.second.first][p3.second.second] = 1 + mm[pp.first.first][pp.first.second][pp.second.first][pp.second.second];
 			q.push(p3);
 		}
 		}
 
 		if (d){
 		auto p4 = pp;
 		p4.second.second -= d;
 		p4.second.second = max(0, p4.second.second);
 		p4.first.first -= p4.second.second;
 		p4.first.first = max(0, p4.first.first);
 		if (p4.first.first && !mm[p4.first.first][p4.first.second][p4.second.first][p4.second.second])
 		{
 			mm[p4.first.first][p4.first.second][p4.second.first][p4.second.second] = 1 + mm[pp.first.first][pp.first.second][pp.second.first][pp.second.second];
 			q.push(p4);
 		}
 		}
 	}
 
 	int mn = INF;
 	for (int i = 0; i < 101; ++i)
 		for (int j = 0; j < 101; ++j)
 			for (int k = 0; k < 101; ++k)
 				if (mm[i][j][0][k])
 					mn = min(mn, mm[i][j][0][k]);
 
 	// окончание решения
 	//sem_wait(&sem[id]);
 	// вывод данных
 
 	ans[id].ans = mn;
 
 
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
 
