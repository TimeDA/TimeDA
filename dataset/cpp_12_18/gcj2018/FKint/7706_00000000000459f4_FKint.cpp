#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ENDL "\n"
const int NEIGHBOUR[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool in_grid(int r, int c, int top_row, int left_col, int bottom_row, int right_col){
    return r >= top_row && r <= bottom_row && c >= left_col && c <= right_col;
}
int find_connected_size_except(int start_row, int start_col, vector<vector<char>>& grid, int row_top, int col_left, int row_bottom, int col_right){
    int R = grid.size();
    int C = grid[0].size();
    if(!in_grid(start_row, start_col, 0, 0, R-1, C-1)){
        return 0;
    }
    if(in_grid(start_row, start_col, row_top, col_left, row_bottom, col_right)){
        return 0;
    }
    char color = grid[start_row][start_col];

    set<pair<int,int>> connected_component;
    queue<pair<int,int>> q;
    q.push(make_pair(start_row, start_col));
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        if(connected_component.count(t)){
            continue;
        }
        connected_component.insert(t);
        for(int i = 0; i < 4; ++i){
            pair<int,int> nb = make_pair(t.first + NEIGHBOUR[i][0], t.second + NEIGHBOUR[i][1]);
            if(!in_grid(nb.first, nb.second, 0, 0, R-1, C-1)){
                continue;
            }
            if(in_grid(nb.first, nb.second, row_top, col_left, row_bottom, col_right)){
                continue;
            }
            if(grid[nb.first][nb.second] != color){
                continue;
            }
            if(connected_component.count(nb)){
                continue;
            }
            q.push(nb);
        }
    }
    return connected_component.size();
}
int find_connected_size(int start_row, int start_col, vector<vector<char>>& grid, int row_top, int col_left, int row_bottom, int col_right){
    if(!in_grid(start_row, start_col, row_top, col_left, row_bottom, col_right)){
        return 0;
    }
    char color = grid[start_row][start_col];

    set<pair<int,int>> connected_component;
    queue<pair<int,int>> q;
    q.push(make_pair(start_row, start_col));
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        if(!in_grid(t.first, t.second, row_top, col_left, row_bottom, col_right)){
            continue;
        }
        if(connected_component.count(t)){
            continue;
        }
        connected_component.insert(t);
        for(int i = 0; i < 4; ++i){
            pair<int,int> nb = make_pair(t.first + NEIGHBOUR[i][0], t.second + NEIGHBOUR[i][1]);
            if(!in_grid(nb.first, nb.second, row_top, col_left, row_bottom, col_right)){
                continue;
            }
            if(grid[nb.first][nb.second] != color){
                continue;
            }
            if(connected_component.count(nb)){
                continue;
            }
            q.push(nb);
        }
    }
    return connected_component.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for (int curr_case = 1; curr_case <= T; ++curr_case)
    {
        int R, C; cin >> R >> C;
        vector<vector<char>> grid(R,vector<char>(C));
        for(int i = 0; i < R; ++i){
            for(int j = 0; j < C; ++j){
                cin >> grid[i][j];
            }
        }
        int best = 0;
        for(int i = 0; i <= R; ++i){
            for(int j = 0; j <= C; ++j){
                int best_full = find_connected_size(i, j, grid, 0, 0, R-1, C-1);
                int topleft = find_connected_size(i-1,j-1,grid, 0, 0, i-1, j-1);
                int topright = find_connected_size(i-1,j, grid, 0, j, i-1, C-1);
                int bottomleft = find_connected_size(i, j-1, grid, i, 0, R-1,j-1);
                int bottomright = find_connected_size(i, j, grid, i, j, R-1,C-1);
                int separate_quarters = 0;
                if(topleft == 0 && bottomright == 0){
                    separate_quarters = max(topright, bottomleft);
                }else if(bottomleft == 0 && topright == 0){
                    separate_quarters = max(bottomright, topleft);
                }else{
                    separate_quarters = topleft + topright + bottomleft + bottomright;
                }
                int except_topleft = max(
                    find_connected_size_except(i-1,j,grid, 0, 0, i-1, j-1),
                    find_connected_size_except(i,j-1,grid, 0, 0, i-1, j-1));
                int except_topright = max(
                    find_connected_size_except(i-1,j-1,grid, 0, j, i-1, C-1),
                    find_connected_size_except(i,j,grid, 0, j, i-1, C-1));
                int except_bottomleft = max(
                    find_connected_size_except(i-1,j-1,grid, i, 0, R-1, j-1),
                    find_connected_size_except(i,j,grid, i, 0, R-1, j-1));
                int except_bottomright = max(
                    find_connected_size_except(i-1,j,grid, i, j, R-1, C-1),
                    find_connected_size_except(i,j-1,grid, i, j, R-1, C-1));
                int best_with_corner = max(
                    max(topleft + except_topleft, topright + except_topright),
                    max(bottomleft + except_bottomleft, bottomright + except_bottomright));
                
                int best_left = find_connected_size(i, j-1, grid, 0, 0, R-1,j-1);
                int best_right = find_connected_size(i, j, grid, 0, j, R-1, C-1);

                int best_top = find_connected_size(i-1, j, grid, 0, 0, i-1, C-1);
                int best_bottom = find_connected_size(i, j, grid, i, 0, R-1, C-1);

                int best_halves = max(best_left + best_right, best_top+best_bottom);
                int current = max(max(best_halves, best_with_corner), max(best_full, separate_quarters));
                best = max(best, current);
            }
        }
        cout << "Case #" << curr_case << ": ";
        cout << best;
        cout << ENDL;
    }
    return 0;
}
