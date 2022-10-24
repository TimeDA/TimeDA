#include <cstdio>
 #include <queue>
 #include <vector>
 #include <algorithm>
 
 #define INF 1000000005
 #define SOURCE 0
 #define SINK 100040
 #define MAX_NODES 100050
 using namespace std;
 
 int dy[4] = {-1,0,1,0};
 int dx[4] = {0,1,0,-1};
 
 int _T, W, H, B;
 int x0, y0, x1, y1;
 
 bool cover[505][105];
 int inId[505][105], outId[505][105];
 
 struct aEdge {
     int p, f;
     aEdge (int _p=0, int _f=0) {
         p = _p; f = _f;
     }
 };
 
 vector <aEdge> allE[MAX_NODES];
 bool seen[MAX_NODES];
 int par[MAX_NODES];
 
 int outE[MAX_NODES], inE[MAX_NODES];
 
 int cFlow, mFlow;
 
 bool bfs() {
     for (int i = 0; i < MAX_NODES; i++) {
         seen[i] = false;
     }
     queue <int> q;
     q.push (SOURCE);
     seen[SOURCE] = true;
     par[SOURCE] = -1;
     while (!q.empty()) {
         int frQ = q.front();
         q.pop();
         for (int i = 0; i < allE[frQ].size(); i++) {
             if (!seen[allE[frQ][i].p] && allE[frQ][i].f) {
                 //printf ("pushed on %d->%d\n", frQ, allE[frQ][i].p);
                 //printf ("Flow is %d\n", allE[frQ][i].f);
                 q.push (allE[frQ][i].p);
                 par[allE[frQ][i].p] = frQ;
                 seen[allE[frQ][i].p] = true;
             }
         }
     }
     return (seen[SINK]);
 }
 
 
 void reset() {
     for (int i = 0; i < 505; i++) {
         for (int p = 0; p < 105; p++) {
             cover[i][p] = false;
         }
     }
     for (int i = 0; i < MAX_NODES; i++) {
         allE[i].clear();
     }
     mFlow = 0;
     return;
 }
     
 
 int main() {
     freopen ("q3.in", "r", stdin);
     freopen ("q3.out", "w", stdout);
     scanf ("%d", &_T);
     for (int _z=1; _z <= _T; _z++) {
         printf ("Case #%d: ", _z);
         scanf ("%d %d %d", &W, &H, &B);
         reset();
         for (int i = 0; i < B; i++) {
             scanf ("%d %d %d %d", &x0, &y0, &x1, &y1);
             for (int p = x0; p <= x1; p++) {
                 for (int t = y0; t <= y1; t++) {
                     cover[t][p] = true;
                 }
             }
         }
         int nId = 1;
         int onId = 50001;
         for (int i = 0; i < H; i++) {
             for (int p = 0; p < W; p++) {
                 inId[i][p] = nId++;
                 outId[i][p] = onId++;
                 if (!cover[i][p]) {
                     allE[inId[i][p]].push_back (aEdge (outId[i][p], 1));
                     allE[outId[i][p]].push_back (aEdge (inId[i][p], 0));
                 }
             }
         }
         //Construct graph:
         for (int i = 0; i < H; i++) {
             for (int p = 0; p < W; p++) {
                 for (int t = 0; t < 4; t++) {
                     if (i+dy[t] >= 0 && i+dy[t] < H && p+dx[t] >= 0 && p+dx[t] < W) {
                         allE[outId[i][p]].push_back (aEdge (inId[i+dy[t]][p+dx[t]], 1));
                         allE[inId[i+dy[t]][p+dx[t]]].push_back (aEdge (outId[i][p], 0));
                     }
                 }
             }
         }
         
         for (int i = 0; i < W; i++) {
             allE[SOURCE].push_back (aEdge (inId[0][i], 1));
             allE[inId[0][i]].push_back (aEdge (SOURCE, 0));
             allE[outId[H-1][i]].push_back (aEdge (SINK, 1));
             allE[SINK].push_back (aEdge (outId[H-1][i], 0));
         }
         /*
         printf ("\n");
         for (int i = 0; i < MAX_NODES; i++) {
             if (allE[i].size() == 0) continue;
             printf ("%d: %d\n", i, allE[i].size());
             for (int p = 0; p < allE[i].size(); p++) {
                 printf ("%d ", allE[i][p]);
             }
             printf ("\n");
         }
         printf ("\n\n\n\n");
         */
         //Fordfulkerson:
         int prC;
         int counter = 0;
         while (bfs()) {
             cFlow = INF;
             for (int c = SINK; c != -1; prC = c, c = par[c]) {
                 //printf ("%d ", c);
                 //Find imp out edge:
                 if (c != SINK) {
                     for (int p = 0; p < allE[c].size(); p++) {
                         if (allE[c][p].p == prC) {
                             outE[c] = p;
                             cFlow = min (cFlow, allE[c][p].f);
                         }
                     }
                 }
                 if (c != SOURCE) {
                     for (int p = 0; p < allE[c].size(); p++) {
                         if (allE[c][p].p == par[c]) {
                             inE[c] = p;
                         }
                     }
                 }
             }
             //printf ("\n%d\n", cFlow);
             for (int c = SINK; c != -1; prC = c, c = par[c]) {
                 if (c != SINK) {
                     //printf ("%d->%d\n", c, allE[c][outE[c]].p);
                     allE[c][outE[c]].f -= cFlow;
                     //printf ("%d: %d\n", c, allE[c][outE[c]].f);
                 }
                 if (c != SOURCE) {
                     //printf ("%d->%d\n", c, allE[c][inE[c]].p);
                     allE[c][inE[c]].f += cFlow;
                     //printf ("%d: %d\n", c, allE[c][inE[c]].f);
                 }
             }
             mFlow += cFlow;
             //if (counter > 10) return true;
             counter++;
         }
         printf ("%d\n", mFlow);
     }
     return 0;
 }
             
             
