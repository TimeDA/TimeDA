#include <iostream>
 #include <string>
 #include <cstring>
 #include <algorithm>
 #include <cstdio>
 #include <set>
 #include <map>
 #include <vector>
 
 using namespace std;
 
 string k = "yhesocvxduiglbkrztnwjpfmaq";
 char s[500];
 
 int main() {
 	freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
 	int t;
 	scanf("%d\n", &t);
 	for (int tests = 1; tests <= t; ++tests) {
 		gets(s);
 		int len = strlen(s);
 		printf("Case #%d: ", tests);
 		for (int i = 0; i < len; ++i) {
 			if (s[i] == ' ') {
 				printf(" ");
 			} else {
 				printf("%c", k[s[i] - 'a']);
 			}
 		}
 		printf("\n");
 	}
 
 	return 0;
 }