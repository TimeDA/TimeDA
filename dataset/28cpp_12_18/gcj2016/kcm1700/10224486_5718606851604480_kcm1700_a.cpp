#include <cstdio>
 #include <cstdlib>
 #include <cmath>
 #include <memory>
 #include <vector>
 #include <algorithm>
 #include <thread>
 
 using namespace std;
 
 
 struct Solver
 {
   int n, r, p, s;
 
   void input()
   {
     scanf("%d%d%d%d", &n, &r, &p, &s);
   }
 
   string ans;
 
   string getRes(int n, int head)
   {
     string s;
     if (n == 0) {
       s.push_back("PRS"[head]);
       return s;
     }
 
     string s1 = getRes(n - 1, head);
     string s2 = getRes(n - 1, (head + 1) % 3);
     if (s1 < s2)
     {
       s = s1;
       s += s2;
     }
     else
     {
       s = s2;
       s += s1;
     }
     return s;
   }
 
   void solve()
   {
     // PRS
     int cnt[3] = { 1,0,0 };
     for (int i = 0; i < n; i++) {
       int ncnt[3] = {
         cnt[0] + cnt[2],
         cnt[1] + cnt[0],
         cnt[2] + cnt[1],
       };
       for (int j = 0; j < 3; j++)
         cnt[j] = ncnt[j];
     }
     int offset = -1;
     for (int j = 0; j < 3; j++) {
       if (p == cnt[j] && r == cnt[(j + 1) % 3] && s == cnt[(j + 2) % 3])
       {
         offset = j;
         break;
       }
     }
     if (offset == -1)
     {
       ans = "IMPOSSIBLE";
       return;
     }
     ans = getRes(n, (3-offset)%3);
   }
 
   void output(int testcase)
   {
     printf("Case #%d: %s\n", testcase, ans.c_str());
   }
 };
 
 int main()
 {
   int testCaseCount;
   scanf("%d", &testCaseCount);
 
   const int batchSize = 1;
   for (int testcase = 1; testcase <= testCaseCount; testcase += batchSize)
   {
     vector<unique_ptr<Solver>> solvers;
     vector<unique_ptr<thread>> threads;
     for (int batchInd = 0; batchInd < batchSize && testcase + batchInd <= testCaseCount; batchInd++)
     {
       solvers.emplace_back(new Solver());
     }
     for (auto &solver : solvers)
     {
       solver->input();
       threads.emplace_back(new thread(&Solver::solve, solver.get()));
     }
     for (int batchInd = 0; batchInd < solvers.size(); batchInd++)
     {
       threads[batchInd]->join();
       solvers[batchInd]->output(testcase + batchInd);
     }
   }
   return 0;
 }