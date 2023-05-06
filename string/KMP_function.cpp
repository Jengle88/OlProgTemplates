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

void build_kmp(string &s, vector<int> &kmpout, int start) { //build kmp array
    for (int i = start + 1; i < s.size(); i++) {
        int k = kmpout[i - 1];
        while (k > 0 && s[i] != s[k])
            k = kmpout[k - 1];
        if (s[i] == s[k])
            k++;
        kmpout[i] = k;
    }
}

void example() {
    string t, s;//text + string
    vector<int> p;//kmp array
    cin >> t >> s;
    int size = s.size();//where do we start?
    s += "#";// s + # + t
    s += t;
    p.resize(s.size());
    build_kmp(s, p, size);
    vector<int> ans;//indexs, where s is substring of t
    for (int i = size; i < s.size(); i++) {
        if (p[i] == size)// if s is substring of t
            ans.push_back(i - 2 * size + 1);
    }
    cout << ans.size() << '\n';
    for (auto it: ans) {
        cout << it << ' ';
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
    example();

    return 0;
}
