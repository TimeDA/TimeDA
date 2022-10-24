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
   int n, K;
   vector<double> p;
   void input()
   {
     scanf("%d%d", &n, &K);
     p.resize(n);
     for (int i = 0; i < n; i++) {
       scanf("%lf", &p[i]);
     }
     sort(p.begin(), p.end());
   }
   double ans;
   void solve()
   {
     ans = 0;
     int bi = 0;
     for (int b = 0; b < (1 << n); b++) {
       int cnt = 0;
       for (int i = 0; i < n; i++) {
         if (b & (1 << i)) {
           cnt++;
         }
       }
       if (cnt != K)
         continue;
       double prob[20][20] = { 0, };
       prob[0][0] = 1;
       vector<int> selection;
       for (int i = 0; i < n; i++) {
         if (b & (1 << i))
           selection.push_back(i);
       }
       for (int i = 0; i < K; i++) {
         for (int j = 0; j <= i; j++) {
           prob[i + 1][j] += prob[i][j] * p[selection[i]];
           prob[i + 1][j+1] += prob[i][j] * (1-p[selection[i]]);
         }
       }
       if (ans < prob[K][K / 2])
       {
         ans = prob[K][K / 2];
         bi = b;
       }
     }
   }
 
   void output(int testcase)
   {
     printf("Case #%d: %.10f\n", testcase, ans);
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