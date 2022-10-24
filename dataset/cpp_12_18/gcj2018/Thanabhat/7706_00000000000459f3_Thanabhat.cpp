#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<set>

#define pii pair<int,int>
#define eps 1e-8

using namespace std;

int cal1(int n1,int n2){
    int sol=0;
    int x=1;
    while(true){
        for(int a=0;a<=x;a++){
            int b=x-a;
            if(n1>=a&&n2>=b){
                n1-=a;
                n2-=b;
                sol++;
            }
        }
        if(x>n1+n2){
            break;
        }
        x++;
    }
    return sol;
}
int cal2(int n1,int n2){
    int sol=0;
    int tb[33][33];
    for(int i=0;i<33;i++){
        for(int j=0;j<33;j++){
            tb[i][j]=0;
        }
    }
    int lastsol=sol;
    while(true){
        lastsol=sol;
        for(int i=0;i<33;i++){
            for(int j=0;j<33;j++){
                if(tb[i][j]||(i==0&&j==0)){
                    continue;
                }
                if(n1>=i&&n2>=j){
                    tb[i][j]=1;
                    n1-=i;
                    n2-=j;
                    sol++;
    //                cout<<i<<" "<<j<<endl;
                }else{
                    for(int ii=0;ii<i;ii++){
                        for(int jj=32;jj>=0;jj--){
                            if(tb[ii][jj]){
                                if(ii+n1>=i*2&&jj+n2>=j*2+1){
                                    tb[ii][jj]=0;
                                    tb[i][j]=1;
                                    tb[i][j+1]=1;
                                    sol++;
                                    n1+=(ii-i-i);
                                    n2+=(jj-j-j-1);
    //                cout<<i<<" "<<j<<endl;
    //                cout<<i<<" "<<j+1<<endl;
                                }
                            }else{
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(lastsol==sol){
            break;
        }
    }
    for(int i=0;i<33;i++){
        for(int j=i;j<33;j++){
            int tmp=tb[i][j];
            tb[i][j]=tb[j][i];
            tb[j][i]=tmp;
        }
    }
    int tmp=n1;
    n1=n2;
    n2=tmp;
    while(true){
        lastsol=sol;
        for(int i=0;i<33;i++){
            for(int j=0;j<33;j++){
                if(tb[i][j]||(i==0&&j==0)){
                    continue;
                }
                if(n1>=i&&n2>=j){
                    tb[i][j]=1;
                    n1-=i;
                    n2-=j;
                    sol++;
    //                cout<<i<<" "<<j<<endl;
                }else{
                    for(int ii=0;ii<i;ii++){
                        for(int jj=32;jj>=0;jj--){
                            if(tb[ii][jj]){
                                if(ii+n1>=i*2&&jj+n2>=j*2+1){
                                    tb[ii][jj]=0;
                                    tb[i][j]=1;
                                    tb[i][j+1]=1;
                                    sol++;
                                    n1+=(ii-i-i);
                                    n2+=(jj-j-j-1);
    //                cout<<i<<" "<<j<<endl;
    //                cout<<i<<" "<<j+1<<endl;
                                }
                            }else{
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(lastsol==sol){
            break;
        }
    }
    return sol;
}

int solve(int cc){
    int R,B;
    cin>>R>>B;
//    if(R>B){
//        int tmp=R;
//        R=B;
//        B=tmp;
//    }
    int sol=max(cal1(R,B),cal1(B,R));
    sol=max(sol,cal2(B,R));
    sol=max(sol,cal2(R,B));
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
