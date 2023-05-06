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

void recoverAnswer(vector<vector<int>> &knapsack, vector<int> &things, vector<int> &answer) {
    int i = knapsack.size() - 1, j = knapsack[0].size() - 1;
    while (i != 0) {
        if (knapsack[i][j] > knapsack[i - 1][j]) {
            answer.push_back(things[i]);
            j -= things[i];
        }
        i--;
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
    int cntThings, wantedWeight;//things, need weight
    cin >> wantedWeight >> cntThings;
    vector<vector<int>> knapsack(cntThings + 1, vector<int>(wantedWeight + 1));// DP table
    vector<int> things(cntThings + 1), answer;//things, recovered answer
    for (int i = 1; i <= cntThings; i++)
        cin >> things[i];
    for (int i = 1; i <= cntThings; i++) {
        for (int j = 1; j <= wantedWeight; j++) {
            if (j >= things[i] && j >= things[i] + knapsack[i - 1][j - things[i]])
                knapsack[i][j] = max(knapsack[i - 1][j], things[i] + knapsack[i - 1][j - things[i]]);
            else
                knapsack[i][j] = knapsack[i - 1][j];
        }
    }
    recoverAnswer(knapsack, things, answer);// recover answer
    cout << knapsack[knapsack.size() - 1][knapsack[0].size() - 1];//max size
    return 0;
}
