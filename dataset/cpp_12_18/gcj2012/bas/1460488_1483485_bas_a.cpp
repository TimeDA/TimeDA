#include<iostream>
 #include<vector>
 #include<string>
 
 using namespace std;
 
 
 int main(){
 	int C;
 	string s;
 	cin>>C;  getline(cin, s);
 	string d1="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv qz";
 	string d2="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up zq";
 	vector<char> tab = vector<char>(26);
 	for(int i=0; i<d1.length(); i++){
 		if(d1[i]==' ')continue;
 		int ind = d1[i]-'a';
 		tab[ind] = d2[i];
 	}
 	for(int i=0; i<C; i++){
 		//cin>>wrds[i]; 
 		getline(cin, s);
 		int len = s.length();
 		string res="";
 		for(int j=0; j<len; j++)
 			if(s[j]==' ')res=res+' ';
 			else	res=res+tab[s[j]-'a'];
 		cout<<"Case #"<<i+1<<": " <<res<<"\n";
 	}
 	
 }
