#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

ll sovle(int n, vector<ll> a) {
    for (int i = 0; i < n; i++) {
        a[i] = abs(a[i]);
    }
    sort(a.begin(), a.end());

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = n;
        while (r - l > 1) {
            int mid = midpoint(r, l);
            if (a[mid] <= 2 * a[i]) {
                l = mid;
            } else {
                r = mid;
            }
        }

        cnt += l - i;
    }

    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<ll> a(n, 0);
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;

        a[i] = temp;
    }

    cout << sovle(n, a);
    return 0;
}