#define BUFSIZE 1000000
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 #include <algorithm>
 #include <string>
 #include <vector>
 #include <map>
 #include <stdio.h>
 using namespace std;
 
 #define Size(x) (int(x.size()))
 
 string getLine() {
   string s;
   while(!feof(stdin)) {
     char c = fgetc(stdin);
     if(c == 13) continue;
     if(c == 10) return s;
     s += c;
     }
   return s;
   }
 
 int scanerr;
 
 int getNum() {
 #ifdef LINEBYLINE
   string s = getLine();
   return atoi(s.c_str());
 #else
   int i;
   scanerr = scanf("%d", &i);
   return i;
 #endif
   }
 
 #ifndef BUFSIZE
 #define BUFSIZE 1000000
 #endif
 
 char buf[BUFSIZE];
 
 string getStr() {
 #ifdef LINEBYLINE
   return getStr();
 #else
   scanerr = scanf("%s", buf);
   return buf;
 #endif
   }
 
 char *scanerrp;
 
 #line 10 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 #define P 1000000007
 
 vector<pair<string, int> > data;
  
 map<int, int> googlements;
 
 int p10[10];
 
 map<int, array<int, 10>> qty;
 
 int oa, dig;
 
 int sdig[100000000];
 int nstep[100000000];
 int mdig[100000000];
 int digc[100000000];
 
 int sdigit(int a) {
   return a<10 ? a : (a%10) + sdig[a/10];
   }
 
 int nstepf(int a) {
   return a<10 ? p10[a] : p10[a%10] + nstep[a/10];
   }
 
 void run(int a) {
   if(a == 0) exit(1);
   qty[a][dig]++;
   if(a < 2) return;
   int res = nstepf(a);
   // while(a > 0) { res += p10[a%10]; a /= 10; }
   run(res);
   }
 
 void solveCase() {
   int res = 1;
 
   string s = getStr();
   int L = Size(s);
   int val = 0;
   for(int i=0; i<L; i++) val += p10[1+i] * (s[i]-'0');
   
   // printf("val=%d\n", val);
   
   auto& q = qty[val];
   
   // for(int z=0; z<10; z++) printf("%d ", q[z]); printf("\n");
   
   for(int s=0; s<=L; s++) res += q[s];
   
   printf("Case #%d: %d\n", cnum, res);
   }
 
 int main() {
   p10[0] = 0;
   p10[1] = 1;
   for(int s=1; s<=8; s++) p10[s+1] = p10[s] * 10;
   
   /* this outputs solution.txt:
 
   for(int i=0; i<100000000; i++) sdig[i] = sdigit(i);
   for(int i=0; i<100000000; i++) nstep[i] = nstepf(i);
   for(int i=0; i<100000000; i++) 
     mdig[i] = i < 10 ? i : max(i%10, mdig[i/10]);
 
   for(int i=0; i<100000000; i++) 
     digc[i] = i < 10 ? 1 : 1 + digc[i/10];
     
   for(int a=1; a<1000000000; a++) {  
     if(a % 10000000 == 0) fprintf(stderr, "%d\n", a);
     // if(sdigit(a) > 9) continue;
     oa = a;
     int a0 = a;
     dig = 0;
     if(a >= 100000000) dig = 9;
     else dig = max(digc[a], mdig[a]);
     run(nstepf(a));
     }
   
   for(auto t: qty) {
     printf("%d", t.first);
     for(auto r: t.second) printf(" %d", r);
     printf("\n");
     }
   exit(0);
   */
   
   FILE *f = fopen("solution.txt", "rt");
   while(true) {
     int val = -1;
     scanerr=fscanf(f, "%d", &val);
     if(val == -1) break;
     auto& v = qty[val];
     for(int r=0; r<10; r++) scanerr=fscanf(f, "%d", &v[r]);
     }
   fclose(f);
   qty[1][1]--;
   
   if(!MANYTESTS) Tests = 1;
   else Tests = getNum();
 
   for(cnum=1; cnum<=Tests; cnum++)
     solveCase();
     
   // finish
   return 0;
   }
 
 // This solution includes hidden routines to solve test cases in separate
 // processes in order to make it faster. I will update them to run on a
 // cluster if I get one ;)
 // See https://github.com/eryxcc/templates
