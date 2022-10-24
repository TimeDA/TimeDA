#include <cstdio>
 #include <vector>
 #include <cstring>
 
 using namespace std;
 
 #define INFINITE 1000000
 #define MAXSIZE 100005
 
 struct Edge {
    int a, b;
    int c;
    int f;
 };
 
 int N, source, sink;
 vector<Edge> graph[MAXSIZE];
 
 Edge *getEdge(int a, int b) {
    for (int i = 0 ; i < graph[a].size() ; i++) {
       if (graph[a][i].b == b)
          return &graph[a][i];
    }
    Edge e;
    e.a = a;
    e.b = b;
    e.c = 0;
    e.f = 0;
    graph[a].push_back(e);
 
    return &graph[a][graph[a].size() - 1];
 }
 
 int maxflow() {
    static int queue[MAXSIZE];
    static Edge *from[MAXSIZE];
    static int front, rear;
    static int now;
    static int to;
    static int flow;
 
    for (int i = 0 ; i < N ; i++) {
       for (int j = 0 ; j < graph[i].size() ; j++) {
          getEdge(graph[i][j].b, i);
       }
    }
 
    bool change = true;
    while (change) {
       change = false;
 
       memset(from, 0, N*sizeof(Edge *));
 
       front = rear = 0;
       queue[rear++] = source;
       while (front < rear) {
          now = queue[front++];
 
          for (int i = 0 ; i < graph[now].size() ; i++) {
             if (graph[now][i].c - graph[now][i].f == 0 || graph[now][i].b == source) continue;
 
             to = graph[now][i].b;
             if (to == sink) {
                flow = graph[now][i].c - graph[now][i].f;
                for (Edge *j = from[now] ; j ; j = from[j->a]) {
                   if (flow > j->c - j->f)
                      flow = j->c - j->f;
                }
                if (flow) {
                   graph[now][i].f += flow;
                   Edge *edge = getEdge(to, now);
                   edge->f = -graph[now][i].f;
                   for (Edge *j = from[now] ; j ; j = from[j->a]) {
                      j->f += flow;
                      edge = getEdge(j->b, j->a);
                      edge->f = -(j->f);
                   }
                   change = true;
                }
             }
             else if (from[to] == 0) {
                queue[rear++] = to;
                from[to] = &graph[now][i];
             }
          }
       }
    }
 
    int result = 0;
    for (int i = 0 ; i < graph[source].size() ; i++)
       result += graph[source][i].f;
 
    return result;
 }
 
 int a[505][505];
 
 int main()
 {
 	int T;
 	scanf("%d", &T);
 	for (int cn = 1; cn <= T; ++cn)
 	{
 		memset(a, 0, sizeof(a));
 
 		int w, h, b;
 		scanf("%d%d%d", &w, &h, &b);
 //		printf("w = %d, h = %d\n", w, h);
 		source = 0;
 		sink = 2 * w * h + 1;
 		N = sink + 1;
 
 		for (int i = 0; i < N; ++i)
 			graph[i].clear();
 		Edge e;
 		e.f = 0;
 		e.c = 1;
 		
 		for (int i = 0; i < b; ++i)
 		{
 			int x0, y0, x1, y1;
 			scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
 			for (int j = x0; j <= x1; ++j)
 				for (int k = y0; k <= y1; ++k)
 					a[j][k] = 1;
 		}
 
 		// make graph
 		for (int i = 0; i < w; ++i)
 			for (int j = 0; j < h; ++j)
 			{
 				e.a = w * j + i + 1;
 				e.b = (w * h) + w * j + i + 1;
 				if (a[i][j] == 0)
 				{
 					graph[e.a].push_back(e);
 				}
 			}
 		for (int i = 0; i < w; ++i)
 			for (int j = 0; j < h; ++j)
 			{
 				if (i != w - 1 && a[i][j] == 0 && a[i + 1][j] == 0)
 				{
 					e.a = (w * h) + w * j + i + 1;
 					e.b = w * j + (i + 1) + 1;
 					graph[e.a].push_back(e);
 					e.a = (w * h) + w * j + (i + 1) + 1;
 					e.b = w * j + i + 1;
 					graph[e.a].push_back(e);
 				}
 				if (j != h - 1 && a[i][j] == 0 && a[i][j + 1] == 0)
 				{
 					e.a = (w * h) + w * j + i + 1;
 					e.b = w * (j + 1) + i + 1;
 					graph[e.a].push_back(e);
 					e.a = (w * h) + w * (j + 1) + i + 1;
 					e.b = w * j + i + 1;
 					graph[e.a].push_back(e);
 				}
 			}
 		for (int i = 0; i < w; ++i)
 		{
 			if (a[i][0] == 0)
 			{
 				e.a = source;
 				e.b = i + 1;
 				graph[e.a].push_back(e);
 			}
 		}
 		for (int i = 0; i < w; ++i)
 		{
 			if (a[i][h - 1] == 0)
 			{
 				e.a = (w * h) + w * (h - 1) + i + 1;
 				e.b = sink;
 				graph[e.a].push_back(e);
 			}
 		}
 /*
 		for (int i = 0; i < N; ++i)
 		{
 			printf("%d: ", i);
 			for (int j = 0; j < graph[i].size(); ++j)
 				printf("%d, ", graph[i][j].b);
 			printf("\n");
 		}
 */
 		int result = maxflow();
 		printf("Case #%d: %d\n", cn, result);
 	}
 }
 
