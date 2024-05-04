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

pair<ll, ll> solve(ll a, ll b, ll c, vector<ll> u, vector<ll> p) {
    sort(u.begin(), u.end());
    sort(p.begin(), p.end());

    ll cnt = 0, sum_ = 0;
    ll ai = 0, bi = 0;
    while (ai < u.size() && ai < a) {
        sum_ += u[ai];
        cnt += 1;
        ai += 1;
    }

    while (bi < p.size() && bi < b) {
        sum_ += p[bi];
        cnt += 1;
        bi += 1;
    }

    while (c > 0 && (bi < p.size() || ai < u.size())) {
        if (bi >= p.size() || (ai < u.size() && u[ai] < p[bi])) {
            sum_ += u[ai];
            ai++;
        } else {
            sum_ += p[bi];
            bi++;
        }

        c--;
        cnt++;
    }

    return {cnt, sum_};
}

int main() {
    fastio();
    IN_OUT();

    ll a, b, c;
    cin >> a >> b >> c;

    unordered_map<string, int> map = {
            {"USB",  0},
            {"PS/2", 1},
    };

    int m;
    cin >> m;

    vector<ll> u, p;
    for (int i = 0; i < m; i++) {
        string typ;
        ll price;
        cin >> price >> typ;

        if (typ == "USB")
            u.emplace_back(price);
        else
            p.emplace_back(price);
    }

    auto pair = solve(a, b, c, u, p);
    cout << pair.first << ' ' << pair.second;

    return 0;
}