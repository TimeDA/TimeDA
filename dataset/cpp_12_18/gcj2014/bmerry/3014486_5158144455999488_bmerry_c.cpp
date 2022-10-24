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
 
 /* Network flow */
 
 #include <vector>
 #include <cassert>
 #include <queue>
 #include <set>
 #include <stack>
 #include <algorithm>
 #include <limits>
 
 template<typename T = int>
 struct MFEdge
 {
     typedef T flow_type;
 
     int trg;
     T flow;
     T cap;
     int dual;
 
     MFEdge() {}
     MFEdge(int trg, T cap, int dual) : trg(trg), flow(0), cap(cap), dual(dual) {}
 };
 
 template<typename T = int>
 class MFGraph : public GraphBase<MFEdge<T> >
 {
 private:
     struct pqitem
     {
         int trg;
         T prio;
 
         pqitem() {}
         pqitem(int trg, T prio) : trg(trg), prio(prio) {}
 
         bool operator<(const pqitem &b) const
         {
             return prio < b.prio;
         }
     };
 public:
     typedef typename MFEdge<T>::flow_type flow_type;
     typedef typename GraphBase<MFEdge<T> >::Edge Edge;
     typedef typename GraphBase<MFEdge<T> >::Node Node;
 
     void add(int a, int b, T cap, T rcap)
     {
         assert(a >= 0 && a < this->size() && b >= 0 && b < this->size());
         if (a == b)
             return; // no use in network flow, and complicates this function
         int da = this->size(a);
         int db = this->size(b);
         this->nodes[a].edges.push_back(Edge(b, cap, db));
         this->nodes[b].edges.push_back(Edge(a, rcap, da));
     }
 
     T augment(int source, int sink)
     {
         const int N = this->size();
         const T big = std::numeric_limits<T>::max();
 
         std::vector<T> prio(N);
         std::vector<int> preve(N);
         std::priority_queue<pqitem> q;
 
         prio[source] = big;
         q.push(pqitem(source, big));
         while (!q.empty())
         {
             int cur = q.top().trg;
             T p = q.top().prio;
             q.pop();
             if (p != prio[cur])
                 continue;
             if (cur == sink)
                 break;
             for (int i = 0; i < this->size(cur); i++)
             {
                 const Edge &e = this->nodes[cur].edges[i];
                 T p2 = std::min(p, e.cap - e.flow);
                 if (p2 > prio[e.trg])
                 {
                     prio[e.trg] = p2;
                     preve[e.trg] = e.dual;
                     q.push(pqitem(e.trg, p2));
                 }
             }
         }
 
         T up = prio[sink];
         if (up > 0)
         {
             int cur = sink;
             while (cur != source)
             {
                 Edge &ed = this->nodes[cur].edges[preve[cur]];
                 Edge &e = this->nodes[ed.trg].edges[ed.dual];
                 e.flow += up;
                 ed.flow -= up;
                 cur = ed.trg;
             }
         }
         return up;
     }
 
     T make_flow(int source, int sink)
     {
         for (int i = 0; i < this->size(); i++)
             for (int j = 0; j < this->size(i); j++)
                 this->nodes[i].edges[j].flow = 0;
 
         T flow = 0;
         T up;
         while ((up = augment(source, sink)) != 0)
             flow += up;
         return flow;
     }
 
     // Returns all vertices on the source side of the cut. Call this
     // immediately after make_flow
     std::set<int> cut_vertices(int source) const
     {
         std::stack<int> st;
         st.push(source);
         std::set<int> reach;
         reach.insert(source);
         while (!st.empty())
         {
             int cur = st.top();
             st.pop();
             for (int i = 0; i < this->size(cur); i++)
             {
                 const Edge &e = this->nodes[cur].edges[i];
                 if (e.flow != e.cap && !reach.count(e.trg))
                 {
                     st.push(e.trg);
                     reach.insert(e.trg);
                 }
             }
         }
         return reach;
     }
 
     explicit MFGraph(std::size_t size = 0) : GraphBase<MFEdge<T> >(size) {}
 };
 
 
 #include <bits/stdc++.h>
 #include <fcntl.h>
 #include <unistd.h>
 
 using namespace std;
 
 /*** START OF TEMPLATE CODE ***/
 
 typedef vector<int> vi;
 typedef vector<string> vs;
 typedef long long ll;
 typedef complex<double> pnt;
 typedef pair<int, int> pii;
 
 #define RA(x) begin(x), end(x)
 #define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
 #define SZ(x) ((int) (x).size())
 
 template<class T>
 vector<T> splitstr(const string &s)
 {
     istringstream in(s);
     vector<T> out;
     copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
     return out;
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
     cin.exceptions(ios::failbit | ios::badbit);
 }
 
 /*** END OF TEMPLATE CODE ***/
 
 static const int dx[4] = {-1, 0, 1, 0};
 static const int dy[4] = {0, -1, 0, 1};
 
 struct Build
 {
     int x0, y0, x1, y1;
 };
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     for (int cas = 0; cas < cases; cas++)
     {
         int W, H, B;
         cin >> W >> H >> B;
         vector<Build> build(B);
         for (int i = 0; i < B; i++)
         {
             cin >> build[i].x0 >> build[i].y0 >> build[i].x1 >> build[i].y1;
             build[i].x1++;
             build[i].y1++;
         }
 
         int V = 2 * W * H + 2;
 
         MFGraph<> g(V);
         const int src = V - 2;
         const int sink = V - 1;
         for (int y = 0; y < H; y++)
             for (int x = 0; x < W; x++)
             {
                 int id = 2 * (y * W + x);
                 bool dead = false;
                 for (int i = 0; i < B; i++)
                     if (x >= build[i].x0 && x < build[i].x1
                         && y >= build[i].y0 && y < build[i].y1)
                     {
                         dead = true;
                         break;
                     }
                 if (!dead)
                     g.add(id, id + 1, 1, 0);
                 for (int d = 0; d < 4; d++)
                 {
                     int x2 = x + dx[d];
                     int y2 = y + dy[d];
                     if (x2 >= 0 && x2 < W && y2 >= 0 && y2 < H)
                     {
                         int id2 = 2 * (y2 * W + x2);
                         g.add(id + 1, id2, 1, 0);
                     }
                 }
                 if (y == 0)
                     g.add(src, id, 1, 0);
                 if (y == H - 1)
                     g.add(id + 1, sink, 1, 0);
             }
 
         int flow = g.make_flow(src, sink);
         cout << "Case #" << cas + 1 << ": " << flow << "\n";
     }
     return 0;
 }
