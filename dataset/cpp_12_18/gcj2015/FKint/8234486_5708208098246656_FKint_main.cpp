#include <bits/stdc++.h>
 #include <cstdio>
 using namespace std;
 
 #define EMPTY 0
 #define LEFT 1
 #define RIGHT 2
 #define UP 3
 #define DOWN 4
 
 int count_bad_arrows(vector<vector<int> > &grid, set<pair<int, int> > &positions, int value){
 	int counter = 0;
 	for(set<pair<int, int> >::iterator it = positions.begin(); it != positions.end(); ++it){
 		if(grid[it->first][it->second] == value){
 			counter++;
 		}
 	}
 	return counter;
 }
 int main(){
 	std::ios::sync_with_stdio(false);
 	int nb_test_cases;
 	cin >> nb_test_cases;
 	for(int current_test_case = 1; current_test_case <= nb_test_cases; ++ current_test_case){
 		int R, C;
 		cin >> R >> C;
 		vector<vector<int> > grid;
 		string s;
 		getline(cin, s);
 		for(int i = 0; i < R; ++i){
 			getline(cin, s);
 			vector<int> line;
 			for(int j = 0; j < C; ++j){
 				char c = s[j];
 				if(c == '.'){
 					line.push_back(EMPTY);
 				}else if(c == '^'){
 					line.push_back(UP);
 				}else if(c == 'v'){
 					line.push_back(DOWN);
 				}else if(c == '>'){
 					line.push_back(RIGHT);
 				}else if(c == '<'){
 					line.push_back(LEFT);
 				}else{
 					cerr << "ERROR\n" << endl;
 				}
 			}
 			grid.push_back(line);
 		}
 		set<pair<int, int> > left_side_arrows;
 		set<pair<int, int> > right_side_arrows;
 		set<pair<int, int> > top_side_arrows;
 		set<pair<int, int> > bottom_side_arrows;
 		for(int i = 0; i < R; ++i){
 			for(int j = 0; j < C; ++j){
 				if(grid[i][j] == EMPTY)
 					continue;
 				left_side_arrows.insert(make_pair(i, j));
 				break;
 			}
 			for(int j = C-1; j >= 0; --j){
 				if(grid[i][j] == EMPTY)
 					continue;
 				right_side_arrows.insert(make_pair(i, j));
 				break;
 			}
 		}
 		for(int j = 0; j < C; ++j){
 			for(int i = 0; i < R; ++i){
 				if(grid[i][j] == EMPTY)
 					continue;
 				top_side_arrows.insert(make_pair(i, j));
 				break;
 			}
 			for(int i = R - 1; i >= 0; --i){
 				if(grid[i][j] == EMPTY)
 					continue;
 				bottom_side_arrows.insert(make_pair(i, j));
 				break;
 			}
 		}
 		cout << "Case #" << current_test_case << ": ";
 		bool done = false;
 		for(set<pair<int, int> >::iterator it = left_side_arrows.begin(); it != left_side_arrows.end(); ++it){
 			if(right_side_arrows.count(*it) > 0 && top_side_arrows.count(*it) > 0 && bottom_side_arrows.count(*it) > 0){
 				done = true;
 				cout << "IMPOSSIBLE";
 				break;
 			}
 		}
 		if(!done){
 			int total = count_bad_arrows(grid, left_side_arrows, LEFT);
 			total += count_bad_arrows(grid, right_side_arrows, RIGHT);
 			total += count_bad_arrows(grid, top_side_arrows, UP);
 			total += count_bad_arrows(grid, bottom_side_arrows, DOWN);
 			cout << total;
 		}
 		cout << endl;
 	}
     return 0;
 }
