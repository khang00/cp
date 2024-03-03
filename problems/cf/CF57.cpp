#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;

#define ll long long

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int main() {
    int n;
    cin >> n;

    int mod = 1000000007;
    vector<ll> pre(n, 0);
    for (int j = 0; j < n; j++) {
        pre[j] = 1;
    }

    vector<ll> curr(n, 0);
    for (int i = 1; i <= n; i++) {
        curr[0] = pre[0];
        for (int j = 1; j < n; j++) {
            curr[j] = curr[j - 1] + pre[j];
            curr[j] %= mod;
        }

        pre = curr;
    }

    cout << (2 * curr[n - 1] - n) % mod << '\n';

    return 0;
}