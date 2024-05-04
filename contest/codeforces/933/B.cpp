#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

ll comb(ll n, ll k) {
    ld res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;

    return (ll) (res + 0.01);
}

vector<ll> pow_2_arr(ll exp) {
    vector<ll> _2_pow(exp + 1, 1);
    _2_pow[0] = 1;

    for (int i = 1; i <= exp; i++) {
        _2_pow[i] = _2_pow[i - 1] * 2;
    }

    return _2_pow;
}

ll big_pow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

string solve(int n, vector<ll> nums) {
    for (int i = 0; i < n - 2; i++) {
        if (nums[i] == 0) {
            continue;
        }

        int x = min((ll)nums[i], (ll)floor(nums[i + 1] / 2));
        nums[i] -= x;
        nums[i + 1] -= x * 2;
        nums[i + 2] -= x;
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<ll> nums(n, 0);
        for (int j = 0; j < n; j++) {
            ll temp;
            cin >> temp;

            nums[j] = temp;
        }


        cout << solve(n, nums) << '\n';
    }

    return 0;
}