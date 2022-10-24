#include <bits/stdc++.h>
using namespace std;
struct AugPath {
    int A, B;   //size of left, right groups
    vector<vector<int> > G; //size A
    vector<bool> visited;   //size A
    vector<int> P;          //size B

    AugPath(int _A, int _B): A(_A), B(_B), G(_A), P(_B, -1) {}

    void AddEdge(int a, int b) {    //a from left, b from right
        G[a].push_back(b);
    }
    bool Aug(int x) {
        if (visited[x]) return 0;
        visited[x] = 1;
        /* Greedy heuristic */
        for (auto it:G[x]) {
            if (P[it] == -1) {
                P[it] = x;
                return 1;
            }
        }
        for (auto it:G[x]) {
            if (Aug(P[it])) {
                P[it] = x;
                return 1;
            }
        }
        return 0;
    }
    int MCBM() {
        int matchings = 0;
        for (int i = 0; i < A; ++i) {
            visited.resize(A, 0);
            matchings += Aug(i);
            visited.clear();
        }
        return matchings;
    }
};
int t,n,a[104][104];
vector <pair<int,int> >v[204];
int main(){
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        printf("Case #%d: ",tc);
        scanf("%d",&n);
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                scanf("%d",&a[x][y]);
                if(a[x][y]<0) v[n-a[x][y]].emplace_back(x,y);
                else v[a[x][y]].emplace_back(x,y);
            }
        }
        int ans=n*n;
        for(int x=1;x<=2*n;x++){
            if(v[x].empty()) continue;
            AugPath mcbm=AugPath(n,n);
            for(auto i:v[x]) mcbm.AddEdge(i.first,i.second);
            ans-=mcbm.MCBM();
            v[x].clear();
        }
        printf("%d\n",ans);
    }
    return 0;
}