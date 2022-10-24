#include <bits/stdc++.h>
 using namespace std;
 
 #define LEFT 0
 #define RIGHT 1
 #define TOP 2
 #define BOTTOM 3
 
 const int directions[][2] = {
 	{0, -1},
 	{0, 1},
 	{-1, 0},
 	{1, 0}
 };
 
 const int backslash_dir[] = {
 	TOP,
 	BOTTOM,
 	LEFT,
 	RIGHT
 };
 
 const int slash_dir[] = {
 	BOTTOM,
 	TOP,
 	RIGHT,
 	LEFT
 };
 
 
 struct beamer_config{
 	bool exists;
 	int r, c, d;
 	beamer_config(){
 		this->exists = false;
 	}
 	beamer_config(int r, int c, int d){
 		this->exists = true;
 		this->r = r;
 		this->c = c;
 		this->d = d;
 	}
 	bool found(){
 		return this->exists;
 	}
 };
 
 vector<vector<char>> grid;
 int R, C;
 bool in_grid(int r, int c){
 	return r >= 0 && r < R && c >= 0 && c <= C;
 }
 
 bool is_vertical(int d){
 	return d == TOP || d == BOTTOM;
 }
 
 beamer_config reached_beamer(int curr_row, int curr_col, int direction, int orig_row, int orig_col){
 	// TODO: DP
 	//cerr << curr_row << " " << curr_col << endl;
 	if(!in_grid(curr_row, curr_col))
 		return beamer_config();
 	char cell = grid[curr_row][curr_col];
 	if(cell == '#')
 		return beamer_config();
 	if(cell == '|' || cell == '-')
 		return beamer_config(curr_row, curr_col, direction);
 	int new_direction = direction;
 	if(cell == '\\'){
 		new_direction = backslash_dir[direction];
 	}else if(cell == '/'){
 		new_direction = slash_dir[direction];
 	}
 	int new_row = directions[new_direction][0] + curr_row;
 	int new_col = directions[new_direction][1] + curr_col;
 	if(new_row == orig_row && new_col == orig_col)
 		return beamer_config();
 	return reached_beamer(new_row, new_col, new_direction, orig_row, orig_col);
 }
 
 bool apply_consequences(int id, bool val, map<pair<int, bool>, vector<pair<int, bool> > >& consequences, map<int, bool>& assignment){
 	if(assignment.count(id)){
 		return assignment[id] == val;
 	}
 	assignment[id] = val;
 	pair<int, bool> p = make_pair(id, val);
 	for(const auto& c : consequences[p]){
 		if(!apply_consequences(c.first, c.second, consequences, assignment)){
 			return false;
 		}
 	}
 	return true;
 }
 
 
 int main(){
 	std::ios::sync_with_stdio(false);
 	int nb_test_cases; cin >> nb_test_cases;
 	for(int test_case_id = 1; test_case_id <= nb_test_cases; ++test_case_id){
 		cin >> R >> C;
 		vector<pair<int, int>> beamer_locations;
 		map<pair<int, int>, int > beamer_ids;
 		grid.clear();
 		for(int i = 0; i < R; ++i){
 			grid.push_back(vector<char>(C));
 			for(int j = 0; j < C; ++j){
 				cin >> grid[i][j];
 				if(grid[i][j] == '|' || grid[i][j] == '-'){
 					beamer_ids[make_pair(i, j)] = beamer_locations.size();
 					beamer_locations.push_back(make_pair(i, j));
 				}
 			}
 		}
 		map<pair<int, bool>, bool> valid_configs;
 		vector<vector<beamer_config> > clauses;
 		bool possible = true;
 		for(int i = 0; i < R && possible; ++i){
 			for(int j = 0; j < C && possible; ++j){
 				if(grid[i][j] == '.'){
 					beamer_config beamer_left = reached_beamer(i, j, LEFT, i, j);
 					beamer_config beamer_right = reached_beamer(i, j, RIGHT, i, j);
 					beamer_config beamer_top = reached_beamer(i, j, TOP, i, j);
 					beamer_config beamer_bottom = reached_beamer(i, j, BOTTOM, i, j);
 					vector<beamer_config> clause;
 					if(beamer_left.found() && !beamer_right.found()){
 						clause.push_back(beamer_left);
 						//cerr << "left" << endl;
 					}
 					if(beamer_right.found() && !beamer_left.found()){
 						clause.push_back(beamer_right);
 						//cerr << "right" << endl;
 						//cerr << beamer_right.r << " " << beamer_right.c << " " << beamer_right.d << endl;
 					}
 					if(beamer_top.found() && !beamer_bottom.found()){
 						clause.push_back(beamer_top);
 						//cerr << "top!" << endl;
 					}
 					if(beamer_bottom.found() && !beamer_top.found()){
 						clause.push_back(beamer_bottom);
 						//cerr << "bottom!" << endl;
 					}
 					clauses.push_back(clause);
 					//cerr << clause.size() << endl;
 				}else if(grid[i][j] == '-' || grid[i][j] == '|'){
 					int id = beamer_ids[make_pair(i, j)];
 					bool one_good = false;
 					if(reached_beamer(i + directions[TOP][0], j + directions[TOP][1], TOP, -10, -10).found() || reached_beamer(i + directions[BOTTOM][0], j + directions[BOTTOM][1], BOTTOM, -10, -10).found()){
 						valid_configs[make_pair(id, true)] = false;
 					}else{
 						valid_configs[make_pair(id, true)] = true;
 						one_good = true;
 						//cerr << "can shoot vertical!" << endl;
 					}
 
 					if(reached_beamer(i + directions[LEFT][0], j + directions[LEFT][1], LEFT, -10, -10).found() || reached_beamer(i + directions[RIGHT][0], j + directions[RIGHT][1], RIGHT, -10, -10).found()){
 						valid_configs[make_pair(id, false)] = false;
 					}else{
 						valid_configs[make_pair(id, false)] = true;
 						one_good = true;
 						//cerr << "can shoot horizontal!" << endl;
 					}
 					if(!one_good){
 						possible = false;
 					}
 				}
 			}
 		}
 
 		
 		vector<vector<pair<int, bool> > > transformed_clauses;
 		map<pair<int, bool>, vector<pair<int, bool> > > consequences;
 		vector<pair<int, bool> > fixed_assignments;
 		for(const auto & v : clauses){
 			vector<pair<int, bool> > new_v;
 			for(const auto & c : v){
 				const auto p = make_pair(beamer_ids[make_pair(c.r, c.c)], is_vertical(c.d));
 				if(valid_configs[p]){
 					new_v.push_back(p);
 				}
 			}
 			if(new_v.size() == 0){
 				possible = false;
 				break;
 			}
 			transformed_clauses.push_back(new_v);
 			if(new_v.size() == 1){
 				fixed_assignments.push_back(new_v[0]);
 			}else{
 				pair<int, bool> a = new_v[0];
 				pair<int, bool> b = new_v[1];
 				consequences[make_pair(a.first, !a.second)].push_back(b);
 				consequences[make_pair(b.first, !b.second)].push_back(a);
 			}
 		}
 
 
 		map<int, bool> assignment;
 		for(const auto& p : fixed_assignments){
 			if(assignment.count(p.first) && assignment[p.first] != p.second){
 				possible = false;
 				break;
 			}
 			if(!apply_consequences(p.first, p.second, consequences, assignment)){
 				possible = false;
 			}
 		}
 		for(int i = 0; possible && i < beamer_locations.size(); ++i){
 			if(assignment.count(i))
 				continue;
 			map<int, bool> test_assignment = assignment;
 			if(apply_consequences(i, true, consequences, test_assignment)){
 				assignment = test_assignment;
 				continue;
 			}
 			test_assignment = assignment;
 			if(apply_consequences(i, false, consequences, test_assignment)){
 				assignment = test_assignment;
 				continue;
 			}
 			possible = false;
 		}
 
 		cout << "Case #" << test_case_id << ": " ;
 		if(possible){
 			cout << "POSSIBLE" << endl;
 			for(int i = 0; i < R; ++i){
 				for(int j = 0; j < C; ++j){
 
 					if(beamer_ids.count(make_pair(i, j))){
 						if(assignment[beamer_ids[make_pair(i, j)]])
 							cout << "|";
 						else
 							cout << "-";
 					}else{
 						cout << grid[i][j];
 					}
 				}
 				cout << endl;
 			}
 		}else
 			cout << "IMPOSSIBLE" << endl;
 	}
     return 0;
 }
