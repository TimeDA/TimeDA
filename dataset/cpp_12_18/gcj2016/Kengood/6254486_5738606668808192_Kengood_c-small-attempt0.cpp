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
 
 
 long long powa[12][16];
 long long t[16];
 long long haha[16];
 
 long long isprime(long long n)
 {
 	long long limit = sqrt((double)n) + 1000LL;
 	for (long long i = 2; i < limit; ++i)
 	{
 		if (n%i == 0)
 			return i;
 	}
 
 	return -1;
 }
 
 struct Data
 {
 	long long a;
 	vector<long long> div;
 };
 
 vector<Data> af()
 {
 	for (long long i = 2; i < 11; ++i)
 	{
 		long long as = 1;
 		for (long long j = 0; j < 16; ++j)
 		{
 			powa[i][j] = as;
 			as*=i;
 		}
 	}
 
 	vector<Data> data;
 	for (long long all = 32769; all <65536 && data.size() != 50; all+=2)
 	{
 		for (long long j = 0; j < 16; ++j)
 			t[j] = (all& (1<<j))>>j;
 
 
 		char ok = 1;
 		for (long long i = 2; i < 11; ++i)
 		{
 			long long as = 0;
 			for (long long j = 0; j < 16; ++j)
 				as += t[j]*powa[i][j];
 			
 			haha[i] = isprime(as);
 			if (haha[i] == -1)
 			{
 				printf("%lld %lld -> %lld no \n" , all , i , as);
 			
 				ok = 0;
 				break;
 			}
 		}
 
 		if (ok)
 		{
 			cout << data.size() +1 << " : " << all << endl;
 			Data dd;
 			dd.a = all;
 			for (long long i = 2; i < 11; ++i)
 				dd.div.push_back( haha[i]);
 			data.push_back(dd);
 		}
 
 	}
 
 	return data;
 }
 
 void printBin(int a)
 {
 	for (long long j = 16; j--;)
 	{
 		printf("%d" , (a&(1<<j))?1:0 );
 	}
 }
 
 int main(int a, char **ag)
 {	
 
 
 	vector<Data> data = af();
 
 
 	int Case, cases = 0;
 	scanf("%d" , &Case);
 	while (Case--)	
 	{
 		
 		
 		printf("Case #%d: " , ++cases );
 		puts("");
 		
 		for (int i = 0 ; i < data.size(); ++i)
 		{
 			printBin(data[i].a);			
 			for (int j = 0 ; j < data[i].div.size(); ++j)
 				printf(" %lld" , data[i].div[j]);
 			puts("");
 		}
 
 	}
 
 	return 0;
 }
 
