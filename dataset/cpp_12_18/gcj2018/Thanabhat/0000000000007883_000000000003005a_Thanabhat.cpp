#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

using namespace std;

int solve(int cc){
    bool sol=true;
    int r,c,h,v;
//    string str[105];
    char str[105][105];

//    cin>>r>>c>>h>>v;
    scanf("%d %d %d %d",&r,&c,&h,&v);
    for(int i=0;i<r;i++){
//        cin>>str[i];
        scanf("%s",str[i]);
    }

//    cout<<"Case #"<<cc<<": ";
    printf("Case #%d: ",cc);

    int cntall=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(str[i][j]=='@'){
                cntall++;
            }
        }
    }

    int each=cntall/(h+1)/(v+1);
    if(cntall==0){
//        cout<<"POSSIBLE"<<endl;
        printf("POSSIBLE\n");
        return 0;
    }
    if(each*(h+1)*(v+1)!=cntall){
        sol=false;
    }else{
        int sumh[105]={0};
        int sumv[105]={0};
        for(int i=0;i<r;i++){
            int tmp=0;
            for(int j=0;j<c;j++){
                if(str[i][j]=='@'){
                    tmp++;
                }
            }
            sumh[i]=tmp;
        }
        for(int j=0;j<c;j++){
            int tmp=0;
            for(int i=0;i<r;i++){
                if(str[i][j]=='@'){
                    tmp++;
                }
            }
            sumv[j]=tmp;
        }
        vector<int> cuth,cutv;
        cuth.push_back(-1);
        cutv.push_back(-1);
        int cnt=0;
        for(int i=0;i<r;i++){
            cnt+=sumh[i];
            //cout<<i<<" "<<cnt<<endl;
            if(cnt==each*(v+1)){
                cuth.push_back(i);
                cnt=0;
            }
        }
        if(cuth.size()!=h+2){
            sol=false;
        }

        int hind = 0;
        int sum[h+1];
        for(int k=0;k<h+1;k++){
            sum[k]=0;
        }
        for(int j=0;j<c;j++){
//            cout<<j<<endl;
//            for(int k=0;k<h+1;k++){
//                cout<<sum[k]<<" ";
//            }
//            cout<<endl;
            for(int ii=0;ii<cuth.size()-1;ii++){
                //cout<<ii<<endl;
                for(int i=cuth[ii]+1;i<=cuth[ii+1];i++){
                    if(str[i][j]=='@'){
                        sum[ii]+=1;
                    }
                }
            }
//            cout<<"check"<<endl;
            for(int k=0;k<h+1;k++){
                if(sum[k]==each){
                    if(k==h){
                        cutv.push_back(j);
                        for(int kk=0;kk<h+1;kk++){
                            sum[kk]=0;
                        }
                    }
                }else{
                    break;
                }
            }
//            cout<<"check"<<endl;
        }
        if(cutv.size()!=v+2){
            sol=false;
        }
    }
    if(sol){
//        cout<<"POSSIBLE"<<endl;
        printf("POSSIBLE\n");
    }else{
//        cout<<"IMPOSSIBLE"<<endl;
        printf("IMPOSSIBLE\n");
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    //cin>>t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        solve(i+1);
    }
    return 0;
}
