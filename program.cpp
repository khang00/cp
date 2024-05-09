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

ll solve(ll n, ll r, ll avg, vector<pair<ll, ll>> a) {
    sort(a.begin(), a.end());

    ll sum_ = 0;
    for (auto [_, sec]: a)
        sum_ += sec;

    ll cnt = 0;
    ll exp_sum = avg * n;
    if (sum_ > exp_sum)
        return 0;

    for (int i = 0; i < n; i++) {
        ll left = r - a[i].second;
        if (left == 0)
            continue;

        if (sum_ + left >= exp_sum) {
            cnt += (exp_sum - sum_) * a[i].first;
            break;
        } else {
            sum_ += left;
            cnt += left * a[i].first;
        }
    }

    return cnt;
}

int main() {
    fastio();
    IN_OUT();

    ll n, r, avg;
    cin >> n >> r >> avg;

    vector<pair<ll, ll>> a(n, pair(0, 0));
    for (int i = 0; i < n; i++) {
        pair<ll, ll> temp;
        cin >> temp.second >> temp.first;

        a[i] = temp;
    }

    cout << solve(n, r, avg, a);
    return 0;
}