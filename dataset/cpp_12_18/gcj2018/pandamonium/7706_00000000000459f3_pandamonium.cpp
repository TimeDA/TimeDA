#include <bits/stdc++.h>
using namespace std;
int dp[504][504][36],choose[36];
int f(int r, int b, int i){
    if(r==0&&b==0) return 0;
    if(dp[r][b][i]>=0) return dp[r][b][i];
    dp[r][b][i]=0;
    for(int k=1;;k++){
        int rm=k*i;
        if(rm>r) break;
        int bm=choose[k];
        if(bm>b) break;
        dp[r][b][i]=max(dp[r][b][i],f(r-rm,b-bm,i+1)+k);
    }
    return dp[r][b][i];
}
int main(){
    int t,r,b;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    for(int x=0;x<36;x++) choose[x]=x*(x-1)/2;
    for(int tc=1;tc<=t;tc++){
        scanf("%d %d",&r,&b);
        printf("Case #%d: %d\n",tc,f(r,b,0)-1);
    }
    return 0;
}