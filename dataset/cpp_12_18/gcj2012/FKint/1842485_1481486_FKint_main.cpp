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
 int vine_pos[10000];
 int vine_length[10000];
 int n;
 int total_dist;
 
 int best_dist[10000];
 
 int main(){
 
     int t;
     scanf("%d", &t);
     for(int curr_case = 0; curr_case < t; ++curr_case){
 		scanf("%d", &n);
 		for(int i = 0; i < n; ++i){
 			scanf("%d%d", &vine_pos[i], &vine_length[i]);
 			best_dist[i] = 0;
 		}
 		scanf("%d", &total_dist);
 		best_dist[0]=vine_pos[0];
 		bool reached = (best_dist[0]+vine_pos[0]>=total_dist);
 		for(int i = 0; i < n; ++i){
 			int index = i+1;
 			while(vine_pos[index]<=vine_pos[i]+best_dist[i] && index < n){
 				best_dist[index]=max(best_dist[index],min(vine_length[index],vine_pos[index]-vine_pos[i]));
 				if(best_dist[index]+vine_pos[index]>=total_dist){
 					reached = true;
 					break;
 				}
 				++index;
 			}
 			if(reached)
 				break;
 		}
 	//	if(!reached){
 	//		reached = (best_dist[n-1]+vine_pos[n-1]>=total_dist);
 	//	}
         printf("Case #%d: %s\n", curr_case+1,reached?"YES":"NO");
     }
     return 0;
 }
