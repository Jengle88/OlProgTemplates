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

ll fsometo10(string &s, int osn)
{ //from osn to 10 (ll)
    ll res = 0;
    ll k = 1;
    char z = 'a' + osn - 11;
    if (z >= 'a') {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] >= 'a' && s[i] <= z)
                res += (s[i] - 'a' + 10) * k;
            else
                res += (s[i] - '0') * k;
            k *= osn;
        }
    } else {
        for (int i = s.size() - 1; i >= 0; i--) {
            res += (s[i] - '0') * k;
            k *= osn;
        }
    }
    return res;
}

void f10tosome(ll a, int osn, string &ans)
{ // from 10 to osn (string)
    if (a) {
        int z = a % osn;
        f10tosome(a / osn, osn, ans);
        if (z >= 10)
            ans += 'a' + z - 10;
        else
            ans += '0' + z;
    }
}

// osn = [2, 36]
void solve()
{ //example
    string s;
    f10tosome(46655, 36, s);//ZZZ
    cout << s << ' ';
    cout << fsometo10(s, 36);
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
