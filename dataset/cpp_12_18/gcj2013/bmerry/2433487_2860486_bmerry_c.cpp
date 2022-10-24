#include <string>
 #include <vector>
 #include <map>
 #include <set>
 #include <queue>
 #include <stack>
 #include <cstdlib>
 #include <cstring>
 #include <cassert>
 #include <iostream>
 #include <sstream>
 #include <cstddef>
 #include <algorithm>
 #include <utility>
 #include <iterator>
 #include <numeric>
 #include <list>
 #include <complex>
 #include <cstdio>
 #include <climits>
 #include <fcntl.h>
 #include <unistd.h>
 
 // Various simple graph types
 
 #ifndef GRAPH_TYPES_CPP
 #define GRAPH_TYPES_CPP
 
 #include <vector>
 #include <cassert>
 
 template<typename EdgeType>
 struct SimpleNode
 {
     typedef EdgeType Edge;
     std::vector<Edge> edges;
 };
 
 struct SimpleEdge
 {
     int trg;
 
     SimpleEdge() {}
     explicit SimpleEdge(int trg) : trg(trg) {}
 };
 
 template<typename T = int>
 struct WeightedEdge
 {
     typedef T weight_type;
 
     int trg;
     T weight;
     WeightedEdge() {}
     WeightedEdge(int trg, T weight) : trg(trg), weight(weight) {}
 };
 
 template<typename EdgeType, typename NodeType = SimpleNode<EdgeType> >
 class GraphBase
 {
 public:
     typedef EdgeType Edge;
     typedef NodeType Node;
 
     std::vector<Node> nodes;
 
     int size() const { return nodes.size(); }
 
     int size(int id) const
     {
         assert(0 <= id && id < size());
         return nodes[id].edges.size();
     }
 
     NodeType &operator[](int id)
     {
         assert(0 <= id && id < size());
         return nodes[id];
     }
 
     const NodeType &operator[](int id) const
     {
         assert(0 <= id && id < size());
         return nodes[id];
     }
 
     explicit GraphBase(std::size_t size = 0) : nodes(size) {}
 };
 
 // Unweighted graph with arbitrary node type
 template<typename NodeType = SimpleNode<SimpleEdge> >
 class UGGraph : public GraphBase<SimpleEdge, NodeType>
 {
 public:
     // Add unidirectional edge
     void add1(int a, int b)
     {
         assert(0 <= a && a < this->size());
         assert(0 <= b && b < this->size());
         this->nodes[a].edges.push_back(SimpleEdge(b));
     }
 
     // Add bidirected edge
     void add2(int a, int b)
     {
         add1(a, b);
         add1(b, a);
     }
 
     explicit UGGraph(std::size_t size = 0) : GraphBase<SimpleEdge, NodeType>(size) {}
 };
 
 // Unweighted graph
 typedef UGGraph<> UGraph;
 
 // Weighted graph
 template<typename T = int, typename NodeType = SimpleNode<WeightedEdge<T> > >
 class WGraph : public GraphBase<WeightedEdge<T>, NodeType>
 {
 public:
     typedef typename GraphBase<WeightedEdge<T>, NodeType>::Edge::weight_type weight_type;
     typedef typename GraphBase<WeightedEdge<T>, NodeType>::Edge Edge;
     typedef typename GraphBase<WeightedEdge<T>, NodeType>::Node Node;
 
     // Add unidirectional edge
     void add1(int a, int b, T weight)
     {
         assert(0 <= a && a < this->size());
         assert(0 <= b && b < this->size());
         this->nodes[a].edges.push_back(Edge(b, weight));
     }
 
     // Add bidirectional edge
     void add2(int a, int b, T weight)
     {
         add1(a, b, weight);
         add1(b, a, weight);
     }
 
     explicit WGraph(std::size_t size = 0) : GraphBase<WeightedEdge<T>, NodeType>(size) {}
 };
 
 #endif /* GRAPH_TYPES_CPP */
 
 using namespace std;
 
 typedef vector<int> vi;
 typedef vector<string> vs;
 typedef long long ll;
 typedef complex<double> pnt;
 typedef pair<int, int> pii;
 
 #define RA(x) (x).begin(), (x).end()
 #define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
 #define SZ(x) ((int) (x).size())
 
 template<class T>
 void splitstr(const string &s, vector<T> &out)
 {
     istringstream in(s);
     out.clear();
     copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
 }
 
 template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
 
 static void redirect(int argc, const char **argv)
 {
     if (argc > 1)
     {
         int fd = open(argv[1], O_RDONLY);
         if (fd == -1) { perror(argv[1]); exit(1); }
         if (-1 == dup2(fd, 0)) { perror(argv[1]); exit(1); }
         if (-1 == close(fd)) { perror(argv[1]); exit(1); }
     }
 
     if (argc > 2)
     {
         int fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
         if (fd == -1) { perror(argv[2]); exit(1); }
         if (-1 == dup2(fd, 1)) { perror(argv[2]); exit(1); }
         if (-1 == close(fd)) { perror(argv[2]); exit(1); }
     }
 
     ios::sync_with_stdio(false);
 }
 
 struct road
 {
     int u = -1, v = -1;
     int a = -1, b = -1;
     int pid = -1;
 };
 
 struct pqitem
 {
     int trg;
     int prio;
 
     pqitem() = default;
     pqitem(int trg, int prio) : trg(trg), prio(prio) {}
     bool operator<(const pqitem &b) const
     {
         return prio > b.prio;
     }
 };
 
 static void dijkstra(const WGraph<> &g, int src, vi &prio)
 {
     int N = g.size();
     prio.clear();
     prio.resize(N, INT_MAX);
     priority_queue<pqitem> q;
     q.push(pqitem(src, 0));
     prio[src] = 0;
     while (!q.empty())
     {
         int cur = q.top().trg;
         int p = q.top().prio;
         q.pop();
         if (p != prio[cur])
             continue;
         for (const auto &e : g[cur].edges)
         {
             if (p + e.weight < prio[e.trg])
             {
                 prio[e.trg] = p + e.weight;
                 q.push(pqitem(e.trg, prio[e.trg]));
             }
         }
     }
 }
 
 static bool reachable(const WGraph<> &g, int cur, int trg, vector<bool> &usable)
 {
     if (!usable[cur])
         return false;
     else if (cur == trg)
         return true;
     else
     {
         usable[cur] = false;
         for (const auto &e : g[cur].edges)
             if (reachable(g, e.trg, trg, usable))
                 return true;
     }
     return false;
 }
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     for (int cas = 0; cas < cases; cas++)
     {
         int N, M, P;
         cin >> N >> M >> P;
 
         vector<road> roads(M);
         for (int i = 0; i < M; i++)
         {
             cin >> roads[i].u >> roads[i].v >> roads[i].a >> roads[i].b;
             roads[i].u--;
             roads[i].v--;
         }
 
         vector<int> mypath;
         for (int i = 0; i < P; i++)
         {
             int x;
             cin >> x;
             x--;
             roads[x].pid = i;
             mypath.push_back(x);
         }
 
         WGraph<> sht(N);
         for (const auto &r : roads)
             sht.add1(r.u, r.v, r.a);
 
         int travel = 0;
         int ans = -1;
         for (int i = 0; i < P; i++)
         {
             travel += roads[mypath[i]].a;
             int cur = roads[mypath[i]].v;
 
             WGraph<> g(N);
             for (const auto &r : roads)
                 g.add1(r.u, r.v, r.pid >= 0 && r.pid <= i ? r.a : r.b);
 
             vi lngDist, shtDist;
             dijkstra(g, 0, lngDist);
             dijkstra(sht, cur, shtDist);
 
             vector<bool> usable(N);
             for (int j = 0; j < N; j++)
                 usable[j] = shtDist[j] != INT_MAX && shtDist[j] + travel <= lngDist[j];
 
             if (!reachable(g, cur, 1, usable))
             {
                 ans = i;
                 break;
             }
         }
 
         cout << "Case #" << cas + 1 << ": ";
         if (ans == -1)
             cout << "Looks Good To Me\n";
         else
             cout << mypath[ans] + 1 << '\n';
     }
     return 0;
 }
