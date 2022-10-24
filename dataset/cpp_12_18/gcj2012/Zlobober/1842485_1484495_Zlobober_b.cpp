#include <iostream>
 #include <algorithm>
 #include <cstdio>
 #include <cassert>
 using namespace std;
 
 const int N = 1050;
 
 struct rect
 {
     int num;
     int x;
     friend bool operator <(rect a, rect b)
     {
         return a.x > b.x;
     }
 } R[N];
 
 int rad[N];
 
 int X[N], Y[N];
 int rev[N];
 
 int pt = 0;
 
 inline void set(int num, int x, int y, int _inv)
 {
     X[num] = x, Y[num] = y, rev[num] = _inv;
 }
 
 #define eprintf(...) //fprintf(stderr, __VA_ARGS__)
 
 int n;
 
 void place(int x1, int y1, int x2, int y2, bool inv, int deb = 0)
 {
     if (pt == n)
         return;
     if (y2 - y1 > x2 - x1)
     {
         swap(x1, y1);
         swap(x2, y2);
         inv ^= 1;
         for (int i = 0; i < deb; i++)
             eprintf(" ");
         eprintf("reverting\n");
         place(x1, y1, x2, y2, inv, deb + 1);
         return;
     }
 
     if (R[pt].x > y2 - y1)
         return;
     int left = x1;
     while (2 * R[pt].x > y2 - y1 && left + R[pt].x <= x2 && pt != n)
     {
         for (int i = 0; i <deb; i++)
             eprintf(" ");
         eprintf("placing 2k %d\n", R[pt].num);
         set(R[pt].num, left + R[pt].x / 2, y1 + R[pt].x / 2, inv);
         left += R[pt].x;
         pt++;
     }
     while (left + R[pt].x <= x2 && pt != n)
     {
         for (int i = 0; i < deb; i++)
             eprintf(" ");
         eprintf("calling \n");
         int v = R[pt].x;
         place(left, y1, left + R[pt].x, y2, inv, deb + 1);
         left += v;
     }
 }
 
 inline bool check(int a, int b)
 {
     assert(a != b);
     long long dx = X[a] - X[b];
     long long dy = Y[a] - Y[b];
     long long sr = rad[a] + rad[b];
     if (dx * dx + dy * dy < sr * sr)
     {
         printf("HOLY FUCK bad %d %d\n", a, b);
         assert(false);
     }
 }
 
 void solve(int C)
 {
     scanf("%d", &n);
     int w, l;
     scanf("%d %d", &w, &l);
 
     for (int i = 0; i < n; i++)
     {
         scanf("%d", &R[i].x);
         R[i].x *= 2;
         R[i].num = i;
         rad[i] = R[i].x / 2;
     }
     sort(R, R + n);
     bool inv = false;
     if (w < l)
         swap(w, l), inv = 1;
     int left = 0;
     pt = 0;
     while (l < 2 * R[pt].x && pt != n)
     {
         set(R[pt].num, left + R[pt].x / 2, 0, inv);
         left += R[pt].x;
         pt++;
     }
     place(left, 0, w, l, inv);
     printf("Case #%d:", C);
     for (int i = 0; i < n; i++)
         if (rev[i])
             swap(Y[i], X[i]);
     for (int i = 0; i < n; i++)
         printf(" %d %d", X[i], Y[i]);
 
     printf("\n");
     for (int i = 0; i < n; i++)
         for (int j = 0; j < i; j++)
             check(i, j);
     if (inv)
         swap(w, l);
     for (int i = 0; i < n; i++)
     {
         assert(0 <= X[i] && X[i] <= w);
         assert(0 <= Y[i] && Y[i] <= l);
     }
     assert(pt == n);
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int c = 1; c <= T; c++)
     {
         solve(c);
     }
 }
