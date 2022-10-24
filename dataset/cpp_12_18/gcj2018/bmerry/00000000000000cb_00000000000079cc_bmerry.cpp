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
typedef complex<ll> pnt;
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

static inline ll dot(const pnt &a, const pnt &b)
{
    return real(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b)
{
    return imag(conj(a) * b);
}

static inline ll cross(const pnt &a, const pnt &b, const pnt &c)
{
    return cross(b - a, c - a);
}

class CompareY
{
public:
    bool operator()(const pnt &a, const pnt &b) const
    {
        if (a.imag() != b.imag())
            return a.imag() < b.imag();
        else
            return a.real() < b.real();
    }
};

class CompareAngle
{
private:
    const pnt base;

public:
    explicit CompareAngle(const pnt &base) : base(base) {}

    bool operator()(const pnt &a, const pnt &b) const
    {
        const pnt da = a - base;
        const pnt db = b - base;
        bool fa = da.imag() > 0 || (da.imag() == 0 && da.real() >= 0);
        bool fb = db.imag() > 0 || (db.imag() == 0 && db.real() >= 0);
        if (fa != fb)
            return fa;
        else
        {
            ll c = cross(da, db);
            if (c != 0)
                return c > 0;
            else
                return dot(da, da) < dot(db, db);
        }
    }
};

std::vector<pnt> convex_hull_exclusive(std::vector<pnt> pnts)
{
    sort(RA(pnts), CompareY());
    pnts.resize(unique(RA(pnts)) - pnts.begin());
    std::vector<pnt> hull;
    if (pnts.size() < 3)
    {
        std::sort(pnts.begin(), pnts.end(), CompareY());
        hull.swap(pnts);
        return hull;
    }

    std::vector<pnt>::iterator firstpos = std::min_element(RA(pnts), CompareY());
    std::swap(pnts[0], *firstpos);
    std::sort(pnts.begin() + 1, pnts.end(), CompareAngle(pnts[0]));

    hull.push_back(pnts[0]);
    for (int i = 1; i < SZ(pnts); i++)
    {
        while (SZ(hull) >= 2 && cross(hull[SZ(hull) - 2], hull.back(), pnts[i]) <= 0)
            hull.pop_back();
        hull.push_back(pnts[i]);
    }
    return hull;
}

template<typename T, int R, int C = R>
class Matrix
{
private:
    T values[R][C];
    template<typename T2, int R2, int C2> friend class Matrix;

public:
    struct uninitialized {};

    typedef T value_type;
    static constexpr int rows() { return R; }
    static constexpr int cols() { return C; }

    Matrix(uninitialized) {}

    explicit Matrix(T diag = T(1))
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                values[i][j] = (i == j) ? diag : T(0);
    }

    template<int D>
    Matrix<T, R, D> operator *(const Matrix<T, C, D> &b) const
    {
        Matrix<T, R, D> ans = typename Matrix<T, R, D>::uninitialized();
        for (int i = 0; i < R; i++)
            for (int j = 0; j < D; j++)
            {
                T sum = T();
                for (int k = 0; k < C; k++)
                    sum += values[i][k] * b.values[k][j];
                ans.values[i][j] = sum;
            }
        return ans;
    }

    Matrix &operator *=(const Matrix<T, C> &b)
    {
        *this = *this * b;
        return *this;
    }

    Matrix operator +(const Matrix &b) const
    {
        Matrix ans = uninitialized();
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.values[i][j] = values[i][j] + b.values[i][j];
        return ans;
    }

    Matrix &operator +=(const Matrix &b)
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                values[i][j] += b.values[i][j];
        return *this;
    }

    Matrix operator -(const Matrix &b) const
    {
        Matrix ans = uninitialized();
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.values[i][j] = values[i][j] - b.values[i][j];
        return ans;
    }

    Matrix &operator -=(const Matrix &b)
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                values[i][j] -= b.values[i][j];
        return *this;
    }

    Matrix operator -() const
    {
        Matrix ans = uninitialized();
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.values[i][j] = -values[i][j];
        return ans;
    }

    template<typename P, typename SFINAE = typename std::enable_if<R == C && std::is_same<P, P>::value>::type>
    Matrix power(P exponent) const
    {
        Matrix ans;
        Matrix p2 = *this;
        while (exponent > 0)
        {
            if (exponent & 1)
                ans *= p2;
            p2 *= p2;
            exponent >>= 1;
        }
        return ans;
    }

    bool operator==(const Matrix &b) const
    {
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (values[i][j] != b.values[i][j])
                    return false;
        return true;
    }

    bool operator!=(const Matrix &b) const
    {
        return !(*this == b);
    }

    const T *operator[](int idx) const
    {
        assert(idx >= 0 && idx < R);
        return values[idx];
    }

    T *operator[](int idx)
    {
        assert(idx >= 0 && idx < R);
        return values[idx];
    }
};

typedef Matrix<double, 3> Mat;
typedef Matrix<double, 3, 1> Vec;

static Mat rotate_y(double angle)
{
    double c = cos(angle);
    double s = sin(angle);
    Mat out;
    out[0][0] = c;
    out[0][2] = -s;
    out[2][0] = s;
    out[2][2] = c;
    return out;
}

static Mat rotate_z(double angle)
{
    double c = cos(angle);
    double s = sin(angle);
    Mat out;
    out[0][0] = c;
    out[0][1] = s;
    out[1][0] = -s;
    out[1][1] = c;
    return out;
}

static double area(const Mat &rot)
{
    Mat sides(0.5);
    sides = rot * sides;
    vector<pnt> pnts;
    for (int i = 0; i < 8; i++)
    {
        pnt cur = 0;
        for (int j = 0; j < 3; j++)
        {
            pnt proj(ll(round(100000000 * sides[0][j])),
                     ll(round(100000000 * sides[2][j])));
            if (i & (1 << j))
                cur += proj;
            else
                cur -= proj;
        }
        pnts.push_back(cur);
    }

    pnts = convex_hull_exclusive(pnts);
    ll ans = cross(pnts.back(), pnts[0]);
    for (size_t i = 1; i < pnts.size(); i++)
        ans += cross(pnts[i - 1], pnts[i]);
    return ans * 0.5e-16;
}

static void solve_case(int cas, ostream &cout, unique_ptr<promise<void> > &&input_done)
{
    double A;
    cin >> A;

    if (input_done) input_done->set_value();

    Mat diag = rotate_y(M_PI / 4);
    double lo = 0.0;
    double hi = atan(sqrt(2.0));
    for (int i = 0; i < 50; i++)
    {
        double x = (lo + hi) * 0.5;
        Mat rot = rotate_z(x) * diag;
        double a = area(rot);
        if (a < A)
            lo = x;
        else
            hi = x;
    }

    Mat rot = rotate_z(lo) * diag;
    Mat sides(0.5);
    sides = rot * sides;
    cout << "Case #" << cas + 1 << ":\n";
    cout << fixed << setprecision(9);
    for (int i = 0; i < 3; i++)
        cout << sides[0][i] << ' ' << sides[1][i] << ' ' << sides[2][i] << '\n';
}
