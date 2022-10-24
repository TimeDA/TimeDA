#include <cstdio>
 #include <cstring>
 #include <vector>
 #include <algorithm>
 using namespace std;
 int keys[205][205],mk;
 vector <int> order;
 int k,n,cnt=0,cnt2=0,type[205];
 bool visited[2100000];
 int open(int bm){
     if(cnt2==n){
         for(int x=0;x<n;x++) printf(" %d",order[x]);
         printf("\n");
         return 1;
     }
     if(visited[bm]) return -1;
     visited[bm]=1;
     for(int x=1;x<=n;x++){
         if(!(bm&(1<<x))&&keys[0][type[x]]>0){
             keys[0][type[x]]--;
             for(int y=1;y<=mk;y++) keys[0][y]+=keys[x][y];
             order[cnt2]=x;
             cnt2++;
             if(open(bm|(1<<x))==1) return 1;
             cnt2--;
             for(int y=1;y<=mk;y++) keys[0][y]-=keys[x][y];
             keys[0][type[x]]++;
         }
     }
     return -1;
 }
 int main(){
     int t,x,y,temp,temp2;
     scanf("%d",&t);
     while(t--){
         cnt++;
         cnt2=0;
         order.assign(205,0);
         scanf("%d %d",&k,&n);
         memset(keys,0,sizeof(keys));
         memset(visited,0,sizeof(visited));
         mk=0;
         for(x=0;x<k;x++){
             scanf("%d",&temp);
             mk=max(mk,temp);
             keys[0][temp]++;
         }
         for(x=1;x<=n;x++){
             scanf("%d %d",&type[x],&temp);
             for(y=0;y<temp;y++){
                 scanf("%d",&temp2);
                 keys[x][temp2]++;
                 mk=max(mk,temp2);
             }
         }
         printf("Case #%d:",cnt);
         if(open(0)==-1) printf(" IMPOSSIBLE\n");
     }
     return 0;
 }
