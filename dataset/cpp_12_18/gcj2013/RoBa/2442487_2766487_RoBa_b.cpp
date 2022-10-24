#include <cstdio>
 #include <string>
 #include <vector>
 using namespace std;
 
 #define PB push_back
 typedef vector<int> VI;
 int N, P;
 
 VI gen_worst(const vector<int> &in) {
   vector<int> out;
   for (int i = 0 ; i < in.size() ; i++)
     out.push_back(in[i]*2);
   for (int i = 0 ; i < in.size() ; ++i) {
     if (i != in.size() - 1) {
       out.push_back(2*in.size()-2);
     } else out.push_back(2*in.size()-1);
   }
   return out;
 }
 
 VI gen_best(const VI &in) {
   VI out;
   for (int i = 0 ;i < in.size() ; ++i)
     if (i == 0) out.PB(0);
     else out.PB(1);
   for (int i = 0 ;i < in.size() ; ++i)
     out.PB(in[i]*2+1);
   return out;
 }
 
 void output_v(vector<int> &v) {
   for (int i = 0 ; i < v.size() ; ++i)
     printf(" %d",v[i]);
   printf("\n");
 }
 
 int main() {
   int T, ca;
   scanf("%d",&T);
   for (ca = 1 ; ca <= T ; ++ca) {
     printf("Case #%d: ", ca);
     scanf("%d%d",&N,&P);
     VI b, w, tb, tw;
     b.PB(0); b.PB(1);
     w.PB(0); w.PB(1);
     for (int i = 0 ; i < N - 1 ; ++i) {
       // printf("i:%d\n",i);
       tb = gen_best(b);
       b = tb;
       // output_v(b);
       tw = gen_worst(w);
       w = tw;
     }
     // output_v(b);
     // output_v(w);
     --P;
     int ans1, ans2;
     for (int i = 0 ; i < b.size() ; ++i) {
       if (w[i] <= P) ans1 = i;
       if (b[i] <= P) ans2 = i;
     }
     printf("%d %d\n",ans1,ans2);
   }
   return 0;
 }
 
