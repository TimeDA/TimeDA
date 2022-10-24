/**
 	Author: Floris Kint
   **/
 
 
 #include <cstdio>
 #include <bitset>
 #include <iostream>
 #include <vector>
 #include <list>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <string>
 #include <sstream>
 #include <cmath>
 #include <stack>
 #include <queue>
 #include <functional>
 
 #define PI atan2(0,-1)
 
 using namespace std;
 struct cell{
     cell(){
         this->from = make_pair(0,0);
         this->to = make_pair(0,0);
         this->used = false;
         this->building = false;
     }
     pair<int, int> from;
     pair<int, int> to;
     bool used;
     bool building;
     bool visited;
 };
 #define MAXH 500
 #define MAXW 100
 cell field[MAXH][MAXW];
 
 vector<pair<pair<int, int>, pair<int, int> > > building_coordinates;
 
 void set_building(int x1, int y1, int x2, int y2, bool value){
     for(int i = y1; i <= y2; ++i){
         for(int j = x1; j <= x2; ++j){
             field[i][j].building = value;
         }
     }
 }
 
 
 int W, H, B;
 const int neighbours[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
 bool dfs(int row, int col, int prev_row, int prev_col){
     if(row < 0 || row >= H || col < 0 || col >= W)
         return false;
     if(field[row][col].building)
         return false;
     if(field[row][col].visited)
         return false;
     field[row][col].visited = true;
     if(field[row][col].used){
         int dr = field[row][col].from.first;
         int dc = field[row][col].from.second;
         field[dr][dc].used = false;
         if(dfs(dr, dc, row, col)){
             field[row][col].from = make_pair(prev_row, prev_col);
             return true;
         }
         field[dr][dc].used = true;
         return false;
     }else{
         if(row == H-1){
             field[row][col].from = make_pair(prev_row, prev_col);
             field[row][col].used = true;
             return true;
         }else{
             for(int i = 0; i < 4; ++i){
                 int dr = row+neighbours[i][0];
                 int dc = col + neighbours[i][1];
                 if(dfs(dr, dc, row, col)){
                     field[row][col].to = make_pair(dr, dc);
                     field[row][col].used = true;
                     field[row][col].from = make_pair(prev_row, prev_col);
                     return true;
                 }
             }
         }
     }
     return false;
 }
 int find_flow_path(int col){
     if(field[0][col].building)
         return 0;
     for(int i = 0; i < H; ++i){
         for(int j = 0; j < W; ++j){
             field[i][j].visited = false;
         }
     }
     field[0][col].visited = true;
     if(dfs(1, col, 0, col)){
         return 1;
     }
 }
 
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	//cin >> T;
 	for(int current_case = 1; current_case <= T; ++current_case){
 		//read input
         scanf("%d%d%d", &W, &H, &B);
         for(int i = 0; i < B; ++i){
             int x1, x2, y1, y2;
             scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
             set_building(x1, y1, x2, y2, true);
             building_coordinates.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
         }
 		//process
         int flow = 0;
         for(int i = 0; i < W; ++i){
             flow += find_flow_path(i);
         }
 
 
 
 
 		printf("Case #%d:", current_case);
 		//cout << "Case #" << current_case << ":";
 
 
         printf(" %d", flow);
 
 		//output answer
 		printf("\n");
 		//cout << endl;
         for(vector<pair<pair<int, int>, pair<int, int> > >::iterator it = building_coordinates.begin(); it != building_coordinates.end();++it){
             set_building(it->first.first, it->first.second, it->second.first, it->second.second, false);
         }
 	}
     return 0;
 }
