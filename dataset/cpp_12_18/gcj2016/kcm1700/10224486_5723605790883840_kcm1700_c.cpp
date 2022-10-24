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
   int R, C;
   vector<int> p;
   void input()
   {
     scanf("%d%d", &R, &C);
     p.resize(2 * (R + C));
 
     for (int i = 0; i < (R + C); i++) {
       int a, b;
       scanf("%d%d", &a, &b);
       a--, b--;
       p[a] = b;
       p[b] = a;
     }
   }
 
   vector<string> ans;
 
   void solve()
   {
     ans.clear();
     ans.push_back("IMPOSSIBLE");
     vector<int> matched(p.size());
     vector<vector<int>> answer(R, vector<int>(C, -1));
     int n = 2 * (R + C);
     int matchcnt = 0;
     for (;;)
     {
       bool found = false;
       for (int i = 0; i < n; i++) {
         if (matched[i])
           continue;
         int cand = -1;
         for (int j = 1; j < n; j++) {
           int nj = (i + j) % n;
           if (matched[nj] == 0)
           {
             cand = nj;
             break;
           }
         }
         if (cand == p[i])
         {
           found = true;
           matchcnt += 2;
           matched[i] = 1;
           matched[cand] = 1;
 
           int r, c, s;
           if (i < C) {
             r = 0;
             c = i;
             s = 0;
           }
           else if (i < R + C) {
             r = i - C;
             c = C;
             s = 1;
           }
           else if (i < R + C + C) {
             r = R;
             c = C - (i - (R + C));
             s = 2;
           }
           else {
             r = R - (i - (R + C + C));
             c = 0;
             s = 3;
           }
 
           int dir[4][2] = {
             1, 1,
             1, -1,
             -1, -1,
             -1, 1
           };
 
           {
             int ns = s;
             bool ok = false;
             for (int trial = 0; trial < 4; trial++)
             {
               int ncr = min(r, dir[ns][0] + r);
               int ncc = min(c, dir[ns][1] + c);
               if (ncr < 0 || ncc < 0 || ncr >= R || ncc >= C)
               {
                 // impossible
                 return;
               }
               int &prev = answer[ncr][ncc];
               if (prev != -1 && prev != ns % 2)
               {
                 ns = (ns + 1) % 4;
                 continue;
               }
               ok = true;
               break;
             }
             if (!ok)
               return;
             s = ns;
           }
           pair<int, int> lastcell;
           for (;;)
           {
             int nr = r + dir[s][0];
             int nc = c + dir[s][1];
             int cr = min(r, nr);
             int cc = min(c, nc);
             if (cr < 0 || cc < 0 || cr >= R || cc >= C)
               break;
             lastcell = make_pair(cr, cc);
             if (answer[cr][cc] == -1) {
               answer[cr][cc] = s % 2;
             }
             else if (answer[cr][cc] != s % 2) {
               /* impossible */
               return;
             }
             int ns = (s + 3) % 4;
             bool finished = false;
             bool ok = false;
             for (int trial = 0; trial < 4; trial++)
             {
               int ncr = min(nr, dir[ns][0] + nr);
               int ncc = min(nc, dir[ns][1] + nc);
               if (ncr < 0 || ncc < 0 || ncr >= R || ncc >= C)
               {
                 finished = true;
                 break;
               }
               int &prev = answer[ncr][ncc];
               if (prev != -1 && prev != ns % 2)
               {
                 ns = (ns + 1) % 4;
                 continue;
               }
               ok = true;
               break;
             }
             if (finished)
               break;
 
             if (!ok)
               return;
 
             r = nr;
             c = nc;
             s = ns;
           }
 
           int er, ec, es;
           if (cand < C) {
             er = 0;
             ec = cand;
             es = 0;
           }
           else if (cand < R + C) {
             er = cand - C;
             ec = C;
             es = 1;
           }
           else if (cand < R + C + C) {
             er = R;
             ec = C - (cand - (R + C));
             es = 2;
           }
           else {
             er = R - (cand - (R + C + C));
             ec = 0;
             es = 3;
           }
 
           {
             int nr = er + dir[es][0];
             int nc = ec + dir[es][1];
             int cr = min(er, nr);
             int cc = min(ec, nc);
             if (abs(cr-lastcell.first) > 1 && abs(cc-lastcell.second) > 1)
             {
               fprintf(stderr, "FAIL\n");
             }
           }
         }
       }
       if (!found)
       {
         break;
       }
     }
     if (matchcnt == n)
     {
       ans.clear();
       for (int i = 0; i < R; i++) {
         string s;
         for (int j = 0; j < C; j++) {
           s.push_back("\\/"[answer[i][j] == 1 ? 1 : 0]);
         }
         ans.push_back(s);
       }
     }
   }
 
   void output(int testcase)
   {
     fprintf(stderr, "Output %d\n", testcase);
     printf("Case #%d:\n", testcase);
     for (auto s : ans)
     {
       puts(s.c_str());
     }
   }
 };
 
 int main()
 {
   int testCaseCount;
   scanf("%d", &testCaseCount);
 
   for (int testcase = 1; testcase <= testCaseCount; testcase ++)
   {
     Solver solver;
     solver.input();
     solver.solve();
     solver.output(testcase);
   }
   return 0;
 }