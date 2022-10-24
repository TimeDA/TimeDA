#include <bits/stdc++.h>
 using namespace std;
 
 #define FOR(i,a,b) for (int i = (a); i < (b); ++i)
 #define FORD(i,b,a) for (int i = (int)(b)-1; i >= (a); --i)
 #define REP(i,N) FOR(i,0,N)
 #define st first
 #define nd second
 #define pb push_back
 #define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
 
 typedef pair<int, int> PII;
 typedef long long LL;
 
 namespace flow {
   // MAX FLOW MIN COST O(V^2F)
   // Adam Polak
 
   // Usage: vide push-relabel
 
   const int N = 10000;
   const int INF = 1000*1000*1000;
 
   struct edge {
       int from, v;
       int cost,cap,dist,flow;
       int revIndex;
       bool residual() { return flow<cap; }
       edge(int _f, int _v, int _cap, int _cost):
           from(_f),v(_v),cost(_cost),dist(_cost),cap(_cap),flow(0){}
   };
 
   int n,s,t,d[N];
   vector<edge>::iterator p[N];
   vector<edge> g[N];
 
   bool queued[N];
   void bellmanFord() {
       REP(i,n) { d[i]=INF; queued[i]=0; }
       queue<int> q;
       d[s]=0; q.push(s); queued[s]=0;
       while(!q.empty()) {
           int u=q.front(); q.pop(); queued[u]=0;
           FOREACH(i, g[u])
               if (i->residual() && d[i->v] > d[u]+i->dist) {
                   d[i->v] = d[u]+i->dist;
                   p[i->v] = i;
                   if (!queued[i->v]) { q.push(i->v); queued[i->v]=1; }
               }
       }
   }
 
   void dijkstra() {
       REP(i,n) { d[i]=INF; }
       priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > q;
       d[s]=0; q.push(make_pair(0,s));
       while(!q.empty()) {
           int u = q.top().second;
           int dist = q.top().first;
           q.pop();
           if (dist!=d[u]) continue;
           FOREACH(i, g[u])
               if (i->residual() && d[i->v] > d[u]+i->dist) {
                   d[i->v] = d[u]+i->dist;
                   p[i->v] = i;
                   q.push(make_pair(d[i->v],i->v));
               }
       }
   }
 
   void usePotentials() {
       REP(u,n) FOREACH(i, g[u])
           i->dist = i->dist + d[i->from] - d[i->v];
   }
 
   // Mozna (za/od)komentowac linie z gwiazdkami - w praktyce bywa szybciej
   int FLOW, COST;
   void fordFulkerson() {
       FLOW = COST = 0;
       bellmanFord();       // *
       usePotentials();     // *
       for(;;) {
           // bellmanFord();   // * dijkstra sux ;)
           dijkstra();      // *
           usePotentials(); // *
           if (d[t]==INF) break;
           int cost = 0;
           for(int u=t;u!=s;u=p[u]->from) {
               p[u]->flow++;
               g[p[u]->v][p[u]->revIndex].flow--;
               cost += p[u]->cost;
           }
           FLOW ++; COST += cost;
       }
   }
 
   void addEdge(int a, int b, int f, int c) {
       assert(a != b);  // NIE wrzucac petelek!
       g[a].push_back(edge(a,b,f,c));
       g[b].push_back(edge(b,a,0,-c));
       g[a].back().revIndex = g[b].size()-1;
       g[b].back().revIndex = g[a].size()-1;
   }
 };
 
 int C;
 vector<pair<int, PII>> tours[2000];
 
 void read_input() {
   scanf("%d", &C);
   REP(i,C) tours[i].clear();
   REP(i,C)REP(j,2) {
     int e, l, d;
     scanf("%d%d%d", &e, &l, &d);
     tours[i].push_back(make_pair(e-1, PII(l, d)));
   }
 }
 
 void scase() {
   int result = 0;
   flow::n = 4*C + 4;
   flow::s = 4*C;
   flow::t = 4*C+1;
   int w1 = 4*C + 2, w2 = 4*C + 3;
 
   REP(i, flow::n) flow::g[i].clear();
 
   flow::addEdge(w1, flow::t, 1, 0);
   flow::addEdge(w2, flow::t, 1, 0);
 
   REP(i,C)REP(j,2) {
     result += tours[i][j].nd.nd;
 
     flow::addEdge(flow::s, 2*i+j, 1, 0);
     if (i > 0) {
       flow::addEdge(2*C + 2*i + j, flow::t, 1, 0);
     } else {
       flow::addEdge(2*C + 2*i + j, w1, 1, tours[0][1-j].nd.st);
     }
 
 
     int dest = tours[i][j].st;
     if (dest == 0) {
       flow::addEdge(2*i+j, w2, 1, 0);
     }
 
     REP(k,2) {
       int delay = tours[dest][k].nd.st - (tours[i][j].nd.st + tours[i][j].nd.nd);
       delay = ((delay % 24) + 24) % 24;
       flow::addEdge(2*i+j, 2*C + 2*dest + k, 1, delay);
     }
   }
 
   flow::fordFulkerson();
   printf("%d\n", result + flow::COST);
 }
 
 struct TestCaseConfig {
   int offset = 0;
   bool readAndPass = false;
 };
 
 TestCaseConfig read_config(int argc, const char* argv[]) {
   TestCaseConfig cfg;
 
   int argi = 0;
   while (argi < argc) {
     const char* arg = argv[argi++];
     if (strcmp(arg, "--read-and-pass") == 0) {
       cfg.readAndPass = true;
     } else if (strcmp(arg, "--case-offset") == 0 && argi < argc) {
       cfg.offset = atoi(argv[argi++]);
     }
   }
 
   return cfg;
 }
 
 int main(int argc, const char* argv[]) {
   TestCaseConfig cfg = read_config(argc, argv);
 
   int C;
   scanf("%d",&C);
   FOR(i,1,C+1) {
     read_input();
     if (cfg.readAndPass) {
       continue;
     }
     printf("Case #%d: ", i + cfg.offset);
     scase();
   }
 
   if (cfg.readAndPass) {
     int MAX_LINE = 20000000;
     char* buffer = new char[MAX_LINE];
     while (fgets(buffer, MAX_LINE, stdin)) {
       fputs(buffer, stderr);
     }
   }
 }
