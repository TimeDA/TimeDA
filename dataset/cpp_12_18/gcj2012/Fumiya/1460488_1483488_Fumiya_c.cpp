#include <iostream>
 #include <vector>
 #include <cstdio>
 
 using namespace std;
 
 int main(){
 	int T; cin >> T;
 	for(int test=1;test<=T;test++){
 		int A, B; cin >> A >> B;
 		int res = 0;
 		int len = 0;
 		for(int t=A;t;t/=10) len++;
 		vector<int> vi(len);
 		for(int i=A;i<=B;i++){
 			vector<int> mem;
 			for(int t=i,j=len-1;j>=0;j--,t/=10) vi[j] = t%10;
 			for(int j=1;j<len;j++){
 				int s = 0;
 				for(int k=0;k<len;k++)
 					s = 10*s + vi[(j+k)%len];
 				bool ok = true;
 				for(int k=0;k<mem.size();k++){
 					if(mem[k] == s) ok = false;
 				}
 				if(!ok) continue;
 				if(i < s && s <= B) res++;
 				mem.push_back(s);
 			}
 		}
 		printf("Case #%d: %d\n", test, res);
 	}
 }