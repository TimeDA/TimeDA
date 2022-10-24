#ifdef DEBUG_OUTPUT
 #include "debug_output.h"
 #else
 #define PRINT(x)
 #define PRINT_CONT(x)
 #define PRINT_MSG(x)
 #endif
 
 #include <iostream>
 #include <cmath>
 #include <vector>
 #include <string>
 #include <cstring>
 #include <sstream>
 #include <algorithm>
 #include <memory.h>
 #include <set>
 #include <map>
 #include <cstdio>
 #include <cassert>
 using namespace std;
 
 
 // Enlarge MSVS stack size
 #pragma comment(linker, "/STACK:16777216")
 
 #define pb push_back
 #define all(c) c.begin(), c.end()
 #define mp(x, y) make_pair(x, y)
 #define sz(x) static_cast<int>(x.size())
 typedef long long int64;
 typedef pair<int, int> ii;
 
 template<class T> T sqr(const T& t) {return t * t;}
 template<class T> T abs(const T& t) {return ((t > 0) ? (t) : (-t));}
 
 void initialize()
 {
     freopen("2.in", "r", stdin);
     freopen("2.out", "w", stdout);
 }
 
 int h, w;
 
 struct Rect
 {
     Rect(int sx_, int sy_, int ex_, int ey_):
         sx(sx_), sy(sy_), ex(ex_), ey(ey_)
     {
         if (sx > ex) swap(sx, ex);
         if (sy > ey) swap(sy, ey);
     }
 
     int sx, sy, ex, ey;
 
     bool contains(int x, int y) const {
         return (sx <= x) && (x <= ex) && (sy <= y) && (y <= ey);
     }
 };
 
 vector<Rect> rects;
 set<ii> globalCovered;
 
 void init() {
     globalCovered.clear();
     rects.clear();
 }
 
 
 bool covered(int x, int y) {
     if (globalCovered.find(ii(x, y)) != globalCovered.end()) {
         return true;
     }
 
     for (const auto& r : rects) {
         if (r.contains(x, y)) {
             globalCovered.insert(ii(x, y));
             return true;
         }
     }
     return false;
 }
 
 bool inter(int a, int b, int c, int d) {
     if (a > c || (a == c && b >= d)) {
         swap(a, c);
         swap(b, d);
     }
     return b >= c;
 }
 
 
 bool covered(int x1, int y1, int x2, int y2) {
     for (const auto& r :  rects) {
         if (inter(r.sx, r.ex, x1, x2) && inter(r.sy, r.ey, y1, y2)) {
             return true;
         }
     }
     return false;
 
     //vector<Rect> rects;
     //for (int x = x1; x <= x2; ++x) {
     //    for (int y = y1; y <= y2; ++y) {
     //        if (covered(x, y)) {
     //            return true;
     //        }
     //    }
     //}
     //return false;
 }
 
 void addRect(const Rect& rect) {
     rects.pb(rect);
 }
 
 set<ii> pointsSet;
 vector<ii> points;
 vector<vector<int>> edges;
 
 void addVertex(int x, int y) {
     if (x < 0 || x >= w || y < 0 || y >= h) {
         return;
     }
     if (covered(x, y)) {
         return;
     }
     if (pointsSet.find(ii(x, y)) != pointsSet.end()) {
         return;
     }
     points.pb(ii(x, y));
     pointsSet.insert(ii(x, y));
 }
 
 struct Vertex
 {
     Vertex(int x_, int y_, int index_) 
         : x(x_), y(y_), index(index_)
     { }
 
     int x, y, index;
 };
 
 int getIndex(ii c, ii p) {
     if (c.first == p.first && c.second > p.second) {
         return 3;
     }
     if (c.first == p.first && c.second < p.second) {
         return 1;
     }
     if (c.first > p.first && c.second == p.second) {
         return 0;
     }
     if (c.first < p.first && c.second == p.second) {
         return 2;
     }
     assert(false);
 }
 
 bool better(ii c, ii a, ii b) {
     return getIndex(c, a) < getIndex(c, b);
 }
 
 void buildGraph() {
     pointsSet.clear();
     points.clear();
     edges.clear();
 
     for (int i = 0; i < rects.size(); ++i) {
         addVertex(rects[i].sx - 1, rects[i].sy - 1);
         addVertex(rects[i].sx, rects[i].sy - 1);
         addVertex(rects[i].sx - 1, rects[i].sy);
 
         addVertex(rects[i].ex + 1, rects[i].sy - 1);
         addVertex(rects[i].ex, rects[i].sy - 1);
         addVertex(rects[i].ex + 1, rects[i].sy);
 
         addVertex(rects[i].ex + 1, rects[i].ey + 1);
         addVertex(rects[i].ex, rects[i].ey + 1);
         addVertex(rects[i].ex + 1, rects[i].ey);
         
         addVertex(rects[i].sx - 1, rects[i].ey + 1);
         addVertex(rects[i].sx, rects[i].ey + 1);
         addVertex(rects[i].sx - 1, rects[i].ey);
     }
 
     for (int x = 0; x < w; ++x) {
         addVertex(x, 0);
         addVertex(x, h - 1);
     }
 
     edges.resize(points.size());
     
     vector<Vertex> vertices;
     for (int i = 0; i < points.size(); ++i) {
         vertices.pb(Vertex(points[i].first, points[i].second, i));
     }
     
     sort(all(vertices), [] (const Vertex& a, const Vertex& b) {
         if (a.x != b.x) {
             return a.x < b.x;
         }
         return a.y < b.y;
     });
     for (int i = 0; i + 1 < vertices.size(); ++i) {
         if (vertices[i].x != vertices[i + 1].x) {
             continue;
         }
         if (!covered(vertices[i].x, vertices[i].y, vertices[i + 1].x, vertices[i + 1].y)) {
             edges[vertices[i].index].pb(vertices[i + 1].index);
             edges[vertices[i + 1].index].pb(vertices[i].index);
         }
     }
 
     sort(all(vertices), [] (const Vertex& a, const Vertex& b) {
         if (a.y != b.y) {
             return a.y < b.y;
         }
         return a.x < b.x;
     });
     for (int i = 0; i + 1 < vertices.size(); ++i) {
         if (vertices[i].y != vertices[i + 1].y) {
             continue;
         }
         if (!covered(vertices[i].x, vertices[i].y, vertices[i + 1].x, vertices[i + 1].y)) {
             edges[vertices[i].index].pb(vertices[i + 1].index);
             edges[vertices[i + 1].index].pb(vertices[i].index);
         }
     }
 
     for (int i = 0; i < edges.size(); ++i) {
         for (int k = 0; k < edges[i].size(); ++k) {
             int j = k;
             while (j > 0 && better(points[i], points[edges[i][j]], points[edges[i][j - 1]]) ) {
                 swap(edges[i][j], edges[i][j - 1]);
                 j -= 1;
             }
         }
     }
 }
 
 vector<bool> visited;
 vector<int> path;
 
 bool dfs(int v) {
     if (visited[v]) {
         return false;
     }
     visited[v] = true;
     path.pb(v);
     if (points[v].second == h - 1) {
         return true;
     }
 
     for (int i = 0; i < edges[v].size(); ++i) {
         if (dfs(edges[v][i])) {
             return true;
         }
     }
     path.pop_back();
     return false;
 }
 
 int main()
 {
     initialize();
 
     int T;
     cin >> T;
 
     for (int tt = 1; tt <= T; ++tt) {
         init();
         cerr << "TEST: " << tt << endl;
         int n;
         cin >> w >> h >> n;
         for (int i = 0; i < n; ++i) {
             int x1, y1, x2, y2;
             cin >> x1 >> y1 >> x2 >> y2;
             addRect(Rect(x1, y1, x2, y2));
         }
 
 
         int res = 0;
         while (true) {
             buildGraph();
             //std::cerr << "BBB: " << points.size() << " " << edges.size()<< endl;
             int  startPoint = -1;
             int x = w;
             for (int i = 0; i < points.size(); ++i) {
                 if (points[i].second == 0 && points[i].first < x) {
                     startPoint = i;
                     x = points[i].first;
                 }
             }
             //cerr << "SDASDASD: " << startPoint << endl;
             if (startPoint == -1) {
                 break;
             }
                 
             //for (int i = 0; i < points.size(); ++i) {
             //    cerr << "(" << points[i].first << ", " << points[i].second << ") ";
             //}
             //cerr << endl;
 
             path.clear();
             visited = vector<bool>(points.size(), false);
             if (!dfs(startPoint)) {
                 //cerr << "LLL" << endl;
                 addRect(Rect(points[startPoint].first, points[startPoint].second, points[startPoint].first, points[startPoint].second));
             } else {
                 res += 1;
                 //cerr << "RES: " << path.size() << endl;
                 //for (int i = 0; i < path.size(); ++i) {
                 //    cerr << "(" << points[path[i]].first << ", " << points[path[i]].second << ") ";
                 //}
                 //cerr << endl;
                 for (int i = 0; i + 1 < path.size(); ++i) {
                     addRect(Rect(points[path[i]].first, points[path[i]].second, points[path[i + 1]].first, points[path[i + 1]].second));
                 }
             }
         }
         cout << "Case #" << tt << ": " << res << endl;
     }
 
 
     
     return 0;
 }
