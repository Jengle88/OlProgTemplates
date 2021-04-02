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
//#include <Windows.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template <class T>
using pt = std::pair<T, T>;
using namespace std;


struct edge
{
	int from, to;// from->to
	int weight;	 // weight
};

struct snmachka //DSU
{
	int value,size; //root,size set

};
vector<snmachka> snmSet;//set of our edges

int findik(int x)//find
{
	if (snmSet[x].value != x)
		snmSet[x].value = findik(snmSet[x].value);
	return snmSet[x].value;
}

void unionchik(int x,int y)//union
{
	x = findik(x), y = findik(y);
	if (snmSet[x].value == snmSet[y].value)
		return;
	if (snmSet[x].size > snmSet[y].size)
		swap(x, y);
	snmSet[x].value = y;
	snmSet[y].size += snmSet[x].size;
}

bool good(int x, int y)//no cycle
{
	return findik(x) != findik(y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "weight", stdout);
#else
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<edge> graph(m);
	snmSet.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		snmSet[i].value = i; //start root
	}
	for (int i = 0; i < m; i++)
	{
		cin >> graph[i].from >> graph[i].to >> graph[i].weight;
	}
	sort(graph.begin(), graph.end(), [](edge a, edge b) {return a.weight < b.weight; }); //sort by weight
	ll sum = 0;
	for (int i = 0; i < m; i++)
	{
		if (good(graph[i].from, graph[i].to)) // if from.root != to.root -> no cycle in set with (from,to)
		{
			sum += graph[i].weight;
			unionchik(graph[i].from, graph[i].to);
		}
	}
	cout << sum;
	return 0;
}
