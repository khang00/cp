#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1e18
#define ll long long
#define ul unsigned long
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

string solve(string s) {
    unordered_set<char> a = {'H', 'Q', '9'};
    for (auto c: s) {
        if (a.contains(c))
            return "YES";
    }

    return "NO";
}

int main() {
    fastio();
    IN_OUT();

    string s;
    cin >> s;

    cout << solve(s);

    return 0;
}