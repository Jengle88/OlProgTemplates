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

vector<pt<int>> eul;//euler
vector<vector<int>> ed;// tabl edges
vector<bool> is;// in or not?

class Sparse {
    int lim;
    vector<vector<pt<int>>> dp;
public:
    void in_a() { //euler -> sparse tabl
        lim = log2(eul.size()) + 2;
        dp.resize(eul.size(), vector<pt<int>>(log2(eul.size()) + 2));
        for (int i = 0; i < eul.size(); i++) {
            dp[i][0].first = eul[i].second;
            dp[i][0].second = eul[i].first;
        }
    }

    void bld() { //build tabl
        int k1;
        for (int k = 1; k < lim; k++) {
            k1 = (1 << (k - 1));
            for (int i = 0; i < dp.size(); i++) {
                if (i + k1 < dp.size()) {
                    if (dp[i][k - 1].first > dp[i + k1][k - 1].first)
                        dp[i][k] = dp[i + k1][k - 1];
                    else
                        dp[i][k] = dp[i][k - 1];
                }
            }
        }
    }

    pt<int> out(int l, int r) { // RMQ
        if (l > r)
            swap(l, r);
        ll lg = (int) log2(r - l + 1);
        r++;
        return min(dp[l][lg], dp[r - (1 << lg)][lg]);
    }
};

int ind = 0;// first time_in in eul

vector<int> nedg;// n edges
void dfs(int st, int h) { //do dfs and euler
    eul.push_back({st, h});
    nedg[st] = ind;
    ind++;
    is[st] = true;
    for (int i = 0; i < ed[st].size(); i++) {
        if (!is[ed[st][i]]) {
            dfs(ed[st][i], h + 1);
            eul.push_back({st, h});
            ind++;
        }
    }
}

void build_lca(Sparse &a) { //build lca
    dfs(1, 0);
    a.in_a();
    a.bld();
}

void solve() { //example
    int n, m;
    cin >> n >> m;
    ed.resize(n + 1);
    is.resize(n + 1);
    nedg.resize(n + 1);
    eul.reserve(m * 2);
    int i1, i2;
    for (int i = 0; i < m; i++) {
        cin >> i1 >> i2;
        //	i1--; i2--;
        ed[i1].push_back(i2);
        ed[i2].push_back(i1);
    }
    Sparse sp;
    build_lca(sp);
    int q;
    cin >> q;
    while (q--) {
        int i1, i2;
        cin >> i1 >> i2;
        cout << sp.out(nedg[i1], nedg[i2]).second << ' ';
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
