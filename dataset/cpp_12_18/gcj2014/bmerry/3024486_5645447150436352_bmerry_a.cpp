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
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     for (int cas = 0; cas < cases; cas++)
     {
         ll N, p, q, r, s;
         cin >> N >> p >> q >> r >> s;
         vector<ll> t(N);
         for (ll i = 0; i < N; i++)
             t[i] = (i * p + q) % r + s;
         vector<ll> sum(N + 1);
         partial_sum(t.begin(), t.end(), sum.begin() + 1);
         ll ans = 0;
         for (int a = 0; a < N; a++)
             for (int b = a + 1; b < N; b++)
             {
                 ll big = max(sum[a], max(sum[b] - sum[a], sum[N] - sum[b]));
                 big = sum[N] - big;
                 ans = max(ans, big);
             }
         cout << fixed << setprecision(12);
         cout << "Case #" << cas + 1 << ": " << ans / (double) sum[N] << "\n";
     }
     return 0;
 }
