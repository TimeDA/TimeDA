#include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <queue>
 #define RI(x) scanf("%d", &x)
 #define PI(x) printf("%d\n", (x))
 #define FOR(i,s,e) for (int i=(s); i<(e); i++)
 #define FOE(i,s,e) for (int i=(s); i<=(e); i++)
 #define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
 #define CLR(a,x) memset(a, x, sizeof(a))
 #define EXP(i,l) for (int i=(l); i; i=qn[i])
 #define LLD long long
 using namespace std;
 
 
 int n, m;
 priority_queue<int> q;
 
 int main(){int tc;scanf("%d", &tc);FOE(TC,1,tc){printf("Case #%d: ", TC);
 	RI(n), RI(m);
 	while (!q.empty()) q.pop();
 	q.push(n);
 	FOR(i,0,m){
 		int t = q.top(); q.pop();
 		t--;
 		int l = t/2, r = t-l;
 		q.push(l), q.push(r);
 		if (i == m-1) printf("%d %d\n", r, l);
 	}
 }return 0;}
