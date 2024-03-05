#include <bits/stdc++.h>
using namespace std;

#define ll long long

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<char, ll> map;
    for (int i = 0; i < n; i++) {
        auto c = s[i];
        if (map.find(c) != map.end()) {
            map[c] += 1;
        } else {
            map[c] = 1;
        }
    }

    if (map['A'] > map['D']) {
        cout << "Anton";
    } else if (map['A'] < map['D']) {
        cout << "Danik";
    } else {
        cout << "Friendship";
    }

    return 0;
}