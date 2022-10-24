#include <cstdio>
 #include <string>
 #include <algorithm>
 #include <vector>
 using namespace std;
 string ans="";
 vector <string> nums,zeros; 
 int size,x;
 bool parity;
 bool cmp(string a, string b){
     if(a.length()==b.length()) return a<b;
     return a.length()<b.length();
 }
 void recur(int level, int prev){
     if(prev+1>=size/2||level==5) return;
     for(int i=prev+1;i<size/2;i++){
         ans[i]='1';
         ans[size-1-i]='1';
         nums.push_back(ans);
         if(parity){
             ans[size/2]='1';
             nums.push_back(ans);
             if(level==2){
                 ans[size/2]='2';
                 nums.push_back(ans);
             }
             ans[size/2]='0';
         }
         recur(level+1,i);
         ans[i]='0';
         ans[size-1-i]='0';
     }
     return;
 }
 int main(){
     zeros.clear();
     zeros.push_back("");
     for(x=1;x<55;x++){
         zeros.push_back(zeros[x-1]);
         zeros[x]+="0";
     }
     nums.clear();
     nums.push_back("0");
     nums.push_back("1");
     nums.push_back("2");
     nums.push_back("3");
     for(x=1;x<=25;x++){
         size=2*x;
         ans=zeros[x*2];
         ans[0]='2';
         ans[x*2-1]='2';
         nums.push_back(ans);
         ans[0]='1';
         ans[x*2-1]='1';
         nums.push_back(ans);
         parity=0;
         recur(2,0);
         size=2*x+1;
         ans=zeros[x*2+1];
         ans[0]='2';
         ans[x*2]='2';
         nums.push_back(ans);
         ans[x]='1';
         nums.push_back(ans);
         ans[x]='0';
         ans[0]='1';
         ans[x*2]='1';
         nums.push_back(ans);
         ans[x]='1';
         nums.push_back(ans);
         ans[x]='0';
         parity=1;
         recur(2,0);
     }
     sort(nums.begin(),nums.end(),cmp);
     for(x=0;x<int(nums.size());x++){
         printf("%s\n",nums[x].c_str());
     }
     return 0;
 }
