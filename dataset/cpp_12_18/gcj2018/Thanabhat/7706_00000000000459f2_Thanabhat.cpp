#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

#define pii pair<int,int>
#define eps 1e-8

using namespace std;

int solve(int cc){
    int c;
    int b[105];
    int inv[105][2];
    cin>>c;
    for(int i=0;i<c;i++){
        cin>>b[i];
        inv[i][0]=inv[i][1]=-1;
    }
    cout<<"Case #"<<cc<<": ";
    int valid=0;
    for(int i=0;i<c;i++){
        if((i==0||i==c-1)&&b[i]==0){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
        if(b[i]>0){
            inv[i][0]=valid;
            inv[i][1]=valid+b[i]-1;
            valid=inv[i][1]+1;
        }
    }
//    for(int i=0;i<c;i++){
//        cout<<i<<" "<<inv[i][0]<<" "<<inv[i][1]<<endl;
//    }
    char tb[105][105];
    for(int i=0;i<105;i++){
        for(int j=0;j<c;j++){
            tb[i][j]='.';
        }
        tb[i][c]=0;
    }
    int mx = 0;
    for(int i=0;i<c;i++){
        if(inv[i][0]!=-1&&inv[i][1]!=-1){
            int L=i-inv[i][0];
            if(L>0){
                for(int j=0;j<L;j++){
                    int y=j+1;
                    int x=i-1-j;
                    if(x<0||x>=c||tb[y][x]!='.'){
                        cout<<"IMPOSSIBLE"<<endl;
                        return 0;
                    }
                    tb[y][x]='\\';
                    mx=max(mx,y);
                }
            }
            int R=inv[i][1]-i;
            if(R>0){
                for(int j=0;j<R;j++){
                    int y=j+1;
                    int x=i+1+j;
                    if(x<0||x>=c||tb[y][x]!='.'){
                        cout<<"IMPOSSIBLE"<<endl;
                        return 0;
                    }
                    tb[y][x]='/';
                    mx=max(mx,y);
                }
            }
        }
    }
    cout<<mx+1<<endl;
    for(int i=mx;i>=0;i--){
        cout<<tb[i]<<endl;
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
