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

struct HASH {
    size_t operator()(const pair<int, int> &x) const {
        return hash<long long>()(((long long) x.first) ^ (((long long) x.second) << 32));
    }
};

map<int, int> parent;
map<int, int> set_size;

void make_set(int a) {
    if (parent.find(a) != parent.end())
        return;
    parent[a] = a;
    set_size[a] = 1;
}

int find_set(int a) {
    if (parent[a] == a)
        return a;

    parent[a] = find_set(parent[a]);
    return parent[a];
}

void merge_set(int a, int b) {
    auto lt = find_set(a);
    auto gt = find_set(b);
    if (lt == gt)
        return;

    if (set_size[lt] > set_size[gt])
        swap(lt, gt);

    parent[lt] = gt;
    set_size[gt] += set_size[lt];
}

string solve(string a, string b, string c) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        make_set(a[i]);
        make_set(b[i]);
        merge_set(a[i], b[i]);
    }

    for (int i = 0; i < c.size(); i++) {
        if (parent.find(c[i]) == parent.end())
            continue;

        auto currRep = find_set(c[i]);
        for (int j = 'a'; j <= 'z'; j++) {
            if (parent.find(j) != parent.end() && currRep == find_set(j)) {
                c[i] = j;
                break;
            }
        }
    }

    return c;
}

int main() {
    fastio();
    IN_OUT();

    string a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c);
    return 0;
}