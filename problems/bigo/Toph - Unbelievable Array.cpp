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

long parent[MAX];
long set_size[MAX];

class DSU {
public:

    void make_set(ll a) {
        parent[a] = a;
        set_size[a] = 1;
    }

    ll find_set(ll a) {
        if (parent[a] == a)
            return a;

        parent[a] = find_set(parent[a]);
        return parent[a];
    }

    void merge_set(ll a, ll b) {
        auto lt = find_set(a);
        auto gt = find_set(b);
        if (lt == gt)
            return;

        if (set_size[lt] > set_size[gt])
            swap(lt, gt);

        parent[lt] = gt;
        set_size[gt] += set_size[lt];
    }
};

void solve(const vector<ll> &a, int n, int q) {
    DSU dsu;
    unordered_map<ll, ll> valueToRep;
    unordered_map<ll, ll> repToValue;
    for (int i = 0; i < n; i++) {
        dsu.make_set(i + 1);
        if (valueToRep.find(a[i]) != valueToRep.end())
            dsu.merge_set(i + 1, valueToRep[a[i]]);

        auto rep = dsu.find_set(i + 1);
        valueToRep[a[i]] = rep;
        repToValue[rep] = a[i];
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 2) {
            int index;
            cin >> index;

            cout << repToValue[dsu.find_set(index)] << "\n";
            continue;
        }

        ll x, y;
        cin >> x >> y;
        if (x == y || valueToRep[x] == 0) {
            // cout << "no: " << x << " " << y << " " << valueToRep[x] << "\n";
            continue;
        }

        if (valueToRep[y] == 0) {
            valueToRep[y] = valueToRep[x];
            valueToRep[x] = 0;

            repToValue[valueToRep[y]] = y;
        } else {
            auto rep = valueToRep[x];
            dsu.merge_set(valueToRep[x], valueToRep[y]);

            rep = dsu.find_set(rep);
            valueToRep[x] = 0;
            valueToRep[y] = rep;

            repToValue[rep] = y;
        }

        // cout << "bbbb " << x << " " << y << " " << dsu.find_set(x) << "\n";
    }
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;

        vector<ll> a(n);
        for (int j = 0; j < n; j++)
            cin >> a[j];

        cout << "Case " << i + 1 << ":" << "\n";
        solve(a, n, q);
    }
    return 0;
}