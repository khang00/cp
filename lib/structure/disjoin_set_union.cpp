#include <bits/stdc++.h>
#include <concepts>

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

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

template<std::regular T, Container<T> F>
class DSU {
private:
    F anc;
public:
    DSU() {
        anc = F();
    }

    void make_set(T a) {
        anc[a] = a;
    }

    T find_set(T a) {
        while (anc[a] != a)
            a = anc[a];
        return a;
    }

    void merge(T a, T b) {
        T sa = find_set(a);
        T sb = find_set(b);
        if (sa != sb)
            anc[sa] = sb;
    }
};

int main() {
    auto a = DSU<pair<int, int>, unordered_map<pair<int, int>, pair<int, int>, pair_hash>>();
    a.make_set(pair(1, 2));
    a.make_set(pair(2, 1));

    cout << a.find_set(pair(1, 2)).first << endl;
    cout << a.find_set(pair(2, 1)).first << endl;

    a.merge(pair(1, 2), pair(2, 1));
    cout << a.find_set(pair(1, 2)).first << endl;
    cout << a.find_set(pair(2, 1)).first << endl;

    return 0;
}