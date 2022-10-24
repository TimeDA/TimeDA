#include <cstdio>
 #include <cstring>
 #include <string>
 #include <vector>
 
 using namespace std;
 
 vector<int> table[10];
 
 void gen(int sz, int ind, vector<int> sum) {
   if (ind == sz) {
     vector<int> newsum(sz);
     for (;;) {
       int num = 0;
       for (int i = 0; i < sz; i++) {
         num *= 10;
         num += sum[i];
       }
       table[sz][num]++;
 
       for (int i = 0; i < sz; i++) newsum[i] = 0;
       for (int i = 0; i < sz; i++) {
         if (sum[i] > 0) {
           newsum[sum[i] - 1]++;
         }
       }
       if (newsum == sum) {
         break;
       }
       newsum.swap(sum);
     }
     return;
   }
   for (int i = 0; i <= sz; i++) {
     sum.push_back(i);
     gen(sz, ind + 1, sum);
     sum.pop_back();
   }
 }
 
 void buildtable() {
   for (int i = 1; i <= 5; i++) {
     fprintf(stderr, "building %d\n", i);
     int sz = 1;
     for (int j = 0; j < i; j++) sz *= 10;
     table[i].resize(sz);
     gen(i, 0, vector<int>());
   }
 }
 
 int main() {
   buildtable();
 
   //freopen("A-large.in", "r", stdin);
   int TT;
   scanf("%d", &TT);
   for (int testcase = 1; testcase <= TT; testcase++) {
     char buffer[256];
     scanf("%s", buffer);
     int len = strlen(buffer);
     int ind;
     sscanf(buffer, "%d", &ind);
     printf("Case #%d: %d\n", testcase, table[len][ind]);
   }
   return 0;
 }