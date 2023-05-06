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

tuple<ll, ll, ll> gcd2(ll a, ll b) { // super-Euclid
    if (!b)
        return {1, 0, a};
    else {
        ll x, y, g;
        tie(x, y, g) = gcd2(b, a % b);
        return {y, x - (a / b) * y, g};
    }
}

void diofant(ll a, ll b, vector<pt<int>> &out) { //find solutions
    int l = 1, r = 5; //find with k on segment [L,R]
    ll x, y, g;
    tie(x, y, g) = gcd2(a, b);
    for (int k = l; k <= r; k++) {
        out.push_back({x + b * k / g, y - a * k / g});
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
    ll a = 2, b = 3;
    ll x, y, g;
    tie(x, y, g) = gcd2(a, b);
    cout << "x = " << x << ", y = " << y << ", g = " << g << '\n';
    vector<pt<int>> arr;
    diofant(a, b, arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << "x = " << arr[i].first << ", y = " << arr[i].second << '\n';
    }
    return 0;
}
