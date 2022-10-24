#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ENDL "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int curr_case = 1; curr_case <= T; ++curr_case)
    {
        int C; cin >> C;
        vector<int> Bs(C);
        for(int i = 0; i < C; ++i){cin >> Bs[i];}

        cout << "Case #" << curr_case << ": ";
        if(Bs.front() == 0 || Bs.back() == 0){
            // cerr << "not in else" << ENDL;
            cout << "IMPOSSIBLE" << ENDL;
        }else{
            // cerr << "in else" << ENDL;
            int lowest = -1;
            queue<int> q;
            for(int i = 0; i < C; ++i){
                for(int j = 0; j < Bs[i]; ++j){
                    q.push(i);
                }
            }
            vector<vector<char>> grid(C,vector<char>(C,'.'));
            for(int i = 0; i < C; ++i){
                int bottom_col = q.front();
                q.pop();
                for(int j = i, row=0; j > bottom_col; --j, ++row){
                    grid[row][j] = '/';
                    lowest = max(lowest, row);
                }
                for(int j = i, row=0; j < bottom_col; ++j, ++row){
                    grid[row][j] = '\\';
                    lowest = max(lowest, row);
                }
            }
            int height = lowest + 2;
            cout << height << ENDL;
            for(int i = 0; i < height; ++i){
                for(const auto x : grid[i]) cout << x;
                cout << ENDL;
            }
        }
    }
    return 0;
}
