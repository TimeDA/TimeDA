#include<stdio.h>
int T, L, R, N, M;
int main(){
    scanf("%d", &T);
    for(int tt = 1; tt <= T; ++tt){
        scanf("%d%d", &L, &R);
        scanf("%d", &N);
        while(1){
            int M = (L + R + 1) / 2;
            printf("%d\n", M);
            fflush(stdout);
            static char s[200];
            scanf("%s", s);
            if(s[0] == 'C') break;
            else if(s[4] == 'S') L = M;
            else R = M;
        }
    }
    return 0;
}