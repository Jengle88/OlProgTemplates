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
#include <random>
#include <unordered_map>

//#include <Windows.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<class T>
using pt = std::pair<T, T>;
using namespace std;

vector<ll> t, a;

int f(int x) { //for out
    return x & (x + 1);
}

int h(int x) { //for add
    return x | (x + 1);
}

void add(int i, ll x) { //add elem
    ll c = x - a[i]; //delta
    while (i < a.size()) {
        t[i] += c;
        i = h(i);
    }
}

ll prefs(int k) { //print sum on sub-section
    ll res = 0;// score
    while (k >= 0) {
        res += t[k];
        k = f(k) - 1;
    }
    return res;
}

void example() {
    int n;
    int tt, q;
    cin >> n >> q;
    a.resize(n + 1);
    t.resize(n + 1); //our array, temp array
    ll i1;
    for (int i = 1; i <= n; i++) {
        cin >> i1;
        upd(i, i1);
        a[i] = i1;
    }
    while (q--) {
        cin >> tt;
        if (tt) { //edit
            ll ind, d;
            cin >> ind >> d;
            upd(ind, d);
            a[ind] = d;
        } else { //out subsum
            int l, r;
            cin >> l >> r;
            cout << sum(r) - sum(l - 1) << '\n';
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
    cin.tie(0);
    cout.tie(0);
    //start array from 1
    return 0;
}
