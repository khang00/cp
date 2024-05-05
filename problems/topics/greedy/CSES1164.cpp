#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
#define ll long long
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

vector<long long> pow_bin_arr(long long exp) {
    vector<long long> pows(exp + 1, 1);
    pows[0] = 1;

    for (int i = 1; i <= exp; i++) {
        pows[i] = pows[i - 1] * 2;
    }

    return pows;
}

pair<ll, vector<ll>> solve(ll n, vector<pair<ll, ll>> a) {
    vector<pair<ll, ll>> b(n, pair(0, 0));
    for (int i = 0; i < n; i++)
        b[i] = pair(a[i].first, i);
    sort(b.begin(), b.end());

    ll min_room = 1;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> min_q;
    min_q.emplace(pair(a[b[0].second].second, 1));

    vector<ll> c(n, 1);
    for (int i = 1; i < n; i++) {
        ll room_number = -1;
        if (min_q.top().first < b[i].first) {
            room_number = min_q.top().second;
            min_q.pop();
        }

        if (room_number == -1)
            room_number = (ll) min_q.size() + 1;

        min_q.emplace(a[b[i].second].second, room_number);
        min_room = max(min_room, (ll) min_q.size());
        c[b[i].second] = (ll) room_number;
    }

    return {min_room, c};
}

int main() {
    fastio();
    IN_OUT();

    ll n;
    cin >> n;

    vector<pair<ll, ll>> a(n, pair(0, 0));
    for (ll i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    auto [min_room, c] = solve(n, a);
    cout << min_room << endl;

    for (auto it: c)
        cout << it << ' ';

    return 0;
}