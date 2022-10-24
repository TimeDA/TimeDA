#include<iostream>

using namespace std;

int solve(int cc) {
    int a,b,n;
    cin>>a>>b>>n;
    a++;
    int cnt = 0;
    while(cnt<n){
        int c=(b-a)/2+a;
        cout<<c<<endl<<flush;
        string response;
        cin>>response;
        if(response=="CORRECT"){
            return 0;
        }else if (response=="TOO_SMALL"){
            a=c+1;
        }else if (response=="TOO_BIG"){
            b=c-1;
        }else if (response=="WRONG_ANSWER"){
            return 1;
        }
        cnt++;
    }


    return 0;
}

int main() {
    int t;
    cin>>t;
    bool error = false;
    for(int i=0;i<t&&!error;i++){
        error |= solve(i+1);
    }

    return 0;
}
