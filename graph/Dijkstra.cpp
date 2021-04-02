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
template<class T>
using pt = std::pair<T, T>;
using namespace std;

struct edge {
	int to;
	int length = 0;
};
struct graph {
	int dist = INF;
	vector<edge> arrEdge;
};

void Dijkstra(int start, vector<graph> &gr) {
	priority_queue<pt<int>> que;//length,to
	gr[start].dist = 0;
	que.push({0, start});
	while (!que.empty()) {
		auto edgeQue = que.top();//length, to
		que.pop();
		for (int i = 0; i < gr[edgeQue.second].arrEdge.size(); i++) {
			auto edgeGraph = gr[edgeQue.second].arrEdge[i];//to and length
			if (gr[edgeGraph.to].dist > edgeQue.first + edgeGraph.length) {
				gr[edgeGraph.to].dist = edgeQue.first + edgeGraph.length;
				que.push({gr[edgeGraph.to].dist, edgeGraph.to});
			}
		}
	}
}


void example() {
	int n, start, finish;
	cin >> n >> start >> finish;
	int i1;
	vector<graph> graph(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> i1;
			if (i == j)
				continue;
			if (i1 != -1) {
				graph[i].arrEdge.push_back({j, i1});
			}
		}
	}
	Dijkstra(start, graph);
	if (graph[finish].dist == INF)
		cout << -1;
	else
		cout << graph[finish].dist;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	example();
	return 0;
}
