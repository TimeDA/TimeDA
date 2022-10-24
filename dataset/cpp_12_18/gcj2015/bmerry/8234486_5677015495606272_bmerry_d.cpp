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
 
 #define MOD 1000000007
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     for (int cas = 0; cas < cases; cas++)
     {
         int R, C;
         cin >> R >> C;
         vector<ll> dp(R + 1), dp0(R + 1);
         dp[0] = 1;
         dp0[0] = 1;
         for (int i = 1; i <= R; i++)
         {
             ll s = 0;
             if (i == 1)
                 s = 1;
             else if (i == 2)
             {
                 if (C % 3 == 0)
                     s++;
                 if (C % 6 == 0)
                     s++;
             }
             else if (i == 3)
             {
                 if (C % 4 == 0)
                     s++;
             }
             dp0[i] = s;
             for (int j = 1; j <= i - 2; j++)
                 s = (s + dp0[j] * dp[i - 2 - j]) % MOD;
             dp[i] = s;
         }
         ll ans = dp[R];
         if (R >= 2)
             ans = (ans + dp[R - 2]) % MOD;
         cout << "Case #" << cas + 1 << ": " << ans << "\n";
     }
     return 0;
 }
