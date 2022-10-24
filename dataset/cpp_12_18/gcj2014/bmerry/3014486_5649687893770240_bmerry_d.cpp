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
 
 static int tnodes(const vs &S)
 {
     set<string> pre;
     for (const string &s : S)
         for (int i = 0; i <= SZ(s); i++)
             pre.insert(s.substr(0, i));
     return pre.size();
 }
 
 template<typename T>
 static void recurse(const vs &S, vi &A, int N, int pos, const T &cb)
 {
     if (pos == SZ(A))
     {
         vector<vs> subs(N);
         for (int i = 0; i < SZ(A); i++)
             subs[A[i]].push_back(S[i]);
         int total = 0;
         for (int i = 0; i < N; i++)
         {
             if (subs[i].empty())
                 return;
             total += tnodes(subs[i]);
         }
         cb(total);
     }
     else
     {
         for (A[pos] = 0; A[pos] < N; A[pos]++)
             recurse(S, A, N, pos + 1, cb);
     }
 }
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     for (int cas = 0; cas < cases; cas++)
     {
         int M, N;
         cin >> M >> N;
         vector<string> S(M);
         for (int i = 0; i < M; i++)
         {
             cin >> S[i];
         }
 
         vi A(M);
         int most = 0;
         auto cb1 = [&] (int nodes) {
             most = max(most, nodes);
         };
 
         int ans = 0;
         auto cb2 = [&] (int nodes) {
             if (nodes == most)
                 ans++;
         };
 
         recurse(S, A, N, 0, cb1);
         recurse(S, A, N, 0, cb2);
 
         cout << "Case #" << cas + 1 << ": " << most << ' ' << ans << "\n";
     }
     return 0;
 }
