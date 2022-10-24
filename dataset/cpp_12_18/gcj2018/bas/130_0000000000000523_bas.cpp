#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
cin>>t;
for(int i=0; i<t; i++){
    int A, B;
    cin>>A>>B;
    int l=A; int r=B;
    while(true){
        int c = (l+r)/2;
        cout<<c<<"\n";
        string res;
	cin>>res;
        if(res=="CORRECT"){
            break;    
        }
        if(res=="TOO_BIG"){
            r=c-1;
        }else{
            l=c+1;
        }
    }
}
}
