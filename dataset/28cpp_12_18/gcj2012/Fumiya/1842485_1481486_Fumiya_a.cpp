#include <iostream>
 #include <cstring>
 #include <cstdio>
 
 using namespace std;
 
 int N, D;
 bool mem[10000][10000];
 int d[10000];
 int l[10000];
 bool ok;
 
 void search(int prev, int cur){
 	if(mem[prev][cur]) return ;
 	mem[prev][cur] = true;
 	if(d[cur] + min(d[cur]-d[prev], l[cur]) >= D) ok = true;
 	for(int i=cur+1;i<N;i++){
 		if(d[i]-d[cur] > min(d[cur]-d[prev], l[cur])) break;
 		search(cur, i);
 	}
 }
 
 int main(){
 	int TEST; cin >> TEST;
 	for(int test=1;test<=TEST;test++){
 		memset(mem, false, sizeof(mem));
 		cin >> N;
 		for(int i=0;i<N;i++) cin >> d[i] >> l[i];
 		cin >> D;
 		ok = false;
 		for(int i=1;i<N;i++){
 			if(d[i]-d[0] > d[0]) break;
 			search(0, i);
 		}
 		printf("Case #%d: %s\n", test, ok?"YES":"NO");
 	}
 }
