#include <cstdio>
 #include <cstring>
 #include <string>
 #include <vector>
 #include <algorithm>
 
 using namespace std;
 
 char buffer[1048576];
 
 string getLargestTidy(const string &N) {
   string ans;
   int lastDigit = 0;
   for (int i = 0; i < N.length(); i++) {
     int newDigit = -1;
     for (int digit = lastDigit; digit < 10; digit++) {
       string cand(N.length() - i, '0' + digit);
       string target = N.substr(i);
       if (cand > target) {
         break;
       }
       newDigit = digit;
     }
     if (newDigit > 0) {
       ans.push_back('0' + newDigit);
     }
     lastDigit = newDigit;
     if ('0' + newDigit != N[i]) {
       ans += string(N.length() - i - 1, '9');
       break;
     }
   }
   return ans;
 }
 int main() {
   int T;
   scanf("%d", &T);
   for (int testcase = 1; testcase <= T; testcase++) {
     printf("Case #%d: ", testcase);
     scanf("%s", buffer);
     printf("%s\n", getLargestTidy(buffer).c_str());
   }
   return 0;
 }