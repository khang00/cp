#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double log_a_to_base_b(double a, double b) {
    return std::log(a) / std::log(b);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;

        long long ans = pow(2, floor(log2(n)));
        cout << ans << '\n';
    }

    return 0;
}