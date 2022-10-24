#include <cstdio>
 #include <iostream>
 #include <vector>
 #include <set>
 #include <algorithm>
 #include <map>
 #include <queue>
 #include <stack>
 #include <string>
 #include <sstream>
 
 using namespace std;
 struct square{
 	square(int x,int y, int rad){
 		posx=x;
 posy=y;
 this->rad = rad;
 	}
 	int posx,posy;
 	int rad;
 	bool intersects(square &s){
 		return abs(posx-s.posx)<s.rad+rad && abs(posy-s.posy)<s.rad+rad;
 	}
 };
 vector<int> radii;
 vector<square> occupied;
 
 int n,w,l;
 bool found;
 void push(square s, int index, int comparer){
 	if(found)
 		return;
 	if(index < 0){
 		for(int i = n-1; i >= 0; --i){
 			printf("%f %f ", (float)occupied[i].posx, (float)occupied[i].posy);
 		}
 		found=true;
 		return;
 	}
 	if(s.posy>l||s.posx>w)
 		return;
 	if(comparer>=occupied.size()){
 		occupied.push_back(s);
 		push(square(0,0,radii[index-1]),index-1,0);
 		occupied.pop_back();
 		return;
 	}
 	if(occupied[comparer].intersects(s)){
 		push(square(occupied[comparer].rad+occupied[comparer].posx+s.rad,s.posy,s.rad),index,comparer+1);;
 		push(square(s.posx,occupied[comparer].posy+occupied[comparer].rad+s.rad,s.rad),index,comparer+1);
 	}
 
 }
 
 int main(){
 
     int t;
     scanf("%d", &t);
     for(int curr_case = 0; curr_case < t; ++curr_case){
 		scanf("%d%d%d", &n, &w, &l);
 		occupied.clear();
 		radii.clear();
 		found = false;
 		for(int i = 0; i < n; ++i){
 			int r;
 			scanf("%d", &r);
 			radii.push_back(r);
 		}
         printf("Case #%d: ", curr_case+1);
 		push(square(0,0,radii[n-1]),n-1,0);
 		printf("\n");
 		//for(int i = n-1; i >= 0; --i){
 			
 		//}
     }
     return 0;
 }
