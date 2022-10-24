#include <cstdio>
 #include <queue>
 #include <cstdlib>
 #include <cstdint>
 #include <climits>
 #include <string>
 #include <cstring>
 #include <vector>
 #include <map>
 #include <set>
 
 using namespace std;
 
 struct Solver {
   int n, m;
   struct edge_t {
     int next;
     int dir; // 1, -1
     int inputind;
   };
   vector<vector<edge_t>> graph;
   vector<pair<int, int>> edgeinfo;
   vector<int> weight;
 
   Solver() : n(0), m(0), impossible(false), vcnt(0) {
   }
 
   void input() {
     scanf("%d%d", &n, &m);
     weight.resize(m);
     graph.resize(n);
     for (int i = 0; i < m; i++) {
       int a, b;
       scanf("%d%d", &a, &b);
       a--, b--;
       edgeinfo.emplace_back(a, b);
 
       struct edge_t forward = { b, 1, i };
       graph[a].emplace_back(forward);
       struct edge_t backward = { a, -1, i };
       graph[b].emplace_back(backward);
     }
   }
 
   vector<int> visit;
   int vcnt;
 
 
   vector<int> q;
   vector<int> from_q;
   vector<int> from_edge;
   bool find_way(int edgeIndex, int value)
   {
     int from = edgeinfo[edgeIndex].first;
     int to = edgeinfo[edgeIndex].second;
 
     ++vcnt;
     q.clear();
     from_q.clear();
     from_edge.clear();
 
     int tail = 0;
     q.push_back(to);
     from_q.push_back(-1);
     from_edge.push_back(-1);
     tail++;
     visit[to] = vcnt;
 
     for (int head = 0; head < tail; head++) {
       int cur = q[head];
       for (const auto &edge : graph[cur]) {
         if (edge.inputind == edgeIndex) continue;
         if (visit[edge.next] == vcnt) continue;
         if (weight[edge.inputind] + value * edge.dir == 0) continue;
 
         if (edge.next == from) {
           weight[edge.inputind] += value * edge.dir;
           weight[edgeIndex] += value;
 
           int follow = head;
           for (;;) {
             int follow_edge = from_edge[follow];
             if (follow_edge == -1) break;
             if (edgeinfo[follow_edge].first != q[follow]) {
               weight[follow_edge] += value;
             }
             else {
               weight[follow_edge] -= value;
             }
 
             follow = from_q[follow];
           }
           return true;
         }
 
         q.push_back(edge.next);
         from_q.push_back(head);
         from_edge.push_back(edge.inputind);
         tail++;
         visit[edge.next] = vcnt;
       }
     }
     return false;
   }
 
   bool find_way(int edgeIndex) {
     for (int passValue = 1; passValue <= n; passValue++) {
       if (find_way(edgeIndex, passValue)) {
         return true;
       }
       if (find_way(edgeIndex, -passValue)) {
         return true;
       }
     }
     return false;
   }
 
   bool impossible;
 
   void process() {
     visit.resize(n);
     for (int i = 0; i < m; i++) {
       if (weight[i] == 0) {
         if (!find_way(i)) {
           impossible = true;
           return;
         }
       }
     }
   }
 
   void output(FILE *fp) {
     if (impossible) {
       fprintf(fp, "IMPOSSIBLE\n");
       return;
     }
     for (int i = 0; i < m; i++) {
       fprintf(fp, "%d%c", weight[i], " \n"[i + 1 == m]);
     }
   }
 };
 
 
 #include <atomic>
 #include <mutex>
 #include <thread>
 
 constexpr int threadCount = 1;
 constexpr char outputBaseDirectory[] = "temp";
 
 struct Controller {
   mutex inputMutex;
   mutex outputMutex;
   atomic_int testcaseCount;
 
   void start() {
     int numTestCase;
     scanf("%d", &numTestCase);
     testcaseCount = 1;
 
     vector<thread> pool(threadCount);
     for (int i = 0; i < threadCount; i++) {
       pool[i] = thread([&]() {
         for (;;) {
           Solver solver;
           int testcase;
           // input phase
           {
             unique_lock<mutex> lock(inputMutex);
             testcase = testcaseCount.fetch_add(1);
             if (testcase > numTestCase) {
               fprintf(stderr, "No more testcases\n");
               return;
             }
             fprintf(stderr, "Reading Case #%d\n", testcase);
             solver.input();
           }
 
           solver.process();
 
           {
             unique_lock<mutex> lock(outputMutex);
             char filename[256];
             sprintf(filename, "%s\\case%d.out", outputBaseDirectory, testcase);
             fprintf(stderr, "Writing Case #%d\n", testcase);
             FILE *fp = fopen(filename, "w");
             if (fp == nullptr) {
               fprintf(stderr, "Error opening output file\n");
               exit(1);
             }
             fprintf(fp, "Case #%d: ", testcase);
             solver.output(fp);
             fclose(fp);
           }
         }
       });
     }
 
     for (int i = 0; i < threadCount; i++) {
       pool[i].join();
     }
 
     for (int testcase = 1; testcase <= numTestCase; testcase++) {
       char filename[256];
       sprintf(filename, "%s\\case%d.out", outputBaseDirectory, testcase);
       FILE *fp = fopen(filename, "r");
       char buffer[4096];
       for (;;) {
         int cnt = fread(buffer, 1, 4096, fp);
         if (cnt <= 0) break;
         fwrite(buffer, 1, cnt, stdout);
       }
       fclose(fp);
     }
   }
 };
 
 int main() {
   Controller controller;
   controller.start();
   return 0;
 }