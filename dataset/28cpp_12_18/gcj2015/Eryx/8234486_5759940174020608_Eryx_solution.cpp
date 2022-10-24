#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
 #include <string>
 #include <vector>
 #include <set>
 #include <map>
 #include <stdio.h>
 using namespace std;
 
 typedef vector<string> vs;
 
 #define LS <
 #define Size(x) (int(x.size()))
 
 // All macros with parameters "k,a,b" run the "k" variable in range [a,b)
 #define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)
 
 // parse a space-delimited string into a vs
 vs parsevs(string s) {
   s = s + " ";
   string q = "";
   vs res;
   FOR(l,0, Size(s)) {
     if(s[l] == ' ') { res.push_back(q); q = "";}
     else { q += s[l]; }
     }
   return res;
   }
 
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
 
 #line 10 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 map<string, int> id;
 
 string sentences[300];
 
 vector<int> sources;
 set<int> sinks;
 
 #define MAXV 5000
 
 map<int, int> edgecaps[MAXV];
 
 void addEdge(int f, int t, int c) {
   if(edgecaps[f].count(t) == 0) edgecaps[f][t] = 0;
   edgecaps[f][t] += c;
   if(edgecaps[f][t] == 0) edgecaps[f].erase(t);
   }
 
 int flow = 0;
 
 int VN;
 
 int visited[MAXV];
 
 bool findAugmentingPath(int at) {
 //printf("[at %d v=%d]\n", at, visited[at]);
   if(visited[at] == flow) return false;
 //printf("[new %d]\n", at);
   if(sinks.count(at))
     return true;
   visited[at] = flow;
 //printf("[not sink %d]\n", at);
   for(pair<int, int> p: edgecaps[at]) {
 //  printf("TO %d\n", p.first);
     if(findAugmentingPath(p.first)) {
 //    printf("EDGE %d -> %d\n", at, p.first);
       addEdge(at, p.first, -1);
       addEdge(p.first, at, 1);
       return true;
       } }
   return false;
   }
 
 bool augmentingFlow() {
 //printf("Graph:\n");
 
 //for(int s: sources) printf("SRC %d\n", s);
 //for(int s: sinks) printf("SINK %d\n", s);
 //for(int i=0; i<VN; i++) for(pair<int,int> p: edgecaps[i]) printf("%d->%d: %d\n",
 //  i, p.first, p.second);
   
   // if(flow == 3) exit(1);
   
   for(int i: sources)
     if(findAugmentingPath(i))
       return true;
   return false;
   }
 
 void solveCase() {
   int res = 0;
 
   int N = getNum();
   
   for(int i=0; i<N; i++) sentences[i] = getLine();
   
   sources.clear(); sinks.clear(); id.clear();
 
   int numwords = 0;
 
   for(int i=0; i<N; i++) {
     vs x = parsevs(sentences[i]);
     for(string s: x) 
       if(!id.count(s))
         id[s] = numwords++;
     if(i == 0) for(string s:x) 
       sources.push_back(id[s]*2);
     if(i == 1) for(string s:x) 
       sinks.insert(id[s]*2+1);
     if(i>1) for(string s: x) for(string t:x) if(s!=t) 
       addEdge(id[s]*2+1, id[t]*2, 5000);
     }
   
   for(int i=0; i<numwords; i++) addEdge(2*i, 2*i+1, 1);
   
   flow = 0; VN = numwords * 2;
 
   for(int i=0; i<VN; i++) visited[i] = -1;
   
   while(augmentingFlow()) flow++;
   
   for(int i=0; i<VN; i++) edgecaps[i].clear();
   
   printf("Case #%d: %d\n", cnum, flow);
   }
 
 #define P 1000000007
 
 int main() {
 
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
