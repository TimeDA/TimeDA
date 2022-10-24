#include <cstdio>
 #include <cstdlib>
 #include <memory.h>
 #include <map>
 #include <algorithm>
 #include <cassert>
 
 using namespace std;
 
 const int T = 205;
 const int N = 10;
 
 typedef long long llong;
 
 int n;
 
 struct state {
     int col[2 * N];
     int att[2 * N];
     int num;
     llong hsh() {
         llong val = 0;
         for (int i = 0; i < n; i++) {
             val = val * 4243 + col[i];
         }
         for (int i = 0; i < num; i++) {
             val = val * 4243 + att[i];
         }
         return val;
     }
     llong reg();
     state() {
         memset(att, 0, sizeof(att));
         memset(col, 0, sizeof(col));
     }
     void renum() {
         int tmp[2 * N];
         memcpy(tmp, col, sizeof(col));
         sort(tmp, tmp + n);
         int pt = unique(tmp, tmp + n) - tmp;
         int new_att[2 * N];
         memset(new_att, 0, sizeof(new_att));
         for (int i = 0; i < 2 * N; i++) {
             int new_i = lower_bound(tmp, tmp + pt, i) - tmp;
             if (tmp[new_i] != i)
                 continue;
             new_att[new_i] = att[i];
         }
         memcpy(att, new_att, sizeof(new_att));
         for (int i = 0; i < n; i++) {
             col[i] = lower_bound(tmp, tmp + pt, col[i]) - tmp;
         }
         num = pt;
     }
 };
 
 map<llong, state> hsh2st;
 
 llong state::reg() {
     llong h = hsh();
     if (hsh2st.count(h))
         return h;
     hsh2st[h] = *this;
     return h;
 }
 
 
 map<llong, pair<llong, int>> D[T];
 
 int top[T];
 int bot[T];
 int rgt[T];
 
 char field[T][T];
 char field2[T][T];
 
 int match[T];
 
 bool matches(int a, int b) {
     return (a == 0 || b == 0 || (match[a] == b));
 }
 
 int par[4 * T];
 
 int vl[T][T], vr[T][T], vd[T][T], vu[T][T];
 
 int get_par(int x) {
     return (x == par[x]) ? x : par[x] = get_par(par[x]);
 }
 
 void merge(int a, int b) {
     a = get_par(a);
     b = get_par(b);
     if (a == b)
         return;
     par[a] = b;
 }
 
 bool check(int a, int b) {
     a = get_par(a);
     b = get_par(b);
     return (a == b);
 }
 
 int orig_match[T];
 
 bool check(char F[T][T], int n, int m) {
     for (int i = 0; i < 4 * n * m; i++)
         par[i] = i;
     int ver = 0;
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
             vl[i][j] = ver++;
             vu[i][j] = ver++;
             vr[i][j] = ver++;
             vd[i][j] = ver++;
         }
     }
     for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
             if (j)
                 merge(vl[i][j], vr[i][j - 1]);
             if (i)
                 merge(vu[i][j], vd[i - 1][j]);
             if (F[i][j] == '/')
                 merge(vu[i][j], vl[i][j]), merge(vd[i][j], vr[i][j]);
             else
                 merge(vu[i][j], vr[i][j]), merge(vd[i][j], vl[i][j]);
         }
     }
     int num[T];
     for (int j = 0; j < m; j++) {
         num[j + 1] = vu[0][j];
         num[2 * m + n - j] = vd[n - 1][j];
     }
     for (int i = 0; i < n; i++) {
         num[m + 1 + i] = vr[i][m - 1];
         num[2 * m + 2 * n - i] = vl[i][0];
     }
     for (int i = 1; i <= 2 * (n + m); i++) {
         for (int j = 1; j < i; j++) {
             bool act = check(num[i], num[j]);
             bool need = orig_match[i] == j;
             if (act != need) {
                 //fprintf(stderr, "BAD!\n");
                 //fprintf(stderr, "%d %d\n", i, j);
                 return false;
 //                exit(1);
             }
         }
     }
     return true;
 }
 
 
 
 void solve(int cs) {
     int r, c;
     scanf("%d %d", &r, &c);
     for (int i = 1; i <= (r + c); i++) {
         int a, b;
         scanf("%d %d", &a, &b);
         match[a] = b;
         match[b] = a;
     }
     memcpy(orig_match, match, sizeof match);
     bool swapped = false;
     if (r > c) {
         swap(r, c);
         swapped = true;
         int new_match[T];
         for (int i = 1; i <= 2 * (r + c); i++) {
             int j = match[i];
             int ni = 2 * (r + c) + 1 - i;
             int nj = 2 * (r + c) + 1 - j;
             new_match[ni] = nj;
             new_match[nj] = ni;
         }
         memcpy(match, new_match, sizeof(int) * (2 * (r + c) + 1));
     }
     n = r;
     int m = c;
     hsh2st.clear();
     for (int j = 0; j <= m; j++)
         D[j].clear();
 
     state init;
     init.num = n;
     for (int i = 0; i < n; i++) {
         init.col[i] = i;
         init.att[i] = 2 * (r + c) - i;
     }
     for (int i = 0; i < n; i++) {
         rgt[i] = c + i + 1;
     }
     llong init_h = init.reg();
     D[0].insert(make_pair(init_h, make_pair(-42, -42)));
 
     for (int i = 0; i < m; i++)
         top[i] = i + 1, bot[i] = 2 * c + r - i;
 
     for (int j = 0; j < m; j++) {
         for (auto elem : D[j]) {
             llong sh = elem.first;
             state s = hsh2st.at(sh);
             for (int msk = 0; msk < (1 << n); msk++) {
                 int dir[N];
                 for (int i = 0; i < n; i++)
                     dir[i] = ((msk >> i) & 1);
                 bool bad = false;
                 if (dir[0] == 1 && !matches(top[j], s.att[s.col[0]])) {
                     bad = true;
                 } else if (s.att[s.col[0]] == 0) {
                     s.att[s.col[0]] = top[j];
                 }
                 if (dir[n - 1] == 0 && !matches(bot[j], s.att[s.col[n - 1]])) {
                     bad = true;
                 } else if (s.att[s.col[n - 1]] == 0) {
                     s.att[s.col[n - 1]] = bot[j];
                 }
                 for (int i = 0; i < n - 1; i++) {
                     if (dir[i] == 0 && dir[i + 1] == 1) {
                         if (!matches(s.att[s.col[i]], s.att[s.col[i + 1]])) {
                             bad = true;
                             break;
                         } else if (s.att[s.col[i]] == 0 && s.att[s.col[i + 1]] != 0) {
                             s.att[s.col[i]] = s.att[s.col[i + 1]];
                         } else if (s.att[s.col[i + 1]] == 0 && s.att[s.col[i]] != 0) {
                             s.att[s.col[i + 1]] = s.att[s.col[i]];
                         }
                     }
                 }
                 if (bad)
                     continue;
                 state nst;
                 int new_pt = s.num;
                 for (int i = 0; i < n; i++) {
                     if (i - 1 >= 0 && dir[i] == 0 && dir[i - 1] == 1)
                         nst.col[i] = nst.col[i - 1] = new_pt++;
                     else if (i + 1 < n && dir[i] == 1 && dir[i + 1] == 0) {
                         continue;
                         //nst.col[i] = nst.col[i + 1] = dead_pt--;
                     }
                     else if (dir[i] == 0) {
                         if (i == 0) {
                             nst.col[i] = new_pt++;
                             nst.att[nst.col[i]] = top[j];
                         } else {
                             nst.col[i] = s.col[i - 1];
                             nst.att[nst.col[i]] = s.att[s.col[i - 1]];
                         }
                     } else {
                         if (i == n - 1) {
                             nst.col[i] = new_pt++;
                             nst.att[nst.col[i]] = bot[j];
                         } else {
                             nst.col[i] = s.col[i + 1];
                             nst.att[nst.col[i]] = s.att[s.col[i + 1]];
                         }
                     }
                 }
                 nst.renum();
                 llong h = nst.reg();
                 D[j + 1].insert(make_pair(h, make_pair(sh, msk)));
             }
         }
     }
     llong good_h = -1;
     bool was_good_h = false;
     for (auto elem : D[m]) {
         llong h = elem.first;
         state st = hsh2st.at(h);
         bool bad = false;
         for (int i = 0; i < n; i++) {
             int c = st.col[i];
             if (st.att[c] == 0) {
                 st.att[c] = rgt[i];
             } else if (!matches(st.att[c], rgt[i])) {
                 bad = true;
                 break;
             }
         }
         if (!bad) {
             was_good_h = true;
             good_h = h;
             break;
         }
     }
     printf("Case #%d:\n", cs);
     if (!was_good_h) {
         printf("IMPOSSIBLE\n");
     } else {
         llong h = good_h;
         for (int j = m - 1; j >= 0; j--) {
             assert(D[j + 1].count(h));
             pair<llong, int> prv = D[j + 1][h];
             llong ph = prv.first;
             int msk = prv.second;
             for (int i = 0; i < n; i++)
                 field[i][j] = ((msk >> i) & 1) ? '/' : '\\';
             h = ph;
         }
         if (swapped) {
             for (int i = 0; i < n; i++) {
                 for (int j = 0; j < m; j++) {
                     field2[j][i] = field[i][j];
                 }
             }
             swap(n, m);
             for (int i = 0; i < n; i++) {
                 for (int j = 0; j < m; j++) {
                     field[i][j] = field2[i][j];
                 }
             }
         }
         for (int i = 0; i < n; i++)
             field[i][m] = 0;
         for (int i = 0; i < n; i++) {
             printf("%s\n", field[i]);
         }
         check(field, n, m);
     }
 }
 
 void stup_solve(int cs) {
     int r, c;
     scanf("%d %d", &r, &c);
     for (int i = 1; i <= (r + c); i++) {
         int a, b;
         scanf("%d %d", &a, &b);
         match[a] = b;
         match[b] = a;
     }
     memcpy(orig_match, match, sizeof match);
     for (int msk = 0; msk < (1 << (r * c)); msk++) {
         int pt = 0;
         for (int i = 0; i < r; i++) {
             for (int j = 0; j < c; j++) {
                 field[i][j] = ((msk >> pt++) & 1) ? '/' : '\\';
             }
             field[i][c] = 0;
         }
         if (check(field, r, c)) {
             printf("Case #%d:\n", cs);
             for (int i = 0; i < r; i++) {
                 printf("%s\n", field[i]);
             }
             return;
         }
     }
     printf("Case #%d:\n", cs);
     printf("IMPOSSIBLE\n");
 }
 
 int main() {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++) {   
         stup_solve(i + 1);
     }
 }
