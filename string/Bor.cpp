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
#include <unordered_set>

//#include <Windows.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<class T>
using pt = std::pair<T, T>;
using namespace std;

class bor {
    struct vert {
        char c; //symbol
        int cnt; // count of strings ending here
        map<char, vert *> edg;//next vert
        vert(char c) : c(c), cnt(0) {};

        vert() {};
    };

    vert *root = new vert;//your root
public:
    vert *getr() { //get root
        return root;
    }

    void insert(vert *root, string &s, int ind = 0) {
        if (ind == s.size()) {
            root->cnt++;
            return;
        }
        if (root->edg.count(s[ind]))
            insert(root->edg[s[ind]], s, ind + 1);
        else {
            root->edg[s[ind]] = new vert(s[ind]);
            insert(root->edg[s[ind]], s, ind + 1);
        }
    }

    bool find(vert *root, string &s, int ind = 0) { //find string
        if (ind == s.size()) // && root->cnt != 0)
            return true;
        else if (root->edg.count(s[ind]))
            return find(root->edg[s[ind]], s, ind + 1);
        else
            return false;
    }
    //for lcp are using lca on bor
};

void solve() {
    bor b;
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        b.insert(b.getr(), s);
    }
    s = "abc";
    cout << b.find(b.getr(), s);

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
