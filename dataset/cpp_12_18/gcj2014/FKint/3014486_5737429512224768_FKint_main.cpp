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
 #define MAXX 1000
 int files_amount[MAXX];
 int main(){
 	int T;
 	scanf("%d", &T);
 	//cin >> T;
 	for(int current_case = 1; current_case <= T; ++current_case){
 		//read input
         int N;
         int X;
         scanf("%d%d", &N, &X);
         for(int i = 0; i <= X; ++i){
             files_amount[i]=0;
         }
         for(int i = 0; i < N; ++i){
             int t;
             scanf("%d", &t);
             files_amount[t]++;
         }
 		//process
         int disk_amount = 0;
         for(int i = X; i >= 0; --i){
             while(files_amount[i] > 0){
                 disk_amount++;
                 files_amount[i]--;
                 for(int j = min(i, X-i); j >= 0; --j){
                     if(files_amount[j] > 0){
                         --files_amount[j];
                         break;
                     }
                 }
             }
         }
 
 
 
 
 
 		printf("Case #%d:", current_case);
 		//cout << "Case #" << current_case << ":";
         printf(" %d", disk_amount);
 
 
 
 		//output answer
 		printf("\n");
 		//cout << endl;
 	}
     return 0;
 }
