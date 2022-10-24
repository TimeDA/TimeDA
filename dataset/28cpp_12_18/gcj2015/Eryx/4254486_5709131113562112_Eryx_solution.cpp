#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
 #include <vector>
 #include <stdio.h>
 using namespace std;
 
 typedef long long ll;
 
 #define LS <
 #define Size(x) (int(x.size()))
 
 // All macros with parameters "k,a,b" run the "k" variable in range [a,b)
 #define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)
 
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
 
 ll getLL() {
 #ifdef LINEBYLINE
   string s = getLine();
   return atoll(s.c_str());
 #else
 #ifdef USEWIN
   string s = getStr();
   return atoll(s.c_str());
 #else
   ll v;
   scanerr = scanf("%Ld", &v);
   return v;
 #endif
 #endif
   }
 
 #line 10 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 #define MAXN 2000000
 
 ll S[MAXN], M[MAXN], rM[MAXN];
 
 ll bySalary[MAXN];
 
 bool sortSalary(int i, int j) {
   return S[i] < S[j];
   }
 
 vector<int> children[MAXN];
 
 bool inCompany[MAXN], beInCompany[MAXN];
 int upto[2000000], upto2[2000000];
 
   int cupto = 0, qinc = 0;
 
 void addToCompany(int q) {
   if(q && !inCompany[rM[q]]) return;
 //printf("ATC %d\n", q);
   inCompany[q] = true; qinc++;
   for(int w: children[q]) if(beInCompany[w]) {
 //  printf("%d -> %d\n", q, w);
     addToCompany(w);
     }
   }
 
 void removeFromCompany(int q) {
   if(!inCompany[q]) return;
 //printf("RFC %d\n", q);
   inCompany[q] = false; qinc--;
   for(int w: children[q]) removeFromCompany(w);
   }
 
 void solveCase() {
   int res = 0;
 
   int N = getNum(), D = getNum();
   
   FOR(i,0,N) children[i].clear();
   
   ll S0 = getLL(), As = getLL(), Cs = getLL(), Rs = getLL();
   ll M0 = getLL(), Am = getLL(), Cm = getLL(), Rm = getLL();
   
   S[0] = S0; M[0] = M0;
   
   FOR(i,0,N)
     S[i+1] = (S[i] * As + Cs) % Rs;
   FOR(i,0,N) 
     M[i+1] = (M[i] * Am + Cm) % Rm;
   
   FOR(i, 1, N) rM[i] = M[i] % i;
   
 //FOR(i,0,N) printf("%d. S=%d, M=%d\n", int(i), int(S[i]), int(rM[i]));
   
   FOR(i,1,N) children[rM[i]].push_back(i);
   
   FOR(m, 0, N) bySalary[m] = m;
   sort(bySalary, bySalary+N, sortSalary);
   
   FOR(i,0,N) beInCompany[i] = inCompany[i] = false;
   
   int best = 0;
    qinc = 0;
   
   int minid = 0, maxid = -1;
   while(maxid < N-1) {
     int nextn = bySalary[maxid+1];
     int smax = S[nextn];
     
     int lastn = bySalary[minid];
     int smin = S[lastn];
     
 //  printf("maxid=%d [next %d], minid=%d [%d]\n", maxid, int(S[nextn]), minid, int(S[lastn]));
 
     if(smax-smin <= D) {
 //    printf("ADD %d (%d)\n", nextn, smax);
       beInCompany[nextn] = true;
       addToCompany(nextn);
       maxid++;
       }
     else {
 //    printf("REMOVE %d (%d)\n", lastn, smin);
       beInCompany[lastn] = false;
       removeFromCompany(lastn);
       minid++;
       }
 //  printf("qindc = %d\n", qinc);
     if(qinc > best) best = qinc;
     }
     
   printf("Case #%d: %d\n", cnum, best);
   }
 
 #define P 1000000007
 
 int main() {
 
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
