#include <vector>
 #include <list>
 #include <map>
 #include <set>
 #include <deque>
 #include <queue>
 #include <stack>
 #include <bitset>
 #include <algorithm>
 #include <functional>
 #include <numeric>
 #include <utility>
 #include <sstream>
 #include <iostream>
 #include <iomanip>
 #include <string>
 #include <complex>
 #include <cstdio>
 #include <cmath>
 #include <cstdlib>
 #include <cctype>
 #include <cstring>
 #include <climits>
 #include <ctime>
 
 #include<unordered_map>
 #include<unordered_set>
 using namespace std;
 const int __dd = 0;
 
 void marknoplus(vector< vector<int> > &mark, int i , int j, int n)
 {
 	for (int a = i-1, b = j-1; a>=0 && b >= 0; --a,--b)
 		mark[a][b] |=1; //no '+'
 	for (int a = i+1, b = j+1; a < n && b <n; ++a,++b)
 		mark[a][b] |=1; //no '+'
 
 	for (int a = i-1, b = j+1; a>=0 && b <n; --a,++b)
 		mark[a][b] |=1; //no '+'
 	for (int a = i+1, b = j-1; a < n && b >=0; ++a,--b)
 		mark[a][b] |=1; //no '+'
 }
 
 void marknocross(vector< vector<int> > &mark, int i , int j, int n)
 {
 	for (int a = i-1; a>=0 ; --a)
 		mark[a][j] |=2; //no 'x'
 	for (int a = i+1; a<n ; ++a)
 		mark[a][j] |=2; //no 'x'
 
 	for (int b = j-1; b>=0 ; --b)
 		mark[i][b] |=2; //no 'x'
 	for (int b = j+1; b<n ; ++b)
 		mark[i][b] |=2; //no 'x'
 }
 
 void delnocross(vector< vector<int> > &mark, int i , int j, int n)
 {
 	for (int a = i-1; a>=0 ; --a)
 		mark[a][j] &=~2;
 	for (int a = i+1; a<n ; ++a)
 		mark[a][j] &=~2;
 
 	for (int b = j-1; b>=0 ; --b)
 		mark[i][b] &=~2;
 	for (int b = j+1; b<n ; ++b)
 		mark[i][b] &=~2;
 }
 
 void printgrid(const vector< vector<char> >& in)
 {
 	if(__dd)
 	{
 	cerr << "--" << endl;
 	for (int i = 0; i < in.size(); ++i)
 	{
 		for (int j = 0; j < in[i].size(); ++j)
 			cerr << in[i][j];
 		cerr << endl;
 	}
 	cerr << "--" << endl;
 	}
 }
 
 void printmark(const vector< vector<int> >& in)
 {
 	if(__dd)
 	{
 	cerr << "--" << endl;
 	for (int i = 0; i < in.size(); ++i)
 	{
 		for (int j = 0; j < in[i].size(); ++j)
 			cerr << in[i][j]<< " ";
 		cerr << endl;
 	}
 	cerr << "--" << endl;
 	}
 }
 
 struct Ans
 {
 	char s;
 	int i;
 	int j;
 	Ans(char s, int i , int j) : s(s), i(i), j(j){}
 };
 
 
 int calscore(const vector<vector<char>>& aa, int n)
 {
 	int ans = 0;
 	for (int i = 0; i < n; ++i)
 	{
 		for (int j = 0; j < n; ++j)
 		{
 			char ok = 1;
 
 			if (aa[i][j] == '+')
 			{
 				for (int a = i-1, b = j-1; a>=0 && b >= 0; --a,--b)
 				{
 					if (aa[a][b] == '+' || aa[a][b] == 'o') return -1;
 				}
 				for (int a = i+1, b = j+1; a < n && b <n; ++a,++b)
 				{
 					if (aa[a][b] == '+'|| aa[a][b] == 'o') return -1;
 				}
 
 				for (int a = i-1, b = j+1; a>=0 && b <n; --a,++b)
 				{
 					if (aa[a][b] == '+'|| aa[a][b] == 'o') return -1;
 				}
 				for (int a = i+1, b = j-1; a < n && b >=0; ++a,--b)
 				{
 					if (aa[a][b] == '+'|| aa[a][b] == 'o') return -1;
 				}
 			}
 			else if (aa[i][j] == 'x')
 			{
 				for (int a = i-1; a>=0 ; --a)
 				{
 					if (aa[a][j] == 'x'|| aa[a][j] == 'o') return -1;
 				}
 
 				for (int a = i+1; a<n ; ++a)
 				{
 					if (aa[a][j] == 'x'|| aa[a][j] == 'o') return -1;
 				}
 
 				for (int b = j-1; b>=0 ; --b)
 				{
 					if (aa[i][b] == 'x'|| aa[i][b] == 'o') return -1;
 				}
 
 				for (int b = j+1; b<n ; ++b)
 				{
 					if (aa[i][b] == 'x'|| aa[i][b] == 'o') return -1;
 				}
 			}
 			else if (aa[i][j] == 'o')
 			{
 				for (int a = i-1, b = j-1; a>=0 && b >= 0; --a,--b)
 				{
 					if (aa[a][b] == 'o') return -1;
 				}
 				for (int a = i+1, b = j+1; a < n && b <n; ++a,++b)
 				{
 					if (aa[a][b] == 'o') return -1;
 				}
 
 				for (int a = i-1, b = j+1; a>=0 && b <n; --a,++b)
 				{
 					if (aa[a][b] == 'o') return -1;
 				}
 				for (int a = i+1, b = j-1; a < n && b >=0; ++a,--b)
 				{
 					if (aa[a][b] == 'o') return -1;
 				}
 
 
 
 				for (int a = i-1; a>=0 ; --a)
 				{
 					if (aa[a][j] == 'o') return -1;
 				}
 
 				for (int a = i+1; a<n ; ++a)
 				{
 					if (aa[a][j] == 'o') return -1;
 				}
 
 				for (int b = j-1; b>=0 ; --b)
 				{
 					if (aa[i][b] == 'o') return -1;
 				}
 
 				for (int b = j+1; b<n ; ++b)
 				{
 					if (aa[i][b] == 'o') return -1;
 				}
 			}
 
 
 			if (ok)
 			{
 				if (aa[i][j] == '+')
 					++ans;
 				else if (aa[i][j] == 'x')
 					++ans;
 				else if (aa[i][j] == 'o')
 					ans+=2;
 			}
 			else
 			{
 				return -1;
 			}
 		}
 	}
 
 
 	return ans;
 }
 
 bool normalpack(int n , vector< vector<int> >& mark, vector< vector<char> > &out)
 {
 	bool changed = false;
 	
 	int ii = 0, iii = n-1;
 	for (int _i = 0; _i < n; ++_i)
 	//for (int _i = n; _i--;)
 	{
 		int real_i = _i;
 			if (_i%2)
 				real_i = ii++;
 			else
 				real_i = iii--;
 		//for (int j = 0; j < n; ++j)
 		for (int j = n; j--;)
 		{
 			
 
 			if (out[real_i][j] == '.')
 			{
 				if (mark[real_i][j] == 0)
 				{
 				//	if(real_i != j)
 					if(1)
 					{
 						out[real_i][j] = '+';
 						marknoplus(mark,real_i,j,n);
 					}
 					else
 					{
 						out[real_i][j] = 'x';
 						marknocross(mark,real_i,j,n);
 					}
 
 					changed = true;
 				}
 				else if (mark[real_i][j] == 2)
 				{
 					out[real_i][j] = '+';
 					marknoplus(mark,real_i,j,n);
 					changed = true;
 				}
 				else if (mark[real_i][j] == 1)
 				{
 					out[real_i][j] = 'x';
 					marknocross(mark,real_i,j,n);
 					changed = true;
 				}
 			}
 		}
 	}
 
 	return changed;
 }
 
 int main(int __an, char **__ag)
 {	
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	while (Case--)	
 	{
 		int n, k;
 		cin >> n >> k;
 		vector< vector<char> > in(n, vector<char>(n,'.')), out;
 		vector< vector<int> > mark(n, vector<int>(n,0));
 
 		for (int i = 0; i < k; ++i)
 		{
 			char a; 
 			int b,c;
 			cin >> a >> b >> c;
 			in[b-1][c-1] = a;
 		}
 		out = in;
 
 		for (int i = 0; i < n; ++i)
 		{
 			for (int j = 0; j < n; ++j)
 			{
 				if (in[i][j] == '+')
 				{
 					marknoplus(mark,i,j,n);
 				}
 				else if (in[i][j] == 'x')
 				{
 					marknocross(mark,i,j,n);
 				}
 				else if (in[i][j] == 'o')
 				{
 					marknoplus(mark,i,j,n);
 					marknocross(mark,i,j,n);
 				}
 			}
 		}
 		printmark(mark);
 
 		//normal
 		normalpack(n,mark,out);
 
 		printmark(mark);
 
 		printgrid(in);
 		printgrid(out);
 
 		//upgrade?
 		for (int i = 0; i < n; ++i)
 		//for (int i = n; i--;)
 		{
 			for (int j = 0; j < n; ++j)
 			//for (int j = n; j--;)
 			{
 				if (out[i][j] != '.' && out[i][j] != 'o' && mark[i][j] == 0)
 				{
 					char prev = out[i][j];
 					out[i][j] = 'o';
 					marknoplus(mark,i,j,n);
 					//if(prev =='x')
 						//delnocross(mark,i,j,n);
 				}				
 			}
 		}
 
 				printmark(mark);
 
 		printgrid(in);
 		printgrid(out);
 
 		bool wtf = true;
 
 		while(wtf)
 		{
 			wtf=normalpack(n,mark,out);
 			
 			//upgrade?
 			for (int i = 0; i < n; ++i)
 		//	for (int i = n; i--;)
 			{
 				for (int j = 0; j < n; ++j)
 				//for (int j = n; j--;)
 				{
 					if (out[i][j] != '.' && out[i][j] != 'o' && mark[i][j] == 0)
 					{
 					 wtf = true;
 						char prev = out[i][j];
 						out[i][j] = 'o';
 						marknoplus(mark,i,j,n);
 						//if(prev =='x')
 						//	delnocross(mark,i,j,n);
 					}				
 				}
 			}
 		}
 
 		int score = 0;
 		vector<Ans> anss;
 		for (int i = 0; i < n; ++i)
 		{
 			for (int j = 0; j < n; ++j)
 			{
 				if(out[i][j] =='+' || out[i][j] =='x')
 					++score;
 				else if(out[i][j] =='o')
 					score +=2;
 				if(out[i][j] != in[i][j])
 				{
 					anss.push_back( Ans(out[i][j],i+1,j+1));
 				}
 			}
 		}
 		
 		printf("Case #%d: " , ++cases);
 		printf("%d %d\n" , score, anss.size());
 	//	cout << "real score:"<< calscore(out,n) << endl;
 		if (calscore(out,n) < 0) cerr<<"wtf"<<endl;
 		for( int i = 0 ; i <anss.size(); ++i)
 			printf("%c %d %d\n" , anss[i].s,anss[i].i,anss[i].j);
 
 	}
 
 	return 0;
 }
 
