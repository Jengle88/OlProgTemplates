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
#define INF 1e9
using namespace std;

vector<int> a;

struct hoba {
    hoba *l = nullptr, *r = nullptr;
    int lf, rg;
    vector<int> a;

    hoba(int l, int r) : lf(l), rg(r) {};
};

hoba *build(int l, int r) {
    hoba *root = new hoba(l, r);
    if (l == r) {
        root->a.push_back(a[l]);
        return root;
    }
    root->l = build(l, (r + l) / 2);
    root->r = build((r + l) / 2 + 1, r);
    root->a.resize(root->l->a.size() + root->r->a.size());
    merge(root->l->a.begin(), root->l->a.end(), root->r->a.begin(), root->r->a.end(), root->a.begin());
    return root;
}

int query(hoba *root, int l, int r, int x) {
    if (r < root->lf || l > root->rg)
        return 0;
    if (l <= root->lf && root->rg <= r)
        return upper_bound(root->a.begin(), root->a.end(), x) -
               lower_bound(root->a.begin(), root->a.end(), x); // x replace 0, if [0,x]
    return query(root->l, l, r, x) + query(root->r, l, r, x);
}


int main() {
    a = {3, 1, 8, 5, 9, 3, 2, 6, 4, 5, 1, 12, 213, 12, 1, 23, 123, 123, 12, 3, 23, 123};
    hoba *tree = build(0, a.size() - 1);
    cout << query(tree, 0, a.size(), 3);
    return 0;
}
