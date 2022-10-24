#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
int T, N;
priority_queue<pair<int,int>> pq;
int main(){
    scanf("%d", &T);
    for(int tt = 1; tt <= T; ++tt){
        scanf("%d", &N);
        int tot = 0;
        for(int i = 0; i < N; ++i){
            static int x;
            scanf("%d", &x);
            pq.push(make_pair(x, i));
            tot += x;
        }
        printf("Case #%d:",tt);
        while(!pq.empty()){
            putchar(' ');
            for(int i = 0; i < 2; ++i) if(!pq.empty()){
                pair<int,int> a = pq.top();
                putchar(a.second + 'A');
                pq.pop();
                if(--a.first) pq.push(a);
                --tot;
                if(tot == 2 && i == 0) break;
            }
        }
        printf("\n");
    }
    return 0;
}