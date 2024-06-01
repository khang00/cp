#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
#define ll long long
#define ul unsigned long
#define ld long double
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

bool build(unordered_map<char, vector<int>> map, string &ans, int d, char small, char big) {
    if ((int) map[small].size() > (int) map[big].size())
        swap(small, big);

    for (int i = 0; i < d; i++) {
        if (i % 2 == 0) {
            ans[map[big][i]] = 'R';
        } else {
            ans[map[big][i]] = 'H';
        }
    }
    int parity = 0;
    if (small == 'N' or small == 'S')
        parity = 1;

    for (int i = 0; i < map[small].size(); i++) {
        if (i % 2 == parity) {
            ans[map[small][i]] = 'R';
            ans[map[big][d + i]] = 'R';
        } else {
            ans[map[small][i]] = 'H';
            ans[map[big][d + i]] = 'H';
        }
    }

    return false;
}

string solve(int n, string x) {
    unordered_map<char, vector<int>> map;
    for (int i = 0; i < n; i++)
        map[x[i]].push_back(i);

    int dx = abs((int) map['E'].size() - (int) map['W'].size());
    int dy = abs((int) map['N'].size() - (int) map['S'].size());
    string ans(n, '*');

    build(map, ans, dx, 'E', 'W');
    build(map, ans, dy, 'N', 'S');

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int isR = false, isH = false;
    unordered_map<char, int> dirs = {
            {'S', 1},
            {'N', -1},
            {'E', 1},
            {'W', -1}
    };

    for (int i = 0; i < n; i++) {
        if (ans[i] == 'R') {
            isR = true;
            if (x[i] == 'E' or x[i] == 'W')
                x1 += dirs[x[i]];
            else
                y1 += dirs[x[i]];
        } else {
            isH = true;
            if (x[i] == 'E' or x[i] == 'W')
                x2 += dirs[x[i]];
            else
                y2 += dirs[x[i]];
        }
    }

    if (x1 == x2 && y1 == y2 && isR && isH)
        return ans;

    return "NO";
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        string x;
        cin >> x;

        cout << solve(n, x) << '\n';
    }

    return 0;
}