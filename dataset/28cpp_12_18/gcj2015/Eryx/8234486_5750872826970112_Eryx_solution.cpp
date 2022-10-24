#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
 #include <string>
 #include <vector>
 #include <iostream>
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
 
 #define BASE 1000
 #define LEN 200
 
 struct bignum {
   int digit[LEN];
   bignum(int b = 0) {
     for(int i=0; i<LEN; i++) { digit[i] = b%BASE; b /= BASE; }
     }
   void fix() {
     int carry = 0;
     for(int i=0; i<LEN; i++) {
       digit[i] += carry;
       carry = digit[i] / BASE;
       digit[i] %= BASE;
       if(digit[i] < 0) { carry--; digit[i] += BASE; }
       }
     }
   };
 
 bignum operator + (bignum a, bignum b) {
   bignum res;
   for(int i=0; i<LEN; i++)
     res.digit[i] = a.digit[i] + b.digit[i];
   res.fix();
   return res;
   }
 
 bignum operator - (bignum a, bignum b) {
   bignum res;
   for(int i=0; i<LEN; i++)
     res.digit[i] = a.digit[i] - b.digit[i];
   res.fix();
   return res;
   }
 
 bignum operator * (bignum a, bignum b) {
   bignum res;
   for(int a=0; a<LEN; a++) res.digit[a] = 0;
   for(int i=0; i<LEN; i++) for(int j=0; j<LEN; j++) if(i+j<LEN)
     res.digit[i+j] += a.digit[i] * b.digit[j];
   res.fix();
   return res;
   }
 
 bool geq0(bignum a) {
   return a.digit[LEN-1] == 0;
   }
 
 bool greater0(bignum a) {
   if(a.digit[LEN-1] != 0) return false;
   for(int i=0; i<LEN; i++) if(a.digit[i]) return true;
   return false;
   }
 
 bool operator >= (bignum a, bignum b) {
   return geq0(a-b);
   }
 
 bool operator > (bignum a, bignum b) {
   return greater0(a-b);
   }
 
 bool operator < (bignum a, bignum b) {
   return greater0(b-a);
   }
 
 bool operator <= (bignum a, bignum b) {
   return geq0(b-a);
   }
 
 bool operator == (bignum a, bignum b) {
   for(int i=0; i<LEN; i++) if(a.digit[i] != b.digit[i]) return false;
   return true;
   }
 
 bool operator != (bignum a, bignum b) {
   for(int i=0; i<LEN; i++) if(a.digit[i] != b.digit[i]) return true;
   return false;
   }
 
 bignum zero;
 
 string asStr(bignum a) {
   if(!geq0(a))
     return "-" + asStr(zero - a);
   string t;
   for(int i=LEN-1; i>=0; i--) {
     char buf[8];
     sprintf(buf, "%03d", a.digit[i]);
     t += buf;
     }
   while(t != "0" && t[0] == '0') t = t.substr(1);
   return t;
   }
 
 double asLD(bignum a) {
   string t = asStr(a);
   return atof(t.c_str());
   }
 
 bignum goalX, goalY;
 
 vector<bignum> sx;
 vector<bignum> sy;
 
 bignum getFrac() {
   string s = getStr();
   string t = "";
   for(int i=0; i<s.size(); i++)
     if(s[i] != '.') t += s[i];
   int i = atoi(t.c_str());
   return bignum(i);
   }
 
 void solveCase() {
   int res = 0;
 
   int N = getNum();
   bignum V = getFrac(); // 8 digits
   bignum X = getFrac(); 
 
 //  if(cnum == 74) cout << asStr(V) << " / " << asStr(X) << endl;
   
   X = X * V; // 14 digits
   
   sx.clear(); sy.clear();
   
   goalX = V; goalY = X;
   
   // goal: (V,V)
   
   bool cooler = false, hotter = false, nonequal = false;
   
   for(int i=0; i<N; i++) {
     bignum Vi = getFrac();
     bignum Xi = getFrac();
 //  if(cnum == 74) cout << asStr(Vi) << " / " << asStr(Xi) << endl;
     
     Xi = Xi * Vi;
 
     sx.push_back(Vi);
     sy.push_back(Xi);
     
     if(Xi*V <= X*Vi)
       cooler = true;
     if(Xi*V >= X*Vi)
       hotter = true;
     if(Xi*V != X*Vi)
       nonequal = true;
     }
   
 //if(cnum != 74) return;
   
   if(!cooler || !hotter) {
     printf("Case #%d: IMPOSSIBLE\n", cnum);
     return;
     }
   
   if(!nonequal) {
     bignum tX = zero;
     for(int i=0; i<N; i++) tX = tX + sx[i];
     printf("Case #%d: %.9lf\n", cnum, asLD(goalX) / asLD(tX));
     return;
     }
   
   bignum tX = zero, tY = zero;
   for(int i=0; i<N; i++) tX = tX + sx[i];
   for(int i=0; i<N; i++) tY = tY + sy[i];
   
   if(tX*goalY <= goalX*tY) {
     swap(goalX, goalY);
     for(int i=0; i<N; i++) swap(sx[i], sy[i]);
     }
     
   for(int i=1; i<N; i++) {
 //  cout << asStr(sx[i]) << "/" << asStr(sy[i]) << endl;
 //  cout << asStr(sx[i-1]) << "/" << asStr(sy[i-1]) << endl;
 //  cout << "cmp1 " << asStr(sx[i] * sy[i-1]) << endl;
 //  cout << "cmp2 " << asStr(sx[i-1] * sy[i]) << endl;
     
     if(i && sx[i] * sy[i-1] < sx[i-1] * sy[i]) { 
       swap(sx[i], sx[i-1]);
       swap(sy[i], sy[i-1]);
 //    printf("swap\n");
       i -= 2;
       }
     }
     
   tX = zero, tY = zero;
   for(int i=0; i<N; i++) {
 //  printf("i=%d\n", i);
     bignum tX2 = tX + sx[i];
     bignum tY2 = tY + sy[i];
     if(true) {
       bignum c1 = tX * goalY - tY * goalX;
       bignum c2 = tX2 * goalY - tY2 * goalX;
 //    cout << asStr(c1) << " / " << asStr(c2) << endl;
       if(i && ((c1 <= zero && c2 >= zero) || (c1 >= zero && c2 <= zero))) {
         // c1*c2-c2*c1 =
         // (tx*c2-tX2*c1) * goalY
         bignum restX = c2 * tX - c1 * tX2;
         bignum restY = c2 * tY - c1 * tY2;
         // cout << asStr(c1) << endl;
         // cout << asStr(c2) << endl;
         bignum restdiv = c2-c1;
 
         // cout << asStr(restX * goalY - restY * goalX) << endl;
        // got restX water in restdiv time units, want goalX
         printf("Case #%d: %.9lf\n", cnum, asLD(goalX * restdiv) / asLD(restX));
         return;
         // res = c2 * (tX2,tY2) + c1 * (tX1,tY1) / (c1+c2)
         }
       }
     tX = tX2;
     tY = tY2;
     }
   
   printf("ERROR\n");
   }
 
 #define P 1000000007
 
 int main() {
 
 //  cout << asStr(bignum(1201) + bignum(1901)) << endl;
   
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
