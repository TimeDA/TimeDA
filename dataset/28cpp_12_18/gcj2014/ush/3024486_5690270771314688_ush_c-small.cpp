
 #include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cctype>
 #include <cmath>
 #include <cassert>
 #include <iostream>
 #include <sstream>
 #include <string>
 #include <algorithm>
 #include <vector>
 #include <map>
 #include <queue>
 #include <set>
 #include <list>
 #include <complex>
 #include <numeric>
 #include <limits>
 using namespace std;
 typedef long long ll;
 
 #define REP(i,n) for(int i = 0; i < (int)(n); ++i)
 #define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
 
 unsigned myrand() {
   static unsigned x = 123456789, y = 362436069, z = 521288629, w = 88675123;
   unsigned t = x ^ (x << 11); x = y; y = z; z = w;
   return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
 }
 
 struct K{
   char type;
   int id;
   int mid;
 };
 K evs[1000+10];
 
 
 
 class Matching {
 private:
   int nL, nR;
   vector<vector<int> > g; // g[vL][i] = vR
   vector<int> matching, dist;
   bool dfs(int vL) {
     REP(i, g[vL].size()){
       int vR = g[vL][i];
       int nextL = matching[vR];
       if(nextL == -1 || dist[nextL] == dist[vL] + 1 && dfs(nextL)){
 	matching[vR] = vL;
 	matching[vL] = vR;
 	return true;
       }
     }
     dist[vL] = -3;
     return false;
   }
   bool bfs() {
     bool res = false;
     queue<int> q;
     dist.assign(nL, -3);
     REP(vL, nL)
       if(matching[vL] == -1)
 	q.push(vL), dist[vL] = 0;
     while(!q.empty()){
       int vL = q.front(); q.pop();
       REP(i, g[vL].size()){
 	int nextL = matching[g[vL][i]];
 	if(nextL == -1)
 	  res = true;
 	else if(dist[nextL] == -3)
 	  q.push(nextL), dist[nextL] = dist[vL]+1;
       }
     }
     return res;
   }
 public:
   Matching(int nL, int nR) : nL(nL), nR(nR), g(nL) {}
   void addEdge(int vL, int vR) { g[vL].push_back(nL+vR); }
   int match() {
     int res = 0;
     for(matching.assign(nL+nR, -1); bfs(); )
       REP(vL, nL)
 	res += matching[vL] == -1 && dfs(vL);
     return res;
   }
   int partner(int vR) { return matching[nL+vR]; }
 };
 
 
 int main(void) {
   int nCase;
   scanf("%d", &nCase);
   REP(iCase, nCase) {
     int n;
     scanf("%d", &n);
     
     REP(i, n){
 //       char type;
 //       int id;
       scanf(" %c %d", &evs[i].type, &evs[i].id);
     }
     
     set<int> inside, outside;
     int entercount = 0;
     int leavecount = 0;
     bool possible = true;
     REP(i, n){
       K& e = evs[i];
       if(e.type == 'E'){
 	e.mid = entercount++;
 	if(e.id == 0){ // ? enter
 	  for(int j = i + 1; j < n; ++j){
 	    if(evs[j].type == 'L' && outside.count(evs[j].id)){
 	      e.id = evs[j].id;
 	      outside.erase(evs[j].id);
 	      inside.insert(evs[j].id);
 	      break;
 	    }
 	  }
 	  
 	}else{ // id enter
 	  if(inside.count(e.id)){
 	    possible = false;
 	    break;
 	  }else{
 	    inside.insert(e.id);
 	  }
 	}
 	
       }else{
 	e.mid = leavecount++;
 	if(e.id == 0){ // ? leave
 	  if(entercount == 0)
 	    continue;
 	  for(int j = i + 1; j < n; ++j){
 	    if(evs[j].type == 'E' && inside.count(evs[j].id)){
 	      e.id = evs[j].id;
 	      inside.erase(evs[j].id);
 	      outside.insert(evs[j].id);
 	      break;
 	    }
 	  }
 	  
 	}else{ // id leave
 	  if(outside.count(e.id)){
 	    possible = false;
 	    break;
 	  }else{
 	    outside.insert(e.id);
 	  }
 	  
 	}
 	
       }
     }
     
 //     cerr << "HOGE" << iCase+1 << endl;
     printf("Case #%d: ", iCase+1);
     if(possible){
       Matching m(entercount, leavecount);
       REP(i, n){
 	K& e = evs[i];
 	if(e.type == 'E'){
 	  for(int j = i+1; j < n; ++j){
 	    if(evs[j].type == 'L' && (e.id == evs[j].id || e.id == 0 || evs[j].id == 0)){
 	      m.addEdge(e.mid, evs[j].mid);
 	    }
 	  }
 	}
       }
 //       cerr << "PIYO" << endl;
       int res = m.match();
       printf("%d\n", entercount - res);
       
     }else{
       printf("CRIME TIME\n");
     }
 //     cerr << "FUGA" << iCase+1 << endl;
   }
   return 0;
 }
