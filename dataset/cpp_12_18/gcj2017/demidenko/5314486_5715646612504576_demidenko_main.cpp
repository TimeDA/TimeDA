#include<bits/stdc++.h>
 #define ALL(c) (c).begin(), (c).end()
 using namespace std;
 using ll = long long;
 using ld = long double;
 
 
 #include <unistd.h>
 #include <wait.h>
 bool __multithreading = 1;
 const int __limitofthreads = 4;
 vector<pid_t> __ids;
 char __str[128];
 int __tests, __testsdone, __id;
 void __inctests(){
 	++__testsdone;
 	sprintf(__str, "\033[1;1Htests %d/%d done.%c",__testsdone,__tests,10);
 	cerr<<__str;
 }
 ifstream __in("input.txt");
 #define cin __in
 
 bool isbeam(char c){
 	return c=='-' || c=='|';
 }
 
 pair<pair<int,int>,int> bget(int x, int y, int vx, int vy, vector<string> &s){
 	int sx = x, sy = y;
 	int n = s.size();
 	int m = s[0].size();
 	int rev = 0;
 	for(;;){
 		x+=vx;
 		y+=vy;
 		if(x<0 || y<0 || x==n || y==m || s[x][y]=='#') return {{-1,-1},0};
 		if(isbeam(s[x][y])) return {{x,y},rev};
 		if(x==sx && y==sy) return {{-1,-1},0};
 		if(s[x][y]=='/'){
 			rev^=1;
 			if(vx==1 && vy==0) vx = 0, vy = -1; else
 			if(vx==-1 && vy==0) vx = 0, vy = 1; else
 			if(vx==0 && vy==1) vx = -1, vy = 0; else
 			if(vx==0 && vy==-1) vx = 1, vy = 0;
 		}else
 		if(s[x][y]=='\\'){
 			rev^=1;
 			if(vx==1 && vy==0) vx = 0, vy = 1; else
 			if(vx==-1 && vy==0) vx = 0, vy = -1; else
 			if(vx==0 && vy==1) vx = 1, vy = 0; else
 			if(vx==0 && vy==-1) vx = -1, vy = 0;
 		}
 	}
 }
 
 
 bool fl(int x, int y, int vx, int vy, vector<string> &s, vector<string> &to){
 	int sx = x, sy = y;
 	int n = s.size();
 	int m = s[0].size();
 	int rev = 0;
 	for(;;){
 		x+=vx;
 		y+=vy;
 		if(x<0 || y<0 || x==n || y==m || s[x][y]=='#') return true;
 		if(isbeam(s[x][y])) return false;
 		if(x==sx && y==sy) return true;
 		if(s[x][y]=='/'){
 			rev^=1;
 			if(vx==1 && vy==0) vx = 0, vy = -1; else
 			if(vx==-1 && vy==0) vx = 0, vy = 1; else
 			if(vx==0 && vy==1) vx = -1, vy = 0; else
 			if(vx==0 && vy==-1) vx = 1, vy = 0;
 		}else
 		if(s[x][y]=='\\'){
 			rev^=1;
 			if(vx==1 && vy==0) vx = 0, vy = 1; else
 			if(vx==-1 && vy==0) vx = 0, vy = -1; else
 			if(vx==0 && vy==1) vx = 1, vy = 0; else
 			if(vx==0 && vy==-1) vx = -1, vy = 0;
 		}else{
 			to[x][y] = '*';
 		}
 	}
 }
 
 map<int,set<int>> g;
 int add;
 
 void _adde(int i, int j, int ival, int jval){
 	if(ival) i+=add;
 	if(!jval) j+=add;
 	g[i].insert(j);
 }
 
 void adde(int i, int j, int ival, int jval){
 	_adde(i,j,ival,jval);
 	if(i!=j) _adde(j,i,jval,ival);
 }
 
 map<pair<int,int>,int> id;
 
 void adde(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2, int val1, int val2){
 	adde(id[p1.first], id[p2.first], val1^p1.second, val2^p2.second);
 }
 
 
 vector<int> st;
 map<int,int> pos, tin, hh;
 int tt, cn;
 map<int,int> cond;
 
 void dfs(int v){
 	tin[v] = hh[v] = ++tt;
 	pos[v] = st.size();
 	st.push_back(v);
 	
 	for(int i : g[v]){
 		if(!tin[i]) dfs(i); else
 		if(pos[i]>0) hh[v] = min(hh[v], hh[i]);
 	}
 	
 	if(hh[v]==tin[v]){
 		++cn;
 		int i;
 		do{
             i = st.back();
             pos[i] = 0;
             cond[i] = cn;
             st.pop_back();
         }while(i!=v);
 	}
 }
 
 
 void solve(int test){
 	///+++start read ALL data+++
 	
 	int n,m;
 	cin>>n>>m;
 	vector<string> s(n);
 	for(auto &r : s) cin>>r;
 	
 	///---end read data---
 	if(__multithreading){
 		if(__ids.size()>=__limitofthreads && wait(0)!=-1) __inctests();
 		__id = fork();
 		if(__id>0){
 			__ids.push_back(__id);
 			return ;
 		}
 		sprintf(__str, "thread%d.out", test);
 		freopen(__str, "w", stdout);
 	}
 	///start solution and write output
 	cout<<"Case #"<<test<<": ";
 	
 	/*cout<<endl;
 	for(string r : s) cout<<r<<endl;
 	cout<<"==="<<endl;*/
 	
 	int idcnt = 0;
 	
 	for(int i=0;i<n;++i)
 	for(int j=0;j<m;++j) if(isbeam(s[i][j])){
 		id[{i,j}] = idcnt++;
 	}
 	
 	#define imp {cout<<"IMPOSSIBLE"<<endl; return ;}
 	
 	pair<int,int> no(-1,-1);
 	add = idcnt;
 	for(int i=0;i<n;++i)
 	for(int j=0;j<m;++j){
 		auto _up = bget(i,j,-1,0,s);
 		auto _dw = bget(i,j,1,0,s);
 		auto _lf = bget(i,j,0,-1,s);
 		auto _rt = bget(i,j,0,1,s);
 		
 		auto up = _up.first; int upr = _up.second;
 		auto dw = _dw.first; int dwr = _dw.second;
 		auto lf = _lf.first; int lfr = _lf.second;
 		auto rt = _rt.first; int rtr = _rt.second;
 		
 		if(isbeam(s[i][j])){
 			if(up!=no) adde(_up, _up, 0, 0); //adde(id[up], id[up], 0^upr, 0^upr);
 			if(dw!=no) adde(_dw, _dw, 0, 0); //adde(id[dw], id[dw], 0^dwr, 0^dwr);
 			if(lf!=no) adde(_lf, _lf, 1, 1); //adde(id[lf], id[lf], 1^lfr, 1^lfr);
 			if(rt!=no) adde(_rt, _rt, 1, 1); //adde(id[rt], id[rt], 1^rtr, 1^rtr);
 		}else
 		if(s[i][j]=='.'){
 			if(up!=no && dw!=no && lf!=no && rt!=no) imp;
 			if(up==no && dw!=no && lf!=no && rt!=no) adde(_lf, _lf, 1, 1), adde(_rt, _rt, 1, 1), adde(_dw, _dw, 1, 1);
 			if(up!=no && dw==no && lf!=no && rt!=no) adde(_lf, _lf, 1, 1), adde(_rt, _rt, 1, 1), adde(_up, _up, 1, 1);
 			if(up==no && dw==no && lf!=no && rt!=no) imp;
 			if(up!=no && dw!=no && lf==no && rt!=no) adde(_dw, _dw, 0, 0), adde(_up, _up, 0, 0), adde(_rt, _rt, 0, 0);
 			if(up==no && dw!=no && lf==no && rt!=no) adde(_dw, _rt, 1, 0);
 			if(up!=no && dw==no && lf==no && rt!=no) adde(_up, _rt, 1, 0);
 			if(up==no && dw==no && lf==no && rt!=no) adde(_rt, _rt, 0, 0);
 			if(up!=no && dw!=no && lf!=no && rt==no) adde(_dw, _dw, 0, 0), adde(_up, _up, 0, 0), adde(_lf, _lf, 0, 0);
 			if(up==no && dw!=no && lf!=no && rt==no) adde(_dw, _lf, 1, 0);
 			if(up!=no && dw==no && lf!=no && rt==no) adde(_up, _lf, 1, 0);
 			if(up==no && dw==no && lf!=no && rt==no) adde(_lf, _lf, 0, 0);
 			if(up!=no && dw!=no && lf==no && rt==no) imp;
 			if(up==no && dw!=no && lf==no && rt==no) adde(_dw, _dw, 1, 1);
 			if(up!=no && dw==no && lf==no && rt==no) adde(_up, _up, 1, 1);
 			if(up==no && dw==no && lf==no && rt==no) imp
 		}
 	}
 	
 	st.push_back(-1);
 	
 	for(int i=0;i<idcnt*2;++i) if(!tin[i]) dfs(i);
 	
 	vector<int> vals(idcnt);
 	for(int i=0;i<idcnt;++i) if(cond[i]==cond[i+add]) imp else{
 		vals[i] = cond[i]<cond[i+add];
 	}
 	
 	//cerr<<"vals = "; for(int x : vals) cerr<<x<<' '; cerr<<endl;
 	
 	
 	for(int i=0;i<n;++i)
 	for(int j=0;j<m;++j) if(isbeam(s[i][j])){
 		int k = id[{i,j}];
 		s[i][j] = "-|"[vals[k]];
 	}
 	
 	
 	
 	auto to = s;
 	bool ok = true;
 	for(int i=0;i<n;++i)
 	for(int j=0;j<m;++j){
 		if(s[i][j]=='-'){
 			ok&=fl(i,j,0,-1,s,to);
 			ok&=fl(i,j,0,1,s,to);
 		}else
 		if(s[i][j]=='|'){
 			ok&=fl(i,j,-1,0,s,to);
 			ok&=fl(i,j,1,0,s,to);
 		}
 	}
 	//cout<<"==="<<endl;
 	//for(string r : to) cout<<r<<endl;
 	for(string r : to) if(count(ALL(r), '.')){
 		imp;
 	}
 	cout<<"POSSIBLE"<<endl;
 	for(string r : s) cout<<r<<endl;
 }
 
 int main(){
 	freopen("output.txt","w",stdout);
 	/*for(int m=0;m<16;++m){
 		vector<int> b(4);
 		for(int i=0;i<4;++i) b[i] = (m>>i&1);
 		string s = "!=";
 		cout<<"if(up"<<s[b[0]]<<"=no && dw"<<s[b[1]]<<"=no && lf"<<s[b[2]]<<"=no && rt"<<s[b[3]]<<"=no)"<<endl;
 	}
 	
 	return 0;*/
 	cin>>__tests;
 	for(int i=1;i<=__tests;++i){
 		solve(i);
 		if(__multithreading&&__id==0) return 0;
 	}
 	
 	///combining outputs
 	if(__multithreading){
 		for(pid_t __id : __ids) if(waitpid(__id,0,0)!=-1) __inctests();
 		int __bufsize = 1<<16;
 		char *__buf = new char[__bufsize];
 		for(int i=1;i<=__tests;++i){
 			sprintf(__str, "thread%d.out", i);
 			FILE *f = fopen(__str, "r");
 			while(fgets(__buf, __bufsize, f)) printf("%s",__buf);
 			fclose(f);
 			remove(__str);
 		}
 		delete [] __buf;
 	}
 	
 	return 0;
 }
