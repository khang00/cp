#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <utility>

using namespace std;
using namespace __gnu_pbds;

#define INF (ll) 1e18
#define MAX (int) 1e6
#define ll long long
#define ul unsigned long
#define ld long double
#define fastio()                                                               \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);                                                               \
  cout.tie(NULL);                                                              \
  cout << fixed << std::setprecision(10)

void IN_OUT() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

string solve(ll n, string s, ll k) {
    for (int i = 0; i < pow(2, n - 1); i++) {
        string ans, curr;
        curr.push_back(s[0]);

        ll sum = 0;
        for (int j = 0; j < n - 1; j++) {
            if (i >> j & 1) {
                sum += atoi(curr.c_str());
                ans += curr + "+";
                curr = "";
            }
            if (sum > k)
                break;
            curr.push_back(s[j + 1]);
        }
        ans += curr;
        sum += atoi(curr.c_str());
        if (sum == k)
            return ans;
    }
    return "";
}

int main() {
    fastio();
    IN_OUT();

    ll t;
    cin >> t;

    while (t > 0) {
        t--;

        string s;
        ll k;
        cin >> s >> k;

        cout << solve(s.size(), s, k) << "\n";
    }

    return 0;
}
