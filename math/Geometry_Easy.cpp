#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <complex>
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
#define eps -1e6

struct point {
    ld x, y;

    point(ld x, ld y) : x(x), y(y) {}

    point() : x(0), y(0) {}

    point &operator+(point &b) {
        point res(this->x + b.x, this->y + b.y);
        return res;
    }

    ld len() {
        return sqrtl(this->x * this->x + this->y * this->y);
    }

    ld len_safe() {
        ll x = ll(this->x) % int(1e9), y = ll(this->y) % int(1e9);
        return sqrtl(x * x + y * y);
    }

    point &operator-(point &b) {
        point res(this->x - b.x, this->y - b.y);
        return res;
    }

    point &operator*(ld k) {
        point res(this->x * k, this->y * k);
        return res;
    }
};

ld vectproz(point &a, point &b) {
    return a.x * b.y - a.y * b.x;
}

int direction(point &a, point &b) {
    ld z = vectproz(a, b);
    if (z < eps)
        return 0;//Straight
    else
        return z > 0 ? 1 : -1; //Left, Right
}

ld Eucl_len(point &a, point &b) {
    return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld Manh_len(point &a, point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

ld SS(vector<point> &a) {
    ld ansS = 0;
    a.push_back(a.front());
    for (int i = 0; i < a.size() - 1; i++) {
        ansS += (a[i + 1].x - a[i].x) * (a[i + 1].y + a[i].y) / 2;
    }
    return abs(ansS);
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}
