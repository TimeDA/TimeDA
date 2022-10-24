#include <bits/stdc++.h>
using namespace std;
char grid[24][24];
bool vis[24][24];
int r,c,t;
typedef pair<int,int> ii;
queue <ii>q;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
unordered_set <string> us[4];
inline bool check(int x, int y, int x2, int y2, int z, string& s){
    if(z==0&&grid[x2][y2]!=s[0]) return 0;
    if(z==1){
        if(y2<=y&&grid[x2][y2]!=s[0]) return 0;
        if(y2>y&&grid[x2][y2]!=s[1]) return 0;
    }
    if(z==2){
        if(x2<=x&&grid[x2][y2]!=s[0]) return 0;
        if(x2>x&&grid[x2][y2]!=s[1]) return 0;
    }
    if(z==3){
        if(x2<=x&&y2<=y&&grid[x2][y2]!=s[0]) return 0;
        if(x2<=x&&y2>y&&grid[x2][y2]!=s[1]) return 0;
        if(x2>x&&y2<=y&&grid[x2][y2]!=s[2]) return 0;
        if(x2>x&&y2>y&&grid[x2][y2]!=s[3]) return 0;
    }
    return 1;
}
int main(){
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d %d",&r,&c);
        for(int x=0;x<r;x++){
            scanf("%s",grid[x]);
        }
        for(int x=0;x<4;x++) us[x].clear();
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                string s="";
                s+=grid[x][y];
                us[0].insert(s);
                if(y<c-1){
                    s+=grid[x][y+1];
                    us[1].insert(s);
                    if(x<r-1){
                        s+=grid[x+1][y];
                        s+=grid[x+1][y+1];
                        us[3].insert(s);
                    }
                }
                if(x<r-1){
                    s="";
                    s+=grid[x][y];
                    s+=grid[x+1][y];
                    us[2].insert(s);
                }
            }
        }
        int ans=1;
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                for(int z=0;z<4;z++){
                    if(z==1&&y==c-1) continue;
                    if(z==2&&x==r-1) continue;
                    if(z==3&&(x==r-1||y==c-1)) continue;
                    for(auto s:us[z]){
                        memset(vis,0,sizeof(vis));
                        for(int xx=0;xx<r;xx++){
                            for(int yy=0;yy<c;yy++){
                                if(!check(x,y,xx,yy,z,s)) continue;
                                while(!q.empty()) q.pop();
                                q.push(ii(xx,yy));
                                int cnt=1;
                                vis[xx][yy]=1;
                                while(!q.empty()){
                                    ii cur=q.front();
                                    q.pop();
                                    for(int d=0;d<4;d++){
                                        int x2=cur.first+dx[d];
                                        if(x2<0||x2>=r) continue;
                                        int y2=cur.second+dy[d];
                                        if(y2<0||y2>=c) continue;
                                        if(vis[x2][y2]) continue;
                                        if(!check(x,y,x2,y2,z,s)) continue;
                                        vis[x2][y2]=1;
                                        q.push(ii(x2,y2));
                                        cnt++;
                                    }
                                }
                                ans=max(ans,cnt);
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}