#include <bits/stdc++.h>
#include <fcntl.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/time.h>
#include <sys/resource.h>

using namespace std;

/*** START OF TEMPLATE CODE ***/

static constexpr bool THREADED = false;

typedef vector<string> vs;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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
    cin.tie(NULL);
    struct rlimit stack_limit;
    getrlimit(RLIMIT_STACK, &stack_limit);
    stack_limit.rlim_cur = 1024 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &stack_limit);

    char opt;
    int threads = thread::hardware_concurrency();
    bool threaded = THREADED;
    while ((opt = getopt(argc, argv, "pt:")) != -1)
    {
        switch (opt)
        {
        case 'p':
            threaded = !THREADED;
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

typedef array<ll, 3> pnt;
typedef pair<pnt, ll> plane;

static pnt operator-(const pnt &x, const pnt &y)
{
    return pnt{{x[0] - y[0], x[1] - y[1], x[2] - y[2]}};
}

static pnt cross(const pnt &a, const pnt &b, const pnt &c)
{
    pnt p = b - a;
    pnt q = c - a;
    return pnt{{p[1] * q[2] - p[2] * q[1],
                p[2] * q[0] - p[0] * q[2],
                p[0] * q[1] - p[1] * q[0]}};
}

static ll dot(const pnt &a, const pnt &b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

static plane make_plane(const pnt &a, const pnt &b, const pnt &c)
{
    pnt norm = cross(a, b, c);
    if (norm[2] < 0)
    {
        for (int i = 0; i < 3; i++)
            norm[i] = -norm[i];
    }
    return plane(norm, dot(norm, a));
}

static bool recurse(const vector<pnt> &pnts, vi &order, vector<bool> &used)
{
    int N = SZ(pnts);
    if (SZ(order) == N)
        return true;
    pnt p1 = pnts[order[SZ(order) - 2]];
    pnt p2 = pnts[order.back()];
    for (int i = 0; i < N; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            order.push_back(i);
            pnt p3 = pnts[i];
            plane p = make_plane(p1, p2, p3);
            for (int j = 0; j < N; j++)
            {
                if (used[j] && dot(p.first, pnts[j]) > p.second)
                    goto bad;
            }
            if (recurse(pnts, order, used))
                return true;
bad:
            order.pop_back();
            used[i] = false;
        }
    }
    return false;
}

static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
{
    int N;
    cin >> N;
    vector<pnt> pnts(N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> pnts[i][j];

    if (input_done) input_done->set_value();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (i != j)
            {
                vi order{i, j};
                vector<bool> used(N);
                used[i] = used[j] = true;
                if (recurse(pnts, order, used))
                {
                    cout << "Case #" << cas + 1 << ":";
                    for (int idx : order)
                        cout << ' ' << idx + 1;
                    cout << "\n";
                    return;
                }
            }
    assert(0);
}
