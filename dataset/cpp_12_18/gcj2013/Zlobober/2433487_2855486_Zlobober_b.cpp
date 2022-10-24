#include <cstdio>
 #include <vector>
 #include <algorithm>
 using namespace std;
 
 const int N = 10;
 
 struct vt
 {
     int x, y;
     vt(int _x, int _y)
     {
         x = _x, y = _y;
     }
     vt(){}
     friend vt operator +(vt a, vt b)
     {
         return vt(a.x + b.x, a.y + b.y);
     }
     friend vt operator -(vt a, vt b)
     {
         return vt(a.x - b.x, a.y - b.y);
     }
     friend int operator *(vt a, vt b)
     {
         return a.x * b.x + a.y * b.y;
     }
     friend int operator ^(vt a, vt b)
     {
         return a.x * b.y - b.x * a.y;
     }
     friend bool operator ||(vt a, vt b)
     {
         return (a ^ b) == 0;
     }
 };
 
 int sign(int x)
 {
     return (x < 0) ? -1 : x > 0;
 }
 
 bool in(vt x, vt a, vt b)
 {
     return (((a - x) || (b - x)) && ((x - a) * (x - b) <= 0));
 }
 
 int n;
 
 inline int mymod(int x)
 {
     return (x >= n) ? x - n : x;
 }
 
 bool inter(vt a, vt b, vt c, vt d)
 {
     if ((b - a) || (c - d))
     {
         if (!((b - a) || (c - a)))
             return false;
         return (in(a, c, d) || in(b, c, d) || in(c, a, b) || in(d, a, b));
     }
     else
         return sign((b - a) ^ (c - a)) * sign((b - a) ^ (d - a)) <= 0 &&
                sign((d - c) ^ (b - c)) * sign((d - c) ^ (a - c)) <= 0;
 }
 
 int P[N];
 
 vt V[N], Q[N];
 
 void solve(int tc)
 {
     scanf("%d", &n);
     for (int i = 0; i < n; i++)
         scanf("%d %d", &Q[i].x, &Q[i].y);
     for (int i = 0; i < n; i++)
         P[i] = i;
     pair<int, vector<int> > mx(0, vector<int>());
     #define eprintf(...) fprintf(stderr, __VA_ARGS__)
     eprintf("%d\n", tc);
     do
     {
 
         int S = 0;
         for (int i = 0; i < n; i++)
             V[i] = Q[P[i]];
         for (int i = 0; i < n; i++)
             S += V[i] ^ V[(i + 1) % n];
         if (S <= 0)
             continue;
         bool bad = false;
         for (int i = 0; i < n; i++)
             for (int j = 0; j < n; j++)
             {
                 if (i != j && i != mymod(j + 1) && j != mymod(i + 1) && inter(V[i], V[mymod(i + 1)], V[j], V[mymod(j + 1)]))
                     bad = true;
             }
         if (!bad)
             mx = max(mx, make_pair(S, vector<int>(P, P + n)));
     } while(next_permutation(P, P + n));
     printf("Case #%d:", tc);
     for (int i = 0; i < n; i++)
         printf(" %d", mx.second[i]);
     printf("\n");
 }
 
 int main()
 {
     int T;
     scanf("%d", &T);
     for (int i = 0; i < T; i++)
         solve(i + 1);
 }
