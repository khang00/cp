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

vector<string> solve(int q) {
    vector<string> ans;
    ll s = 1, t = 1;
    bool ta = true, sa = true;
    for (int i = 0; i < q; i++) {
        ll d, k;
        string x;
        cin >> d >> k >> x;

        for (auto c: x) {
            if (d == 1) {
                if (c == 'a')
                    s += k;
                else
                    sa = false;
            } else {
                if (c == 'a')
                    t += k;
                else
                    ta = false;
            }
        }

        if (!ta)
            ans.push_back("Yes");
        else if (sa && s < t)
            ans.push_back("Yes");
        else
            ans.push_back("No");
    }

    return ans;
}

int main() {
    fastio();
    IN_OUT();

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int q;
        cin >> q;

        auto ans = solve(q);
        for (auto it: ans)
            cout << it << endl;
    }

    return 0;
}