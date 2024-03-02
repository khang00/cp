#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_set>

using namespace std;

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int solve(int a, int b, int l) {
    unordered_set<int> ress;
    for (int i = 0;; i++) {
        if (pow(a, i) > l) {
            break;
        }

        for (int j = 0;; j++) {
            int res = pow(a, i) * pow(b, j);
            if (res > l) {
                break;
            }

            if (l % res == 0) {
                int k = l / res;
                ress.insert(k);
            }
        }
    }

    return ress.size();
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a, b, l;
        cin >> a >> b >> l;

        cout << solve(a, b, l) << '\n';
    }

    return 0;
}
