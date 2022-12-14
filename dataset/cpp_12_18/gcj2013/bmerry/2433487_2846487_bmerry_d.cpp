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
     cout.precision(14);
     cout << fixed;
     for (int cas = 0; cas < cases; cas++)
     {
         string line;
         cin >> line;
         int N = SZ(line);
         int start = 0;
         for (int i = 0; i < N; i++)
             if (line[i] == 'X')
                 start |= 1 << i;
 
         int all = (1 << N) - 1;
         vector<double> dp(1 << N);
         dp[all] = 0;
         for (int i = all - 1; i >= 0; i--)
         {
             double total = 0.0;
             for (int j = 0; j < N; j++)
             {
                 int k = j;
                 int win = N;
                 while (i & (1 << k))
                 {
                     k++;
                     if (k == N)
                         k = 0;
                     win--;
                 }
                 total += win + dp[i | (1 << k)];
             }
             dp[i] = total / N;
         }
         cout << "Case #" << cas + 1 << ": " << dp[start] << "\n";
     }
     return 0;
 }
