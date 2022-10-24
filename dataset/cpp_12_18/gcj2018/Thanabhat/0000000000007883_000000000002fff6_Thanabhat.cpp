#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

//#include<cstdio>

using namespace std;

int solve(int cc){
    long long R,B,C,M[1005],S[1005],P[1005];
    cin>>R>>B>>C;
    for(int i=0;i<C;i++){
        cin>>M[i]>>S[i]>>P[i];
    }
    long long l=0,m,h=1000000000000000000LL;
    long long sol=-1;
//    cout<<h<<endl;
    while(l<=h){
        m=(l+h)/2;
        vector<int> vv;
        for(int i=0;i<C;i++){
            long long tmp=(m-P[i])/S[i];
            if(tmp>=0){
                tmp=min(tmp,M[i]);
                vv.push_back(tmp);
            }
        }
        sort(vv.begin(),vv.end(),greater<long long>());
        long long sum=0;
        for(int i=0;i<min(R,(long long)vv.size());i++){
            sum+=vv[i];
        }
//        cout<<l<<" "<<m<<" "<<h<<" "<<sum<<endl;
        if(sum>=B){
            h=m-1;
            sol=m;
        }else{
            l=m+1;
        }
    }
    cout<<"Case #"<<cc<<": "<<sol<<endl;
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
//    scanf("%d",&t);
    for(int i=0;i<t;i++){
        solve(i+1);
    }
    return 0;
}
