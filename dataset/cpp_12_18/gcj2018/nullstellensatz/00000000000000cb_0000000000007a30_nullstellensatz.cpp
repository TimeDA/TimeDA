


/*
    Prob:
    Author: 
    Time:   
    Description:
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

const int MaxN = 205;
const int init = 100, term = 160;

int T, n;
bool tree[MaxN][MaxN];

bool check(int pos_x, int pos_y) {
    if (pos_x < 0 || pos_y < 0) return true;
    for (int i = -1; i <= 1; ++ i)
        for (int j = -1; j <= 1; ++ j)
            if (!tree[pos_x + i][pos_y + j]) return false;
    
    return true;
}

int main() {    
    cin >> T;
    for (int testcase = 1; testcase <= T; ++ testcase) {
        cin >> n;
        memset(tree, 0, sizeof tree);
        int cur_x = init, cur_y = init;
        while (cur_x > 0 && cur_y > 0) {
            int pos_x, pos_y;
            do {
                cout << cur_x << " " << cur_y << endl;
                cout.flush();
                cin >> pos_x >> pos_y;
                if (pos_x > 0 && pos_y > 0)
                    tree[pos_x][pos_y] = true;
                else
                    cur_x = cur_y = -1;
            } while (!check(cur_x, cur_y));
            if (cur_y > term) ++ cur_y; else cur_y += 3;
        }
    }
    
    return 0;
}
