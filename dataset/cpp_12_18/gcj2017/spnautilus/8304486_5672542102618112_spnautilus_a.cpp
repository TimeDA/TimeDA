//spnauT
 #include <bits/stdc++.h>
 #define FOR(i,a,b) for(int _=b,i=a;i<_;++i)
 #define ROF(i,b,a) for(int _=a,i=b;i>_;--i)
 #define REP(n) for(int _=(n);_--;)
 #define _1 first
 #define _2 second
 #define PB push_back
 #define SZ(x) int((x).size())
 #define ALL(x) begin(x),end(x)
 #define MSET(m,v) memset(m,v,sizeof(m))
 #define MAX_PQ(T) priority_queue<T>
 #define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
 #define IO {ios_base::sync_with_stdio(0);cin.tie(0);}
 #define nl '\n'
 #define cint1(a) int a;cin>>a
 #define cint2(a,b) int a,b;cin>>a>>b
 #define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
 using namespace std;using LL=int64_t;using PII=pair<int,int>;
 using VI=vector<int>;using VL=vector<LL>;using VP=vector<PII>;
 template<class A,class B>bool mina(A&x,B&&y){return y<x?(x=forward<B>(y),1):0;}
 template<class A,class B>bool maxa(A&x,B&&y){return x<y?(x=forward<B>(y),1):0;}
 
 const int MAX_N {6};
 
 map<string,int> counts[MAX_N];
 
 int main()
 {
 	IO;
 	ifstream db("a_sup2.txt");
 	if(!db.is_open())
 	{
 		cerr << "Cannot open the answer file" << endl;
 		return 1;
 	}
 
 	FOR(i,1,MAX_N)
 	{
 		int n, m;
 		db >> n >> m;
 		assert(db.good());
 		assert(i == n);
 		assert(m > 0);
 		string s(n,'0');
 		REP(m)
 		{
 			int k;
 			db >> s >> k;
 			counts[i][s] = k;
 		}
 	}
 
 	cint1(TT);
 	FOR(T,1,TT+1)
 	{
 		string S;
 		cin >> S;
 		int N {SZ(S)};
 		int sol {1};
 		auto si = counts[N].find(S);
 		if(si != counts[N].end()) sol = si->_2;
 
 		cout << "Case #" << T << ": " << sol << nl;
 	}
 
 	return 0;
 }
 
 /*
 // I ran the following program before running this solution (it's still running)
 
 //spnauT
 #include <bits/stdc++.h>
 #define FOR(i,a,b) for(int _=b,i=a;i<_;++i)
 #define ROF(i,b,a) for(int _=a,i=b;i>_;--i)
 #define REP(n) for(int _=(n);_--;)
 #define _1 first
 #define _2 second
 #define PB push_back
 #define SZ(x) int((x).size())
 #define ALL(x) begin(x),end(x)
 #define MSET(m,v) memset(m,v,sizeof(m))
 #define MAX_PQ(T) priority_queue<T>
 #define MIN_PQ(T) priority_queue<T,vector<T>,greater<T>>
 #define IO {ios_base::sync_with_stdio(0);cin.tie(0);}
 #define nl '\n'
 #define cint1(a) int a;cin>>a
 #define cint2(a,b) int a,b;cin>>a>>b
 #define cint3(a,b,c) int a,b,c;cin>>a>>b>>c
 using namespace std;using LL=int64_t;using PII=pair<int,int>;
 using VI=vector<int>;using VL=vector<LL>;using VP=vector<PII>;
 template<class A,class B>bool mina(A&x,B&&y){return y<x?(x=forward<B>(y),1):0;}
 template<class A,class B>bool maxa(A&x,B&&y){return x<y?(x=forward<B>(y),1):0;}
 
 map<string,int> counts;
 
 ofstream fout("a_sup2.txt");
 string s;
 
 void rec(int p, int n)
 {
 	if(p < n)
 	{
 		FOR(i,0,n+1)
 		{
 			if(p == 0) cerr << "try " << n << " - " << i << endl;
 			s[p] = '0'+i;
 			rec(p+1, n);
 		}
 	}
 	else
 	{
 		string t {s}, tt {s};
 		set<string> found;
 		int sum {0};
 		for(char c: t) sum += c - '0';
 		bool valid {sum <= n};
 
 		while(found.insert(t)._2)
 		{
 			if(valid) ++counts[t];
 			valid = true; // always true after the first decay
 			tt.assign(n,'0');
 			for(char c: t) if(c > '0') ++tt[int(c-'1')];
 			swap(t, tt);
 		}
 	}
 }
 
 int main()
 {
 	IO;
 	FOR(n,1,10)
 	{
 		counts.clear();
 		s.resize(n);
 		rec(0, n);
 
 		fout << n << ' ' << SZ(counts) << nl;
 		for(const auto& p: counts) fout << p._1 << ' ' << p._2 << nl;
 		fout << flush;
 
 		cerr << "done with n = " << n << " " << SZ(counts) << endl;
 	}
 
 	return 0;
 }
 // 9: 24310
 
 */