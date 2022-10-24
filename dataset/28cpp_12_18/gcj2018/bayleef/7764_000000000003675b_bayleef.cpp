#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define WH 41414141
#define BAD -41414141

using namespace std;

struct TT
{
	int x, y;
}v[100100];

TT intersect(TT t1, TT t2)
{
	if (t1.x == t2.x && t1.y == t2.y)
		return t1;
	if (t1.x == BAD || t1.y == BAD)
		return t1;
	if (t2.x == BAD || t2.y == BAD)
		return t2;
	TT t;
	if (t1.x == t2.x)
		t.x = t1.x;
	else if (t1.x == WH)
		t.x = t2.x;
	else if (t2.x == WH)
		t.x = t1.x;
	else t.x = BAD;

	if (t1.y == t2.y)
		t.y = t1.y;
	else if (t1.y == WH)
		t.y = t2.y;
	else if (t2.y == WH)
		t.y = t1.y;
	else t.y = BAD;

	return t;
}

vector<TT> intersect(vector<TT> v1, vector<TT>v2)
{
	vector<TT>v;
	for (int i = 0; i < v1.size(); i++)
		for (int j = 0; j < v2.size(); j++)
		{
			TT t = intersect(v1[i], v2[j]);
			if (t.x != BAD && t.y != BAD)
				v.push_back(t);
		}
	vector<TT>w;
	for (int i = 0; i < v.size(); i++)
	{
		bool ok = true;
		for (int j = 0; j < v.size(); j++)
			if (i != j && (v[i].x == v[j].x && v[j].y == WH || v[i].y == v[j].y && v[j].x == WH))
			{
				ok = false;
				break;
			}
		if (ok)
			w.push_back(v[i]);
	}
	return w;
}

vector<TT> emptyrules()
{
	vector<TT>v;
	TT t;
	t.x = t.y = WH;
	v.push_back(t);
	return v;
}

vector<TT>rules[400];
vector<TT>basicrules[100100];
vector<TT>r;
int ans, num;

void checkans(int x)
{
	if (x > ans)
	{
		ans = x;
		num = 1;
	}
	else if (x == ans)
		++num;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int ts = 1; ts <= T; ts++)
	{
		ans = 0;
		int n, i, j, k;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			basicrules[i].clear();
			int d, a, b;
			scanf("%d%d%d", &d, &a, &b);
			v[i].x = d + a;
			v[i].y = d - b;
			TT t;
			t.x = WH;
			t.y = v[i].y;
			basicrules[i].push_back(t);
			t.x = v[i].x;
			t.y = WH;
			basicrules[i].push_back(t);
		}
		int m = sqrt(1.0*n);
		for (i = 0; i < n; i += m)
		{
			rules[i / m] = basicrules[i];
			for (j = i + 1; j < i + m && j < n; j++)
				rules[i / m] = intersect(rules[i / m], basicrules[j]);
		}
		for (i = 0; i < n; i++)
		{
			r = basicrules[i];
			for (j = i + 1; j%m && j < n; j++)
			{
				r = intersect(r, basicrules[j]);
				if (r.empty())
					break;
			}
			if (r.empty() || j == n)
			{
				checkans(j - i);
				continue;
			}
			for (; j < n; j += m)
			{
				if (intersect(r, rules[j / m]).empty())
					break;
				r = intersect(r, rules[j / m]);
			}
			if (j >= n)
			{
				checkans(n - i);
				continue;
			}
			for (; ; j++)
			{
				r = intersect(r, basicrules[j]);
				if (r.empty())
					break;
			}
			checkans(j - i);
		}
		printf("Case #%d: %d %d\n", ts, ans, num);
	}
	return 0;
}