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
    int k, r;
    cin >> k >> r;

    for (int i = 1; i <= 10; i++) {
        if (k * i % 10 == 0 || k * i % 10 == r) {
            cout << i;
            return 0;
        }
    }
    return 0;
}