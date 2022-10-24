#define BUFSIZE 1000000
 char buf[BUFSIZE];
 int Tests, cnum;
 // #define USEWIN
 #define MANYTESTS 1
 // #define LINEBYLINE
 
 // Eryx's new template for I/O contests, May 3, 2015
 
 #include <algorithm>
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
 
 #line 10 "work.cpp"
 
 /// ----
 
 
 //Eryx
 
 // !FDI
 
 int drum[200][200], X, Y, solves;
 
 int drum2[200][200];
 
 bool correct(int x, int y) {
   int q = 0;
   if(y && drum[y-1][x] == drum[y][x]) q++;
   if(y<Y-1 && drum[y+1][x] == drum[y][x]) q++;
   if(drum[y][(x+1)%X] == drum[y][x]) q++;
   if(drum[y][(x+X-1)%X] == drum[y][x]) q++;
   return drum[y][x] == q;
   }
 
 bool checkTwoDrums() {
   for(int y=0; y<Y; y++) for(int x=0; x<X; x++)
     if(drum[y][x] != drum2[y][x])
       return drum[y][x] < drum2[y][x];
   return false;
   }
 
 
 bool lexfirst() {
   for(int s=0; s<X; s++) {
     for(int y=0; y<Y; y++) for(int x=0; x<X; x++)
       drum2[y][x] = drum[y][(x+s) % X];
     
     if(checkTwoDrums()) { return false; }
     }
   return true;
   }
 
 void solve(int x, int y) {
 //printf("%d,%d\n", x, y);
   if(x==X) { x=0; y++; }
   if(y==Y) { 
     if(!lexfirst()) return;
     solves++; 
     /* for(int y=0; y<Y; y++) {
       for(int x=0; x<X; x++) printf("%d ", drum[y][x]);
       printf("\n");
       }
     printf("\n"); */
     return; 
     }
   for(int z=1; z<=3; z++) {
     drum[y][x] = z;
     if(y && !correct(x, y-1)) continue;
     if(y == Y-1 && x > 1) {
       if(!correct(x-1, y)) continue;
       if(x == X-1 && !correct(0, y)) continue;
       if(x == X-1 && !correct(x, y)) continue;
       }
     solve(x+1, y);
     }
   }
 
 void solveCase() {
   int res = 0;
 
   Y = getNum(), X = getNum();
   
   solves = 0;
   solve(0, 0);
   
   printf("Case #%d: %d\n", cnum, solves);
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
