#include <cstdio>
 #include <iostream>
 #include <vector>
 #include <map>
 #include <set>
 #include <string>
 #include <cstring>
 #include <cstdlib>
 #include <cstdarg>
 #include <algorithm>
 
 void dbg(const char * fmt, ...)
 {
 #ifdef DBG1
     va_list args;
     va_start(args, fmt);
     vfprintf(stderr, fmt, args);
     va_end(args);
 
     fflush(stderr);
     fflush(stdout);
 #endif
 }
 
 using namespace std;
 
 typedef long long ll;
 typedef unsigned long long ull;
 typedef pair<int,int> pii;
 
 const int dy[] = {-1, 1, 0};
 const int dx[] = {0, 0, 1};
 
 const int N = 100;
 const int M = 100;
 
 ll hashTable[N][M];
 
 int n, m;
 bool used[N][M];
 char s[N][M];
 
 const int MAX_HASH = (1 << 22) - 1;
 
 void dfsBack(int x, int y)
 {
     //dbg("dfs %d %d\n", x, y);
     if (used[x][y])
         return;
     used[x][y] = true;
     for (int i = 0; i < 3; ++i)
     {
         if (s[x - dx[i]][y - dy[i]] != '#')
             dfsBack(x - dx[i], y - dy[i]);
     }
 }
 
 struct CellSet {
     set <pii> cells;
     ll hash;
 
     CellSet()
     {
         hash = 0;
     }
     
     void add(int x, int y)
     {
         if (cells.find(pii(x, y)) != cells.end())
             return;
         cells.insert(pii(x, y));
         hash ^= hashTable[x][y];
     }
 
     bool contains(int x, int y)
     {
         return cells.find(pii(x, y)) != cells.end();
     }
 
     void print()
     {
         for (set<pii>::iterator it = cells.begin(); it != cells.end(); ++it)
         {
             dbg("%d %d |", it -> first, it -> second);
         }
         dbg("\n");
     }
 };
 
 struct Queue {
     vector <CellSet> v;
     ll hash[MAX_HASH + 1];
     int first;
 
     void clear()
     {
         first = 0;
         v.clear();
         memset(hash, 0xFF, sizeof(hash));
     }
 
     bool empty()
     {
         return first == int(v.size());
     }
 
     CellSet& pop()
     {
         return v[first++];
     }
 
     void push(CellSet & c)
     {
         if (tryAdd(c))
             v.push_back(c);
     }
 
     bool tryAdd(const CellSet & c)
     {
         int x = c.hash & MAX_HASH;
         while (hash[x] != c.hash && hash[x] != -1)
             x = (x + 1) & MAX_HASH;
         bool res = hash[x] == -1;
         hash[x] = c.hash;
         return res;
     }
 };
 
 CellSet buildSet()
 {
     CellSet result;
     for (int i = 0; i < n; ++i)
         for (int j = 0; j < m; ++j)
             if (used[i][j])
                 result.add(i, j);
     return result;
 }
 
 Queue q;
 
 void solve2(int x0, int y0)
 {
     memset(used, 0, sizeof(used));
     dfsBack(x0, y0);
     CellSet start = buildSet();
     CellSet finish;
     finish.add(x0, y0);
 
     dbg("size = %d\n", start.cells.size()); 
 
     q.clear();
     q.push(start);
 
     bool lucky = false;
 
     while (!q.empty() && !lucky)
     {
         CellSet curSet = q.pop();
         curSet.print();
         if (curSet.hash == finish.hash)
             lucky = true;
         for (int i = 0; i < 3; ++i)
         {
             CellSet newSet;
             bool ok = true;
             for (set<pii>::iterator it = curSet.cells.begin(); it != curSet.cells.end(); ++it)
             {
                 pii newV = pii(it -> first + dx[i], it -> second + dy[i]);
                 if (s[newV.first][newV.second] == '#')
                     newV = *it;
                 {
                     ok &= start.contains(newV.first, newV.second);
                     newSet.add(newV.first, newV.second);
                 }
             }
             if (ok)
                 q.push(newSet);
             
         }
     }
 
     printf("%d %s\n", start.cells.size(), lucky ? "Lucky" : "Unlucky");
 }
 
 void solve()
 {
     scanf("%d%d\n", &n, &m);
     for (int i = 0; i < n; ++i)
         gets(s[i]);
 
     for (int i = 0; i < 10; ++i)
     {
         for (int j = 0; j < n; ++j)
             for (int k = 0; k < m; ++k)
                 if (s[j][k] == '0' + i)
                 {
                     printf("%d: ", i);
                     solve2(j, k);
                 }
     }
 }
 
 int rand31()
 {
     return (rand() << 15) ^ rand();
 }
 
 ll rand63()
 {
     return (((ll)rand31()) << 30) ^ rand31();
 }
 
 int main()
 {
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
 
     srand(100);
     for (int i = 0; i < N; ++i)
         for (int j = 0; j < M; ++j)
             hashTable[i][j] = rand63();
 
     int tt;
     scanf("%d", &tt);
     for (int ii = 0; ii < tt; ++ii)
     {
        printf("Case #%d:\n", ii + 1);
        solve(); 
     }
 
     return 0;
 }