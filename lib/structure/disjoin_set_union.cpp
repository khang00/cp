#include <bits/stdc++.h>

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

int main() {
    auto a = DSU<int, unordered_map<int, int>>();
    a.make_set(1);
    a.make_set(2);

    cout << a.find_set(1) << endl;
    cout << a.find_set(2) << endl;

    a.merge(1, 2);
    cout << a.find_set(1) << endl;
    cout << a.find_set(2) << endl;

    return 0;
}