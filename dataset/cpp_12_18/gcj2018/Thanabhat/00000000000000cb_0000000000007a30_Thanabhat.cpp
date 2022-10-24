#include<iostream>

using namespace std;

int tb[1005][1005];

int solve(int cc) {
    int a;
    cin>>a;
    int x1,x2,y1,y2;
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=1000;j++){
            tb[i][j]=0;
        }
    }
    if(a==20){
        x1=500;
        x2=502;
        y1=500;
        y2=501;
    }else if(a==200){
        x1=500;
        x2=517;
        y1=500;
        y2=507;
    }
    int dx[9]={-1,0,1,-1,0,1,-1,0,1};
    int dy[9]={-1,-1,-1,0,0,0,1,1,1};

    while(true){
        int mx=0;
        int nextx=500;
        int nexty=500;
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                int sum=9;
                for(int k=0;k<9;k++){
                    sum-=tb[i+dx[k]][j+dy[k]];
                }
                //cout<<"->"<<i<<" "<<j<<" "<<sum<<endl<<flush;
                if(sum>mx){
                    mx=sum;
                    nextx=i;
                    nexty=j;
                }
            }
        }
        cout<<nextx<<" "<<nexty<<endl<<flush;

        int rx,ry;
        cin>>rx>>ry;
        if(rx==0&&ry==0){
            return 0;
        }else if(rx==-1&&ry==-1){
            return 1;
        }else{
            tb[rx][ry]=1;
        }
    }
    return 0;
}

int main() {
    //std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    bool error = false;
    for(int i=0;i<t&&!error;i++){
        error |= solve(i+1);
    }
    return 0;
}
