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

struct PHASH {
    size_t operator()(const pair<int, int> &x) const {
        return hash<long long>()(((long long) x.first) ^ (((long long) x.second) << 32));
    }
};

struct CHash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

double log_a_b(double a, double b) { return std::log(a) / std::log(b); }

long long comb(long long n, long long k) {
    long double res = 1;
    for (long long i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;

    return (long long) (res + 0.01);
}

vector<long long> pow_bin_arr(long long exp) {
    vector<long long> pows(exp + 1, 1);
    pows[0] = 1;

    for (int i = 1; i <= exp; i++) {
        pows[i] = pows[i - 1] * 2;
    }

    return pows;
}

long long big_pow_m(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long bin_pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

vector<pair<ll, ll>> find_bridges(ll n, vector<vector<ll>> &adj) {
    if (n == 0)
        return {};

    vector<ll> parents(n, -1);
    vector<vector<bool>> spanEdges(n, vector<bool>(n));
    vector<ll> dp(n, 0);
    vector<bool> vis(n);

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        parents[u] = p;

        vis[u] = true;
        for (auto v: adj[u])
            if (vis[v] && not spanEdges[u][v])
                dp[u] += 2;

        for (auto v: adj[u]) {
            if (vis[v])
                continue;

            spanEdges[u][v] = true;
            spanEdges[v][u] = true;
            dfs(v, u);
            dp[u] += dp[v];
        }

        for (auto v: adj[u])
            if (not spanEdges[u][v])
                dp[u] -= 1;
    };

    for (int i = 0; i < n; i++)
        if (not vis[i])
            dfs(i, -1);

    vector<pair<ll, ll>> bridges;
    for (ll i = 0; i < n; i++) {
        if (parents[i] != -1 && dp[i] == 0)
            bridges.emplace_back(min(i, parents[i]), max(i, parents[i]));
    }
    std::sort(bridges.begin(), bridges.end());
    return bridges;
}

int main() {
    fastio();
    IN_OUT();

    return 0;
}
