#include<iostream>
#include<algorithm>

using namespace std;

int ar[2][100005];

int solve(int cc) {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i%2][i/2];
    }
    sort(ar[0],ar[0]+(n+1)/2);
    sort(ar[1],ar[1]+(n)/2);
    int sol=-1;
    for(int i=0;i<n-1;i++){
        if(ar[i%2][i/2]>ar[(i+1)%2][(i+1)/2]){
            sol=i;
            break;
        }
    }
    cout<<"Case #"<<cc<<": ";
    if(sol>=0){
        cout<<sol<<endl;
    }else{
        cout<<"OK"<<endl;
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        solve(i+1);
    }
    return 0;
}
