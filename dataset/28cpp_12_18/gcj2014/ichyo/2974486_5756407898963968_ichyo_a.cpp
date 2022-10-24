#include <bits/stdc++.h>
 #define REP(i,n) for(int i=0; i<(int)(n); ++i)
 
 using namespace std;
 set<int> parse_input(){
     int row;
     cin >> row;
     set<int> res;
     REP(y, 4) {
         int g[4];
         REP(x, 4) {
             cin >> g[x];
         }
         if(y + 1 == row){
             REP(x, 4) {
                 res.insert(g[x]);
             }
         }
     }
     return res;
 }
 
 int main(){
     int TESTCASE;
     cin >> TESTCASE;
     for(int casenumber = 0; casenumber < TESTCASE; casenumber++){
         printf("Case #%d: ", casenumber + 1);
         set<int> s1 = parse_input();
         set<int> s2 = parse_input();
         set<int> s;
         for(int i = 1; i <= 16; i++){
             if(s1.count(i) && s2.count(i)) s.insert(i);
         }
         if(s.size() == 0) {
             cout << "Volunteer cheated!" << endl;
         } else if(s.size() >= 2) {
             cout << "Bad magician!" << endl;
         } else {
             cout << *s.begin() << endl;
         }
     }
     return 0;
 }
 
