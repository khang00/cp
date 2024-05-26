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

string solve(string s, int k) {
    auto n = s.size();

    int l = 0, r = 1;
    while (k > 0) {
        if (s[l] > s[r]) {
            s[l] = '*';
            k--;
            l = r;
            r++;
        } else {
            s[r] = '*';
            k--;
            r++;
        }
    }

    string ans;
    for (int i = 0; i < n; i++) {
        if (s[i] != '*')
            ans.push_back(s[i]);
    }

    return s;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string x;
        cin >> x;

        int k;
        cin >> k;

        cout << solve(x, k) << '\n';
    }

    return 0;
}