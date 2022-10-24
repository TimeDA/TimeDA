#include<stdio.h>
#include<algorithm>
int T, D, N;
double maxT;
int main(){
    scanf("%d", &T);
    for(int tt = 1; tt <= T; ++tt){
        scanf("%d%d", &D, &N);
        maxT = 0;
        for(int i = 1; i <= N; ++i){
            static int K, S;
            scanf("%d%d", &K, &S);
            maxT = std::max(maxT, (double)(D - K) / S);
        }
        printf("Case #%d: %.10f\n", tt, D / maxT);
    }
    return 0;
}