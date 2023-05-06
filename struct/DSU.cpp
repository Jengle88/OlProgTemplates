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

struct hoba {
    int val;
    int min = INT_MAX, max = INT_MIN;
    int size = 1;

    hoba() {
        static int indx = 1;
        val = indx;
        indx++;
    }

};

vector<hoba> a;

int findik(int x) { // find root set, where a[x] elem
    if (a[x].val != x)
        a[x].val = findik(a[x].val);//fast
    return a[x].val;                //doesn't always work
    /*
    while(a[x].val != x)  //slow
        x = a[x].val;
    return x;
    */
}

void unionchik(int x, int y) { //union two set, less -> greater
    x = findik(x), y = findik(y);
    if (a[x].val == a[y].val)
        return;
    if (a[x].size > a[y].size)
        swap(x, y);
    a[x].val = y;
    a[y].size += a[x].size;
    a[y].min = min(a[y].min, a[x].min);
    a[y].max = max(a[y].max, a[x].max);

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
    int n;
    cin >> n;
    a.resize(n + 1);
    string s;
    int i1, i2;
    while (cin >> s) {
        if (s == "union") {
            cin >> i1 >> i2;
            unionchik(i1, i2);
        } else {
            cin >> i1;
            int z = findik(i1);
            cout << a[z].min << ' ' << a[z].max << ' ' << a[z].size << '\n';
        }
    }
    return 0;
}
