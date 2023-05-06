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

class Sparse {
private:
    vector<vector<int>> dp;
    int lim;

    int (*f)(int a, int b);

public:
    void in(int n) { // cin table
        this->lim = log2(n) + 2;
        dp.resize(n, vector<int>(lim));
        for (int i = 0; i < n; i++)
            cin >> dp[i][0];
    }

    void in_a(vector<int> &a) { //arr -> table
        this->lim = log2(a.size()) + 2;
        dp.resize(a.size(), vector<int>(lim));
        for (int i = 0; i < a.size(); i++) {
            dp[i][0] = a[i];
        }
    }

    void bld(int (&func)(int a, int b)) { //build table
        this->f = func;
        for (int k = 1; k < lim; k++) {
            for (int i = 0; i < dp.size(); i++) {
                if (i + (1 << (k - 1)) < dp.size()) {
                    dp[i][k] = func(dp[i][k - 1], dp[i + (1 << (k - 1))][k - 1]);
                }
            }
        }
    }

    int out(int l, int r) { // RMQ
        l--;
        r--;
        if (l > r)
            swap(l, r);
        ll lg = (int) log2(r - l + 1);
        r++;
        return this->f(dp[l][lg], dp[r - (1 << lg)][lg]);
    }
};

int f(int a, int b) { //compar func
    return max(a, b);
}

void solve() { //example
    Sparse t;
    int n;
    cin >> n;
    t.in(n);
    t.bld(f);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;//if l from [1,n]
        cout << t.out(l, r) << ' ';
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

