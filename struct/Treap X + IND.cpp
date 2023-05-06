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

ll sum = 0;

class Treap {
    struct treap {
        treap *l = nullptr, *r = nullptr;
        ll y, sz;
        ll x, val;

        treap(ll x, ll val) : x(x), val(val) {
            y = rand();
            sz = 1;
        }

        treap() {
            y = rand() % (ll) 1e9;
            sz = 1;
        }
    };

    ll realsz(treap *root) { // size node
        if (root && !root->l && !root->r)
            return 1;
        else
            return root ? root->sz : 0;
    }

    void upd(treap *root) { // update size node
        if (root)
            root->sz = realsz(root->l) + realsz(root->r) + 1;
    }

    pt<treap *> splitk(treap *root, ll k) { //split K
        if (root == nullptr) {
            return {nullptr, nullptr};
        }
        if (realsz(root->l) < k) {
            auto a = splitk(root->r, k - realsz(root->l) - 1);
            root->r = a.first;
            upd(root);
            return {root, a.second};
        } else {
            auto a = splitk(root->l, k);
            root->l = a.second;
            upd(root);
            return {a.first, root};
        }
    }

    ll realx(treap *root) { // val node
        if (!root)
            return -1e18;
        else
            return root->x;
    }

    pt<treap *> split(treap *root, ll x) { //split X
        if (root == nullptr) {
            return {nullptr, nullptr};
        }
        if (realx(root) < x) {
            auto a = split(root->r, x);
            root->r = a.first;
            upd(root);
            return {root, a.second};
        } else {
            auto a = split(root->l, x);
            root->l = a.second;
            upd(root);
            return {a.first, root};
        }

    }

    treap *merge(treap *l, treap *r) { // merge
        if (l == nullptr) {
            return r;
        } else if (r == nullptr) {
            return l;
        }
        if (l->y < r->y) {
            r->l = merge(l, r->l);
            upd(r);
            return r;

        } else {
            l->r = merge(l->r, r);
            upd(l);
            return l;

        }
    }

public:
    treap *root = nullptr; //your root

    ll size() { //count nodes
        return realsz(root);
    }

    treap *findk(treap *root, ll ind) { // find K
        //ind--;
        ll pos = realsz(root->l);
        if (pos > ind)
            return findk(root->l, ind);
        else if (pos == ind)
            return root;
        else
            return findk(root->r, ind - pos - 1);
    }

    treap *findx(treap *root, ll x) { // find X
        if (root->x == x)
            return root;
        else if (root->x > x)
            return findx(root->r, x);
        else
            return findx(root->l, x);
    }

    void do_dfs(vector<ll> &a, treap *t) { // treap->vector || print treap || full clear treap
        if (!t->l && !t->r) {
            //cout << t->x << ' ' ;
            a.push_back(t->val);
            //delete t;
        } else {
            if (t->l) do_dfs(a, t->l);
            //cout << t->x << ' ';
            a.push_back(t->val);
            if (t->r) do_dfs(a, t->r);
            //delete t;
        }
    }

    void mas_insert(vector<int> &a) { // vector->treap
        root = new treap;
        for (ll i = 1; i < a.size(); i++) {
            insertk(i, a[i]);
        }
    }

    void edit2(ll ind1, ll ind2, ll ed1, ll ed2) { // edit 2 neightbors
        treap *it1 = findk(root, ind1), *it2 = findk(root, ind2);
        sum -= it1->x * it1->x + it2->x * it2->x;
        it1->x += ed1, it2->x += ed2;
        sum += it1->x * it1->x + it2->x * it2->x;
    }

    void edit1(ll ind1, ll ed1) { // edit 1 neightbor
        treap *it = findk(root, ind1);
        sum -= it->x * it->x;
        it->x += ed1;
        sum += it->x * it->x;
    }

    void insertx(ll ind, ll val) { // insert X
        auto p = split(root, ind);
        treap *n = new treap(ind, val);
        root = merge(merge(p.first, n), p.second);
    }

    void insertk(ll ind, ll x) { // insert K
        //ind--;
        auto p = splitk(root, ind);
        treap *n = new treap(ind, x);
        root = merge(merge(p.first, n), p.second);
    }

    void erase(ll ind) { // erase
        ind--;
        auto a = splitk(root, ind + 1LL);
        auto b = splitk(a.first, realsz(a.first) - 1);
        delete b.second;
        root = merge(b.first, a.second);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Treap tree;

    return 0;
}
