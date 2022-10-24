#define BUFSIZE 1000000
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 #include <algorithm>
 #include <string>
 #include <vector>
 #include <set>
 #include <stdio.h>
 using namespace std;
 
 #define LS <
 #define Size(x) (int(x.size()))
 
 // All macros with parameters "k,a,b" run the "k" variable in range [a,b)
 #define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)
 
 string getLine() {
   string s;
   while(!feof(stdin)) {
     char c = fgetc(stdin);
     if(c == 13) continue;
     if(c == 10) return s;
     s += c;
     }
   return s;
   }
 
 int scanerr;
 
 int getNum() {
 #ifdef LINEBYLINE
   string s = getLine();
   return atoi(s.c_str());
 #else
   int i;
   scanerr = scanf("%d", &i);
   return i;
 #endif
   }
 
 #ifndef BUFSIZE
 #define BUFSIZE 1000000
 #endif
 
 char buf[BUFSIZE];
 
 #include <sys/resource.h>
 
 void removeStackLimit() {
     const rlim_t kStackSize = 1600 * 1048576LL;   // min stack size = 16 MB
     struct rlimit rl;
     int result;
 
     result = getrlimit(RLIMIT_STACK, &rl);
     if (result == 0)
     {
         if (rl.rlim_cur < kStackSize)
         {
             rl.rlim_cur = kStackSize;
             result = setrlimit(RLIMIT_STACK, &rl);
             if (result != 0)
             {
                 fprintf(stderr, "setrlimit returned result = %d\n", result);
             }
         }
     }
   }
 
 #line 9 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 struct edge {
   int a, b, val;
   };
 
 vector<edge*> alledges, alledges2;
 vector<edge*> edges[3000];
 
 int lastvisit[3000];
 int visitid;
 
 #define FORBIDDEN 1000000000
 #define REVERSE 
 
 vector<edge*> cycle;
 vector<int> cyclev;
 
 int target;
 
 bool dfs(int at) {
   if(at == target) {
     cyclev.push_back(at); return true;
     }
   else if(lastvisit[at] == visitid) return false;
   else {
     lastvisit[at] = visitid;
     for(auto e: edges[at]) if(e->val != FORBIDDEN && dfs(e->b ^ e->a ^ at)) {
       cycle.push_back(e);
       cyclev.push_back(at);
       return true;
       }
     return false;
     }
   }
 
 vector<int> cands;
 
 void solveCase() {
   int res = 0;
 
   int F = getNum();
   int P = getNum();
   
   alledges.clear();
   FOR(f,1,F+1) edges[f].clear();
   
   FOR(p,0,P) {
     int a = getNum();
     int b = getNum();
     auto ed = new edge;
     ed->a = a; ed->b = b; ed->val = 0;
     edges[a].push_back(ed);
     edges[b].push_back(ed);
     alledges.push_back(ed);
     }
     
   alledges2 = alledges;
 
 again:
 
   for(auto ed: alledges) if(ed->val == 0) {
     ed->val = FORBIDDEN;
     visitid++;
     target = ed->a;
     cycle.clear(); cyclev.clear();
     if(!dfs(ed->b)) {
       printf("Case #%d: IMPOSSIBLE\n", cnum);
       return;
       }
     
     cycle.push_back(ed);
     cyclev.push_back(target);
     
     ed->val = 0;
     int L = Size(cycle);
     set<int> used;
     for(int l=0; l<L; l++)
       if(cycle[l]->a == cyclev[l]) used.insert(cycle[l]->val);
       else used.insert(-cycle[l]->val);
     
     for(int c: cands) if(!used.count(c)) {
 //    printf("applied cand=%d\n", c);
       for(int l=0; l<L; l++) {            
         if(cycle[l]->a == cyclev[l]) cycle[l]->val -= c;
           else cycle[l]->val += c;
 //      printf("%d-%d (v=%d)\n", cycle[l]->a, cycle[l]->b, cycle[l]->val);
         }
       break;
       }
     }
   
   for(auto ed: alledges) if(ed->val > F*F || ed->val < -F*F) {
     fprintf(stderr, "MAGNITUDE ERROR (%d)\n", cnum);
     for(auto ed: alledges) ed->val = 0;
     random_shuffle(alledges2.begin(), alledges2.end());
     goto again;
     }
 
   printf("Case #%d:", cnum);
   for(auto ed: alledges) printf(" %d", ed->val);
   printf("\n");
   }
 
 #define P 1000000007
 
 int main() {
 
   removeStackLimit();
   
   for(int i=1; i<6000; i++) {
     cands.push_back(i);
     cands.push_back(-i);
     }
 
   if(!MANYTESTS) Tests = 1;
   else Tests = getNum();
   
   for(cnum=1; cnum<=Tests; cnum++)
     solveCase();
     
   // finish
   return 0;
   }
 
 // This solution includes hidden routines to solve test cases in separate
 // processes in order to make it faster. I will update them to run on a
 // cluster if I get one ;)
 // See https://github.com/eryxcc/templates
