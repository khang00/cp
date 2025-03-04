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


vector<pair<ll, ll>> findBridgesTarjan(ll n, vector<vector<ll>> &adj) {
    set<pair<ll, ll>> bridges;

    ll curr = 1;
    vector<ll> level(n);
    vector<ll> low(n);
    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        level[u] = low[u] = ++curr;
        for (auto nxt: adj[u]) {
            if (level[nxt] == 0) {
                dfs(nxt, u);
                low[u] = min(low[u], low[nxt]);
                if (low[nxt] > level[u])
                    bridges.insert({u, nxt});
            } else if (nxt != p)
                low[u] = min(low[u], level[nxt]);
        }
    };

    for (int i = 0; i < n; i++)
        if (level[i] == 0)
            dfs(i, -1);

    return {bridges.begin(), bridges.end()};
}

vector<pair<ll, ll>> findBridges(ll n, vector<vector<ll>> &adj) {
    // number of edges pass through u and its parent p
    vector<ll> dp(n);
    vector<ll> level(n);
    vector<pair<ll, ll>> bridges;

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        if (p == -1)
            level[u] = 1;

        dp[u] = 0;
        for (auto v: adj[u]) {
            if (level[v] == 0) { // edge to direct child
                level[v] = level[u] + 1;
                dfs(v, u);
                dp[u] += dp[v];
            } else if (level[v] < level[u]) { // edge upwards
                dp[u]++;
            } else { // edge downwards
                dp[u]--;
            }
        }

        dp[u]--; // minus edge connect to parent of u
        if (level[u] >= 1 && dp[u] == 0)
            bridges.emplace_back(p, u);
    };

    for (int i = 0; i < n; i++)
        if (level[i] == 0)
            dfs(i, -1);

    return bridges;
}

int main() {
    fastio();
    IN_OUT();

    return 0;
}
