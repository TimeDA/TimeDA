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
         int P;
         cin >> P;
         vector<pair<ll, ll> > terms(P);
         for (int i = 0; i < P; i++)
             cin >> terms[i].first;
         for (int i = 0; i < P; i++)
             cin >> terms[i].second;
 
         vector<ll> S;
         while (terms.size() > 1 || terms[0].second > 1)
         {
             ll v;
             if (terms[0].second > 1)
             {
                 v = 0;
                 for (auto &t : terms)
                     t.second /= 2;
             }
             else
             {
                 v = terms[1].first;
                 vector<pair<ll, ll> > terms2;
                 while (!terms.empty())
                 {
                     if (terms.back().second == 0)
                     {
                         terms.pop_back();
                         continue;
                     }
                     ll f = terms.back().second;
                     ll q = terms.back().first - v;
                     int pos = 0;
                     while (terms[pos].first != q)
                         pos++;
                     assert(terms[pos].second >= f);
                     terms2.emplace_back(q, f);
                     terms[pos].second -= f;
                     terms.pop_back();
                 }
                 terms = move(terms2);
                 sort(RA(terms));
             }
             S.push_back(v);
         }
         cout << "Case #" << cas + 1 << ":";
         for (ll s : S)
             cout << ' ' << s;
         cout << '\n';
     }
     return 0;
 }
