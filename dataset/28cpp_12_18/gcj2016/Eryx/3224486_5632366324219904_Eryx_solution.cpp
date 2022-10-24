#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
 #include <string>
 #include <set>
 #include <stdio.h>
 using namespace std;
 
 #define LS <
 #define Size(x) (int(x.size()))
 
 // All macros with parameters "k,a,b" run the "k" variable in range [a,b)
 #define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)
 
 string getLine() {
   string s;
   while(!feof(stdin)) {
     char c = fgetc(stdin);
     if(c <= 0) continue;
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
 
 string getStr() {
 #ifdef LINEBYLINE
   return getStr();
 #else
   scanerr = scanf("%s", buf);
   return buf;
 #endif
   }
 
 #line 10 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 set<string> good;
 string bad;
 
 void solveCase() {
   int res = 0;
 
   int N = getNum(), L = getNum();
   good.clear();
   FOR(c,0,N) good.insert(getStr());
   bad = getStr();
   
   if(0) if(N==1 && L == 1) {
     printf("*\n");
     printf("%s\n", bad.c_str());
     for(string g: good) printf("%s\n", g.c_str());
     }
   
   if(good.count(bad)) {
     printf("Case #%d: IMPOSSIBLE\n", cnum);
     }
   else {
     printf("Case #%d: ", cnum);
     FOR(i,0,L) printf("0?");
     printf(" ");
     printf("0");
     FOR(i,1,L) printf("1");
     printf("\n");
     }
   }
 
 #define P 1000000007
 
 int q;
 
 set<string> outputs;
 
 void test(string t1, string t2, string output, char reg) {
   if(t1 == "" && t2 == "") outputs.insert(output); 
   if(t1 == "") return;
   switch(t1[0]) {
     case '0': case '1': reg = t1[0]; break;
     case '-': break;
     case '?': output += reg; break;
     }
   test(t1.substr(1), t2, output, reg);
   test(t2, t1.substr(1), output, reg);
   }
 
 char gch() {
   char res = "01-" [q%3];
   q /= 3;
   return res;
   }
 
 void sim() {
   for(int p=0;; p++) {
     q = p;
     string p1 = ""; p1 += gch(); p1 += "?"; p1 += gch(); p1 += "?"; p1 += gch(); p1 += "?";
     string p2 = ""; p2 += gch(); p2 += gch(); p2 += gch();
     outputs.clear();
     test(p1, p2, "", '0');
     // for(string s: outputs) printf("%s ", s.c_str()); printf("\n");
     if(Size(outputs) == 7 && !outputs.count("111"))
       printf("%s %s\n", p1.c_str(), p2.c_str());
       
     if(q) break;
     }
   }
 
 int main() {
 
   // sim();
   // return 0;
 
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
