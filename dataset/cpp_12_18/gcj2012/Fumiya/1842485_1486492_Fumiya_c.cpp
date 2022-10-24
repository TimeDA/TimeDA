#include <iostream>
 #include <cstdio>
 #include <cstring>
 
 using namespace std;
 
 int n;
 int x[2000];
 int h[2000];
 bool ok;
 
 void solve(int begin, int end){
 	if(begin >= end) return ;
 	if(!ok) return ;
 	int curend = end;
 	for(int i=end-1;i>=begin;i--){
 		if(x[i] == end){
 			int newH = double(h[x[curend]] - h[curend])/(x[curend]-curend) * (i+1-curend) + h[curend];
 			if(newH < 0) ok = false;
 			for(int j=i+1;j<curend;j++) h[j] = newH;
 			solve(i+1, curend);
 			curend = i;
 		}
 		if(x[i] > end) ok = false;
 	}
 	if(x[begin] != end){
 		int newH = double(h[x[curend]] - h[curend])/(x[curend]-curend) * (begin-curend) + h[curend];
 		if(newH < 0) ok = false;
 		for(int j=begin;j<curend;j++) h[j] = newH;
 		solve(begin, curend);
 	}
 }
 
 int main(){
 	int TEST; cin >> TEST;
 	for(int test=1;test<=TEST;test++){
 		cin >> n;
 		for(int i=0;i<n;i++) h[i] = 999999999;
 		h[n-1] = 1000000000;
 		for(int i=0;i<n-1;i++){ cin >> x[i]; x[i]--; }
 		printf("Case #%d:", test);
 		ok = true;
 		solve(0, n-1);
 		if(ok){
 			for(int i=0;i<n;i++){ cout << " " << h[i]; }
 			cout << endl;
 		}
 		else
 			cout << " Impossible" << endl;
 	}
 }
