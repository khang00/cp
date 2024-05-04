#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

bool is_possible(int n, int d, ll c, vector<ll> a) {
    int cows = 1;
    ll pre = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - pre >= d) {
            cows += 1;
            pre = a[i];
        }
    }

    if (cows >= c) {
        return true;
    }

    return false;
}

ll solve(int n, ll c, vector<ll> a) {
    sort(a.begin(), a.end());
    int l = 0, r = 1e9 + 7;
    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        if (is_possible(n, mid, c, a)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return l;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, c;
        cin >> n >> c;

        vector<ll> a(n, 0);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        cout << solve(n, c, a) << '\n';
    }

    return 0;
}