#include <iostream>
 #include <sstream>
 #include <fstream>
 #include <string>
 #include <vector>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <set>
 #include <map>
 #include <algorithm>
 #include <functional>
 #include <utility>
 #include <bitset>
 #include <cmath>
 #include <cstdlib>
 #include <ctime>
 #include <cstdio>
 
 using namespace std;
 
 #define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
 #define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
 bool red(char c){
 	return (c == 'R' || c == 'O' || c == 'V');
 }
 
 bool blue(char c){
 	return (c == 'B' || c == 'G' || c == 'V');
 }
 
 bool yellow(char c){
 	return (c == 'Y' || c == 'O' || c == 'G');
 }
 
 bool adj(char c1, char c2){
 	if(red(c1) && red(c2)) return true;
 	if(blue(c1) && blue(c2)) return true;
 	if(yellow(c1) && yellow(c2)) return true;
 	return false;
 }
 
 bool valid(string s){
 	int N=s.length(),i;
 	REP(i,N) if(adj(s[i], s[(i+1)%N])) return false;
 	return true;
 }
 
 string brute(int N, int R, int O, int Y, int G, int B, int V){
 	int i;
 	
 	string s;
 	REP(i,R) s += 'R';
 	REP(i,O) s += 'O';
 	REP(i,Y) s += 'Y';
 	REP(i,G) s += 'G';
 	REP(i,B) s += 'B';
 	REP(i,V) s += 'V';
 	
 	sort(s.begin(),s.end());
 	
 	do {
 		if(valid(s)) return s;
 	} while(next_permutation(s.begin(),s.end()));
 	
 	return "";
 }
 
 string func3(int X, int Y, int Z){
 	int N=X+Y+Z,i,j;
 	string s;
 	
 	if(max(X, max(Y, Z)) * 2 > X + Y + Z) return "";
 	
 	vector <pair <int, char> > v;
 	v.push_back(make_pair(X, 'X'));
 	v.push_back(make_pair(Y, 'Y'));
 	v.push_back(make_pair(Z, 'Z'));
 	sort(v.begin(),v.end());
 	
 	int P = v[0].first;
 	char p = v[0].second;
 	int Q = v[1].first;
 	char q = v[1].second;
 	int R = v[2].first;
 	char r = v[2].second;
 	
 	REP(i,N) s += '-';
 	REP(i,R) s[2*i] = r;
 	REP(i,Q){
 		int j = N - 1 - 2 * i;
 		if(s[j] != '-') j--;
 		s[j] = q;
 	}
 	REP(i,N) if(s[i] == '-') s[i] = p;
 	
 	return s;
 }
 
 vector <string> func2(int X, int Y, char x, char y){
 	int i;
 	vector <string> ans;
 	
 	if(X == 0 && Y == 0) return ans;
 	
 	string s;
 	REP(i,Y) s = s + x + y;
 	s = s + x;
 	X -= (Y + 1);
 	
 	ans.push_back(s);
 	REP(i,X) ans.push_back((string)("") + x);
 	
 	return ans;
 }
 
 string func(int N, int R, int O, int Y, int G, int B, int V){
 	int i;
 	
 	if(R < G || Y < V || B < O) return "";
 	
 	if(R == G && R > 0){
 		if(R+G != N) return "";
 		string tmp;
 		REP(i,N/2) tmp += "RG";
 		return tmp;
 	}
 	
 	if(Y == V && Y > 0){
 		if(Y+V != N) return "";
 		string tmp;
 		REP(i,N/2) tmp += "YV";
 		return tmp;
 	}
 	
 	if(B == O && B > 0){
 		if(B+O != N) return "";
 		string tmp;
 		REP(i,N/2) tmp += "BO";
 		return tmp;
 	}
 	
 	vector <string> x = func2(R, G, 'R', 'G');
 	vector <string> y = func2(Y, V, 'Y', 'V');
 	vector <string> z = func2(B, O, 'B', 'O');
 	
 	string s = func3(x.size(), y.size(), z.size());
 	if(s.empty()) return "";
 	
 	int xx = 0, yy = 0, zz = 0;
 	string ans;
 	
 	REP(i,s.length()){
 		if(s[i] == 'X'){
 			ans += x[xx];
 			xx++;
 		} else if(s[i] == 'Y'){
 			ans += y[yy];
 			yy++;
 		} else {
 			ans += z[zz];
 			zz++;
 		}
 	}
 	
 	return ans;
 }
 
 void stress_testing(int N){
 	cout << N << endl;
 	
 	for(int R=0;R<=N;R++){
 		for(int O=0;R+O<=N;O++){
 			for(int Y=0;R+O+Y<=N;Y++){
 				for(int G=0;R+O+Y+G<=N;G++){
 					for(int B=0;R+O+Y+G+B<=N;B++){
 						int V = N - (R+O+Y+G+B);
 						string s1 = brute(N, R, O, Y, G, B, V);
 						string s2 = func(N, R, O, Y, G, B, V);
 						if((s1.empty()) != (s2.empty())) cout << N << ' ' << R << ' ' << O << ' ' << Y << ' ' << G << ' ' << B << ' ' << V << ' ' << s1 << ' ' << s2 << endl;
 						if(!valid(s2)) cout << N << ' ' << R << ' ' << O << ' ' << Y << ' ' << G << ' ' << B << ' ' << V << ' ' << s1 << ' ' << s2 << endl;
 					}
 				}
 			}
 		}
 	}
 }
 
 void main2(void){
 	int N,R,O,Y,G,B,V;
 	cin >> N >> R >> O >> Y >> G >> B >> V;
 	string ans = func(N, R, O, Y, G, B, V);
 	if(ans.empty()) ans = "IMPOSSIBLE";
 	cout << ans << endl;
 }
 
 ////////////////////////////////////////////////////////////////////////////////////////////////////
 
 int main(void){
 //	for(int N=3;;N++) stress_testing(N);
 	int TC,tc;
 	cin >> TC;
 	REP(tc,TC){
 		printf("Case #%d: ", tc + 1);
 		main2();
 	}
 	return 0;
 }
