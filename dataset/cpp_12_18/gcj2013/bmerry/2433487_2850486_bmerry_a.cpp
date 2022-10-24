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
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     const int P = 37;
     cout << fixed;
     cout.precision(10);
     for (int cas = 0; cas < cases; cas++)
     {
         ll start[P + 1] = {};
         ll B;
         int N;
         cin >> B >> N;
         for (int i = 0; i < N; i++)
             cin >> start[i];
         for (int i = N; i < P; i++)
             start[i] = 0;
         start[P] = LLONG_MAX / 2;
         sort(start, start + P);
 
         double ans = 0.0;
         for (int p = 1; p <= P; p++)
             for (int q = p; q <= P; q++)
             {
                 ll bias = 0;
                 for (int i = 0; i < q; i++)
                     bias += start[i];
                 if (B + bias - (q - p) < 0)
                     continue;
                 ll hi = (B + bias - (q - p)) / q;
                 hi = min(hi, start[q] - 1);
 
                 ll lo = start[p - 1];
                 if (q > p)
                     lo = max(lo, start[q - 1] - 1);
                 if (hi < lo)
                     continue;
 
                 ll vals[2] = {lo, hi};
                 for (int i = 0; i < 2; i++)
                 {
                     ll lvl = vals[i];
                     ll waste = 0;
                     ll bets = 0;
                     for (int j = 0; j < p; j++)
                         bets += max(0LL, lvl - start[j]);
                     for (int j = p; j < q; j++)
                         waste += max(0LL, (lvl + 1) - start[j]);
                     assert(bets + waste <= B);
                     double profit = bets * (36.0 / p - 1.0) - waste;
                     if (profit > ans)
                         ans = profit;
                 }
             }
         cout << "Case #" << cas + 1 << ": " << ans << "\n";
     }
     return 0;
 }
