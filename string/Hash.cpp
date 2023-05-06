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

class _hash {
private:
    int x, m;//basa, mod
    vector<int> power, prefix;//step x, tabl

public:
    _hash(const string &s, int x = 73, int m = 1e9 + 7) : x(x), m(m) { //build hash
        //if s[i] = {'A','a' and '1'} => x = 221!!
        power.resize(s.size() + 1);
        prefix.resize(s.size() + 1);

        power[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            power[i] = (ll) power[i - 1] * x % m;
        }
        for (int i = 0; i <= s.size() - 1; i++) {
            prefix[i + 1] = ((ll) prefix[i] * x + s[i] - 'a' + 1) % m;
        }
    }

    int sum_hash(string &s1, string &s2) { //hash1 + hash2
        return ((ll) get_hashf(s1) * power[s2.size()] + (ll) get_hashf(s2)) % m;
    }

    int sum_hash(int l, int r, string &s) { //prefix[r] + hash2
        return (get_hashp(l, r) * power[s.size()] + (ll) get_hashf(s)) % m;
    }

    int get_size() { // size prefix
        return prefix.size();
    }

    int get_hashp(int i = 1, int j = -1) { //hash on substr
        if (j == -1)//0 -> i
            return prefix[i];
        else//i -> j
            return (prefix[j] - (ll) prefix[i - 1] * power[j - i + 1] % m + m) % m;
    }

    int get_hashstr() { //full hash
        return prefix.back();
    }

    int get_hashf(string &s, int l = 0, int r = 1e9) { //hash func
        int res = 0;
        int size = min((size_t) r, s.size());
        for (int i = l; i < size; i++) {
            res = ((ll) res * x + s[i] - 'a' + 1) % m;
        }
        return res;
    }
};


void solve() { //example
    string s, s1;
    cin >> s;
    _hash hf(s);
    int q;
    cin >> q;
    flag:
    while (q--) {
        cin >> s1;
        int fnd = hf.get_hashf(s1);
        if (s1.size() == s.size() && fnd == hf.get_hashp(1, hf.get_size() - 1)) {
            cout << "YES\n";
            goto flag;
        }
        for (int i = 1; i <= s.size() - s1.size(); i++) {
            if (hf.get_hashp(i, i + s1.size() - 1) == fnd) {
                cout << "YES\n";
                goto flag;
            }
        }
        cout << "NO\n";
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
