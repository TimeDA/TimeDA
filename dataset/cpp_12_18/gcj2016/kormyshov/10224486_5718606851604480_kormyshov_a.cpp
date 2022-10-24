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
 #define MAX_T 101
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
 	string ans;
 	friend ostream& operator <<(ostream& out, const Answer &a){
 		out<<a.ans;
 		//out<< setprecision(12) <<a.ans;
 		return out;
 	}
 };
 Answer ans[MAX_T];
 
 char get_char(char c){
 	if(c == 'R') return 'S';
 	if(c == 'P') return 'R';
 	return 'P';
 }
 
 string str[MAX_Threads];
 void rec(int num_th, char ch, int l, int r) {
 	if(l+1 == r){
 		str[num_th][l] = ch;
 		return ;
 	}
 	int mid = (l+r)/2;
 	rec(num_th, ch, l, mid);
 	rec(num_th, get_char(ch), mid, r);
 }
 
 void* solve(void *_id){
 	const int id = *(int*)_id;
 	const int num_th = thread_pop();
 	// считывание данных из потока in
 
 	int n;
 	in >> n;
 	int m[3];
 	in >> m[1] >> m[0] >> m[2];
 
 	// завершение считывания
 	sem_post(&sem[id+1]);
 	// основное решение
 
 	str[num_th] = "";
 	for(int i=0; i<(1<<n); ++i) str[num_th] += " ";
 
 	string s = "PRS";
 	int i;
 	for(i=0; i<3; ++i){
 		rec(num_th, s[i], 0, 1<<n);
 		int mas[3] = {0, 0, 0};
 		for(int j=0; j< (1<<n); ++j)
 			if(str[num_th][j] == 'P') mas[0]++;
 			else if(str[num_th][j] == 'R') mas[1]++;
 			else mas[2]++;
 		if(m[0]==mas[0] && m[1]==mas[1] && m[2]==mas[2]) break;
 	}
 
 	string res = "IMPOSSIBLE";
 	if(i!=3) {
 		res = str[num_th];
 		for(int step = 1; step < (1<<n); step<<=1){
 			for(int j=0; j < (1<<n); j += 2 * step){
 				int f = 0;
 				for(int k=0; k<step && !f; ++k){
 					if(res[j+k] < res[j+k+step]) f = -1;
 					if(res[j+k] > res[j+k+step]) f =  1;
 				}
 				if(f == 1)
 					for(int k=0; k<step; ++k)
 						swap(res[j+k], res[j+k+step]);
 			}
 		}
 	}
 
 	// окончание решения
 	//sem_wait(&sem[id]);
 	// вывод данных
 
 	ans[id].ans = res;
 
 
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
