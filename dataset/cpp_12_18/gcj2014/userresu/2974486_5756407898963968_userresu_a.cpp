#include <cstdio>
 #include <set>
 using namespace std;
 
 int T;
 int main () {
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
     scanf("%d",&T);
     for (int z=1;z<=T;++z) {
         printf("Case #%d: ",z);
         int a,b;
         scanf("%d",&a);
         set<int> S;
         bool bad=0;
         for (int i=1;i<=4;++i) for (int j=1;j<=4;++j) {
             int x;
             scanf("%d",&x);
             if (i==a) S.insert(x);
         }
         scanf("%d",&b);
         int last=-1;
         for (int i=1;i<=4;++i) for (int j=1;j<=4;++j) {
             int x;
             scanf("%d",&x);
             if (i==b && S.find(x)!=S.end()) {
                 if (last==-1) last=x;
                 else bad=1;
             }
         }
         if (bad) printf("Bad magician!\n");
         else if (last==-1) printf("Volunteer cheated!\n");
         else printf("%d\n",last);
     }
     return 0;
 }
 
