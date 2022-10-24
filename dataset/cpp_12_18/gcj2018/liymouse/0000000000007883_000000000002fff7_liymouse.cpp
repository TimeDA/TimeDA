#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

int cmp(pair<double , double> &x , pair<double , double> &y)
{
    if (x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}
void clean(vector<pair<double, double> > &a)
{
    sort(a.begin() , a.end() , cmp);
    vector<pair<double, double> > b;
    double x = a[0].first;
    double y = a[0].second;
    for (int i = 1; i < a.size(); i ++)
    {
        if (a[i].first <= y) y = max(y , a[i].second);
        else
        {
            b.push_back(make_pair(x , y));
            x = a[i].first;
            y = a[i].second;
        }
    }
    b.push_back(make_pair(x , y));
    a = b;
}
int main()
{
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n , p;
        int w[101];
        int h[101];
        double res = 0;
        double tot = 0;
        double totmin = 0;
        pair<double, double> a[101];
        scanf("%d %d" , &n , &p);
        double P = p;
        for (int i = 0; i < n; i ++)
        {
            scanf("%d %d" , &w[i] , &h[i]);
            a[i] = make_pair(2 * min(w[i] , h[i]) , 2 * sqrt((double)w[i]*w[i] + h[i]*h[i]));
            p -= 2 * (w[i] + h[i]);
            res += 2 * (w[i] + h[i]);
            tot += a[i].second;
            totmin += a[i].first;
        }
        if (p >= tot) {printf("%.10lf\n" , res + tot); continue;}
        if (totmin <= p) {printf("%.10lf\n" , P); continue;}
        if (p <= 1e-8) {printf("%.10lf\n" , res); continue;}
        sort(a , a + n , cmp);
        vector<pair<double, double> > sen;
        for (int i = 0; i < n; i ++)
        {
            for (int j = 0; j < sen.size(); j ++)
            {
                sen[j].first += a[i].first;
                sen[j].second += a[i].second;
            }
            sen.push_back(a[i]);
            clean(sen);
        }
        double last = 0;
        for (int i = 0; i < sen.size(); i ++)
        {
            if (p < sen[i].first) {printf("%.10lf\n" ,res + last); break;}
            else if (p <= sen[i].second) {printf("%.10lf\n" , P); break;}
            last = sen[i].second;
            if (i == n) printf("%.10lf\n" , res + last);
        }
    }
    return 0;
}