#include <bits/stdc++.h>

using namespace std;

int my, mx, cy, cx;
char arr[110][110];
int cntx[110], cnty[110], cpx[110], cpy[110];
int s;

bool good(int *arr, int n, int sp, int *cp) {
    if (s % (sp + 1) != 0) return false;
    int ss = s / (sp + 1);
    int cur = 0;
    int idx = 1 ;
    cp[0] = 0;
    for (int i = 0; i < n; ++i) {
        cur += arr[i];
        if (cur > ss) return false;
        if (cur == ss) {
           cur = 0;
           cp[idx++] = i + 1;
        }
    }
    cp[idx] = n;
    return true;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        memset(cntx, 0, sizeof(cntx));
        memset(cnty, 0, sizeof(cnty));
        s = 0;
        
        scanf("%d%d%d%d", &my, &mx, &cy, &cx);
        
        for (int i = 0; i < my; ++i) {
            scanf("%s", arr[i]);
            for (int j = 0; j < mx; ++j) {
                if (arr[i][j] == '@') {
                    ++s;
                    ++cnty[i];
                    ++cntx[j];
                }
            }
        }
        
        bool ok = (good(cnty, my, cy, cpy) && good(cntx, mx, cx, cpx)) && (s % ((cx + 1) * (cy + 1)) == 0);
        
        int ss = s / (cx + 1) / (cy + 1);
        if (ok) {
            
            for (int i = 0; ok && i <= cy; ++i) {
                for (int j = 0; ok && j <= cx; ++j) {
                    int cnt = 0;
                    for (int y = cpy[i]; y < cpy[i + 1]; ++y)
                    for (int x = cpx[j]; x < cpx[j + 1]; ++x)
                    if (arr[y][x] == '@') ++cnt;
                    if (cnt != ss) ok = false;
                }
            }
        }
        
        if (ok) printf("Case #%d: POSSIBLE\n", t);
        else printf("Case #%d: IMPOSSIBLE\n", t);
    }
    
    return 0;
}
