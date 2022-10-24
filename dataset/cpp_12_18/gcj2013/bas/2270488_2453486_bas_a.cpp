//
 //  C.cpp
 //  
 //
 #include <algorithm>
 #include <iostream>
 #include<vector>
 #include<cmath>
 #include <iomanip>
 #include<string>
 #define mod 1000000007
 
 
 
 using namespace std;
 vector<string> map;
 
 bool hor(int n, char t){
     for(int i=0; i<4; i++) if(map[n][ i]!=t && map[n][i]!='T') return false;
     return true;
 }
 bool ver(int n, char t){
     for(int i=0; i<4; i++) if(map[i][ n]!=t && map[i][n]!='T') return false;
     return true;
 }
 
 bool diag1(char t){
     for(int i=0; i<4; i++)if(map[i][ i]!=t && map[i][i]!='T') return false;
     return true;
 
 }
 
 bool diag2(char t){
     for(int i=0; i<4; i++)if(map[i][ 3-i]!=t && map[i][3-i]!='T') return false;
     return true;
     
 }
 
 
 bool test(char t){
     for(int i=0; i<4; i++){
         if(hor(i, t) || ver(i, t))return true;
     }
     if(diag1(t) || diag2(t)) return true;
     return false;
     
 }
 bool dots(){
     for(int i=0; i<4; i++){
         for(int j=0; j<4; j++){
             if(map[i][j]=='.')return true;
             
         }
     }
     return false;
 }
 
 int main(){
     int T;
     cin>>T;
     for (int i=1; i<=T; i++){
         map.clear(); map.resize(4);
         for(int j=0; j<4; j++)
             cin>>map[j];
         string tmp;
         getline(cin, tmp);
         
         cout<<"Case #"<<i<<": ";
         
         if(test('X'))cout<<"X won";
         else if(test('O'))cout<<"O won";
         else if(dots())cout<<"Game has not completed";
         else cout<<"Draw";
         
         cout<<"\n";
     }
 }
