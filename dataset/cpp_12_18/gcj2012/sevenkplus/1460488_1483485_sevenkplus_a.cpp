#include<cstdio>
 #include<map>
 #include<string>
 #include<iostream>
 #include<algorithm>
 using namespace std;
 map<char,char> F;
 void ff(string a,string b){for(int i=0;i<(int)a.length();i++)F[a[i]]=b[i];}
 string gg(string s){string t=s;for(int i=0;i<(int)s.length();i++)t[i]=F[s[i]];return t;}
 int main()
 {
 	ff(string("ejp mysljylc kd kxveddknmc re jsicpdrysi"),string("our language is impossible to understand"));
 	ff(string("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"),string("there are twenty six factorial possibilities"));
 	ff(string("de kr kd eoya kw aej tysr re ujdr lkgc jv"),string("so it is okay if you want to just give up"));
 	F['z']='q',F['q']='z';
 	int _;scanf("%d\n",&_);
 	for(int __=1;__<=_;__++)
 	{
 		string s;getline(cin,s);
 		cout<<"Case #"<<__<<": "<<gg(s)<<endl;
 	}
 	return 0;
 }
