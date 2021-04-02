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
#include <type_traits>
#include <climits>
#include <functional>
#include <iomanip>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_map>

//#include <Windows.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<class T>
using pt = std::pair<T, T>;
using namespace std;

int log2N;
vector<vector<int>> moveUp;//matrix bin lifts 1,2,4...
vector<int> timeIn, timeOut;//time in and out

bool anc(int ancestor, int child)//checker, ancestor or no?
{
	return timeIn[ancestor] <= timeIn[child] && timeIn[child] < timeOut[ancestor];
}

int graph_time = 0;

void dfs(int v, vector<vector<int>> &graph)//dfs with moveUp and timeIn/timeOut
{
	for (int l = 1; l < log2N; l++)
		moveUp[v][l] = moveUp[moveUp[v][l - 1]][l - 1];
	timeIn[v] = graph_time++;
	for (int u : graph[v]) {
		moveUp[u][0] = v;
		dfs(u, graph);
	}
	timeOut[v] = graph_time;
}

int lca(int u, int v) //find lca
{
	if (anc(v, u)) return v;
	if (anc(u, v)) return u;
	for (int l = log2N - 1; l >= 0; l--) {
		if (!anc(moveUp[v][l], u))
			v = moveUp[v][l];
	}
	return moveUp[v][0];
}

void solve()//example
{
	int n, m, i1, i2;
	cin >> n >> m;
	log2N = ceil(log2(n));
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; i++) {
		cin >> i1 >> i2;
		graph[i1].push_back(i2);
	}
	moveUp.resize(n, vector<int>(log2N));
	timeIn.resize(n);
	timeOut.resize(n);
	dfs(0, graph);
	int q;
	cin >> q;
	while (q--) {
		cin >> i1 >> i2;
		cout << lca(i1, i2) << ' ';
	}

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
	solve();
	return 0;
}
