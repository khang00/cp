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

string solve(string s) {
    int q = stoi(s.substr(3));
    unordered_set<int> set;
    for (int i = 1; i < 350; i++) {
        if (i == 316)
            continue;
        set.insert(i);
    }

    if (set.contains(q))
        return "Yes";
    else
        return "No";
}

int main() {
    string s;
    cin >> s;

    cout << solve(s);

    return 0;
}