#include <bits/stdc++.h>

using namespace std;

int arr[25][25];
int mx, my;
int offset = 10;

bool cmd(int x, int y) {
    printf("%d %d\n", x + offset, y + offset);
    fflush(stdout);
    scanf("%d%d", &x, &y);
    if (x == 0 && y == 0) return true;
    if (x == -1 && y == -1) exit(0);
    arr[x - offset][y - offset] = 1;
    return false;
}

int getp(int x, int y) {
    int ans = 0;
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            ans += 1 - arr[x + dx][y + dy];
        }
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        int a;
        scanf("%d", &a);
        memset(arr, 0, sizeof(arr));
        if (a == 20) {
            mx = 4;
            my = 5;
        } else {
            mx = 10;
            my = 20;
        }
        while (true) {
            int bx = 0, by = 0;
            int bp = 0;
            for (int x = 1; x < mx - 1; ++x) {
                for (int y = 1; y < my - 1; ++y) {
                    int cp = getp(x, y);
                    if (cp > bp) {
                        bp = cp;
                        bx = x;
                        by = y;
                    }
                }
            }
            if (cmd(bx, by)) break;
        }
    }

    return 0;
}
