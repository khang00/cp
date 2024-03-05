#include <bits/stdc++.h>

using namespace std;

#define ll long long

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

vector<pair<int, int>> solve(int n, vector<int> nums) {

}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> nums;
        for (int j = 0; i < n; j++) {
            int num;
            cin >> num;
            nums.push_back(num);
        }
        auto segs = solve(n, nums);
        cout << segs.size() << '\n';
        for (int j = 0; j < segs.size(); j++) {
            cout << segs[j].first << segs[j].second;
        }
    }

    return 0;
}