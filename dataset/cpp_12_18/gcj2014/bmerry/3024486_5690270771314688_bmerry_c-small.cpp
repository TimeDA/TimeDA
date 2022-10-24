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
 
 struct motion
 {
     int id;
     int in;
 };
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     for (int cas = 0; cas < cases; cas++)
     {
         int N;
         cin >> N;
         vector<motion> m(N);
         set<int> idset{0};
         for (int i = 0; i < N; i++)
         {
             char d;
             int id;
             cin >> d >> id;
             m[i].id = id;
             m[i].in = (d == 'E');
             idset.insert(id);
         }
         vi ids(RA(idset));
         for (auto &x : m)
         {
             x.id = find(RA(ids), x.id) - ids.begin() - 1;
         }
         int I = N;
 
         vector<bool> dp(1 << I, true);
         for (const auto &x : m)
         {
             vector<bool> dp2(1 << I);
             int j0 = x.id == -1 ? 0 : x.id;
             int j1 = x.id == -1 ? I : x.id + 1;
             if (!x.in)
             {
                 for (int i = 0; i < (1 << I); i++)
                 {
                     if (dp[i])
                         for (int j = j0; j < j1; j++)
                             if (i & (1 << j))
                                 dp2[i ^ (1 << j)] = true;
                 }
             }
             else
             {
                 for (int i = 0; i < (1 << I); i++)
                 {
                     if (dp[i])
                         for (int j = j0; j < j1; j++)
                             if (!(i & (1 << j)))
                                 dp2[i ^ (1 << j)] = true;
                 }
             }
             dp2.swap(dp);
         }
 
         int ans = INT_MAX;
         for (int i = 0; i < (1 << I); i++)
             if (dp[i])
                 ans = min(ans, __builtin_popcount(i));
 
         if (ans != INT_MAX)
             cout << "Case #" << cas + 1 << ": " << ans << "\n";
         else
             cout << "Case #" << cas + 1 << ": CRIME TIME" << "\n";
     }
     return 0;
 }
