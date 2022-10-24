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
 
 string simulate(const vector<int> &parent,
                 const vector<int> &desc,
                 const vector<vector<int>> &children,
                 const string &letters,
                 mt19937 &engine)
 {
     vector<int> roots;
     int N = SZ(parent);
     for (int i = 0; i < N; i++)
         if (parent[i] == -1)
             roots.push_back(i);
     string out;
     while (SZ(out) < N)
     {
         int rem = N - SZ(out);
         int pick = uniform_int_distribution<int>(0, rem - 1)(engine);
         int next = -1;
         for (int i = 0; i < SZ(roots); i++)
         {
             int r = roots[i];
             if (pick < desc[r])
             {
                 next = i;
                 break;
             }
             else
                 pick -= desc[r];
         }
         assert(next != -1);
         int r = roots[next];
         out += letters[r];
         swap(roots[next], roots.back());
         roots.pop_back();
         roots.insert(roots.end(), RA(children[r]));
     }
     return out;
 }
 
 static int make_desc(vector<int> &desc, const vector<vector<int>> &children, int cur)
 {
     int ans = 1;
     for (int c : children[cur])
     {
         ans += make_desc(desc, children, c);
     }
     desc[cur] = ans;
     return ans;
 }
 
 static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
 {
     int N;
     cin >> N;
     vector<int> parent(N);
     vector<vector<int>> children(N);
     for (int i = 0; i < N; i++)
     {
         cin >> parent[i];
         parent[i]--;
         if (parent[i] != -1)
             children[parent[i]].push_back(i);
     }
     vector<int> desc(N, -1);
     for (int i = 0; i < N; i++)
         if (parent[i] == -1)
         {
             make_desc(desc, children, i);
         }
 
     string letters;
     cin >> letters;
     int M;
     cin >> M;
     vector<string> cool(M);
     for (int i = 0; i < M; i++)
     {
         cin >> cool[i];
     }
 
     if (input_done) input_done->set_value();
 
     mt19937 engine;
     const int passes = 200000;
     vector<int> hits(M);
     for (int i = 0; i < passes; i++)
     {
         string cur = simulate(parent, desc, children, letters, engine);
         for (int j = 0; j < M; j++)
             if (cur.find(cool[j]) != string::npos)
                 hits[j]++;
     }
     cout << "Case #" << cas + 1 << ":" << fixed << setprecision(5);
     for (int i = 0; i < M; i++)
         cout << ' ' << double(hits[i]) / passes;
     cout << '\n';
 }
