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
 typedef pair<ll, ll> pii;
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
 
 static int to_vertex(int R, int C, int x)
 {
     if (x < C)
         return 4 * x;
     else if (x < R + C)
         return 4 * C * (x - C + 1) - 1;
     else if (x < R + 2 * C)
         return 4 * R * C - 4 * (x - R - C) - 2;
     else
         return 4 * C * (2 * R + 2 * C - x - 1) + 1;
 }
 
 static bool reach(const vector<vector<int>> &edges, int a, int b)
 {
     stack<int> st;
     st.push(a);
     vector<bool> done(SZ(edges));
     while (!st.empty())
     {
         int cur = st.top();
         st.pop();
         for (int v : edges[cur])
         {
             if (v == b)
                 return true;
             if (!done[v])
             {
                 st.push(v);
                 done[v] = true;
             }
         }
     }
     return false;
 }
 
 static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
 {
     const string impossible = "IMPOSSIBLE";
     int R, C;
     cin >> R >> C;
     vector<int> opp(2 * (R + C));
     for (int i = 0; i < R + C; i++)
     {
         int x, y;
         cin >> x >> y;
         x--;
         y--;
         opp[x] = y;
         opp[y] = x;
     }
 
     if (input_done) input_done->set_value();
 
     cout << "Case #" << cas + 1 << ":\n";
 
     for (int m = 0; m < (1 << (R * C)); m++)
     {
         vector<vector<int>> edges(4 * R * C);
         auto add = [&](int a, int b)
         {
             edges[a].push_back(b);
             edges[b].push_back(a);
         };
         for (int i = 0; i < R; i++)
             for (int j = 0; j < C; j++)
             {
                 int idx = i * C + j;
                 int base = 4 * (i * C + j);
                 if (m & (1 << idx))
                 {
                     add(base, base + 1);
                     add(base + 2, base + 3);
                 }
                 else
                 {
                     add(base + 1, base + 2);
                     add(base + 3, base);
                 }
                 if (j < C - 1)
                     add(base + 3, base + 5);
                 if (i < R - 1)
                     add(base + 2, base + 4 * C);
             }
         for (int i = 0; i < 2 * (R + C); i++)
         {
             int a = to_vertex(R, C, i);
             int b = to_vertex(R, C, opp[i]);
             if (a < b && !reach(edges, a, b))
                 goto bad;
         }
 
         for (int i = 0; i < R; i++)
         {
             for (int j = 0; j < C; j++)
             {
                 int idx = i * C + j;
                 if (m & (1 << idx))
                     cout << '/';
                 else
                     cout << '\\';
             }
             cout << '\n';
         }
         return;
 
 bad:;
     }
     cout << impossible << '\n';
 }
