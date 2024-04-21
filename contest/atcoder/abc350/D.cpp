#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

using namespace std;
template<typename A, typename B>
concept Container = requires(A a)
{
    {
    std::default_initializable<A> &&
    std::random_access_iterator<A> && requires { A{}; } && requires { ::new A; }
    };
    { std::regular<B> };
};

template<typename T>
concept Hashable = requires(T a)
{
    { std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
    { std::regular<T> };
};

template<Hashable T, Container<T> F>
class DSU {
private:
    F anc;
    unordered_map<T, int> size;
public:
    DSU() {
        anc = F();
        size = unordered_map<T, int>();
    }

    void make_set(T a) {
        anc[a] = a;
        size[a] = 1;
    }

    T find_set(T a) {
        if (a == anc[a])
            return a;

        return anc[a] = find_set(anc[a]);
    }

    void merge(T a, T b) {
        T sa = find_set(a);
        T sb = find_set(b);
        if (sa != sb) {
            if (size[sa] < size[sb])
                swap(sa, sb);
            anc[sa] = sb;
            size[sa] += size[sb];
        }
    }
};

ll solve(int v, int e, vector<pair<int, int>> edges) {
    auto dsu = DSU<int, unordered_map<int, int>>();
    for (int i = 1; i <= v; i++)
        dsu.make_set(i);

    for (int i = 0; i < e; i++) {
        auto [a, b] = edges[i];
        dsu.merge(a, b);
    }

    unordered_map<int, int> map;
    for (int i = 1; i <= v; i++) {
        map[dsu.find_set(i)] += 1;
    }

    ll cnt = 0;
    for (auto it: map) {
        ll n = it.second;
        cnt += (n * (n - 1)) / 2;
    }

    return cnt - e;
}


int main() {
    fastio();
    IN_OUT();

    int v, e;
    cin >> v >> e;

    vector<pair<int, int>> edges(e, pair(0, 0));
    for (int i = 0; i < e; i++) {
        cin >> edges[i].first;
        cin >> edges[i].second;
    }

    cout << solve(v, e, edges);

    return 0;
}
