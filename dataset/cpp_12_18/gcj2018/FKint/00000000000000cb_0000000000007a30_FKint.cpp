#include <bits/stdc++.h>
using namespace std;
pair<int, int> get_best_pair(vector<pair<int, int>>& coordinates, vector<vector<bool>>& grid){
    int most_nb_free = 0;
    pair<int, int> best(0,0);
    for(auto x : coordinates){
        int nb_free = 0;
        for(int i = x.first - 1; i <= x.first + 1; ++i){
            for(int j = x.second - 1; j <= x.second + 1; ++j){
                if(!grid[i][j]) nb_free++;
            }
        }
        if(nb_free > most_nb_free){
            most_nb_free =  nb_free;
            best = x;
        }
    }
    return best;
}
int main(){
    int T; cin >> T;
    for(int case_nb = 1; case_nb <= T; ++case_nb){
        int A; cin >> A;
        vector<pair<int, int>> coordinates;
        vector<vector<bool>> grid(1000, vector<bool>(1000, false));
        bool ready = false;
        if(A == 20){
            coordinates.push_back(make_pair(1,1));
            coordinates.push_back(make_pair(1,2));
            coordinates.push_back(make_pair(3,1));
            coordinates.push_back(make_pair(3,2));
        }else{
            cerr << "Did not implement large input yet" << endl;
            for(int i = 1; i < 19; ++i){
                for(int j = 1; j < 9; ++j){
                    coordinates.push_back(make_pair(i, j));
                }
            }
        }
        while(!ready){
            pair<int, int> best_pair = get_best_pair(coordinates, grid);
            cout << best_pair.first + 1 << " " << best_pair.second + 1 << endl;
            int i, j; cin >> i >> j;
            if(i == 0 && j == 0){
                ready = true;
            }else if(i == -1 && j == -1){
                cerr << "Failed..." << endl;
                return 0;
            }else{
                grid[i-1][j-1] = true;
            }
        }
    }
    return 0;
}