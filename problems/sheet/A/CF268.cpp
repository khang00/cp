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

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int h, g;
        cin >> h >> g;
        arr.push_back(make_pair(h, g));
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && arr[i].first == arr[j].second) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}