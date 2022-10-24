#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<set>

#define pii pair<int,int>
#define eps 1e-8

using namespace std;

int solve(int cc){
    int s;
    int d[105],a[105],b[105],da[105],db[105];
    int cnt[105];
    cin>>s;
    for(int i=0;i<s;i++){
        cin>>d[i]>>a[i]>>b[i];
        da[i]=d[i]+a[i];
        db[i]=d[i]-b[i];
        //cout<<d[i]<<" "<<a[i]<<" "<<b[i]<<" "<<da[i]<<" "<<db[i]<<endl;
    }
    for(int i=0;i<=s;i++){
        cnt[i]=0;
    }
    for(int i=0;i<s;i++){
        set<int> sa;
        for(int j=i;j<s;j++){
            int valid = 0;

            sa.insert(da[j]);
            for(auto it=sa.begin();it!=sa.end();it++){
                int vala=*it;
                set<int> sb;
                for(int k=i;k<=j;k++){
                    if(da[k]!=vala){
                        sb.insert(db[k]);
                    }
                }
                if(sb.size()<=1){
                    valid=1;
                    break;
                }
            }
            //cout<<"->"<<i<<" "<<j<<" "<<valid<<endl;
            if(valid==1){
                cnt[j-i+1]++;
            }
            if(valid==0){
                break;
            }
        }
    }
    cout<<"Case #"<<cc<<": ";
    for(int i=s;i>=0;i--){
        if(cnt[i]){
            cout<<i<<" "<<cnt[i]<<endl;
            break;
        }
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
