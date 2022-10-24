#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

#define pii pair<int,int>
#define eps 1e-8

using namespace std;

int n,l;
pii ar[100005];
int add[100005];

int solve(int cc){
    cin>>n>>l;
    int remain = n;
    for(int i=0;i<l;i++){
        add[i]=0;
    }
    long double ttt = 100.0L/n;
    ttt -= (long)ttt;
    int nnn=1;
    if(ttt>eps){
        long double ttttt = (0.5L/ttt);
        nnn = (int)(ttttt);
        if(ttttt-(long)ttttt>eps){
            nnn+=1;
        }
    }
    //cout<<ttt<<" "<<nnn<<endl;
    int tmp;
    for(int i=0;i<l;i++){
        cin>>tmp;
        remain-=tmp;
        long double tmp2 = 100.0L/n*tmp;
        tmp2 -= (long)tmp2;
        tmp2 = 0.5-tmp2;
        if(tmp2<0){
            tmp2+=1.0L;
        }
        int tmp3=1;
        if(ttt>eps){
            long double ttttt = (tmp2/ttt);
            tmp3 = (int)(ttttt);
            if(ttttt-(long)ttttt>eps){
                tmp3+=1;
            }
        }
        ar[i].first = tmp3;
        ar[i].second = tmp;
    }
    sort(ar,ar+l);
    /*
    for(int i=0;i<l;i++){
        cout<<ar[i].first<<" "<<ar[i].second<<endl;
    }
    */
    for(int i=0;i<l;i++){
        if(ar[i].first==0){
            continue;
        }
        if(ar[i].first>=nnn){
            break;
        }
        if(ar[i].first<=remain){
            remain-=ar[i].first;
            add[i]=ar[i].first;
        }
    }
    int sol=0;
    for(int i=0;i<l;i++){
        long double ggg = 100.0L/n*(ar[i].second+add[i]);
        sol+=(int)ggg;
        if(ggg-(long)ggg>=0.5-eps){
            sol+=1;
        }
    }
//    for(int i=0;i<l;i++){
//        cout<<ar[i].first<<" "<<ar[i].second<<" "<<add[i]<<endl;
//    }
    //cout<<sol<<endl;
    //cout<<"remain"<<remain<<endl;
    if(remain>0){
        long double ggg = 100.0L/n*(nnn);
        sol+=((int)ggg)*(remain/nnn);
        if(ggg-(long)ggg>=0.5-eps){
            sol+=(remain/nnn);
        }
        sol+=(int)(100.0L/n*(remain%nnn));
    }
//    cout<<sol<<endl;
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
