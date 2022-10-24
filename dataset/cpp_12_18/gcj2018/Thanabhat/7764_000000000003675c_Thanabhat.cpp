#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<set>

#define pii pair<int,int>
#define eps 1e-8

using namespace std;

int m,r[105],g[105],ig[105][2];
int sol;
int rec(vector<int> &v){
    if(v.size()==m-1){
//        cout<<v.size()<<"->";
//        for(int i=0;i<v.size();i++){
//            cout<<v[i]<<" ";
//        }
//        cout<<endl;
        int gg[105];
        for(int i=0;i<m;i++){
            gg[i]=g[i];
        }
        for(int i=0;i<v.size();i++){
            gg[i+1]+=v[i];
            gg[ig[i+1][0]]-=v[i];
            gg[ig[i+1][1]]-=v[i];
        }
        bool valid=true;
        for(int i=0;i<m;i++){
            if(gg[i]<0){
                valid=false;
            }
        }
        if(valid){
            sol=max(sol,g[0]+min(gg[ig[0][1]],gg[ig[0][0]]));
//            cout<<sol<<endl;
//            for(int i=0;i<v.size();i++){
//                cout<<v[i]<<" ";
//            }
//            cout<<endl;
        }
    }else{
        int tmp=v.size()+1;
        for(int i=0;i<max(g[ig[tmp][0]],g[ig[tmp][1]]);i++){
            v.push_back(i);
            rec(v);
            v.pop_back();
        }
    }
    return 0;
}

int solve(int cc){
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>ig[i][0]>>ig[i][1];
        ig[i][0]--;
        ig[i][1]--;
    }
    for(int i=0;i<m;i++){
        cin>>g[i];
    }
    sol=g[0];
    vector<int> vv;
    rec(vv);

    cout<<"Case #"<<cc<<": "<<sol<<endl;
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
