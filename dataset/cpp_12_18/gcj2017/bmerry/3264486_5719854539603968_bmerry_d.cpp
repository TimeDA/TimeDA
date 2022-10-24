#include <bits/stdc++.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <semaphore.h>
 #include <sys/time.h>
 #include <sys/resource.h>
 
 using namespace std;
 
 /*** START OF TEMPLATE CODE ***/
 
 typedef vector<string> vs;
 typedef long long ll;
 typedef complex<double> pnt;
 typedef pair<int, int> pii;
 typedef vector<ll> vi;
 
 #define RA(x) begin(x), end(x)
 #define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
 #define SZ(x) ((ll) (x).size())
 
 template<class T>
 vector<T> splitstr(const string &s)
 {
     istringstream in(s);
     vector<T> out;
     copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
     return out;
 }
 
 template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
 
 static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done);
 
 namespace helpers
 {
 
 static sem_t thread_slots;
 
 class sem_poster
 {
 private:
     sem_t *sem;
 public:
     explicit sem_poster(sem_t *sem) : sem(sem) {}
     ~sem_poster() { sem_post(sem); }
     sem_poster(const sem_poster &) = delete;
     sem_poster &operator=(const sem_poster &) = delete;
 };
 
 static string run_case(int cas, unique_ptr<promise<void> > &&input_done)
 {
     sem_poster poster(&thread_slots);
     ostringstream out;
     solve_case(cas, out, move(input_done));
     return out.str();
 }
 
 } // namespace helpers
 
 int main(int argc, char * const *argv)
 {
     using namespace helpers;
     ios::sync_with_stdio(false);
     struct rlimit stack_limit;
     getrlimit(RLIMIT_STACK, &stack_limit);
     stack_limit.rlim_cur = 1024 * 1024 * 1024;
     setrlimit(RLIMIT_STACK, &stack_limit);
 
     char opt;
     int threads = thread::hardware_concurrency();
     bool threaded = false;
     while ((opt = getopt(argc, argv, "pt:")) != -1)
     {
         switch (opt)
         {
         case 'p':
             threaded = true;
             break;
         case 't':
             {
                 char *end;
                 threads = strtol(optarg, &end, 0);
                 if (end == optarg || *end || threads <= 0)
                 {
                     cerr << "Invalid thread count\n";
                     return 2;
                 }
             }
             break;
         case ':':
         case '?':
             return 2;
         }
     }
 
     if (optind < argc)
     {
         int fd = open(argv[optind], O_RDONLY);
         if (fd == -1) { perror(argv[optind]); exit(1); }
         if (-1 == dup2(fd, 0)) { perror(argv[optind]); exit(1); }
         if (-1 == close(fd)) { perror(argv[optind]); exit(1); }
     }
     if (optind + 1 < argc)
     {
         int fd = open(argv[optind + 1], O_WRONLY | O_CREAT, 0666);
         if (fd == -1) { perror(argv[optind + 1]); exit(1); }
         if (-1 == dup2(fd, 1)) { perror(argv[optind + 1]); exit(1); }
         if (-1 == close(fd)) { perror(argv[optind + 1]); exit(1); }
     }
     cin.exceptions(ios::failbit | ios::badbit);
 
     int cases;
     cin >> cases;
     if (!threaded)
     {
         for (int cas = 0; cas < cases; cas++)
             solve_case(cas, cout, unique_ptr<promise<void> >());
     }
     else
     {
         sem_init(&thread_slots, 0, threads);
         deque<future<string> > outputs;
         for (int cas = 0; cas < cases; cas++)
         {
             sem_wait(&thread_slots);
             // Flush any output we can
             while (!outputs.empty())
             {
                 auto status = outputs[0].wait_for(std::chrono::seconds(0));
                 if (status != future_status::ready)
                     break;
                 cout << outputs[0].get() << flush;
                 outputs.pop_front();
             }
             unique_ptr<promise<void> > input_done{new promise<void>()};
             auto input_done_future = input_done->get_future();
             outputs.push_back(async(launch::async, run_case, cas, move(input_done)));
             // Wait until it consumes input before continuing
             input_done_future.get();
         }
         while (!outputs.empty())
         {
             cout << outputs[0].get() << flush;
             outputs.pop_front();
         }
     }
     return 0;
 }
 
 /*** END OF TEMPLATE CODE ***/
 
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
 
 struct preplace
 {
     int t;
     int r, c;
 };
 
 static vector<pii> solve_hv(int N, const vector<preplace> &preplaced)
 {
     set<int> rows, cols;
     for (int i = 0; i < N; i++)
     {
         rows.insert(i);
         cols.insert(i);
     }
     for (const auto &pre : preplaced)
         if (pre.t & 1)
         {
             rows.erase(pre.r);
             cols.erase(pre.c);
         }
     vector<pii> ans;
     auto r = rows.begin();
     auto c = cols.begin();
     while (r != rows.end())
     {
         ans.emplace_back(*r, *c);
         ++r;
         ++c;
     }
     return ans;
 }
 
 static vector<pii> solve_diag(int N, const vector<preplace> &preplaced)
 {
     const int D = 2 * N - 1;
     const int ofs = N - 1;
     vector<bool> pused(D), mused(D);
     for (const auto &pre : preplaced)
     {
         if (pre.t & 2)
         {
             pused[pre.r + pre.c] = true;
             mused[pre.r - pre.c + ofs] = true;
         }
     }
 
     int V = 2 * D + 2;
     MFGraph<> g(V);
     int src = V - 2;
     int sink = V - 1;
     for (int i = 0; i < D; i++)
     {
         if (!pused[i])
             g.add(src, i, 1, 0);
         if (!mused[i])
             g.add(i + D, sink, 1, 0);
     }
     for (int i = 0; i < N; i++)
         for (int j = 0; j < N; j++)
             g.add(i + j, i - j + ofs + D, 1, 0);
     g.make_flow(src, sink);
     vector<pii> ans;
     for (int i = 0; i < D; i++)
         for (int j = 0; j < g.size(i); j++)
             if (g[i].edges[j].flow == 1 && g[i].edges[j].trg != src)
             {
                 int y = g[i].edges[j].trg;
                 int r = (i + (y - ofs - D)) / 2;
                 int c = i - r;
                 ans.emplace_back(r, c);
             }
     return ans;
 }
 
 static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
 {
     int N, M;
     cin >> N >> M;
     vector<preplace> preplaced(M);
     vector<vector<int>> grid(N, vector<int>(N));
     for (int i = 0; i < M; i++)
     {
         char tcode;
         int t = 0;
         cin >> tcode >> preplaced[i].r >> preplaced[i].c;
         preplaced[i].r--;
         preplaced[i].c--;
         switch (tcode)
         {
         case '+': t = 2; break;
         case 'x': t = 1; break;
         case 'o': t = 3; break;
         }
         preplaced[i].t = t;
         grid[preplaced[i].r][preplaced[i].c] = t;
     }
 
     if (input_done) input_done->set_value();
 
     vector<pii> hv = solve_hv(N, preplaced);
     vector<pii> diag = solve_diag(N, preplaced);
     auto grid2 = grid;
     for (const auto &p : hv)
         grid2[p.first][p.second] |= 1;
     for (const auto &p : diag)
         grid2[p.first][p.second] |= 2;
     vector<preplace> upgrades;
     int score = 0;
     for (int i = 0; i < N; i++)
         for (int j = 0; j < N; j++)
         {
             if (grid2[i][j] & 1)
                 score++;
             if (grid2[i][j] & 2)
                 score++;
             if (grid[i][j] != grid2[i][j])
             {
                 preplace u;
                 u.t = grid2[i][j];
                 u.r = i;
                 u.c = j;
                 upgrades.push_back(u);
             }
         }
     const char tmap[4] = {'.', 'x', '+', 'o'};
     cout << "Case #" << cas + 1 << ": " << score << ' ' << SZ(upgrades) << "\n";
     for (const auto &u : upgrades)
         cout << tmap[u.t] << ' ' << u.r + 1 << ' ' << u.c + 1 << '\n';
 }
