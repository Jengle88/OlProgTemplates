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

struct hoba {
    hoba *l = nullptr, *r = nullptr;
    int lf = 0, rg = 0;
    int sum = 0, min = INF, max = -INF;

    hoba(int l, int r) : lf(l), rg(r) {};
};

vector<int> a;

hoba *build(int l, int r) {
    hoba *root = new hoba(l, r);
    if (l == r) {
        root->max = root->min = root->sum = a[l];
        return root;
    }
    root->l = build(l, (l + r) / 2);
    root->r = build((l + r) / 2 + 1, r);
    root->sum = root->l->sum + root->r->sum;
    root->min = min(root->l->min, root->r->min);
    root->max = max(root->l->max, root->r->max);
    return root;
}

void update(hoba *root, int ind, int d) { //1 elem
    if (root->lf > ind || root->rg < ind)
        return;
    if (root->lf == root->rg && root->rg == ind) {
        root->sum = root->min = root->max = d;
    } else {
        update(root->l, ind, d);
        update(root->r, ind, d);
        root->min = min(root->l->min, root->r->min);
        root->max = max(root->l->max, root->r->max);
        root->sum = root->l->sum + root->r->sum;
    }
}

int query_sum(hoba *root, int l, int r) {
    if (root->lf > r || root->rg < l)
        return 0;
    if (l <= root->lf && root->rg <= r)
        return root->sum;
    return query_sum(root->l, l, r) + query_sum(root->r, l, r);
}

int query_min(hoba *root, int l, int r) {
    if (root->lf > r || root->rg < l)
        return INF;
    if (l <= root->lf && root->rg <= r)
        return root->min;
    return min(query_min(root->l, l, r), query_min(root->r, l, r));
}

int query_max(hoba *root, int l, int r) {
    if (root->lf > r || root->rg < l)
        return -INF;
    if (l <= root->lf && root->rg <= r)
        return root->max;
    return max(query_max(root->l, l, r), query_max(root->r, l, r));
}

int main() {
    a = { 3, 1, 8, 5, 9, 3, 2, 6, 4, 5, 1, 12, 213, 12, 1, 23, 123, 123, 12, 3, 23, 123 };
    hoba *tree = build(0, a.size() - 1);
    update(tree, a.size() / 2, 10);
    cout << query_min(tree, 0, a.size() - 1) << '\n';
    cout << query_max(tree, 0, a.size() - 1) << '\n';
    cout << query_sum(tree, 0, a.size() - 1) << '\n';
    return 0;
}
