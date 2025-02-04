#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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

vector<int> z_function(vector<ll> a) {
    int n = a.size();
    vector<int> z(n, 0);
    int l = 0;
    int r = 0;

    for (int i = 1; i < n; i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);

        while (i + z[i] < n && a[i + z[i]] == a[z[i]])
            z[i]++;

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}

ll solve(int n, int w, vector<ll> &a, vector<ll> &b) {
    vector<ll> diff_a(n - 1);
    for (int i = 1; i < n; i++)
        diff_a[i - 1] = a[i] - a[i - 1];

    vector<ll> diff_b(w - 1);
    for (int i = 1; i < w; i++)
        diff_b[i - 1] = b[i] - b[i - 1];

    vector<ll> z_vec(diff_b);
    z_vec.push_back(INF);
    z_vec.insert(z_vec.end(), diff_a.begin(), diff_a.end());

    auto z = z_function(z_vec);
    ll cnt = 0;
    for (auto num: z)
        if (num == w - 1)
            cnt++;

    return cnt;
}

int main() {
    fastio();
    IN_OUT();

    int n, w;
    cin >> n >> w;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<ll> b(w);
    for (int i = 0; i < w; i++)
        cin >> b[i];

    cout << solve(n, w, a, b);
    return 0;
}