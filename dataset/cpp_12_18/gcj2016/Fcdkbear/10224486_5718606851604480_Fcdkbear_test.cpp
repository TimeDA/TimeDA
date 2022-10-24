#include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <stack>
 #include <queue>
 #include <algorithm>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <memory.h>
 #include <ctime>
 #include <bitset>
 
 using namespace std;
 
 #define ABS(a) ((a>0)?a:-(a))
 #define MIN(a,b) ((a<b)?(a):(b))
 #define MAX(a,b) ((a<b)?(b):(a))
 #define FOR(i,a,n) for (int i=(a);i<(n);++i)
 #define MEMS(a,b) memset((a),(b),sizeof(a))
 #define FI(i,n) for (int i=0; i<(n); ++i)
 #define pnt pair <int, int>
 #define mp make_pair
 #define LL long long
 #define U unsigned
 
 bool check(string t) {
 	while (t.size() > 1) {
 		string nt = "";
 		for (int i = 0; i < t.size(); i += 2) {
 			if (t[i] == t[i+1])
 				return false;
 			if (t[i] == 'P') {
 				if (t[i+1] == 'S') {
 					nt += 'S';
 				} else {
 					nt += 'P';
 				}
 			}
 			if (t[i] == 'R') {
 				if (t[i+1] == 'S') {
 					nt += 'R';
 				} else {
 					nt += 'P';
 				}
 			}
 			if (t[i] == 'S') {
 				if (t[i+1] == 'P') {
 					nt += 'S';
 				} else {
 					nt += 'R';
 				}
 			}
 		}
 		t = nt;
 	}
 	return true;
 }
 
 int main()
 {
 #ifdef Fcdkbear
         freopen("in.txt", "r", stdin);
         freopen("out.txt", "w", stdout);
         double beg = clock();
 #else
         freopen("in.txt", "r", stdin);
         freopen("out.txt", "w", stdout);
 #endif
 
         int tests;
         scanf("%d",&tests);
         FOR(testNumber, 1, tests+1) {
         	int n,r,p,s;
         	cin>>n>>r>>p>>s;
         	string res = "";
         	string t = "";
         	FOR(i,0,p) {
         		t += 'P';
         	}
         	FOR(i,0,r) {
         	        		t += 'R';
         	        	}
         	FOR(i,0,s) {
         	        		t += 'S';
         	        	}
         	do {
         		if (check(t)) {
         			if ((res == "") || (res > t))
         				res = t;
         		}
         	} while (next_permutation(t.begin(), t.end()));
         	printf("Case #%d: ",testNumber);
         	if (res == "")
         		cout<<"IMPOSSIBLE"<<endl;
         	else
         		cout<<res<<endl;
         }
 
 #ifdef Fcdkbear
         double end = clock();
         fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
 #endif
         return 0;
 }
