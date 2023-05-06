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
template<class T>
using pt = std::pair<T, T>;
using namespace std;
vector<vector<vector<ll>>> a;

int f(ll x) {
    return x & (x + 1);
}

int h(ll x) {
    return x | (x + 1);
}

void add(int x, int y, int z, ll val) {
    int i, j;
    while (x < a.size()) {
        i = y;
        while (i < a[0].size()) {
            j = z;
            while (j < a[0][0].size()) {
                a[x][i][j] += val;
                j = h(j);
            }
            i = h(i);
        }
        x = h(x);
    }
}

ll psum(int x, int y, int z) {
    ll res = 0;
    int i = x;
    while (i >= 0) {
        int j = y;
        while (j >= 0) {
            int k = z;
            while (k >= 0) {
                res += a[i][j][k];
                k = f(k) - 1;
            }
            j = f(j) - 1;
        }
        i = f(i) - 1;
    }
    return res;
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

    //sum on cubes
    int x1, y1, z1, x2, y2, z2, val;
    int n;
    cin >> n;
    a.resize(n, vector<vector<ll>>(n, vector<ll>(n)));
    //add
    cin >> x1 >> y1 >> z1 >> val;
    add(x1, y1, z1, val);
    // query
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    ll res = 0;
    res += psum(x2, y2, z2);
    res -= psum(x1 - 1, y2, z2);
    res -= psum(x2, y1 - 1, z2);
    res += psum(x1 - 1, y1 - 1, z2);
    res -= psum(x1 - 1, y1 - 1, z1 - 1);
    res += psum(x2, y1 - 1, z1 - 1);
    res += psum(x1 - 1, y2, z1 - 1);
    res -= psum(x2, y2, z1 - 1);
    cout << res << '\n';
    //end


    return 0;
}
