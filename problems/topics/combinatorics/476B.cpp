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


int main() {
    string a, b;
    cin >> a >> b;

    int n;
    n = a.size();

    int pa = 0, na = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '+') {
            pa += 1;
        } else {
            na += 1;
        }
    }

    int pb = 0, nb = 0, qb = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == '+') {
            pb += 1;
        } else if (b[i] == '-') {
            nb += 1;
        } else {
            qb += 1;
        }
    }

    if (pb + qb < pa || nb + qb < na) {
        cout << fixed << setprecision(12) << 0;
        return 0;
    }

    ld res = comb(qb, pa - pb) / (ld) pow_2_arr(qb)[qb];

    cout << fixed << setprecision(12) << res;

    return 0;
}