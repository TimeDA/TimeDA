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
 
 static int getword(map<string, int> &ids, int &pool, const string &word)
 {
     if (ids.count(word))
         return ids[word];
     else
     {
         ids[word] = pool++;
         return ids[word];
     }
 }
 
 int main(int argc, const char **argv)
 {
     redirect(argc, argv);
 
     int cases;
     cin >> cases;
     for (int cas = 0; cas < cases; cas++)
     {
         int N;
         cin >> N >> ws;
         vector<vi> sents;
         map<string, int> ids;
         int pool = 0;
         for (int i = 0; i < N; i++)
         {
             string line;
             getline(cin, line);
             vs words = splitstr<string>(line);
             vi sent;
             for (string word : words)
             {
                 sent.push_back(getword(ids, pool, word));
             }
             sents.push_back(sent);
         }
         int ans = INT_MAX;
         for (int m = 2; m < (1 << N); m += 4)
         {
             vi flags(pool);
             for (int i = 0; i < N; i++)
             {
                 int flag = (m & (1 << i)) ? 1 : 2;
                 for (int word : sents[i])
                     flags[word] |= flag;
             }
             int score = 0;
             for (int flag : flags)
                 score += flag == 3;
             ans = min(ans, score);
         }
         cout << "Case #" << cas + 1 << ": " << ans << "\n";
     }
     return 0;
 }
