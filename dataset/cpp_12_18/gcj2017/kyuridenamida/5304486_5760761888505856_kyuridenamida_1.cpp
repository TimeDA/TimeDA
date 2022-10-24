// this source + manual
 #include <iostream>
 #include <cstdio>
 #include <algorithm>
 #include <vector>
 #include <queue>
 #include <cstdlib>
 #include <cmath>
 #include <cassert>
 #include <map>
 #include <set>
 #include <cstring>
 using namespace std;
 
 void cs()
 {
     static int t = 1;
     cout << "Case #" << t++ << ":" << endl;
 }
 
 char c[110][110];
 char f[110][110];
 int R, C;
 
 void first_attempt(char c_){
 	int max_x = -1e9;
 	int min_x = 1e9;
 	int max_y = -1e9;
 	int min_y = 1e9;
 	for(int i = 0 ; i < R ; i++)
 		for(int j = 0 ; j < C ; j++)
 			if( c[i][j] == c_ ){
 				max_x = max(max_x,j);
 				min_x = min(min_x,j);
 				max_y = max(max_y,i);
 				min_y = min(min_y,i);
 			}
 		
 	for(int i = min_y ; i <= max_y ; i++){
 		for(int j = min_x ; j <= max_x ; j++){
 			c[i][j] = c_;
 		}
 	}
 
 }
 
 void try_fill(char c_)
 {
 	while(true){
 		int cnt = 0;
 		for(int i = 0 ; i < R ; i++)
 			for(int j = 0 ; j < C ; j++)
 				if( c[i][j] == c_ ){
 					cnt++;
 				}
 		if( cnt == 0 ){
 			break;
 		}
 		for(int i = 0 ; i < R ; i++){
 			for(int j = 0 ; j < C ; j++){
 				for(int I = i ; I < R ; I++){
 					for(int J = j ; J < C ; J++){
 						set<char> S;
 						vector<char> cccc(128);
 						set<char> ppp;
 						for(int y = i ; y <= I ; y++){
 							for(int x = j ; x <= J ; x++){
 								cccc[c[y][x]]++;
 								ppp.insert(c[y][x]);
 							}
 						}
 						if( ppp.count('?') == 0 ) continue;
 						ppp.erase('?');
 						if( cccc[c_] == cnt && ppp.size() == 1 ){
 							for(int y = i ; y <= I ; y++){
 								for(int x = j ; x <= J ; x++){
 									c[y][x] = c_;
 									
 								}
 							}
 							goto exit;			
 						}
 						
 					}
 				}
 			}
 
 		}
 		break;
 		exit:;
 	}
 }
 int main()
 {
     int t;
     cin >> t;
     while (t--)
     {
 		
 		cin >> R >> C;
 		for (int i = 0; i < R; i++)
 			for (int j = 0; j < C; j++)
 			cin >> c[i][j], f[i][j] = c[i][j];
 		for (int i = 0; i < 26; i++)
 		{
 			first_attempt(i + 'A');
 		}
 		for (int i = 0; i < 26; i++)
 		{
 			try_fill(i + 'A');
 		}
 		cs();
 		for(int i = 0 ; i < R ; i++){
 			for(int j = 0 ; j < C ; j++){
 					assert(f[i][j] == '?' || f[i][j] == c[i][j]);
 					cout << c[i][j];
 			}
 			cout << endl;
 		}
     }
 }
