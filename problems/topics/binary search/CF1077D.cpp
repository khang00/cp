#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF (ll) 1e18
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

bool check(ll mid, int k, const vector<pair<ll, ll>> &b) {
    ll requiredNumbers = mid * k;
    for (auto it: b) {
        auto takes = it.first / mid;
        requiredNumbers -= takes * mid;
    }

    return requiredNumbers <= 0;
}

vector<ll> solve(vector<ll> &a, int n, int k) {
    unordered_map<ll, ll> frequency;
    for (auto num: a)
        frequency[num] += 1;

    vector<pair<ll, ll>> b;
    for (auto const &[key, value]: frequency)
        b.emplace_back(value, key);
    sort(b.begin(), b.end(), greater<>());

    ll l = 0, r = n + 1;
    while (r - l > 1) {
        auto mid = l + (r - l) / 2;
        if (check(mid, k, b))
            l = mid;
        else
            r = mid;
    }

    vector<ll> ans(k, 0);
    int j = 0;
    for (auto i = 0; i < k; i++) {
        b[j].first -= l;
        ans[i] = b[j].second;

        while (j < b.size() && b[j].first < l)
            j++;

        if (j >= b.size())
            break;
    }

    return ans;
}

int main() {
    fastio();
    IN_OUT();

    int n, k;
    cin >> n >> k;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (auto it: solve(a, n, k))
        cout << it << " ";

    return 0;
}