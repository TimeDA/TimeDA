#include<cstdio>
 #include<cstring>
 #include<algorithm>
 
 using namespace std;
 
 char ch[1010];
 char ans[1010];
 
 int N;
 
 bool isLast[1010];
 int lastPos[30];
 
 bool toFirst[1010];
 
 void solve(){/*
 	N = strlen(ch);
 	for(int i = 0; i < N; ++i) isLast[i] = false;
 	bool ap[30];
 	for(int i = 0; i < 30; ++i){
 		ap[i] = false;
 		lastPos[i] = -1;
 	}
 	for(int i = N - 1; i >= 0; --i){
 		int id = ch[i] - 'a';
 		if(ap[id]) continue;
 		else{
 			isLast[i] = true;
 			ap[id] = true;
 			lastPos[id] = i;
 		}
 	}
 	deque<char> deq;
 	deq.push(ch[0]);
 	int */
 	N = strlen(ch);
 	for(int i = 0; i < N; ++i) toFirst[i] = false;
 	for(char c = 'Z'; c >= ch[0]; --c){
 		for(int i = 0; i < N; ++i){
 			if(ch[i] == c){
 				toFirst[i] = true;
 			}else if(toFirst[i]){
 				break;
 			}
 		}
 	}
 	int id = 0;
 	for(int i = N - 1; i >= 0; --i){
 		if(toFirst[i]){
 			ans[id++] = ch[i];
 		}
 	}
 	for(int i = 0; i < N; ++i){
 		if(!toFirst[i]){
 			ans[id++] = ch[i];
 		}
 	}
 	ans[N] = '\0';
 }
 
 int main(){
 	int T;
 	scanf("%d", &T);
 	for(int datano = 1; datano <= T; ++datano){
 		scanf("%s", ch);
 		solve();
 		printf("Case #%d: %s\n", datano, ans);
 	}
 	return 0;
 }
