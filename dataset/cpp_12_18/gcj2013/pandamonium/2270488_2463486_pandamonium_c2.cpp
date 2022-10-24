#include <cstdio>
 #include <string>
 #include <cstring>
 #include <vector>
 using namespace std;
 int cnt,cnt2,cnt1,t;
 vector <string> nums;
 string a2,b2;
 char a[105],b[105];
 FILE *in=fopen("3in2.txt","r");
 bool cmp(string c, string d){
     if(c.length()==d.length()) return c<d;
     return c.length()<d.length();
 }
 int main(){
     while(fscanf(in,"%s",a)!=EOF){
         while(a[strlen(a)-1]=='\\'){
            fscanf(in,"%s",b);
            a[strlen(a)-1]='\0';
            strcat(a,b);
         }
         nums.push_back(string(a));
     }
     cnt=0;
     scanf("%d\n",&t);
     while(t--){
         cnt++;
         scanf("%s %s\n",a,b);
         //printf("%s %s\n",a,b);
         a2=string(a);
         cnt1=lower_bound(nums.begin(),nums.end(),a2,cmp)-nums.begin();
         b2=string(b);
         cnt2=upper_bound(nums.begin(),nums.end(),b2,cmp)-nums.begin();
         printf("Case #%d: %d\n",cnt,cnt2-cnt1);
     }
     return 0;
 }
