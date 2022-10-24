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
 
 static const int dr[4] = {-1, 0, 1, 0};
 static const int dc[4] = {0, -1, 0, 1};
 static const char dn[4] = {'^', '<', 'v', '>'};
 
 static bool is_safe(const vector<string> &grid, int r, int c, int d)
 {
     int R = grid.size();
     int C = grid[0].size();
     r += dr[d];
     c += dc[d];
     while (r >= 0 && r < R && c >= 0 && c < C)
     {
         if (grid[r][c] != '.')
             return true;
         r += dr[d];
         c += dc[d];
     }
     return false;
 }
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     for (int cas = 0; cas < cases; cas++)
     {
         cout << "Case #" << cas + 1 << ": ";
         int R, C;
         cin >> R >> C;
         vector<string> grid(R);
         for (int i = 0; i < R; i++)
             cin >> grid[i];
         int ans = 0;
         for (int i = 0; i < R; i++)
             for (int j = 0; j < C; j++)
             {
                 if (grid[i][j] == '.')
                     continue;
                 bool any = false;
                 bool good = false;
                 for (int d = 0; d < 4; d++)
                 {
                     bool safe = is_safe(grid, i, j, d);
                     any |= safe;
                     if (safe && dn[d] == grid[i][j])
                         good = true;
                 }
                 if (!any)
                     goto impossible;
                 if (!good)
                     ans++;
             }
 
         cout << ans << '\n';
         continue;
 impossible:
         cout << "IMPOSSIBLE\n";
     }
     return 0;
 }
