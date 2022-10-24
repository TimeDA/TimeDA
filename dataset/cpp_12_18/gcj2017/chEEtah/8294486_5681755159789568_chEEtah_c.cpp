#include <cstdio>
 #include <cstdlib>
 #include <cstring>
 #include <cmath>
 #include <iostream>
 #include <cassert>
 #include <sstream>
 #include <functional>
 #include <algorithm>
 #include <map>
 #include <string>
 #include <vector>
 #include <set>
 #include <queue>
 
 using namespace std;
 
 int nt;
 
 int N;
 int E[100], S[100], D[100][100];
 
 struct Event
 {
     int vertex, horse;
     long double time, left;
 
     bool operator<(const Event &e) const
     {
         if (fabs(time - e.time) > 1e-9) return time < e.time;
         if (fabs(left - e.left) > 1e-9) return left > e.left;
         if (vertex != e.vertex) return vertex < e.vertex;
         return horse < e.horse;
     }
 };
 
 long double T[100][100], L[100][100];
 
 set<Event> Q;
 
 void go(const Event &e)
 {
     if (T[e.vertex][e.horse] == -1 || T[e.vertex][e.horse] > e.time)
     {
         if (T[e.vertex][e.horse] != -1)
         {
             Event old = e;
             old.time = T[e.vertex][e.horse];
             old.left = L[e.vertex][e.horse];
             Q.erase(Q.find(old));
         }
 
         T[e.vertex][e.horse] = e.time;
         L[e.vertex][e.horse] = e.left;
         Q.insert(e);
     }
 }
 
 long double dijkstra(int from, int to)
 {
     Event e, ne;
     e.vertex = from;
     e.horse  = from;
     e.time   = 0.0;
     e.left   = E[from];
 
     for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) T[i][j] = -1;
     T[from][from] = 0;
     L[from][from] = E[from];
 
     Q.clear();
     Q.insert(e);
 
     while(!Q.empty())
     {
         e = *Q.begin();
         Q.erase(Q.begin());
         if (e.vertex == to) return e.time;
 
         for(int v = 0; v < N; v++)
             if (D[e.vertex][v] != -1)
             {
                 ne.vertex = v;
 
                 // keep the horse
                 if (e.left + 1e-9 >= D[e.vertex][v])
                 {
                     ne.horse = e.horse;
                     ne.time  = e.time + (long double)D[e.vertex][v] / S[ne.horse];
                     ne.left  = e.left - D[e.vertex][v];
 
                     go(ne);
                 }
 
                 // change the horse at e.vertex
                 if (E[e.vertex] + 1e-9 >= D[e.vertex][v])
                 {
                     ne.horse = e.vertex;
                     ne.time  = e.time + (long double)D[e.vertex][v] / S[ne.horse];
                     ne.left  = E[e.vertex] - D[e.vertex][v];
 
                     go(ne);
                 }
             }
     }
     return -1;
 }
 
 int main()
 {
 	int nt;
 	scanf("%d", &nt);
 	for(int tt = 1; tt <= nt; tt++)
 	{
 		fprintf(stderr, "test = %d\n", tt);
 		printf("Case #%d: ", tt);
 
         int Q;
         scanf("%d %d", &N, &Q);
 
         for(int i = 0; i < N; i++)
             scanf("%d %d", &E[i], &S[i]);
 
         for(int i = 0; i < N; i++)
             for(int j = 0; j < N; j++) scanf("%d", &D[i][j]);
 
         for(int q = 0; q < Q; q++)
         {
             int U, V;
             if (q) printf(" ");
 
             scanf("%d %d", &U, &V); U--; V--;
 
             printf("%.8Lf", dijkstra(U, V));
         }
         puts("");
 	}
 	return 0;
 }
