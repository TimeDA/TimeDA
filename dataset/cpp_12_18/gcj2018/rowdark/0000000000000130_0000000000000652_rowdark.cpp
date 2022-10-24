#include<stdio.h>
#include<map>
using namespace std;
map<long long, long long> M;
int T;
long long N, K;
int main(){
    scanf("%d", &T);
    for(int tt = 1; tt <= T; ++tt){
        scanf("%lld%lld", &N, &K);
        M.clear();
        M[N] = 1;
        printf("Case #%d: ", tt);
        for(map<long long, long long>::reverse_iterator iter = M.rbegin(); iter != M.rend(); ++iter){
            if(K <= iter -> second){
                printf("%lld %lld\n", iter -> first / 2, (iter -> first - 1) / 2);
                break;
            }
            else{
                K -= iter -> second;
                M[iter -> first / 2] += iter -> second;
                M[(iter -> first - 1) / 2] += iter -> second;
            }
        }
    }
    return 0;
}