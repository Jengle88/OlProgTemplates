#define _CRT_SECURE_NO_WARNINGS
#define INF 1e9
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
	ll to, length;
};

struct vertex
{
	ll dist = INF;
	vector<edge> edges;
};

void Ford_Bellman(int start, vector<vertex>& graph)
{
	graph[start].dist = 0;
	for (int i = 1; i < graph.size(); i++)//for all edges each time
	{
		for (int j = 1; j < graph.size(); j++)//for all edges each time	  
		{					  					
			for (auto edge : graph[j].edges)//for all edges each time          
			{
				if(graph[j].dist != INF)//if not infinity, then decrease
					graph[edge.to].dist = min(graph[edge.to].dist, graph[j].dist + edge.length);
			}
		}
	}
}

void example()
{
	int n, m;
	cin >> n >> m;
	vector<vertex> graph(n + 1);
	int i1, i2, length;
	for (int i = 0; i < m; i++)
	{
		cin >> i1 >> i2 >> length;
		graph[i1].edges.push_back({i2, length });
		//graph[i2].edges.push_back({ i1,length });// NOOOOOOOOOOOOOOOOOOOOOOOO!!11!1!!!!
	}
	Ford_Bellman(1, graph);
	for (int i = 1; i <= n; i++)
	{
		if (graph[i].dist != INF)
			cout << graph[i].dist << ' ';
		else
			cout << INF << ' ';
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	example();
	return 0;
}
