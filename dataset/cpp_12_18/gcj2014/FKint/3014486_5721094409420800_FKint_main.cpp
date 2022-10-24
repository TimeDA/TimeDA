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
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	//cin >> T;
 	for(int current_case = 1; current_case <= T; ++current_case){
 		//read input
         int N;
         scanf("%d", &N);
         map<int, int> positions;
         vector<int> values;
 		//process
         for(int i = 0; i < N; ++i){
             int t;
             scanf("%d", &t);
             positions[t] = i;
             values.push_back(t);
         }
         vector<int> original_values;
         for(int i = 0; i < N; ++i){
             original_values.push_back(values[i]);
         }
         sort(values.begin(), values.end());
 
         int best = N*N;
         while(true){
             bool descending = false;
             bool good = true;
             for(int i = 1; i < N; ++i){
                 if(values[i] > values[i-1] && descending){
                     good = false;
                 }
                 if(values[i]<values[i-1]){
                     descending = true;
                 }
             }
             if(good){
                 int nb_swaps = 0;
                 /*for(int i = 0; i < N; ++i){
                     nb_swaps += abs(positions[values[i]]-i);
                 }*/
                 vector<int> c;
                 for(int i= 0; i< N; ++i){
                     c.push_back(original_values[i]);
                 }
                 for(int i = 0; i < N; ++i){
                     for(int j = 0; j < N; ++j){
                         if(c[j] == values[i]){
                             while(j < i){
                                 c[j]=c[j+1];
                                 c[j+1] = values[i];
                                 ++nb_swaps;
                                 ++j;
                             }
                             while(j > i){
                                 c[j]=c[j-1];
                                 c[j-1]=values[i];
                                 ++nb_swaps;
                                 --j;
                             }
                             break;
                         }
                     }
                 }
                 best = min(nb_swaps, best);
             }
             if(!next_permutation(values.begin(), values.end()))
                 break;
         }
 
 
 
 
 		printf("Case #%d:", current_case);
 		//cout << "Case #" << current_case << ":";
 
         printf(" %d", best/2);
 
 
 		//output answer
 		printf("\n");
 		//cout << endl;
 	}
     return 0;
 }
