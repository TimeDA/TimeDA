#include<iostream>
#include<string>

using namespace std;

int count(string s) {
    int sum=0;
    int cur=1;
    for(int i=0;i<s.length();i++){
        if(s[i]=='S'){
            sum+=cur;
        }else if(s[i]=='C'){
            cur*=2;
        }
    }
    return sum;
}

bool move(string& s) {
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='S'&&i>0&&s[i-1]=='C'){
            s[i]='C';
            s[i-1]='S';
            return true;
        }
    }
    return false;
}

int solve(int cc){
    int d;
    string p;
    cin>>d>>p;
    int sol=0;
    while(count(p)>d){
        bool canmove = move(p);
        if(!canmove){
            sol=-1;
            break;
        }
        sol++;
        //cout<<p<<" "<<sol<<endl;
    }
    cout<<"Case #"<<cc<<": ";
    if(sol>=0){
        cout<<sol<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve(i+1);
    }
    return 0;
}
