#include <vector>
 #include <map>
 #include <set>
 #include <iostream>
 #include <iomanip>
 #include <queue>
 #include <string>
 #include <stack>
 #include <list>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <random>
 #include <cmath>
 #include <cstdio>
 #include <numeric>
 #include <iterator>
 #include <cassert>
 using namespace std;
 
 bool is_empty_grid(const vector<vector<char>> &grid, int first_row, int first_col, int bottom_row, int right_col){
 	for(int i = first_row; i < bottom_row; ++i){
 		for(int j = first_col; j < right_col; ++j){
 			if(grid[i][j] != '?'){
 				return false;
 			}
 		}
 	}
 	return true;
 }
 
 void fill_grid(vector<vector<char>> &grid, int first_row, int first_col, int bottom_row, int right_col){
 	if(first_row >= bottom_row)
 		return;
 	if(first_col >= right_col)
 		return;
 	bool found = false;
 	char c = 0;
 	for(int i = first_row; i < bottom_row && !found; ++i){
 		for(int j = first_col; j < right_col && !found; ++j){
 			if(grid[i][j] != '?'){
 				found = false;
 				c = grid[i][j];
 				int right_border = j;
 				for(int jj = j+1; jj < right_col; ++jj){
 					if(grid[i][jj] != '?'){
 						break;
 					}
 					right_border = jj;
 				}
 				int bottom_border = i;
 				for(int ii = i + 1; ii < bottom_row; ++ii){
 					if(is_empty_grid(grid, ii, first_col, ii + 1, right_border+1)){
 						bottom_border = ii;
 					}else{
 						break;
 					}
 				}
 				for(int ii = first_row; ii <= bottom_border; ++ii){
 					for(int jj = first_col; jj <= right_border; ++jj){
 						grid[ii][jj] = c;
 					}
 				}
 				fill_grid(grid, first_row, right_border + 1, bottom_row, right_col);
 				fill_grid(grid, bottom_border + 1, first_col, bottom_row, right_col);
 				return;
 			}
 		}
 	}
 	cerr << "Reached and of for loop, error!" << endl;
 }
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int nb_test_cases; cin >> nb_test_cases;
 	for(int test_case_id = 1; test_case_id <= nb_test_cases; ++test_case_id){
 		cout << "Case #" << test_case_id << ":" << endl;
 
 		int R, C; cin >> R >> C;
 		vector<vector<char>> grid(R, vector<char>(C));
 		for(int i = 0; i < R; ++i){
 			for(int j = 0; j < C; ++j){
 				cin >> grid[i][j];
 			}
 		}
 
 		fill_grid(grid, 0, 0, R, C);
 		for(int i = 0; i < R; ++i){
 			for(int j = 0; j < C; ++j){
 				cout << grid[i][j];
 			}
 			cout << endl;
 		}
 	}
     return 0;
 }
