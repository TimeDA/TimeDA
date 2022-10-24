#include <iostream>
 #include <fstream>
 #include <cstdio>
 #include <cstring>
 #include <memory.h>
 #include <cmath>
 #include <pthread.h>
 #include <semaphore.h>
 
 #include <vector>
 #include <queue>
 #include <deque>
 #include <stack>
 #include <set>
 #include <map>
 #include <list>
 #include <algorithm>
 
 #define ABS(a) ((a)<0?(-(a)):(a))
 #define SIGN(a) (((a)>0)-((a)<0))
 #define SQR(a) ((a)*(a))
 #define MAX(a,b) ((a)>(b)?(a):(b))
 #define MIN(a,b) ((a)<(b)?(a):(b))
 
 #define PI (3.1415926)
 #define INF (2147483647)
 #define INF2 (1073741823)
 #define EPS (0.00000001)
 
 #define MOD (1000002013)
 
 #define y1 stupid_cmath
 #define y0 stupid_cmath_too
 
 using namespace std;
 
 typedef long long LL;
 template<typename T1,typename T2> ostream& operator<<(ostream &O,pair<T1,T2> t) {return O<<"("<<t.first<<","<<t.second<<")";}
 template<typename T> ostream& operator<<(ostream &O,vector<T> t){for(int _=0;_<(int)t.size();++_)O<<t[_]<<" ";return O; }
 
 ifstream in("input.txt");
 ofstream out("output.txt");
 
 #define MAX_T 21
 #define MAX_Threads 4
 sem_t sem[MAX_T], sem_count;
 pthread_t pthread[MAX_T];
 
 class Answer{
 public:
 	int ans;
 	friend ostream& operator <<(ostream& out, const Answer &a){
 		out<<a.ans;
 		return out;
 	}
 };
 
 LL price(int a, int b, int N){
 	int n = b-a;
 	return (2*N - n + 1)*1LL*n/2;
 }
 
 Answer ans[MAX_T];
 
 void* solve(void *_id){
 	int id = *(int*)_id;
 	// считывание данных
 
 	//cout<<"ok"<<endl;
 	int N, M, mm[1009][3], i, j;
 	in>>N>>M;
 	for(i=0;i<M;++i) for(j=0;j<3;++j) in>>mm[i][j];
 
 	//cout<<"ok"<<endl;
 	// завершение считывания
 	sem_post(&sem[id+1]);
 	// основное решение
 
 	LL r1=0, r2=0;
 	vector<pair<int,int> > v;
 	for(i=0;i<M;++i){
 		v.push_back(make_pair(mm[i][0], -mm[i][2]));
 		v.push_back(make_pair(mm[i][1], mm[i][2]));
 		r1 += price(mm[i][0], mm[i][1], N) *1LL* mm[i][2];
 	}
 	sort(v.begin(), v.end());
 
 	//cout<<v<<endl;
 
 	stack<pair<int,int> > st;
 	pair<int,int> p;
 
 	//cout<<"ok"<<endl;
 	for(i=0; i<(int)v.size(); ++i){
 		if(v[i].second > 0){
 			int t = v[i].second;
 			//cout<<i<<" "<<t<<endl;
 			while(t>0){
 				p = st.top();
 				st.pop();
 				int tmp = min(t, -p.second);
 				r2 += price(p.first, v[i].first, N) *1LL* tmp;
 				t -= tmp;
 				p.second += tmp;
 				if(p.second < 0) st.push(p);
 				//cout<<"   "<<tmp<<" "<<t<<endl;
 			}
 		}else{
 			st.push(v[i]);
 		}
 	}
 
 	// окончание решения
 	//sem_wait(&sem[id]);
 	// вывод данных
 
 	//out<<"Case #"<<id<<": ";
 
 	ans[id].ans = (r1-r2)%MOD;
 
 	cout<<"Write in "<<id<<endl;
 	// окончание вывода
 	sem_post(&sem[id+1]);
 	sem_post(&sem_count);
 	pthread_exit(0);
 }
 
 void gcj_solve(){
 	cout<<"Start solver.\n";
 	int T;
 	char s[99];
 	in>>T;
 
 	sem_init(&sem_count, 0, MAX_Threads);
 	sem_init(&sem[1], 0, 2);
 	for(int ii=2; ii<=T; ++ii) sem_init(&sem[ii], 0, 0);
 
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
 
 int main()
 {
 	ios_base::sync_with_stdio(0);
 
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
 
 
