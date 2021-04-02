#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <utility>
#include <climits>
#include <functional>
#include <iomanip>
#include <stack>
#include <queue>
#include <type_traits>
#include <deque>
#include <unordered_map>
#include <unordered_set>
//#include <Windows.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template <class T>
using pt = std::pair<T, T>;
using namespace std;

struct subArray //sub-arrays
{
	subArray(int n)
	{
		arr.reserve(n);
	}
	int left, right;
	vector<pt<int>>arr;
};

void build(vector<subArray> &a)// sub-arrays
{
	int n;
	cin >> n;
	int root2 = ceil(sqrt(n));
	a.resize(root2, subArray(root2));
	int in;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		a[i / root2].arr.emplace_back(in, i);
	}
	if (a.back().arr.empty())
		a.pop_back();
	for (int i = 0; i < a.size(); i++)
	{
		a[i].left = i * root2;
		a[i].right = i * root2 + root2 - 1;
	}
	a.back().right = n - 1;
}

struct fullArray //full array
{
	int x, left;
};

void build(vector<fullArray> &a)// full array
{
	int n;
	cin >> n;
	int root2 = ceil(sqrt(n));
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x;
		a[i].left = i / root2 * root2;
	}
}

struct sqrtGraph //graph
{
	int x;
	bool isHeavy = false;
	vector<int> ed, heavy;
	sqrtGraph() { ed.reserve(210); heavy.reserve(155); }
};

void build(vector<sqrtGraph> &a, vector<int> &heavy)// graph (heavy-light-node)
{						// heavy node no more than sqrt(n)
	int n, m, idx1, idx2;			// if node is light, then we can do bfs
	cin >> n >> m;				// else we can update nearest heavy edges
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x;
	}
	int root2 = ceil(sqrt(n)); // 1e3?
	heavy.reserve(root2);
	for (int i = 0; i < m; i++)
	{
		cin >> idx1 >> idx2;
		//idx1--; idx2--;
		a[idx1].ed.push_back(idx2);
		a[idx2].ed.push_back(idx1);
		if (a[idx1].ed.size() > root2 && !a[idx1].isHeavy)
		{
			heavy.push_back(idx1);
			a[idx2].heavy.push_back(idx1);
			a[idx1].isHeavy = true;
		}
		if (a[idx2].ed.size() > root2 && !a[idx2].isHeavy)
		{
			heavy.push_back(idx2);
			a[idx1].heavy.push_back(idx2);
			a[idx2].isHeavy = true;
		}
	}
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	return 0;
}
