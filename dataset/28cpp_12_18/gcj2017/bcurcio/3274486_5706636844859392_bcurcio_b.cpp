#include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <algorithm>
 #include <cmath>
 #include <vector>
 using namespace std;
 int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
 
 typedef __int128 ll;
 typedef pair<int,int> pii;
 
 
 
 void solve(){
 	
 	int ac = in();
 	int aj = in();
 	
 	vector<int> timetable(24*60+1);
 	
 	int totalj = 0;
 	int totalc = 0;
 	
 	for(int i=0;i<ac;i++){
 		int x = in();
 		int y = in();
 		totalc += y-x;
 		for(int j=x;j<y;j++) timetable[j] = 1;
 	}
 	
 	
 	for(int i=0;i<aj;i++){
 		int x = in();
 		int y = in();
 		totalj += y-x;
 		for(int j=x;j<y;j++) timetable[j] = 2;
 	}
 	
 	if(ac+aj < 1){
 		cout << 2 << endl;
 		return;
 	}
 	
 	while(1){
 		int mincur = 1440*5;
 		pii poscur(-1,-1);
 		int val = -1;
 		
 		int cur = 0;
 		while(timetable[cur] == 0 && cur < 1440) cur++;
 		
 		while(cur < 1440){
 			int pos = cur;
 			while(timetable[cur%1440] == timetable[pos]) cur++;
 			int d = cur;
 			while(timetable[cur%1440] == 0) cur++;
 			
 			if(timetable[cur%1440] == timetable[pos]){
 				
 				if(timetable[pos]==1 && cur-d < mincur && totalc + cur - d <= 720 ){
 					mincur = cur - d;
 					poscur = pii(d,cur);
 					val = 1;
 				}
 				
 				
 				if(timetable[pos]==2 && cur-d < mincur && totalj + cur - d <= 720 ){
 					mincur = cur - d;
 					poscur = pii(d,cur);
 					val = 2;
 				}
 				
 			}
 		}
 		
 		if(mincur <1500){
 			for(int i=poscur.first;i<poscur.second;i++) timetable[i%1440] = val;
 			if(val==1) totalc+=poscur.second-poscur.first;
 			if(val==2) totalj+=poscur.second-poscur.first;
 		}else{
 			break;
 		}
 	}
 	
 	int ans = 500;
 	
 	int pretotalc = totalc;
 	
 	for(int i=0;i<1440;i++){
 		
 		totalc = pretotalc;
 		for(int j=0;j<1440;j++){
 			if(timetable[(i+j)%1440]==0 && totalc < 720){
 				totalc++;
 				timetable[(i+j)%1440] = 3; 
 			}
 		}
 		//~ cerr << endl;
 		
 		int act = 0;
 		for(int j=0;j<1440;j++) if(timetable[j]%2 != timetable[(j+1)%1440]%2) act++;
 		
 		if(act < ans) ans = act; 
 		
 		//~ cerr << act << endl;
 		
 		
 		for(int j=0;j<1440;j++){
 			if(timetable[j]==3) timetable[j] = 0;
 		}
 		
 		
 	}
 	
 	
 	cout << ans << endl;
 	
 }
 
 int main(){
   for(int i=0,T=in();i<T;i++){
 	  cout <<"Case #"<<i+1 << ": ";
       solve();
   }
 }
