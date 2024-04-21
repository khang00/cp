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

vector<pair<int, int>> solve(int n, vector<int> a) {
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++)
        b[a[i]] = i;

    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1; i++) {
        if (i != a[i]) {
            auto j = b[i];
            b[a[i]] = j;

            swap(a[i], a[j]);
            ans.emplace_back(i, j);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = a[i] - 1;
    }

    auto ans = solve(n, a);
    cout << ans.size() << '\n';

    for (auto it: ans)
        cout << it.first + 1 << ' ' << it.second + 1 << '\n';

    return 0;
}